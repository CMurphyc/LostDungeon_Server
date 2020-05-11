#include <errno.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "server.h"


void Server::Recv() {
    if (fd_to_buff_.find(cur_fd_) == fd_to_buff_.end()) {
        printf("Recv fd do not exist!\n");
        return ;
    }
    cur_recv_len_ = recv(cur_fd_,
                         cur_client_buff_->buff_ + cur_client_buff_->tail_,
                         BUFF_SIZE - cur_client_buff_->tail_, 0);
    if (cur_recv_len_ > 0) {
        // printf("recv %d bytes from %d fd\n", cur_recv_len_, cur_fd_);
        HandleRecvPackage();
    } else if (cur_recv_len_ == 0) {
        //close
        /*
            输出对方主动关闭
        */
        CloseClientFd(cur_fd_);
    } else if (cur_recv_len_ == -1) {
        //这几个错误参数还可以继续进行读写
        if (errno == EINTR || errno == EWOULDBLOCK || errno == EAGAIN) {
            return ;
        }
        CloseClientFd(cur_fd_);
        printf("recv failed, errno = %d, errno_message = %s\n",
                errno, strerror(errno));
    }
}

void Server::Send(google::protobuf::Message &message, int msg_type) {
    if(!Pack(message, msg_type)) {
        return ;
    }
    int send_ret = send(cur_fd_, cur_ret_buff_, cur_ret_msg_len_ + HEAD_SIZE, 0);
    if (send_ret == -1) {
        printf("server send to fd: %d error, errno = %d, strerror : %s\n",
            cur_fd_, errno, strerror(errno));
        CloseClientFd(cur_fd_);
        return ;
    } else {
        // printf("server send to fd_%d| %d bytes\n", cur_fd_, send_ret);
    }
}

//int转byte
void Server::IntToBytes(int n, byte *bytes) {
    bytes[0] = (byte) (0xff & n);
    bytes[1] = (byte) ((0xff00 & n) >> 8);
    bytes[2] = (byte) ((0xff0000 & n) >> 16);
    bytes[3] = (byte) ((0xff000000 & n) >> 24);
    return ;
}

//byte转int
int Server::BytesToInt(byte *bytes) {
    int n = bytes[0] & 0xFF;
    n |= ((bytes[1] << 8) & 0xFF00);
    n |= ((bytes[2] << 16) & 0xFF0000);
    n |= ((bytes[3] << 24) & 0xFF000000);
    return n;
}

//把返回给客户端的消息加上包头并打包
void Server::AddHead() {
    IntToBytes(cur_ret_msg_type_, cur_ret_buff_);
    IntToBytes(cur_ret_msg_len_, cur_ret_buff_ + TYPE_SIZE);
}

//解析收到的消息头
void Server::ParseHead() {
    cur_recv_msg_type_ = BytesToInt(cur_client_buff_->buff_ +
                                    cur_client_buff_->head_);
    cur_recv_msg_len_ = BytesToInt(cur_client_buff_->buff_ +
                                   cur_client_buff_->head_ +
                                   TYPE_SIZE);
}

//处理接接收的包，并把用户缓冲区的数据拆包并解析，防止粘包
void Server::HandleRecvPackage() {
    if (cur_client_buff_->buff_ == nullptr) {
        printf("socket: %d has nullptr buff in HandleRecvPackage\n", cur_fd_);
        int close_ret = close(cur_fd_);
        if (close_ret == -1) {
            printf("close nullptr buff socket in HandleRecvPackage: %d error, errno = %d\n", cur_fd_, errno);
        }
        return ;
    }
    cur_client_buff_->tail_ += cur_recv_len_;
    int l = cur_client_buff_->head_, r = cur_client_buff_->tail_;
    while (l < r && l < BUFF_SIZE && r <= BUFF_SIZE) {
        int buff_len = r - cur_client_buff_->head_;
        // 数据长度不足包头长说明包不完整
        if (buff_len < 8) {
            break ;
        }
        ParseHead();
        // 包头数据有问题要把它close了
        if (cur_recv_msg_type_ <= MIN_REQ_NUM || cur_recv_msg_type_ >= MAX_RET_NUM ||
            cur_recv_msg_len_ < 0 || cur_recv_msg_len_ > BUFF_SIZE) {
            CloseClientFd(cur_fd_);
            break;
        }
        // 数据长度不足一个包
        if (buff_len < cur_recv_msg_len_ + HEAD_SIZE) {
            break ;
        }
        HandleMsg();
        l += (cur_recv_msg_len_ + HEAD_SIZE);
        cur_client_buff_->head_ = cur_client_buff_->head_ +
                                  cur_recv_msg_len_ + HEAD_SIZE;
    }
    cur_client_buff_->MoveData();
}

//服务器根据包头中的类型来进行相应操作
void Server::HandleMsg() {
    // printf("fd %d req %d\n", cur_fd_, cur_recv_msg_type_);
    switch (cur_recv_msg_type_) {
        case BATTLE_INPUT_REQ:
            HandleBattleInput();
            break;
        case LOGIN_REQ:
            TmpLogin();
            //Login(cur_recv_msg_type_);
            break;
        case REGISTER_REQ:
            //Login(cur_recv_msg_type_);
            break;
        case GET_ROOM_LIST_REQ:
            GetRoomList();
            break;
        case ENTER_ROOM_REQ:
            EnterRoom();
            break;
        case PLAYER_READY_REQ:
            PlayerReady();
            break;
        case CREATE_ROOM_REQ:
            CreateRoom();
            break;
        case START_SYNC_REQ:
            StartSync();
            break;
        case ROOM_CHANGE_ROLE_REQ:
            ChangeRole();
            break;
        case LEAVE_ROOM_REQ:
            LeaveRoom();
            break;
        case NEXT_FLOOR_REQ:
            NextFloor();
            break;
        case GAME_OVER_REQ:
            GameOver();
            break;
        default : 
            cout << "recv a none type package" << endl;
            CloseClientFd(cur_fd_);
    }

}

bool Server::Pack(google::protobuf::Message &message, int msg_type) {
    cur_ret_msg_len_ = message.ByteSize();
    if (!Serialize(message)) {
        return false;
    }
    cur_ret_msg_type_ = msg_type;
    // cout << "........" << endl;
    // cout << cur_ret_msg_type_ << ' ' << cur_ret_msg_len_ << endl;
    // cout << "........" << endl;
    AddHead();
    return true;
}

bool Server::Deserialize(google::protobuf::Message &message) {
    int ret = message.ParseFromArray(
        cur_client_buff_->buff_ +
        cur_client_buff_->head_ + HEAD_SIZE,
        cur_recv_msg_len_);
    if (ret < 0) {
        // printf("fd: %d Deserialization error!\n", cur_fd_);
        return false;
    }
    // cout << "++++++++++" << endl;
    // message.PrintDebugString();
    // cout << "++++++++++" << endl;
    return true;
}

bool Server::Serialize(google::protobuf::Message &message) {
    // cout << "----------" << endl;
    // message.PrintDebugString();
    // cout << "----------" << endl;
    int ret = message.SerializeToArray(cur_ret_buff_ + HEAD_SIZE, cur_ret_msg_len_);
    if (ret < 0) {
        // printf("fd: %d Serialize error!\n", cur_fd_);
        return false;
    }
    return true;
}

/*
LoginS2C_LoginRet Server::LoginCheck(const LoginC2S &user) {
    fstream input("user_account_data", ios::in | ios::binary);
    string userName, password;
    while (input >> userName >> password) {
        if (userName == user.username()) {
            if (password == user.password()) {
                input.close();
                return LoginS2C_LoginRet_LOGIN_SUCCESS;
            } else {
                input.close();
                return LoginS2C_LoginRet_WRONG_PASSWORD;
            }
        }
    }
    input.close();
    return LoginS2C_LoginRet_NONE_USERNAME;
}

//返回值：1表示注册成功；-1表示用户名已存在
RegisterS2C_RegisterRet Server::RegisterCheck(const LoginC2S &user) {
    fstream input("user_account_data", ios::in | ios::binary);
    string userName, password;
    while (input >> userName >> password) {
        if (userName == user.username()) {
            input.close();
            return RegisterS2C_RegisterRet_EXIST_USERNAME;
        }
    }
    input.close();
    fstream output("user_account_data", ios::out | ios::app | ios::binary);
    //output << user.username() << ' ' << user.password() << endl;
    output.close();
    return RegisterS2C_RegisterRet_REGISTER_SUCCESS;
}

//登录注册功能
void Server::Login(int type) {
    LoginC2S user = LoginC2S();
    //反序列化
    if (!Deserialize(user)) {
        return ;
    }
    //把登录信息反馈给客户端
    LoginS2C login_s2c;
    if (type == LOGIN_REQ) {
        login_s2c.set_error(LoginCheck(user));
        cur_ret_msg_type_ = LOGIN_RET;
    } else if (type == REGISTER_REQ) {
        login_s2c.set_error(RegisterCheck(user));
        cur_ret_msg_type_ = REGISTER_RET;
    }

    Send(login_s2c, cur_ret_msg_type_);
}

int Server::TmpLoginCheck(const LoginC2S &login_c2s) {
    fstream input("data/user_account_data", ios::in | ios::binary);
    string userName;
    int uid = 0;
    while (input >> uid >> userName) {
        if (userName == login_c2s.username()) {
            input.close();
            return uid;
        }
    }
    input.close();
    fstream output("data/user_account_data", ios::out | ios::app | ios::binary);
    ++uid;
    output << uid << ' ' << login_c2s.username() << endl;
    output.close();
    return uid;
}
*/

void Server::TmpLogin() {
    LoginS2C login_s2c = LoginS2C();
    LoginC2S login_c2s = LoginC2S();
    // 同一客户端不能登录多个账号
    if (fd_to_uid_.find(cur_fd_) != fd_to_uid_.end()) {
        login_s2c.set_loginret(LoginS2C_LoginRet_ALREADY_ONLINE);
        Send(login_s2c, LOGIN_RET);
        cout << "fd : " << cur_fd_ << " is already online, login failed" << endl; 
        return ;
    }
    // 服务器满了
    if (uid_to_player_.size() >= MAX_PLAYER_NUMBER) {
        login_s2c.set_loginret(LoginS2C_LoginRet_SERVER_FULL);
        Send(login_s2c, LOGIN_RET);
        cout << "server player full, fd : " << cur_fd_ << "login failed" << endl;
        return ;
    }
    //反序列化出错
    if (!Deserialize(login_c2s)) {
        login_s2c.set_error(DESERIALIZE_ERROR);
        Send(login_s2c, LOGIN_RET);
        CloseClientFd(cur_fd_);
        /*
            TODO: 客户端数据包出错，把它踢了
        */
        return ;
    }
    //把登录信息反馈给客户端
    //判断下有没有重复的用户名在线
    // int cur_uid = TmpLoginCheck(login_c2s);
    // login_s2c.set_uid(cur_uid);
    // login_s2c.set_username(login_c2s.username());
    // if (fd_to_uid_.find(cur_fd_) == fd_to_uid_.end()) {
    //     if (uid_to_player_.find(cur_uid) == uid_to_player_.end()) {
    //         //正常登录
    //         uid_to_player_[cur_uid] = new Player(cur_uid);
    //     } else if (uid_to_player_[cur_uid]->is_in_game) {
    //         /*
    //             TODO: 断线重连
    //                   (把所有帧发给它)
    //                   (发完后更新is_sync_frame_，再开始同步广播帧同步帧)
    //         */
    //     }
    //     Player *cur_player = uid_to_player_[cur_uid];
    //     cur_player->SetClientFd(cur_fd_);
    //     cur_player->SetUserName(login_c2s.username());
    //     fd_to_uid_[cur_fd_] = cur_uid;
    //     login_s2c.set_loginret(LoginS2C_LoginRet_LOGIN_SUCCESS);
    // } else {
    //     //同一个账号不能重复登录且一个客户端不能登录多个账号
    //     login_s2c.set_loginret(LoginS2C_LoginRet_ALREADY_ONLINE);
    // }
    int cur_uid = (++player_count_);
    login_s2c.set_uid(cur_uid);
    login_s2c.set_username(login_c2s.username());
    uid_to_player_[cur_uid] = new Player(cur_uid);
    Player *cur_player = uid_to_player_[cur_uid];
    cur_player->SetClientFd(cur_fd_);
    cur_player->SetUserName(login_c2s.username());
    fd_to_uid_[cur_fd_] = cur_uid;
    login_s2c.set_loginret(LoginS2C_LoginRet_LOGIN_SUCCESS);
    Send(login_s2c, LOGIN_RET);
    cout << "player : " << cur_player->GetUserName() << " fd : " << cur_player->GetClientFd() << " login success" << endl;
}

bool Server::SecurelyGetPlayerByFd(Player *&player, int fd) {
    if (fd_to_uid_.find(fd) == fd_to_uid_.end()) {
        return false;
    }
    int cur_uid = fd_to_uid_[fd];
    if (uid_to_player_.find(cur_uid) == uid_to_player_.end()) {
        return false;
    }
    player = uid_to_player_[cur_uid];
    return true;
}

bool Server::SecurelyGetPlayerByUid(Player *&player, int uid) {
    if (uid_to_player_.find(uid) == uid_to_player_.end()) {
        return false;
    }
    player = uid_to_player_[uid];
    return true;
}

bool Server::SecurelyGetRoomById(Room *&room, int room_id) {
    if (id_to_room_.find(room_id) == id_to_room_.end()) {
        return false;
    }
    room = id_to_room_[room_id];
    return true;
}

/*
    TODO: 同一出错和越界判断可以参考CreateRoom函数
          有些错误要不就不回包了，比如反序列化出错
          然后可以写俩函数，一个安全获取玩家，一个安全获取房间
*/

void Server::CreateRoom() {
    CreateRoomS2C create_room_s2c = CreateRoomS2C();
    CreateRoomC2S create_room_c2s = CreateRoomC2S();
    Player *cur_player = nullptr;
    if (!SecurelyGetPlayerByFd(cur_player, cur_fd_) ||
        !Deserialize(create_room_c2s)) {
        CloseClientFd(cur_fd_);
        return ;
    }
    if (!cur_player->CheckStatus(Player::PlayerStatus::IN_HALL) ||
        id_to_room_.size() >= MAX_ROOM_NUMBER) {
        create_room_s2c.set_succeed(false);
        Send(create_room_s2c, CREATE_ROOM_RET);
        return ;
    }
    ++available_room_id_;
    id_to_room_[available_room_id_] = new Room(available_room_id_);
    Room *cur_room = id_to_room_[available_room_id_];
    cur_room->SetOwnerUid(cur_player->GetUid());
    cur_room->AddPlayer(cur_player);
    cur_room->SetRoomType(create_room_c2s.roomtype());
    GetRoomInfo(cur_room->GetRoomId());
    cout << "player : " << cur_player->GetUserName() << " fd : " << cur_player->GetClientFd() << " create room id: " << cur_room->GetRoomId() << ", room type: " << room_type_str[cur_room->GetRoomType()] << " success" << endl;
}

void Server::GetRoomList() {
    GetRoomListC2S get_room_list_c2s = GetRoomListC2S();
    GetRoomListS2C get_room_list_s2c = GetRoomListS2C();
    if (!Deserialize(get_room_list_c2s)) {
        CloseClientFd(cur_fd_);
        return ;
    }
    Player *player = nullptr;
    map<int, Room *>::iterator it;
    for (it = id_to_room_.begin(); it != id_to_room_.end(); ++it) {
        if (!(*it).second->CheckStatus(Room::RoomStatus::IN_HALL) ||
            (*it).second->GetRoomType() != get_room_list_c2s.roomtype()) {
            continue;
        }
        RoomInfo *room_info = get_room_list_s2c.add_roomsinfo();
        room_info->set_roomid((*it).first);
        room_info->set_currentsize((*it).second->GetCurRoomSize());
        room_info->set_maxsize((*it).second->GetRoomSize());
        room_info->set_roomtype((*it).second->GetRoomType());
        if (SecurelyGetPlayerByUid(player, (*it).second->GetOwnerUid())) {
            room_info->set_owner(player->GetUserName());
        }
    }
    Send(get_room_list_s2c, GET_ROOM_LIST_RET);
}

/*
    TODO: 优化广播房间信息的函数，不要都广播
*/

void Server::GetRoomInfo(int room_id) {
    GetRoomInfoS2C get_room_info_s2c = GetRoomInfoS2C();
    Room *cur_room = nullptr;
    if (!SecurelyGetRoomById(cur_room, room_id)) {
        return ;
    }
    PlayerInfo *player_info = nullptr;
    Player *cur_player = nullptr;
    set<Player *, PlayerCmp>::iterator it;
    for (it = cur_room->player_set_.begin(); it != cur_room->player_set_.end(); ++it) {
        player_info = get_room_info_s2c.add_playersinfo();
        cur_player = (*it);
        player_info->set_playerid(cur_player->GetUid());
        player_info->set_username(cur_player->GetUserName());
        player_info->set_role(cur_player->GetRole());
        player_info->set_isready(
            cur_player->CheckStatus(Player::PlayerStatus::ROOM_READY));
        player_info->set_runes(cur_player->GetRunes());
    }
    get_room_info_s2c.set_roomownerid(cur_room->GetOwnerUid());
    get_room_info_s2c.set_roomid(cur_room->GetRoomId());
    get_room_info_s2c.set_succeed(true);
    BroadCast(cur_room->player_set_, get_room_info_s2c, GET_ROOM_INFO_BROAD_CAST);
}

void Server::EnterRoom() {
    EnterRoomS2C enter_room_s2c = EnterRoomS2C();
    EnterRoomC2S enter_room_c2s = EnterRoomC2S();
    Player *cur_player = nullptr;
    Room *cur_room = nullptr;
    if (!SecurelyGetPlayerByFd(cur_player, cur_fd_) ||
        !Deserialize(enter_room_c2s)) {
        CloseClientFd(cur_fd_);
        return ;
    }
    // if (!Deserialize(enter_room_c2s)) {
    //     enter_room_s2c.set_error(DESERIALIZE_ERROR);
    //     Send(enter_room_s2c, ENTER_ROOM_RET);
    //     CloseClientFd(cur_fd_);
    //     /*
    //         TODO: 客户端数据包出错，把它踢了
    //     */
    //     return ;
    // }
    cout << "player : " << cur_player->GetUserName() << " fd : " << cur_player->GetClientFd() << " want to enter room : " << enter_room_c2s.roomid() << endl;
    if (!cur_player->CheckStatus(Player::PlayerStatus::IN_HALL) ||
        !SecurelyGetRoomById(cur_room, enter_room_c2s.roomid()) ||
        !cur_room->CheckRoomSize() ||
        !cur_room->CheckStatus(Room::RoomStatus::IN_HALL)) {
        enter_room_s2c.set_succeed(false);
        Send(enter_room_s2c, ENTER_ROOM_RET);
        cout << "player : " << cur_player->GetUserName() << " fd : " << cur_player->GetClientFd() << " enter room : " << enter_room_c2s.roomid() << " failed" << endl;
        return ;
    }
    cur_room->AddPlayer(cur_player);
    GetRoomInfo(cur_room->GetRoomId());
}

void Server::PlayerReady() {
    PlayerReadyS2C player_ready_s2c = PlayerReadyS2C();
    Player *cur_player = nullptr;
    Room *cur_room = nullptr;
    if (!SecurelyGetPlayerByFd(cur_player, cur_fd_)) {
        CloseClientFd(cur_fd_);
        return ;
    }
    if (!cur_player->CheckInRoom() ||
        !SecurelyGetRoomById(cur_room, cur_player->GetRoomId())) {
        player_ready_s2c.set_error(NOT_IN_ROOM_ERROR);
        Send(player_ready_s2c, PLAYER_READY_RET);
        cout << "player : " << cur_player->GetUserName() << " fd : " << cur_player->GetClientFd() << " change ready failed because player is not in room"<< endl;
        return ;
    }
    if (cur_player->GetUid() != cur_room->GetOwnerUid()) {
        cur_player->PlayerReady();
        GetRoomInfo(cur_room->GetRoomId());
        cout << "player : " << cur_player->GetUserName() << " fd : " << cur_player->GetClientFd() << " change ready" << endl;
    } else {
        StartGameS2C start_game_s2c = StartGameS2C();
        if (cur_room->StartGame()) {
            start_game_s2c.set_succeed(true);
            start_game_s2c.set_seed(GenerateRandomNumber(DEFAULT_RANDOM_DIGIT));
            start_game_s2c.set_floornumber(cur_room->GetFloorNumber());
            start_game_s2c.set_maxfloornumber(MAX_FLOOR_NUMBER);
            set<Player *, PlayerCmp>::iterator it;
            PlayerInfo *player_info = nullptr;
            for (it = cur_room->player_set_.begin(); 
                 it != cur_room->player_set_.end(); ++it) {
                player_info = start_game_s2c.add_playersinfo();
                player_info->set_playerid((*it)->GetUid());
                player_info->set_username((*it)->GetUserName());
                player_info->set_role((*it)->GetRole());
            }
            cur_room->start_game_s2c.CopyFrom(start_game_s2c);
            BroadCast(cur_room->player_set_, start_game_s2c,
                      START_GAME_BROAD_CAST);
            UpdateTimeVal(cur_room->pre_tv_);
            room_sync_queue_.push(cur_room);
            cout << "player : " << cur_player->GetUserName() << " fd : " << cur_player->GetClientFd() << " start game success, now is loading..." << endl;
        } else {
            start_game_s2c.set_succeed(false);
            Send(start_game_s2c, START_GAME_BROAD_CAST);
            cout << "player : " << cur_player->GetUserName() << " fd : " << cur_player->GetClientFd() << " start loading failed" << endl;
        }
    }
    
}

void Server::ChangeRole() {
    ChangeRoleS2C change_role_s2c = ChangeRoleS2C();
    ChangeRoleC2S change_role_c2s = ChangeRoleC2S();
    Player *cur_player = nullptr;
    Room *cur_room = nullptr;
    if (!SecurelyGetPlayerByFd(cur_player, cur_fd_) ||
        !Deserialize(change_role_c2s)) {
        CloseClientFd(cur_fd_);
        return ;
    }
    if (!cur_player->CheckInRoom() ||
        !SecurelyGetRoomById(cur_room, cur_player->GetRoomId())) {
        change_role_s2c.set_error(NOT_IN_ROOM_ERROR);
        Send(change_role_s2c, ROOM_CHANGE_ROLE_RET);
        cout << "player : " << cur_player->GetUserName() << " fd : " << cur_player->GetClientFd() << " change role failed, because player is not in room "<< endl;
        return ;
    }
    cur_player->SetRole(change_role_c2s.role());
    GetRoomInfo(cur_player->GetRoomId());
    cout << "player : " << cur_player->GetUserName() << " fd : " << cur_player->GetClientFd() << " change role : " << cur_player->GetRole() << endl;
}

void Server::ChangeRunes() {
    // ChangeRoleS2C change_role_s2c = ChangeRoleS2C();
    // ChangeRoleC2S change_role_c2s = ChangeRoleC2S();
    // Player *cur_player = nullptr;
    // Room *cur_room = nullptr;
    // if (!SecurelyGetPlayerByFd(cur_player, cur_fd_) ||
    //     !Deserialize(change_role_c2s)) {
    //     CloseClientFd(cur_fd_);
    //     return ;
    // }
    // if (!cur_player->is_in_room_ ||
    //     !SecurelyGetRoomById(cur_room, cur_player->GetRoomId())) {
    //     change_role_s2c.set_error(NOT_IN_ROOM_ERROR);
    //     Send(change_role_s2c, ROOM_CHANGE_ROLE_RET);
    //     cout << "player : " << cur_player->GetUserName() << " fd : " << cur_player->GetClientFd() << " change role failed, because player is not in room "<< endl;
    //     return ;
    // }
    // cur_player->SetRole(change_role_c2s.role());
    // GetRoomInfo(cur_player->GetRoomId());
    // cout << "player : " << cur_player->GetUserName() << " fd : " << cur_player->GetClientFd() << " change role : " << cur_player->GetRole() << endl;
}

void Server::LeaveRoom() {
    LeaveRoomS2C leave_room_s2c = LeaveRoomS2C();
    Player *cur_player = nullptr;
    Room *cur_room = nullptr;
    if (!SecurelyGetPlayerByFd(cur_player, cur_fd_)) {
        return ;
    }
    if (!cur_player->CheckInRoom() ||
        !SecurelyGetRoomById(cur_room, cur_player->GetRoomId())) {
        leave_room_s2c.set_error(NOT_IN_ROOM_ERROR);
        Send(leave_room_s2c, LEAVE_ROOM_RET);
        cout << "player : " << cur_player->GetUserName() << " fd : " << cur_player->GetClientFd() << " leave room failed, because player is not in room" << endl;
        return ;
    }
    leave_room_s2c.set_succeed(true);
    Send(leave_room_s2c, LEAVE_ROOM_RET);
    cout << "player : " << cur_player->GetUserName() << " fd : " << cur_player->GetClientFd() << " want to leave room : " << cur_room->GetRoomId() << endl;
    cur_room->LeaveRoom(cur_player);
    if (cur_room->CheckNeedToDeleteRoom()) {
        DeleteRoom(cur_room->GetRoomId());
        cur_room = nullptr;
    } else {
        GetRoomInfo(cur_room->GetRoomId());
    }
}

void Server::DeleteRoom(int room_id) {
    Room *cur_room = nullptr;
    if (!SecurelyGetRoomById(cur_room, room_id)) {
        cout << "delete room: " << room_id << " error, because this room is not exist" << endl;
        return ;
    }
    cout << "room id : " << cur_room->GetRoomId() << " has been deleted" << endl;
    id_to_room_.erase(id_to_room_.find(cur_room->GetRoomId()));
    delete cur_room;
    cur_room = nullptr;
}

void Server::StartSync() {
    Player *cur_player = nullptr;
    Room *cur_room = nullptr;
    if (!SecurelyGetPlayerByFd(cur_player, cur_fd_) ||
        !SecurelyGetRoomById(cur_room, cur_player->GetRoomId())) {
        CloseClientFd(cur_fd_);
        return ;
    }
    StartSyncS2C start_sync_s2c = StartSyncS2C();
    if (!cur_player->CheckStatus(Player::PlayerStatus::IS_LOADING)) {
        start_sync_s2c.set_error(NOT_IN_GAME_ERROR);
        Send(start_sync_s2c, START_SYNC_BROAD_CAST);
        cout << "player : " << cur_player->GetUserName() << " fd : " << cur_player->GetClientFd() << " start sync failed because player is not in game"<< endl;
        return ;
    }
    cout << "room id : " << cur_room->GetRoomId() << " player : " << cur_player->GetUserName() << " fd : " << cur_player->GetClientFd() << " loading success, now is waiting other player" << endl;
    cur_player->ChangeStatus(Player::PlayerStatus::SYNC_READY);
    if (cur_room->StartSync()) {
        start_sync_s2c.set_succeed(true);
        BroadCast(cur_room->player_set_, start_sync_s2c, START_SYNC_BROAD_CAST);
        cout << "room id : " << cur_room->GetRoomId() << " loading success, now start sync" << endl;
    }
}

void Server::StartSync(int room_id) {
    Room *cur_room = nullptr;
    if (!SecurelyGetRoomById(cur_room, room_id)) {
        return ;
    }
    cout << "room id: " << cur_room->GetRoomId() << " a player offline, now room want to re start sync" << endl;
    StartSyncS2C start_sync_s2c = StartSyncS2C();
    if (cur_room->StartSync()) {
        start_sync_s2c.set_succeed(true);
        BroadCast(cur_room->player_set_, start_sync_s2c, START_SYNC_BROAD_CAST);
        cout << "room id : " << cur_room->GetRoomId() << " loading success and restart sync success" << endl;
    }
}

void Server::HandleBattleInput() {
    Player *cur_player = nullptr;
    if (!SecurelyGetPlayerByFd(cur_player, cur_fd_) ||
        !Deserialize(cur_player->cur_battle_input_)) {
        CloseClientFd(cur_fd_);
        return ;
    }
    BattleFrame battle_frame = BattleFrame();
    if (!cur_player->CheckStatus(Player::PlayerStatus::IS_SYNC)) {
        battle_frame.set_error(NOT_IN_GAME_ERROR);
        Send(battle_frame, BATTLE_INPUT_RET);
        return ;
    }
    cur_player->cur_battle_input_.set_uid(cur_player->GetUid());
}

/*
    TODO: 检测是否要删房间需要优化一下
*/

void Server::BroadCastBattleFrame() {
    if (room_sync_queue_.empty()) {
        return ;
    }
    while (CheckTimeInterval(room_sync_queue_.front()->pre_tv_, PER_FRAME_TIME)) {
        Room *cur_room = room_sync_queue_.front();
        room_sync_queue_.pop();
        if (cur_room->CheckNeedToDeleteRoom()) {
            DeleteRoom(cur_room->GetRoomId());
            return ;
        }
        if (cur_room->CheckStatus(Room::RoomStatus::IS_SYNC)) {
            BattleFrame battle_frame = BattleFrame();
            cur_room->CollectPlayerInput(battle_frame);
            BroadCast(cur_room->player_set_, battle_frame, BATTLE_FRAME_BROAD_CAST);
        }
        UpdateTimeVal(cur_room->pre_tv_);
        room_sync_queue_.push(cur_room);
    }
}

/*
    TODO: 状态管理优化可以参考这个NextFloor函数，再把能否转换封装一下就比较完美了
          这样就能有一个正规完善的状态转换流程
*/
void Server::NextFloor() {
    Player *cur_player = nullptr;
    Room *cur_room = nullptr;
    NextFloorC2S next_floor_c2s = NextFloorC2S();
    if (!SecurelyGetPlayerByFd(cur_player, cur_fd_) ||
        !SecurelyGetRoomById(cur_room, cur_player->GetRoomId()) ||
        !Deserialize(next_floor_c2s)) {
        CloseClientFd(cur_fd_);
        return ;
    }
    NextFloorS2C next_floor_s2c = NextFloorS2C();
    if (!cur_room->NextFloor(next_floor_c2s.floornumber())) {
        cout << "player : " << cur_player->GetUserName() << " fd : " << cur_player->GetClientFd() << " already enter the next floor"<< endl;
        return ;
    }
    next_floor_s2c.set_succeed(true);
    next_floor_s2c.set_floornumber(cur_room->GetFloorNumber());
    BroadCast(cur_room->player_set_, next_floor_s2c, NEXT_FLOOR_BROAD_CAST);
    cout << "room: " << cur_room->GetRoomId() << " enter the " << cur_room->GetFloorNumber() << "th floor, now is loading" << endl;
}

void Server::GameOver() {
    cout << "a room want to game over" << endl;
    Player *cur_player = nullptr;
    Room *cur_room = nullptr;
    if (!SecurelyGetPlayerByFd(cur_player, cur_fd_) ||
        !SecurelyGetRoomById(cur_room, cur_player->GetRoomId())) {
        return ;
    }
    GameOverS2C game_over_s2c = GameOverS2C();
    if (!cur_room->GameOver()) {
        cout << "player : " << cur_player->GetUserName() << " fd : " << cur_player->GetClientFd() << " already over the game"<< endl;
        return ;
    }
    game_over_s2c.set_succeed(true);
    BroadCast(cur_room->player_set_, game_over_s2c, GAME_OVER_BROAD_CAST);
    cur_room->Clear();
    cout << "room: " << cur_room->GetRoomId() << " game over" << endl;
}

void Server::UpdateTimeVal(struct timeval &tv) {
    int ret = gettimeofday(&tv, NULL);
    if (ret == -1) {
        printf("UpdateTimeVal Error: errno = %d, (%s)\n", errno, strerror(errno));
    }
}

bool Server::CheckTimeInterval(struct timeval &pre_tv, int time_interval) {
    UpdateTimeVal(cur_tv_);
    if ((cur_tv_.tv_sec * 1000000 + cur_tv_.tv_usec) -
        (pre_tv.tv_sec * 1000000 + pre_tv.tv_usec) >= time_interval) {
        // UpdateTimeVal(pre_tv);
        return true;
    }
    return false;
}

void Server::BroadCast(set<Player *, PlayerCmp> &player_set,
                       google::protobuf::Message &message,
                       int msg_type) {
    if (!Pack(message, msg_type)) {
        return ;
    }
    set<Player *, PlayerCmp>::iterator it;
    for (it = player_set.begin(); it != player_set.end();) {
        if ((*it)->CheckStatus(Player::PlayerStatus::OFFLINE)) {
            ++it;
            continue;
        }
        int send_ret = send((*it)->GetClientFd(), cur_ret_buff_, 
                            cur_ret_msg_len_ + HEAD_SIZE, 0);
        if (send_ret == -1) {
            printf("server broadcast to fd: %d error, errno = %d\n",
                    (*it)->GetClientFd(), errno);
            set<Player *, PlayerCmp>::iterator tmp = it;
            ++it;
            CloseClientFd((*tmp)->GetClientFd());
            continue ;
        }
        ++it;
    }
}

void Server::CloseClientFd(int fd) {
    unordered_map<int, ClientBuff *>::iterator buff_it = fd_to_buff_.find(fd);
    if (buff_it == fd_to_buff_.end()) {
        return ;
    }
    Player *cur_player = nullptr;
    Room *cur_room = nullptr;
    /*
        TODO: 判断玩家状态来删除数据或更新信息
            (在房间中的话要广播给房间内所有客户端这人离开了房间，更新is_in_room_)
            (不在房间中或者上面的情况，要删除该Player信息)
            (在游戏中的话更新它的is_online，但要保留Player信息)
    */
    if (SecurelyGetPlayerByFd(cur_player, fd)) {
        if (SecurelyGetRoomById(cur_room, cur_player->GetRoomId())) {
            cur_room->RemovePlayer(cur_player);
            if (cur_room->CheckNeedToDeleteRoom()) {
                DeleteRoom(cur_room->GetRoomId());
                cur_room = nullptr;
            } else {
                if (cur_room->CheckStatus(Room::RoomStatus::IN_HALL)) {
                    GetRoomInfo(cur_room->GetRoomId());
                } else if (cur_room->CheckStatus(Room::RoomStatus::IS_LOADING)) {
                    StartSync(cur_room->GetRoomId());
                }
            }
        }
        uid_to_player_.erase(uid_to_player_.find(cur_player->GetUid()));
        delete cur_player;
        fd_to_uid_.erase(fd_to_uid_.find(fd));
    }
    delete fd_to_buff_[fd];
    fd_to_buff_.erase(buff_it);
    int close_ret = close(fd);
    if (close_ret == -1) {
        printf("close socket: %d error, errno = %d\n", fd, errno);
        return ;
    }
    printf("socket:%d, closed\n", fd);
}

Server::Server(int _port) {
    player_count_ = 0;
    port_ = _port;
    cur_client_buff_ = nullptr;
    cur_ret_buff_ = new byte[BUFF_SIZE];
    fd_to_buff_.clear();
    cur_ret_msg_ = nullptr;
    available_room_id_ = 0;
    cur_fd_ = 0;
    cur_recv_len_ = 0;
    cur_recv_msg_len_ = 0;
    cur_recv_msg_type_ = 0;
    cur_ret_msg_len_ = 0;
    cur_ret_msg_type_ = 0;
}

Server::~Server() {
    delete[] cur_ret_buff_;
    unordered_map<int, ClientBuff*>::iterator it;
    for (it = fd_to_buff_.begin(); it != fd_to_buff_.end(); ++it) {
        close((*it).first);
        delete (*it).second;
    }
    map<int, Room *>::iterator i;
    for(i = id_to_room_.begin(); i != id_to_room_.end(); ++i) {
        delete i->second;
    }
    // fd_to_uid_.clear();
    // uid_to_fd_.clear();
    // fd_to_buff_.clear();
    
    close(listen_fd_);
}


void Server::Run() {
    int listen_fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, IPPROTO_TCP);
    if(listen_fd == -1) {
        // printf("new server socket error, errno = %d\n", errno);
        return ;
    }

    struct sockaddr_in listen_addr;
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    listen_addr.sin_port = htons(port_);

    int value = 1;
    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR,
                (void*)&value, sizeof(value));

    //bind
    int bind_ret = bind(listen_fd, (struct sockaddr*)&listen_addr,
                        sizeof(listen_addr));
    if (bind_ret == -1) {
        // printf("bind error, errno = %d\n", errno);
        return ;
    } else {
        // printf("bind [0.0.0.0:%d] ok!\n", port_);
    }

    //listen
    int listen_ret = listen(listen_fd, 128);
    if (listen_ret == -1) {
        // printf("listen error, errno = %d\n", errno);
        return ;
    } else {
        // printf("start listening on socket fd [%d] ...\n", listen_fd);
    }

    //使用epoll实现非阻塞处理客户端请求
    int epoll_fd = epoll_create(1);
    if (epoll_fd == -1) {
        // printf("create epoll error, errno = %d\n", errno);
        return ;
    }

    struct epoll_event event;
    event.data.fd = listen_fd;
    event.events = EPOLLIN;

    int ctl_ret = epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listen_fd, &event);
    if(ctl_ret == -1) {
        printf("add listen_fd epoll event error, errno = %d\n", errno);
        return ;
    }

    struct epoll_event* events = new epoll_event[MAXEVENTS];

    while (true) {
        int count = epoll_wait(epoll_fd, events, MAXEVENTS, 1);
        //printf("%d events to deal\n", count);
        for (int i = 0; i < count; ++i) {
            int fd = events[i].data.fd;
            int fd_events = events[i].events;
            //出错处理
            if ((fd_events & EPOLLERR) || (fd_events & EPOLLHUP) || (!(fd_events & EPOLLIN))) {
                printf("error fd: %d, fd_events != EPOLLIN, errno = %d\n", fd, errno);
                CloseClientFd(fd);
                continue;
            } else if (fd == listen_fd) {  //有新客户端的连接请求
                struct sockaddr client_addr;
                socklen_t client_addr_len = sizeof(client_addr);
                int client_fd = accept4(listen_fd, &client_addr, &client_addr_len, SOCK_NONBLOCK);
                if (client_fd == -1) {
                    printf("new client socket error, errno = %d\n", errno);
                    close(client_fd);
                    continue;
                } else {
                    printf("new socket:%d\n", client_fd);
                }
                event.data.fd = client_fd;
                event.events = EPOLLIN;
                int ctl_ret = epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_fd, &event);
                if (ctl_ret == -1) {
                    printf("add socket_fd: %d epoll event error\n", client_fd);
                    int close_ret = close(client_fd);
                    if (close_ret == -1) {
                        printf("close add event error socket: %d error, errno = %d\n", client_fd, errno);
                    }
                    continue;
                }
                if (fd_to_buff_.find(client_fd) == fd_to_buff_.end()) {
                    fd_to_buff_.insert(
                      pair<int, ClientBuff *>(client_fd, new ClientBuff(client_fd)));   
                }   // TODO: else delete buff, 然后new 新的
            } else {
                cur_fd_ = fd;
                if (fd_to_buff_.find(cur_fd_) == fd_to_buff_.end()) {
                    printf("socket: %d has no buff in run\n", cur_fd_);
                    int close_ret = close(cur_fd_);
                    if (close_ret == -1) {
                        printf("close no buff socket in run: %d error, errno = %d\n", cur_fd_, errno);
                    }
                    continue;
                }
                cur_client_buff_ = fd_to_buff_[cur_fd_];
                if (cur_client_buff_->buff_ == nullptr) {
                    printf("socket: %d has nullptr buff in run\n", cur_fd_);
                    int close_ret = close(cur_fd_);
                    if (close_ret == -1) {
                        printf("close nullptr buff socket in run: %d error, errno = %d\n", cur_fd_, errno);
                    }
                    continue;
                }
                Recv();
            }
        }
        BroadCastBattleFrame();
    }
    delete[] events;
}
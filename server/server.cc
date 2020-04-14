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
        printf("recv %d bytes from %d fd\n", cur_recv_len_, cur_fd_);
        HandleRecvPackage();
    } else if (cur_recv_len_ == 0) {
        //close
        CloseClientFd();
    } else if (cur_recv_len_ == -1) {
        //这几个错误参数还可以继续进行读写
        if (errno == EINTR || errno == EWOULDBLOCK || errno == EAGAIN) {
            return ;
        }
        CloseClientFd();
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
        printf("server send to fd: %d error, errno = %d\n",
            send_ret, errno);
        return ;
    } else {
        printf("server send to fd_%d| %d bytes\n", cur_fd_, send_ret);
        //message.PrintDebugString();
    }
}

//int转byte
void Server::IntToBytes(int n, char *bytes) {
    bytes[0] = (char) (0xff & n);
    bytes[1] = (char) ((0xff00 & n) >> 8);
    bytes[2] = (char) ((0xff0000 & n) >> 16);
    bytes[3] = (char) ((0xff000000 & n) >> 24);
    return ;
}

//byte转int
int Server::BytesToInt(char* bytes) {
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
    cur_client_buff_->tail_ += cur_recv_len_;
    int l = cur_client_buff_->head_, r = cur_client_buff_->tail_;
    if (r <= l) {
        r += BUFF_SIZE;
    }
    while (l < r) {
        int buff_len = r - cur_client_buff_->head_;
        //数据长度不足包头长说明包不完整
        if (buff_len < 8) {
            break ;
        }
        ParseHead();
        //数据长度不足一个包
        if (buff_len < cur_recv_msg_len_ + HEAD_SIZE) {
            break ;
        }
        HandleMsg();
        l += (cur_recv_msg_len_ + HEAD_SIZE);
        cur_client_buff_->head_ = cur_client_buff_->head_ +
                                  cur_recv_msg_len_ + HEAD_SIZE;
    }
    cur_client_buff_->MoveData();
    // cout << "*********" << endl;
    // cout << cur_client_buff_->head_ << ' ' << cur_client_buff_->tail_ << endl;
    // cout << "*********" << endl;
}

//服务器根据包头中的类型来进行相应操作
void Server::HandleMsg() {
    
    switch (cur_recv_msg_type_) {
        case LOGIN_REQ:
            TmpLogin();
            //Login(cur_recv_msg_type_);
            break;
        case REGISTER_REQ:
            //Login(cur_recv_msg_type_);
            break;
        case CREATE_ROOM_REQ:
            CreateRoom();
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
        case ROOM_CHANGE_ROLE_REQ:
            ChangeRole();
            break;
        case LEAVE_ROOM_REQ:
            LeaveRoom();
            break;
        case START_GAME_REQ:
            StartGame();
            break;
    }

}

bool Server::Pack(google::protobuf::Message &message, int msg_type) {
    if (!Serialize(message)) {
        return false;
    }
    cur_ret_msg_type_ = msg_type;
    cur_ret_msg_len_ = message.ByteSize();
    AddHead();
    return true;
}

bool Server::Deserialize(google::protobuf::Message &message) {
    //cout << "head_pos: " << fd_to_buff_[cur_fd_]->head_ << '\n' << "tail_pos: " << fd_to_buff_[cur_fd_]->tail_ << endl;
    
    int ret = message.ParseFromArray(
        cur_client_buff_->buff_ +
        cur_client_buff_->head_ + HEAD_SIZE,
        cur_recv_msg_len_);
    if (ret < 0) {
        printf("fd: %d Deserialization error!\n", cur_fd_);
        return false;
    }
    cout << "++++++++++" << endl;
    message.PrintDebugString();
    cout << "++++++++++" << endl;
    return true;
}

bool Server::Serialize(google::protobuf::Message &message) {
    cout << "----------" << endl;
    message.PrintDebugString();
    cout << "----------" << endl;
    int ret = message.SerializeToArray(cur_ret_buff_ + HEAD_SIZE, cur_ret_msg_len_);
    if (ret < 0) {
        printf("fd: %d Serialize error!\n", cur_fd_);
        return false;
    }
    return true;
}

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

    Send(login_s2c, cur_ret_msg_len_);
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

void Server::TmpLogin() {
    LoginS2C login_s2c = LoginS2C();
    LoginC2S login_c2s = LoginC2S();
    if (uid_to_player_.size() >= MAX_PLAYER_NUMBER) {
        login_s2c.set_loginret(LoginS2C_LoginRet_SERVER_FULL);
        Send(login_s2c, LOGIN_RET);
    }
    //反序列化
    if (!Deserialize(login_c2s)) {
        login_s2c.set_error(DESERIALIZE_ERROR);
        Send(login_s2c, LOGIN_RET);
        CloseClientFd();
        /*
            TODO: 客户端数据包出错，把它踢了
        */
        return ;
    }
    //把登录信息反馈给客户端
    
    //判断下有没有重复的用户名在线
    cur_uid_ = TmpLoginCheck(login_c2s);
    login_s2c.set_uid(cur_uid_);
    login_s2c.set_username(login_c2s.username());
    if (fd_to_uid_.find(cur_fd_) == fd_to_uid_.end()) {
        if (uid_to_player_.find(cur_uid_) == uid_to_player_.end()) {
            //正常登录
            uid_to_player_[cur_uid_] = new Player(cur_uid_);
        } else if (uid_to_player_[cur_uid_]->is_in_game) {
            /*
                TODO: 断线重连
                      (把所有帧发给它)
                      (发完后更新is_sync_frame_，再开始同步广播帧同步帧)
            */
        }
        uid_to_player_[cur_uid_]->SetClientFd(cur_fd_);
        fd_to_uid_[cur_fd_] = cur_uid_;
        login_s2c.set_loginret(LoginS2C_LoginRet_LOGIN_SUCCESS);
    } else {
        //同一个账号不能重复登录且一个客户端不能登录多个账号
        login_s2c.set_loginret(LoginS2C_LoginRet_ALREADY_ONLINE);
    }
    
    Send(login_s2c, LOGIN_RET);
}

void Server::CreateRoom() {
    CreateRoomS2C create_room_s2c = CreateRoomS2C();
    CreateRoomC2S create_room_c2s = CreateRoomC2S();
    if (id_to_room_.size() >= MAX_ROOM_NUMBER) {
        create_room_s2c.set_succeed(false);
        Send(create_room_s2c, CREATE_ROOM_RET);
    }
    if (!Deserialize(create_room_c2s)) {
        create_room_s2c.set_error(DESERIALIZE_ERROR);
        Send(create_room_s2c, CREATE_ROOM_RET);
        CloseClientFd();
        /*
            TODO: 客户端数据包出错，把它踢了
        */
        return ;
    }
    while(id_to_room_.find(++available_room_id_) != id_to_room_.end()) {

    }
    id_to_room_[available_room_id_] = new Room(available_room_id_);
    cur_uid_ = fd_to_uid_[cur_fd_];
    id_to_room_[available_room_id_]->SetOwnerUid(cur_uid_);
    Player *cur_player = uid_to_player_[cur_uid_];
    cur_player->is_ready = false;
    cur_player->SetRole(ENGINEER);
    id_to_room_[available_room_id_]->AddPlayer(cur_player);
    GetRoomInfo();
}

void Server::GetRoomList() {
    GetRoomListS2C get_room_list_s2c = GetRoomListS2C();
    map<int, Room *>::iterator it;
    for (it = id_to_room_.begin(); it != id_to_room_.end(); ++it) {
        if ((*it).second->is_start) {
            continue;
        }
        RoomInfo *room_info = get_room_list_s2c.add_roomsinfo();
        room_info->set_roomid((*it).first);
        room_info->set_currentsize((*it).second->GetRoomSize());
        room_info->set_maxsize((*it).second->GetRoomSize());
    }
    Send(get_room_list_s2c, GET_ROOM_LIST_RET);
}

void Server::GetRoomInfo() {
    GetRoomInfoS2C get_room_info_s2c = GetRoomInfoS2C();
    cur_uid_ = fd_to_uid_[cur_fd_];
    Player *cur_player = uid_to_player_[cur_uid_];
    if (!cur_player->is_in_room) {
        get_room_info_s2c.set_succeed(false);
        get_room_info_s2c.set_error(NOT_IN_ROOM_ERROR);
        Send(get_room_info_s2c, GET_ROOM_INFO_BROAD_CAST);
        CloseClientFd();
        /*
            TODO: 客户端不在房间但是发了房间有关包，把它踢了
                  可能是服务器出错了，也可能是客户端错了
        */
        return ;
    }
    Room *cur_room = id_to_room_[cur_player->GetRoomId()];
    PlayerInfo *player_info = nullptr;
    set<Player *, PlayerCmp>::iterator it;
    for (it = cur_room->player_set_.begin(); it != cur_room->player_set_.end(); ++it) {
        player_info = get_room_info_s2c.add_playersinfo();
        cur_player = (*it);
        player_info->set_playerid(cur_player->GetUid());
        player_info->set_username(cur_player->GetUserName());
        player_info->set_role(cur_player->GetRole());
        player_info->set_isready(cur_player->is_ready);
    }
    get_room_info_s2c.set_roomownerid(cur_room->GetOwnerUid());
    get_room_info_s2c.set_succeed(true);
    BroadCast(cur_room->player_set_, get_room_info_s2c, GET_ROOM_INFO_BROAD_CAST);
}

void Server::EnterRoom() {
    EnterRoomS2C enter_room_s2c = EnterRoomS2C();
    GetRoomInfoS2C get_room_info_s2c = GetRoomInfoS2C();
    EnterRoomC2S enter_room_c2s = EnterRoomC2S();
    if (!Deserialize(enter_room_c2s)) {
        get_room_info_s2c.set_error(DESERIALIZE_ERROR);
        Send(get_room_info_s2c, ENTER_ROOM_RET);
        CloseClientFd();
        /*
            TODO: 客户端数据包出错，把它踢了
        */
        return ;
    }
    Player *cur_player = uid_to_player_[fd_to_uid_[cur_fd_]];
    int cur_room_id = cur_player->GetRoomId();
    if (id_to_room_.find(cur_room_id) == id_to_room_.end() ||
       !id_to_room_[cur_room_id]->CheckRoomSize()) {
        get_room_info_s2c.set_succeed(false);
        Send(enter_room_s2c, ENTER_ROOM_RET);
        return ;
    }
    cur_player->is_ready = false;
    cur_player->SetRole(ENGINEER);
    Room *cur_room = id_to_room_[cur_room_id];
    cur_room->AddPlayer(cur_player);
    GetRoomInfo();
}

void Server::PlayerReady() {
    PlayerReadyS2C player_ready_s2c = PlayerReadyS2C();
    cur_uid_ = fd_to_uid_[cur_fd_];
    Player *cur_player = uid_to_player_[cur_uid_];
    if (!cur_player->is_in_room) {
        player_ready_s2c.set_error(NOT_IN_ROOM_ERROR);
        Send(player_ready_s2c, PLAYER_READY_RET);
        CloseClientFd();
        /*
            TODO: 客户端不在房间但是发了房间有关包，把它踢了
                  可能是服务器出错了，也可能是客户端错了
        */
        return ;
    }
    cur_player->is_ready = !cur_player->is_ready;
    GetRoomInfo();
}

void Server::ChangeRole() {
    ChangeRoleS2C change_role_s2c = ChangeRoleS2C();
    ChangeRoleC2S change_role_c2s = ChangeRoleC2S();
    if (!Deserialize(change_role_c2s)) {
        change_role_s2c.set_error(-1);
        Send(change_role_s2c, ROOM_CHANGE_ROLE_RET);
        CloseClientFd();
        /*
            TODO: 客户端数据包出错，把它踢了
        */
        return ;
    }
    int cur_uid_ = fd_to_uid_[cur_fd_];
    Player *cur_player = uid_to_player_[cur_uid_];
    cur_player->SetRole(change_role_c2s.role());
    GetRoomInfo();
}

void Server::LeaveRoom() {
    LeaveRoomS2C leave_room_s2c = LeaveRoomS2C();
    int cur_uid_ = fd_to_uid_[cur_fd_];
    Player *cur_player = uid_to_player_[cur_uid_];
    if (!cur_player->is_in_room) {
        leave_room_s2c.set_error(NOT_IN_ROOM_ERROR);
        Send(leave_room_s2c, LEAVE_ROOM_RET);
        CloseClientFd();
        /*
            TODO: 客户端不在房间但是发了房间有关包，把它踢了
                  可能是服务器出错了，也可能是客户端错了
        */
        return ;
    }
    Room *cur_room = id_to_room_[cur_player->GetRoomId()];
    cur_room->RemovePlayer(cur_player);
    if (cur_room->GetCurRoomSize() <= 0) {
        id_to_room_.erase(cur_room->GetRoomId());
        delete cur_room;
        cur_room = nullptr;
    } else {
        GetRoomInfo();
    }
}

void Server::StartGame() {
    StartGameS2C start_game_s2c = StartGameS2C();
    int cur_uid_ = fd_to_uid_[cur_fd_];
    Player *cur_player = uid_to_player_[cur_uid_];
    if (!cur_player->is_in_room) {
        start_game_s2c.set_error(NOT_IN_ROOM_ERROR);
        Send(start_game_s2c, START_GAME_BROAD_CAST);
        CloseClientFd();
        /*
            TODO: 客户端不在房间但是发了房间有关包，把它踢了
                  可能是服务器出错了，也可能是客户端错了
        */
        return ;
    }
    Room *cur_room = id_to_room_[cur_player->GetRoomId()];
    if(cur_room->GetOwnerUid() != cur_uid_) {
        start_game_s2c.set_error(NOT_OWNER_START_GAME);
        Send(start_game_s2c, START_GAME_BROAD_CAST);
        CloseClientFd();
        /*
            TODO: 不是房主但是发了开始游戏的包
        */
        return ;
    }
    if (cur_room->StartGame()) {
        start_game_s2c.set_succeed(true);
        BroadCast(cur_room->player_set_, start_game_s2c, START_GAME_BROAD_CAST);
    } else {
        start_game_s2c.set_succeed(false);
        Send(start_game_s2c, START_GAME_BROAD_CAST);
    }
}

void Server::UpdateTimeVal(struct timeval &tv) {
    int ret = gettimeofday(&tv, NULL);
    if (ret == -1) {
        printf("UpdateTimeVal Error: errno = %d, (%s)\n", errno, strerror(errno));
    }
}

bool Server::CheckTimeInterval(struct timeval &pre_tv) {
    UpdateTimeVal(cur_tv_);
    if ((cur_tv_.tv_sec * 1000000 + cur_tv_.tv_usec) -
        (pre_tv.tv_sec * 1000000 + pre_tv.tv_usec) >= PER_FRAME_TIME) {
        UpdateTimeVal(pre_tv);
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
    for (it = player_set.begin(); it != player_set.end(); ++it) {
        int send_ret = send((*it)->GetClientFd(), cur_ret_buff_, 
                            cur_ret_msg_len_ + HEAD_SIZE, 0);
        if (send_ret == -1) {
            printf("server send to fd: %d error, errno = %d\n",
                send_ret, errno);
        }
    }
}

void Server::CloseClientFd() {
    if (fd_to_uid_.find(cur_uid_) == fd_to_uid_.end()) {
        return ;
    }
    cur_uid_ = fd_to_uid_[cur_fd_];
    /*
        TODO: 554行段错误
    */
    if (uid_to_player_.find(cur_uid_) != uid_to_player_.end()) {
        Player *cur_player = uid_to_player_[cur_uid_];
        if (cur_player->is_in_game) {
            cur_player->is_sync_frame_ = false;
        } else {
            if (cur_player->is_in_room) {
                LeaveRoom();
            }
            delete cur_player;
            uid_to_player_.erase(cur_uid_);
        }
        /*
            TODO: 判断玩家状态来删除数据或更新信息
                (在房间中的话要广播给房间内所有客户端这人离开了房间，更新is_in_room)
                (不在房间中或者上面的情况，要删除该Player信息)
                (在游戏中的话更新它的is_sync_frame，但要保留Player信息)
        */
    }

    int close_ret = close(cur_fd_);
    if (close_ret == -1) {
        printf("close socket: %d error, errno = %d\n", cur_fd_, errno);
        return ;
    }
    printf("socket:%d, closed\n", cur_fd_);
    delete fd_to_buff_[cur_fd_];
    fd_to_buff_.erase(cur_fd_);
    fd_to_uid_.erase(cur_fd_);
    
}

Server::Server(int _port) {
    port_ = PORT;
    cur_client_buff_ = new ClientBuff();
    cur_ret_buff_ = new char[BUFF_SIZE];
    fd_to_buff_.clear();
    cur_ret_msg_ = nullptr;
    available_room_id_ = 0;
}

Server::~Server() {
    delete[] cur_ret_buff_;
    delete cur_ret_msg_;
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
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);    
    if(listen_fd == -1) {
        printf("new server socket error, errno = %d\n", errno);
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
        printf("bind error, errno = %d\n", errno);
        return ;
    } else {
        printf("bind [0.0.0.0:%d] ok!\n", port_);
    }

    //listen
    int listen_ret = listen(listen_fd, 128);
    if (listen_ret == -1) {
        printf("listen error, errno = %d\n", errno);
        return ;
    } else {
        printf("start listening on socket fd [%d] ...\n", listen_fd);
    }

    //使用epoll实现非阻塞处理客户端请求
    int epoll_fd = epoll_create(1);
    if (epoll_fd == -1) {
        printf("create epoll error, errno = %d\n", errno);
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
            if (fd_events != EPOLLIN) {
                printf("error fd: %d\n", fd);
                //CloseClientFd(fd);
                continue;
            } else if (fd == listen_fd) {  //有新客户端的连接请求
                struct sockaddr client_addr;
                socklen_t client_addr_len = sizeof(client_addr);
                int client_fd = accept(listen_fd, &client_addr, &client_addr_len);
                if (client_fd == -1) {
                    printf("new client socket error, errno = %d\n", errno);
                    continue;
                } else {
                    printf("new socket:%d\n", client_fd);
                }
                event.data.fd = client_fd;
                event.events = EPOLLIN;
                int ctl_ret = epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_fd, &event);
                if (ctl_ret == -1) {
                    printf("add socket_fd: %d epoll event error\n", client_fd);
                    continue;
                }
                if (fd_to_buff_.find(client_fd) == fd_to_buff_.end()) {
                    fd_to_buff_.insert(
                      pair<int, ClientBuff*>(client_fd, new ClientBuff(client_fd)));
                }
            } else {
                cur_fd_ = fd;
                cur_client_buff_ = fd_to_buff_[cur_fd_];
                Recv();
            }
        }
        while (!room_queue_.empty() && CheckTimeInterval(room_queue_.top()->pre_tv_)) {
            /*
                TODO: 广播帧
            */
        }

    }
    delete[] events;
}
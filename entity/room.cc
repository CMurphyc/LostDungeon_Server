#include "../entity/room.h"

Room::Room() {

}

Room::Room(int id) {
    cur_status_ = RoomStatus::IN_HALL;
    room_id_ = id;
    cur_room_size_ = 0;
    room_size_ = 1;
    frame_count_ = 0;
    floor_count_ = 0;
    order_count_ = 0;
    pre_tv_ = {0, 0};
}

Room::Room(int id, RoomType room_type) {
    cur_status_ = RoomStatus::IN_HALL;
    room_id_ = id;
    cur_room_size_ = 0;
    room_type_ = room_type;
    switch (room_type_)
    {
    case PVE:
        room_size_ = PVE_ROOM_SIZE;
        break;
    case PVP:
        room_size_ = PVP_ROOM_SIZE;
    default:
        room_size_ = 1;
        break;
    }
    frame_count_ = 0;
    floor_count_ = 0;
    order_count_ = 0;
    pre_tv_ = {0, 0};
}


Room::~Room() {
    // int len = battle_frames.size();
    // for (int i = 0; i < len; ++i) {
    //     delete battle_frames[i];
    // }
    /*
        TODO: 玩家状态更新写这里还是在游戏结束那里？
    */
}

bool Room::CheckRoomSize() {
    return cur_room_size_ < room_size_;
}

void Room::AddPlayer(Player *player) {
    if (player_set_.find(player) == player_set_.end()) {
        ++cur_room_size_;
        player->ChangeStatus(Player::PlayerStatus::IN_ROOM);
        player->SetRole(ENGINEER);
        player->SetRoomId(room_id_);
        player->in_room_id_ = (++order_count_);
        player_set_.insert(player);
        cout << "player : " << player->GetUserName() << " enter room : " << room_id_ << " success" << endl;
    }
}

void Room::LeaveRoom(Player *player) {
    if (player_set_.find(player) != player_set_.end()) {
        --cur_room_size_;
        player_set_.erase(player_set_.find(player));
        player->ResetPlayer();
        ResetOwner();
        cout << "player : " << player->GetUserName() << " leave room : " << room_id_ << " success" << endl;
    }
}

void Room::RemovePlayer(Player *player) {
    if (player_set_.find(player) != player_set_.end()) {
        --cur_room_size_;
        player_set_.erase(player_set_.find(player));
        ResetOwner();
    }
}

void Room::ResetOwner() {
    if (player_set_.size() == 0) {
        return ;
    }
    SetOwnerUid((*player_set_.begin())->GetUid());
}

void Room::SetOwnerUid(int owner_uid) {
    room_owner_uid_ = owner_uid;
}

int Room::GetOwnerUid() {
    return room_owner_uid_;
}

int Room::GetRoomId() const{
    return room_id_;
}

void Room::SetRoomSize(int room_size) {
    room_size_ = room_size;
}

int Room::GetRoomSize() {
    return room_size_;
}

int Room::GetCurRoomSize() {
    return cur_room_size_;
}

bool Room::StartGame() {
    if (!CheckStatus(RoomStatus::IN_HALL)) {
        return false;
    }
    set<Player *, PlayerCmp>::iterator it;
    for (it = player_set_.begin(); it != player_set_.end(); ++it) {
        if (!(*it)->CheckStatus(Player::PlayerStatus::ROOM_READY) &&
            ((*it)->GetUid() != GetOwnerUid())) {
            return false;
        }
    }
    for (it = player_set_.begin(); it != player_set_.end(); ++it) {
        (*it)->ChangeStatus(Player::PlayerStatus::IS_LOADING);
    }
    floor_count_ = 1;
    ChangeStatus(RoomStatus::IS_LOADING);
    return true;
}

bool Room::StartSync() {
    if (CheckStatus(RoomStatus::IN_HALL)) {
        return false;
    }
    set<Player *, PlayerCmp>::iterator it;
    for (it = player_set_.begin(); it != player_set_.end(); ++it) {
        if (!(*it)->CheckStatus(Player::PlayerStatus::SYNC_READY)) {
            return false;
        }
    }
    for (it = player_set_.begin(); it != player_set_.end(); ++it) {
        (*it)->ChangeStatus(Player::PlayerStatus::IS_SYNC);
    }
    ChangeStatus(RoomStatus::IS_SYNC);
    return true;
}

/*
    TODO: 状态管理优化可以参考这个NextFloor函数，再把能否转换封装一下就比较完美了
          这样就能有一个正规完善的状态转换流程
*/
bool Room::NextFloor(int floor_number) {
    if (!CheckStatus(RoomStatus::IS_SYNC)) {
        return false;
    }
    if (floor_count_ != floor_number - 1 || floor_number > MAX_FLOOR_NUMBER) {
        return false;
    }
    ++floor_count_;
    set<Player *, PlayerCmp>::iterator it;
    for (it = player_set_.begin(); it != player_set_.end(); ++it) {
        if (!(*it)->CheckStatus(Player::PlayerStatus::IS_SYNC)) {
            return false;
        }
    }
    for (it = player_set_.begin(); it != player_set_.end(); ++it) {
        (*it)->NextFloor();
    }
    ChangeStatus(RoomStatus::IS_LOADING);
    return true;
}

bool Room::GameOver() {
    if (!CheckStatus(RoomStatus::IS_SYNC)) {
        return false;
    }
    set<Player *, PlayerCmp>::iterator it;
    for (it = player_set_.begin(); it != player_set_.end(); ++it) {
        if (!(*it)->CheckStatus(Player::PlayerStatus::IS_SYNC)) {
            return false;
        }
    }
    ChangeStatus(RoomStatus::IS_OVER);
    return true;
}

void Room::Clear() {
    set<Player *, PlayerCmp>::iterator it;
    for (it = player_set_.begin(); it != player_set_.end();) {
        Player *player = (*it);
        player_set_.erase(it++);
        player->ResetPlayer();
    }
    cur_room_size_ = 0;
}

void Room::CollectPlayerInput(BattleFrame &battle_frame) {
    battle_frame.set_framenumber(++frame_count_);
    battle_frame.set_randomcode(GenerateRandomNumber(DEFAULT_RANDOM_DIGIT));
    set<Player *, PlayerCmp>::iterator it;
    BattleInput *battle_input = nullptr;
    for (it = player_set_.begin(); it != player_set_.end(); ++it) {
        battle_input = battle_frame.add_battleinputs();
        battle_input->CopyFrom((*it)->cur_battle_input_);
    }
    battle_frames.push_back(battle_frame);
}

bool Room::CheckNeedToDeleteRoom() {
    if (GetCurRoomSize() <= 0 || player_set_.size() == 0 ||
        CheckStatus(Room::IS_OVER)) {
        return true;
    }
    set<Player *, PlayerCmp>::iterator it;
    for (it = player_set_.begin(); it != player_set_.end(); ++it) {
        if (!(*it)->CheckStatus(Player::PlayerStatus::OFFLINE)) {
            return false;
        }
    }
    return true;
}

Room::RoomStatus Room::GetRoomStatus() {
    return cur_status_;
}

void Room::ChangeStatus(Room::RoomStatus status) {
    cur_status_ = status;
}

bool Room::CheckStatus(RoomStatus status) {
    if (cur_status_ == status) {
        return true;
    }
    return false;
}

bool Room::CheckChangeStatus(RoomStatus status) {

}

int Room::GetFloorNumber() {
    return floor_count_;
}

int Room::SetRoomType(RoomType room_type) {
    room_type_ = room_type;
}
        
RoomType Room::GetRoomType() {
    return room_type_;
}
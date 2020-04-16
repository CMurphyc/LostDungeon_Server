#include "../entity/room.h"

Room::Room() {

}

Room::Room(int id) {
    is_start_ = false;
    room_id_ = id;
    cur_room_size_ = 0;
    room_size_ = DEFAULE_ROOM_SIZE;
    frame_count_ = 0;
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
    if (player_set_.find(player) != player_set_.end()) {
        cout << "player has already in room" << endl;
    } else {
        cout << "player is not in the room" << endl;
    }
    if (player_set_.find(player) == player_set_.end()) {
        ++cur_room_size_;
        player->is_ready = false;
        player->SetRole(ENGINEER);
        player->SetRoomId(room_id_);
        player->in_room_id_ = cur_room_size_;
        player->is_in_room = true;
        player_set_.insert(player);
    }
}

void Room::RemovePlayer(Player *player) {
    if (player_set_.find(player) != player_set_.end()) {
        cout << "player has already in room" << endl;
    } else {
        cout << "player is not in the room" << endl;
    }
    if (player_set_.find(player) != player_set_.end()) {
        --cur_room_size_;
        player->is_in_room = false;
        player->is_ready = false;
        player->SetRoomId(0);
        player->SetRole(ENGINEER);
        player->in_room_id_ = 99999;
        player_set_.erase(player_set_.find(player));
        ReSortRoom();
    }
}

void Room::ReSortRoom() {
    if (player_set_.size() == 0) {
        return ;
    }
    set<Player *, PlayerCmp>::iterator it;
    int tot = 0;
    for (it = player_set_.begin(); it != player_set_.end(); ++it) {
        (*it)->in_room_id_ = (++tot);
    }
    SetOwnerUid((*player_set_.begin())->GetUid());
}

void Room::SetOwnerUid(int owner_uid) {
    room_owner_uid_ = owner_uid;
}

int Room::GetOwnerUid() {
    return room_owner_uid_;
}

int Room::GetRoomId() {
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
    if (is_start_) {
        return false;
    }
    set<Player *, PlayerCmp>::iterator it;
    for (it = player_set_.begin(); it != player_set_.end(); ++it) {
        if (!(*it)->is_ready && ((*it)->GetUid() != GetOwnerUid())) {

            return false;
        }
    }
    is_start_ = true;
    return true;
}

void Room::CollectPlayerInput(BattleFrame &battle_frame) {
    battle_frame.set_framenumber(++frame_count_);
    /*
        TODO: 设置随机数
    */
    set<Player *, PlayerCmp>::iterator it;
    BattleInput *battle_input = nullptr;
    for (it = player_set_.begin(); it != player_set_.end(); ++it) {
        battle_input = battle_frame.add_battleinputs();
        battle_input->CopyFrom((*it)->cur_battle_input_);
    }
    battle_frames.push_back(battle_frame);
}
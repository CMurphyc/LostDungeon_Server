#include "../entity/player.h"

Player::Player() {

}

Player::Player(int uid) {
    uid_ = uid;
    ResetPlayer();
}

Player::~Player() {

}

void Player::SetClientFd(int fd) {
    client_fd_ = fd;
}

int Player::GetClientFd() {
    return client_fd_;
}

void Player::SetRoomId(int id) {
    room_id_ = id;
}

int Player::GetRoomId() {
    return room_id_;
}

int Player::GetUid() {
    return uid_;
}

void Player::SetUserName(string user_name) {
    user_name_ = user_name;
}

string Player::GetUserName() {
    return user_name_;
}

void Player::SetRole(Role role) {
    role_ = role;
}

Role Player::GetRole() {
    return role_;
}

int Player::GetRunes() {
    return runes_;
}

void Player::SetRunes(int runes) {
    runes_ = runes;
}

void Player::ResetPlayer() {
    room_id_ = 0;
    in_room_id_ = 99999;
    cur_status_ = IN_HALL;
    role_ = ENGINEER;
    runes_ = 0;
}

PlayerStatus Player::GetPlayerStatus() {
    return cur_status_;
}

bool Player::CheckStatus(PlayerStatus status) {
    if (cur_status_ == status) {
        return true;
    }
    return false;
}

bool Player::CheckInRoom() {
    if (cur_status_ == IN_ROOM || cur_status_ == ROOM_READY) {
        return true;
    }
    return false;
}

void Player::ChangeStatus(PlayerStatus status) {
    cur_status_ = status;
}

/*
    TODO: 检查玩家状态能否互相切换的函数，更加安全的状态转换
*/
bool Player::CheckChangeStatus(PlayerStatus status) {

}

void Player::PlayerReady() {
    if (cur_status_ == IN_ROOM) {
        cur_status_ = ROOM_READY;
    } else if (cur_status_ == ROOM_READY) {
        cur_status_ = IN_ROOM;
    }
}
#include "../entity/player.h"

Player::Player() {

}

Player::Player(int uid) {
    uid_ = uid;
    in_room_id_ = 99999;
    is_online_ = true;
    is_in_room_ = false;
    is_ready_ = false;
    is_in_game_ = false;
    role_ = ENGINEER;
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
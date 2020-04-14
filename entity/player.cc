#include "../entity/player.h"

Player::Player() {

}

Player::Player(int uid) {
    uid_ = uid;
    is_sync_frame_ = false;
    is_in_room = false;
    is_ready = false;
    is_in_game = false;
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

string Player::GetUserName() {
    return userName_;
}

void Player::SetRole(Role role) {
    role_ = role;
}

Role Player::GetRole() {
    return role_;
}
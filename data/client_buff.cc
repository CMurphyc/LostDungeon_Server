#include <new>
#include <cstdio>
#include <cstring>
#include "../other/tools.h"
#include "./client_buff.h"

//客户端缓冲区的类

ClientBuff::ClientBuff() {
    head_ = tail_ = 0;
    UpdateTimeVal(heartbeat_tv_);
    try {
        buff_ = new byte[BUFF_SIZE];
    } catch (const std::exception &e) {
        printf("alloc in %s, %s", __FUNCTION__, e.what());
    }
}

ClientBuff::ClientBuff(int _fd) {
    fd_ = _fd;
    head_ = tail_ = 0;
    UpdateTimeVal(heartbeat_tv_);
    try {
        buff_ = new byte[BUFF_SIZE];
    } catch (const std::exception &e) {
        printf("alloc in %s, %s", __FUNCTION__, e.what());
    }
}

ClientBuff::~ClientBuff() {
    delete[] buff_;
}

void ClientBuff::MoveData() {
    if (tail_ == BUFF_SIZE) {
        memmove(buff_, buff_ + head_, tail_ - head_);
        tail_ = tail_ - head_;
        head_ = 0;
    }
}
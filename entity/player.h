#ifndef ENTITY_PLAYER_H_
#define ENTITY_PLAYER_H_

#include <string>
#include "../protobuf/PlayerInfo.pb.h"
#include "../protobuf/BattleInput.pb.h"
using namespace std;

class Player {
    private:
        int uid_;
        //该玩家客户端socket的fd
        int client_fd_;
        //所在房间id
        int room_id_;
        string user_name_;
        string password_;
        //职业
        Role role_;

    public:
        //是否同步广播帧同步帧
        bool is_online;
        //是否在房间内
        bool is_in_room;
        //在房间中是否准备了
        bool is_ready;
        //是否在游戏中
        bool is_in_game;
        //在房间内的id
        int in_room_id_;
        //玩家当前帧操作
        BattleInput cur_battle_input_;
        
        Player();
        Player(int uid);
        ~Player();
        void SetClientFd(int fd);
        int GetClientFd();
        void SetRoomId(int id);
        int GetRoomId();
        int GetUid();
        void SetUserName(string user_name);
        string GetUserName();
        void SetRole(Role role);
        Role GetRole();

};

//玩家排序，按照其在房间中的编号
struct PlayerCmp {
    bool operator () (const Player *left, const Player *right) const {
        return left->in_room_id_ < right->in_room_id_;
    }
};

#endif
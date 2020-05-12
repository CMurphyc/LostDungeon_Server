#ifndef ENTITY_PLAYER_H_
#define ENTITY_PLAYER_H_

#include <string>
#include "../protobuf/PlayerInfo.pb.h"
#include "../protobuf/BattleInput.pb.h"
using namespace std;


class Player {
    public:
        enum PlayerStatus {
            //掉线状态
            OFFLINE,
            //在大厅内
            IN_HALL,
            //在房间内
            IN_ROOM,
            //在房间内准备了游戏
            ROOM_READY,
            //在加载场景
            IS_LOADING,
            //加载场景完成
            SYNC_READY,
            //在帧同步游戏
            IS_SYNC
        };

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
        int GetRunes();
        void SetRunes(int runes);
        void ResetPlayer();
        PlayerStatus GetPlayerStatus();
        bool CheckStatus(PlayerStatus status);
        bool CheckInRoom();
        void ChangeStatus(PlayerStatus status);
        bool CheckChangeStatus(PlayerStatus status);
        void PlayerReady();
        void NextFloor();
        void ChangeFaction(int faction);
        void GetFaction();

    private:
        int uid_;
        //该玩家客户端socket的fd
        int client_fd_;
        //玩家状态
        PlayerStatus cur_status_;
        //所在房间id
        int room_id_;
        string user_name_;
        string password_;
        //职业
        Role role_;
        //符文
        int runes_;
        //阵营
        int faction_;


};

//玩家排序，按照其在房间中的编号
struct PlayerCmp {
    bool operator () (const Player *left, const Player *right) const {
        return left->in_room_id_ < right->in_room_id_;
    }
};

#endif
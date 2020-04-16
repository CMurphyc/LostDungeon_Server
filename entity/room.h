#ifndef ENTITY_ROOM_H_
#define ENTITY_ROOM_H_

#include <set>
#include <vector>
#include <sys/time.h>
#include "../entity/player.h"
#include "../data/client_buff.h"
#include "../config/global_define.h"
#include "../protobuf/LoginC2S.pb.h"
#include "../protobuf/LoginS2C.pb.h"
#include "../protobuf/RegisterC2S.pb.h"
#include "../protobuf/RegisterS2C.pb.h"
#include "../protobuf/BattleFrame.pb.h"
#include "../protobuf/BattleFrame.pb.h"
#include "../protobuf/BattleInput.pb.h"
#include "../protobuf/BattleInput.pb.h"
using namespace std;

class Room {
    private:
        //房间相关信息
        int room_id_;
        int room_owner_uid_;
        int cur_room_size_;
        int room_size_;
        //帧同步有关数据
        vector<BattleFrame> battle_frames;
        int frame_count_;
    public:
        //该房间游戏是否开始
        bool is_start_;
        //上次广播的时间
        struct timeval pre_tv_;
        //需要广播的所有玩家
        set<Player*, PlayerCmp>player_set_;

        Room();
        Room(int id);
        ~Room();
        bool CheckRoomSize();
        void AddPlayer(Player *player);
        void RemovePlayer(Player *player);
        void ReSortRoom();
        void SetOwnerUid(int owner_uid);
        int GetOwnerUid();
        int GetRoomId();
        void SetRoomSize(int room_size);
        int GetRoomSize();
        int GetCurRoomSize();
        bool StartGame();
        void CollectPlayerInput(BattleFrame &battle_frame);
};

//房间在小根堆中的比较，把已经开始游戏的以及上次广播时间小的房间排前面
struct RoomCmp {
    bool operator () (const Room *left, const Room *right) const {
        return (left->pre_tv_.tv_sec * 1000000 + left->pre_tv_.tv_usec) <
               (right->pre_tv_.tv_sec * 1000000 + right->pre_tv_.tv_usec);
    }
};

#endif
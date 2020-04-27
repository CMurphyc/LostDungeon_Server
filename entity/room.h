#ifndef ENTITY_ROOM_H_
#define ENTITY_ROOM_H_

#include <set>
#include <vector>
#include <sys/time.h>
#include "../other/tools.h"
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
#include "../protobuf/StartGameC2S.pb.h"
#include "../protobuf/StartGameS2C.pb.h"
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
        int floor_count_;
    public:
        //该房间游戏是否开始
        bool is_start_;
        //上次广播的时间
        struct timeval pre_tv_;
        //需要广播的所有玩家
        set<Player*, PlayerCmp>player_set_;
        StartGameS2C start_game_s2c;

        Room();
        Room(int id);
        ~Room();
        bool CheckRoomSize();
        void AddPlayer(Player *player);
        void LeaveRoom(Player *player);
        void RemovePlayer(Player *player);
        void ReSortRoom();
        void SetOwnerUid(int owner_uid);
        int GetOwnerUid();
        int GetRoomId() const;
        void SetRoomSize(int room_size);
        int GetRoomSize();
        int GetCurRoomSize();
        bool StartGame();
        bool StartSync();
        void CollectPlayerInput(BattleFrame &battle_frame);
        bool CheckNeedToDeleteRoom();
};

#endif
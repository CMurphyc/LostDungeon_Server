#ifndef SERVER_SERVER_H_
#define SERVER_SERVER_H_

#include <set>
#include <queue>
#include <unordered_map>
#include "../entity/room.h"
#include "../entity/player.h"
#include "../data/client_buff.h"
#include "../config/global_define.h"
#include "../protobuf/LoginC2S.pb.h"
#include "../protobuf/LoginS2C.pb.h"
#include "../protobuf/PlayerInfo.pb.h"
#include "../protobuf/GameOverC2S.pb.h"
#include "../protobuf/GameOverS2C.pb.h"
#include "../protobuf/RegisterC2S.pb.h"
#include "../protobuf/RegisterS2C.pb.h"
#include "../protobuf/BattleFrame.pb.h"
#include "../protobuf/BattleFrame.pb.h"
#include "../protobuf/BattleInput.pb.h"
#include "../protobuf/BattleInput.pb.h"
#include "../protobuf/HeartbeatC2S.pb.h"
#include "../protobuf/HeartbeatS2C.pb.h"
#include "../protobuf/StartSyncC2S.pb.h"
#include "../protobuf/StartSyncS2C.pb.h"
#include "../protobuf/EnterRoomC2S.pb.h"
#include "../protobuf/EnterRoomS2C.pb.h"
#include "../protobuf/LeaveRoomC2S.pb.h"
#include "../protobuf/LeaveRoomS2C.pb.h"
#include "../protobuf/StartGameC2S.pb.h"
#include "../protobuf/StartGameS2C.pb.h"
#include "../protobuf/NextFloorC2S.pb.h"
#include "../protobuf/NextFloorS2C.pb.h"
#include "../protobuf/ChangeRoleC2S.pb.h"
#include "../protobuf/ChangeRoleS2C.pb.h"
#include "../protobuf/CreateRoomC2S.pb.h"
#include "../protobuf/CreateRoomS2C.pb.h"
#include "../protobuf/PlayerReadyC2S.pb.h"
#include "../protobuf/PlayerReadyS2C.pb.h"
#include "../protobuf/GetRoomListC2S.pb.h"
#include "../protobuf/GetRoomListS2C.pb.h"
#include "../protobuf/GetRoomInfoC2S.pb.h"
#include "../protobuf/GetRoomInfoS2C.pb.h"
#include "../protobuf/ChangeRunesC2S.pb.h"
#include "../protobuf/ChangeRunesS2C.pb.h"
#include "../protobuf/ChangeFactionC2S.pb.h"
#include "../protobuf/ChangeFactionS2C.pb.h"
using namespace std;

class Server {
    private:
        //服务器相关数据
        int port_;
        int listen_fd_;

        //客户端相关数据
        int player_count_;
        unordered_map<int, int>fd_to_uid_;
        unordered_map<int, Player *> uid_to_player_;
        ClientBuff *cur_client_buff_;
        byte *cur_ret_buff_;
        int cur_fd_;
        int cur_recv_len_;
        int cur_recv_msg_len_, cur_recv_msg_type_;
        int cur_ret_msg_len_, cur_ret_msg_type_;
        //用户缓冲区
        unordered_map<int, ClientBuff*>fd_to_buff_;
        //房间相关数据
        int available_room_id_;
        struct timeval cur_tv_;
        map<int, Room *>id_to_room_;
        
        void Recv();
        void Send(google::protobuf::Message &message, int msg_type);
        void IntToBytes(int n, byte *bytes);
        int BytesToInt(byte *bytes);
        bool Serialize(google::protobuf::Message &message);
        bool Deserialize(google::protobuf::Message &message);
        void AddHead();
        void ParseHead();
        void HandleRecvPackage();
        void HandleMsg();
        bool Pack(google::protobuf::Message &message, int msg_type);
        // LoginS2C_LoginRet LoginCheck(const LoginC2S &login_c2s);
        // RegisterS2C_RegisterRet RegisterCheck(const LoginC2S &user);
        // void Login(int type);
        // int TmpLoginCheck(const LoginC2S &login_c2s);
        void TmpLogin();
        void CreateRoom();
        void DeleteRoom(int room_id);
        void GetRoomList();
        void GetRoomInfo(int room_id);
        void EnterRoom();
        void PlayerReady();
        void ChangeRole();
        void ChangeRunes();
        void ChangeFaction();
        void LeaveRoom();
        void StartSync();
        void StartSync(int room_id);
        void HandleBattleInput();
        void HandleRoomEvent();
        void NextFloor();
        void GameOver();
        void CloseClientFd(int fd);
        bool CheckTimeInterval(struct timeval &pre_tv, int time_interval);
        bool CheckRoomLegality(int &cur_uid, Player *cur_player, Room *cur_room);
        void BroadCast(set<Player *, PlayerCmp> &player_set,
                       google::protobuf::Message &message,
                       int msg_type);
        bool SecurelyGetPlayerByFd(Player *&player, int fd);
        bool SecurelyGetPlayerByUid(Player *&player, int uid);
        bool SecurelyGetRoomById(Room *&room, int room_id);
        void Heartbeat();
        void KickClient();
        void KickLoadTimeOut();

    public:
        Server(int _port);
        ~Server();
        void Run();

};

#endif
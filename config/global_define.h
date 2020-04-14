#ifndef CONFIG_GLOBAL_DEFINE_H_
#define CONFIG_GLOBAL_DEFINE_H_

/*
    S2CType = C2SType + 100
    messageType: 
    1表示客户端的登录请求
    2表示客户端的注册请求
    3表示客户端发给服务器的操作
    ...
    101表示服务器处理客户端登录请求的返回消息
    102表示服务器处理客户端注册请求的返回消息
    103表示服务器打包广播给所有客户端的操作集合
    
    104表示服务器通知游戏开始的信号
*/

#define BUFF_SIZE 2048
#define MAXEVENTS 64
#define MAX_ROOM_NUMBER 100
#define MAX_PLAYER_NUMBER 1000
#define DEFAULE_ROOM_SIZE 4

#define HEAD_SIZE 8
#define LEN_SIZE 4
#define TYPE_SIZE 4

#define LOGIN_REQ 1
#define REGISTER_REQ 2

#define CREATE_ROOM_REQ 10
#define GET_ROOM_LIST_REQ 11
#define ENTER_ROOM_REQ 12
#define PLAYER_READY_REQ 14
#define ROOM_CHANGE_ROLE_REQ 15
#define LEAVE_ROOM_REQ 16
#define START_GAME_REQ 17

#define LOGIN_RET 101
#define REGISTER_RET 102

 #define CREATE_ROOM_RET 110
#define GET_ROOM_LIST_RET 111
#define ENTER_ROOM_RET 112
#define GET_ROOM_INFO_BROAD_CAST 113
#define PLAYER_READY_RET 114
#define ROOM_CHANGE_ROLE_RET 115
#define LEAVE_ROOM_RET 116
#define START_GAME_BROAD_CAST 117


#define PER_FRAME_TIME 50000
#define PORT 10000

//错误信息
#define DESERIALIZE_ERROR -1
#define NOT_IN_ROOM_ERROR -2
#define NOT_OWNER_START_GAME -3

#endif
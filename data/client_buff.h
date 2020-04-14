#ifndef DATA_CLIENT_BUFF_H_
#define DATA_CLIENT_BUFF_H_

class ClientBuff {
  public:
    char *buff_;
    //缓冲区头
    int head_;
    //缓冲区尾(最后一个数据+1的位置)
    int tail_;
    int fd_;
    ClientBuff();
    ClientBuff(int _fd);
    ~ClientBuff();
    void MoveData();
};

#endif
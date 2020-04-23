#include <ctime>
#include <sys/time.h>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <bits/stdc++.h>
using namespace std;

#define MAXLINE 80
#define SERV_PORT 10001
#define BIG_DIVIDER "==========================================="
#define SMALL_DIVIDER "-------------------------------------------"

int BytesToInt(char* bytes) {
    int n = bytes[0] & 0xFF;
    n |= ((bytes[1] << 8) & 0xFF00);
    n |= ((bytes[2] << 16) & 0xFF0000);
    n |= ((bytes[3] << 24) & 0xFF000000);
    return n;
}

void IntToBytes(int n, char *bytes) {
    bytes[0] = (char) (0xff & n);
    bytes[1] = (char) ((0xff00 & n) >> 8);
    bytes[2] = (char) ((0xff0000 & n) >> 16);
    bytes[3] = (char) ((0xff000000 & n) >> 24);
    return ;
}

void Log(const char *function_info, int line_info, int fd, int uid, int room_id, const char *log_info) {
    printf("%s\n", BIG_DIVIDER);
    time_t t = time(0);
    char *now_t = ctime(&t);
    struct timeval tv;
    gettimeofday(&tv, NULL);
    printf("%s", now_t);
    printf(", us = %ld\n", tv.tv_sec*1000000+tv.tv_usec);
    printf("%s\n", SMALL_DIVIDER);
    printf("function: %s, line: %d\n", function_info, line_info);
    printf("%s\n", SMALL_DIVIDER);
    printf("log: %s\n", log_info);
    printf("%s\n", BIG_DIVIDER);
}

unsigned int GenerateRandomNumber(int digit) {
    if (digit <= 0 || digit > 9) {
        return 0;
    }
    static default_random_engine random_engine(time(NULL));
    static uniform_int_distribution<unsigned int> head_random_number(1, 9);
    static uniform_int_distribution<unsigned int> body_random_number(0, 9);
    unsigned int ret = 0, base = 1;
    for (int i = 0; i < digit - 1; ++i) {
        ret += (body_random_number(random_engine) * base);
        base *= 10;
    }
    ret += (head_random_number(random_engine) * base);
    return ret;
}

int main(int argc, char *argv[])
{
    int tot = 100;
    while(tot--) {
        cout << GenerateRandomNumber(8) << endl;
    }
    // Log("this is a log", __FUNCTION__, __LINE__);
    // Log("this is a log", __FUNCTION__, __LINE__);
    // struct sockaddr_in servaddr;
    // char buf[MAXLINE];
    // int sockfd, n;
    // char str[3000];

    // IntToBytes(50101, str + 4);
    // // memset(str, 0, sizeof(str));
    // // str[8] = 'x';
    // // str[9] = '1';
    // // str[10] = '0';

    // sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // bzero(&servaddr, sizeof(servaddr));
    // servaddr.sin_family = AF_INET;
    // inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
    // servaddr.sin_port = htons(SERV_PORT);

    // connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    // write(sockfd, str, 11);

    // n = read(sockfd, buf, MAXLINE);
    // printf("Response from server:\n");
    // write(STDOUT_FILENO, buf, n);
    // printf("\n");
    // close(sockfd);
    return 0;
}
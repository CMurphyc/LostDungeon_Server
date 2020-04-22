#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define MAXLINE 80
#define SERV_PORT 10001
#define BIG_DIVIDER "==============================="
#define SMALL_DIVIDER "-------------------------------"

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

void Log(const char *log_info, const char *function_info, int line_info) {
    printf("%s\n", BIG_DIVIDER);
    time_t t = time(0);
    char *now_t = ctime(&t);
    printf("%s", now_t);
    printf("%s\n", SMALL_DIVIDER);
    printf("function: %s, line: %d\n", function_info, line_info);
    printf("%s\n", SMALL_DIVIDER);
    printf("log: %s\n", log_info);
    printf("%s\n", BIG_DIVIDER);
}

int main(int argc, char *argv[])
{
    Log("this is a log", __FUNCTION__, __LINE__);
    Log("this is a log", __FUNCTION__, __LINE__);
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
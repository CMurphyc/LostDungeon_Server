#include "server.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("input port error");
        return 0;
    }
    int port = atoi(argv[1]);
    set_new_handler(NewHandler);
    Server server = Server(port);
    server.Run();
    return 0;
}
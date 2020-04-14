#include "server.h"

int main()
{
    Server server = Server(10000);
    server.Run();
    return 0;
}
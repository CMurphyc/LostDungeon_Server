#include <ctime>
#include <signal.h>
#include <unistd.h>

#include "../other/tools.h"
#include "../config/global_define.h"

char log_type_str[][100] = {"normal", "error", "statistics"};
char player_status_str[][100] = {"offline", "in hall", "in room", "room ready", "is loadying", "sync ready", "is sync"};

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

void Log(const char *log_info, const char *function_info, int line_info) {
    printf("%s", BIG_DIVIDER);
    time_t t = time(0);
    char *now_t = ctime(&t);
    printf("%s", now_t);
    printf("%s", SMALL_DIVIDER);
    printf("function: %s, line: %d", function_info, line_info);
    printf("%s", SMALL_DIVIDER);
    printf("log: %s", log_info);
    printf("%s", BIG_DIVIDER);
}

void InitDaemon(int8_t nochdir, int8_t noclose) {
	daemon(nochdir, noclose);

	//ignore signals 信号

	signal(SIGINT,  SIG_IGN);

	signal(SIGHUP,  SIG_IGN);

	signal(SIGQUIT, SIG_IGN);

	signal(SIGPIPE, SIG_IGN);

	signal(SIGTTOU, SIG_IGN);

	signal(SIGTTIN, SIG_IGN);

	signal(SIGTERM, SIG_IGN);

}
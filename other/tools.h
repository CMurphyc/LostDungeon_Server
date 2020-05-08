#ifndef OTHER_TOOLS_H_
#define OTHER_TOOLS_H_


#include <time.h>
#include <random>
using namespace std;

static char log_type_str[][100] = {"normal", "error", "statistics"};
static char player_status_str[][100] = {"offline", "in hall", "in room", "room ready", "is loadying", "sync ready", "is sync"};
static char room_type_str[][100] = {"PVE", "PVP"};

unsigned int GenerateRandomNumber(int digit);

void Log(const char *log_info, const char *function_info, int line_info);

void InitDaemon(int8_t nochdir, int8_t noclose);

#endif
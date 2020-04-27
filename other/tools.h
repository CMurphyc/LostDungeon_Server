#include <time.h>
#include <random>
using namespace std;

unsigned int GenerateRandomNumber(int digit);

void Log(const char *log_info, const char *function_info, int line_info);

void InitDaemon(int8_t nochdir, int8_t noclose);
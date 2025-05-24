#ifndef TIMER_H
#define TIMER_H

#include <time.h>

void timerInit(int ms);
int timerTimeOver();
void timerDestroy();
long long current_timestamp();  

#endif

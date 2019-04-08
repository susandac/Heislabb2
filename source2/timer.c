#include <time.h>
#include "timer.h"


clock_t start_time;


void timer_start_timer(){
	start_time = clock();
}
int timer_timeout(){
	if ((clock()-start_time)/CLOCKS_PER_SEC < 3){
		return 0;
	}
	return 1;
}

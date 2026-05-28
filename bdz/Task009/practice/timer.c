#include <stdio.h>
#include <time.h>
#include "timer.h"

void now() {
	time_t rn;
	time(&rn);
	printf("Current time: %s", ctime(&rn));
}

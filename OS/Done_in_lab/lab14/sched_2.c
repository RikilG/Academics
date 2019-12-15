#include<sched.h>
#include<linux/sched.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Progamatically change scheduer
// check code to get 36 as output
// make your scheduler: https://bit.ly/2OuTvo6

int main(int argc, char *argv[]) {
	int pmin, pmax, priority=100;
	struct sched_param sp;

	// get min priority the algorithm can take
	pmin = sched_get_priority_min(SCHED_FIFO);
	// get max priority the algorithm can take
	pmax = sched_get_priority_max(SCHED_FIFO);

	printf("min avail pr: %d\n", pmin);
	printf("max avail pr: %d\n", pmax);
	printf("going to set: %d\n", priority);

	printf("Priority before: %d\n", sp.sched_priority);
	if(priority >= pmin && priority <= pmax) {
		sp.sched_priority = priority;
	}
	else {
		sp.sched_priority = pmin;
	}

	sched_setparam(0, &sp);
	printf("Priority after: %d\n", sp.sched_priority);
	return 0;
}

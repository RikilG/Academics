#include<sched.h>
#include<linux/sched.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Progamatically change scheduer
// Changing the rr time quantum can only be done by changing
// 	nice value
// /proc/sys/kernel/sched_rr_timeslice_ms will have the time
// 	quantum. setting it to 0 will reset it

int main(int argc, char *argv[]) {
	struct timespec ts;
	int ret;

	ret = sched_rr_get_interval(0, &ts);

	printf("Timeslice: %lu.%lu\n", ts.tv_sec, ts.tv_nsec);
	return 0;
}

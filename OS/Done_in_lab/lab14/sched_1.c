#include<sched.h>
#include<linux/sched.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Progamatically change scheduer

int main(int argc, char *argv[]) {
	int ret, i;
	struct sched_param sp;
	sp.sched_priority = 50;
	
	scanf("%d", &i);
	// changing "policy" to some value
	// args - pid, policy, 
	// if (sched_setscheduler(atoi(argv[3]), policy, &sp) == -1)
	// 	exit(-1);
	ret = sched_setscheduler(0, SCHED_FIFO, &sp);
	
	if(ret==-1) {
		perror("sched_setscheduler");
		exit(1);
	}
	for(;;);
	exit(0);
}

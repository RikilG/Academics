#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define N 5
int sum = 0;
int inc = 5;

/*
For man pages, packages must be installed: they are:
manpages-posix and manpages-posix-dev
for pthread_mutex*

also find diff b/w pthread and lpthread args for gcc
*/
// comment out line 21 and 26 to see execution without mutex lock (pthread_mutex_lock())

pthread_mutex_t lock; //define a mutex

void *fun(void *val) { //function for threads to execute
	pthread_mutex_lock(&lock);
	// CRITICAL SECTION
	sum += inc;
	printf("Value: %d \t Thread: %d\n", sum, *(int*)val);
	inc += 5;
	pthread_mutex_unlock(&lock);
	// END OF CRITICAL SECTION
	pthread_exit(NULL);
}

int main(int argc, char *argv) {
	pthread_t t[N];
	int errcode, i;
	pthread_mutex_init(&lock, NULL); // initialize mutex
	for(i=0;i<N;i++) {
		if(pthread_create(&t[i], NULL, fun, (void*)&i)) { // positive value if error (0 if success)
			perror("pthread_create");
			return EXIT_FAILURE;
		}
		//printf("Created thread: %d\n", i);
	}
	for (i=0;i<N;i++) { // Join all threads
		pthread_join(t[i], NULL);
	}
	return 0;
}

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

#define NUM_THREADS 5

void *PrintHello(void *threadid) {
	long tid;
	tid = (long)threadid;
	printf("Hello world! This is thread #%ld\n", tid);
	printf("My Threadid is %ld\n", pthread_self());
	pthread_exit(NULL);
}

int main(int argc, char **argv[]) {
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;
	for (t = 0;t<NUM_THREADS;t++) {
		printf("In the main function creating thread #%ld\n", t);
		rc = pthread_create(&threads[t], NULL, PrintHello, (void*)t);
		if (rc) {
			printf("Error in pthread_create %d\n", rc);
			exit(1);
		}
		//pthread_join(threads[t], NULL); create and join here itself
	}
	for (t = 0;t<NUM_THREADS;t++) 
		pthread_join(threads[t], NULL); // first create then join

	pthread_exit(NULL);
	return 0;
}

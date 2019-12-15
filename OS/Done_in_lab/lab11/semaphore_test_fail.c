#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<semaphore.h>
#define NUM 3

sem_t sem;
int counter;
//install manpages-posix and manpages-posix-dev to get manpages for mutex
// sudo apt install manpages-posix manpages-posix-dev

void handler(void *ptr) {
	int x;
	x = *((int*) ptr);
	printf("Thread %d: Waiting to enter critical regeion...\n", x);
	sem_wait(&sem); // lock or decrement semaphore
	// CRITICAL SECTION
	printf("Thread %d: now in critical region...\n", x);
	printf("Thread %d: counter Value: %d\n", x, counter);
	printf("Thread %d: Incrementing Counter...\n", x);
	counter++;
	printf("Thread %d: New Counter Value: %d\n", x, counter);
	printf("Thread %d: Exiting Critical section...\n", x);
	//END OF CRITICAL SECTION
	sem_post(&sem); // unlock or increment semaphore
	pthread_exit(0);
}

int main(void) {
	pthread_t threads[NUM];
	sem_init(&sem, 0, 1);
	// int sem_init(sem_t *sem, int pshared, unsigned int value);
	// pointer to sem, pshared:0 if shared b/w threads only if non-zero,
	// it is shared across process - put in shared mem
	// value: initial semaphore value
	for(int i=0;i<NUM;i++) {
		printf("create thread %d\n", i);
		pthread_create(&threads[i], NULL, (void*)&handler, (void*)&i);
	}
	for(int i=0;i<NUM;i++) {
		pthread_join(threads[i], NULL);
	}
	sem_destroy(&sem);
	// sem_destroy destroys unnamed semaphores( must be init by sem_init())
	// return -1 on error else 0
	// results in undefined behaviour if destroyed when threads are blocking
	// can be re initialized
	return 0;
}

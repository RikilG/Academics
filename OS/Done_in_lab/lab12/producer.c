#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<unistd.h>

#define BUFF_SIZE 5
#define NP 3
#define NC 3
#define NITERS 4

// pastebin url: https://pastebin.com/qHntkMld

typedef struct {
	int buf[BUFF_SIZE];
	int in;
	int out;
	sem_t full;
	sem_t empty;
	pthread_mutex_t mutex;
} sbuf_t;

sbuf_t shared;

void *Producer(void *arg) {
	int i, item;
	long index;
	index = (long)arg;

	for(i=0;i<NITERS;i++) {
		//Produce an item
		item = i;
		//Wait for an empty slot
		sem_wait(&shared.empty);
		// If buffer is being used, then wait
		pthread_mutex_lock(&shared.mutex);
		shared.buf[shared.in] = item;
		shared.in = (shared.in+1)%BUFF_SIZE;
		printf("[P%ld] producing %d\n", index, item);
		fflush(stdout);
		//Release the buffer
		pthread_mutex_unlock(&shared.mutex);
		//Increment the number of full slots
		sem_post(&shared.full);
		//Interleave execution of producer and consumer
		if(i%2 == 1)
			sleep(1);
	}

	return 0;
}

void *Consumer(void *arg) {
	int i, item;
	long index;
	index = (long)arg;

	for(i=NITERS; i>0; i--) {
		sem_wait(&shared.full);
		pthread_mutex_lock(&shared.mutex);
		item=shared.buf[shared.out];
		shared.out = (shared.out+1)%BUFF_SIZE;
		printf("[C%ld] consuming %d\n", index, item);
		fflush(stdout);
		//Release buffer
		pthread_mutex_unlock(&shared.mutex);
		//Increment the number of full slots
		sem_post(&shared.empty);
		//Interleave
		if(i%2==1)
			sleep(1);
	}
	return 0;
}

int main() {
	pthread_t idP, idC;
	long index;
	sem_init(&shared.full, 0, 0);
	sem_init(&shared.empty, 0, BUFF_SIZE);
	pthread_mutex_init(&shared.mutex, NULL);

	for(index=0; index < NP; index++) {
		// Create a new producer
		pthread_create(&idP, NULL, Producer, (void*)index);
	}

	//Create a new consumer
	for(index=0; index<NC; index++) {
		pthread_create(&idC, NULL, Consumer, (void*)index);
	}
	pthread_exit(NULL);
	return 0;
}

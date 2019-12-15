#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

#define BUFF_SIZE 5
#define NP 3
#define NC 3
#define NITERS 4

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
    int i,item;
    long index = (long)arg;

    for(int i=0;i<NITERS;i++) {
        item = i;

        sem_wait(&shared.empty);
        pthread_mutex_lock(&shared.mutex);
        shared.buf[shared.in] = item;
        shared.in = (shared.in+1)%BUFF_SIZE;
        printf("[P%ld] Producing %d...\n", index, item);
        fflush(stdout);
        pthread_mutex_unlock(&shared.mutex);
        sem_post(&shared.full);
        if(i%2==1)
            sleep(1);
    }
    return 0;
}

void *Consumer(void *arg) {
    int i, item;
    long index = (long)arg;

    for(int i=NITERS; i>0; i--) {
        sem_wait(&shared.full);
        pthread_mutex_lock(&shared.mutex);
        item=shared.buf[shared.out];
        shared.out = (shared.out+1)%BUFF_SIZE;
        printf("[C%ld] Consuming %d...\n", index, item);
        fflush(stdout);
        pthread_mutex_unlock(&shared.mutex);
        sem_post(&shared.empty);
        if(i%2==0) sleep(1);
    }
    return 0;
}

int main() {
    pthread_t idP, idC;
    long index;

    sem_init(&shared.full, 0, 0);
    sem_init(&shared.empty, 0, BUFF_SIZE);
    pthread_mutex_init(&shared.mutex, NULL);

    for(index = 0;index<NP;index++) {
        pthread_create(&idP, NULL, Producer, (void *)index);
    }
    for(index=0;index<NC;index++) {
        pthread_create(&idC, NULL, Consumer, (void*)index);
    }
    pthread_exit(NULL);
    return 0;
}
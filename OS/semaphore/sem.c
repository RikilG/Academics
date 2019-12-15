#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

sem_t sem;

void *fun(void *val) {

    pthread_exit(NULL);
}

int main() {

    sem_init(&sem, 0, 1);


    sem_destroy(&sem);
    return 0;
}
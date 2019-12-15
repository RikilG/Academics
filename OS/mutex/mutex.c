#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_mutex_t lock;
int sum, inc=5;

void *fun(void *val) {
    pthread_mutex_lock(&lock);
    // critical section
    sum += inc;
    inc += 5;
    printf("value of sum is: %d\n", sum);
    // end of critical section
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

int main() {
    pthread_mutex_init(&lock, NULL);

    const int threadCount = 5;
    pthread_t threads[threadCount];
    pthread_attr_t threadAttrs[threadCount];
    for(int i=0;i<threadCount;i++) {
        pthread_attr_init(&threadAttrs[i]);
        if(pthread_create(&threads[i], &threadAttrs[i], fun, (void*)&i) != 0) {
            perror("pthread_create");
        }
    }
    // printf("thread creation complete\n");
    for(int i=0;i<threadCount;i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
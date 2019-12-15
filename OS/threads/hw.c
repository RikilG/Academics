#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *PrintHello(void* threadid) {
    long tid = *(int*)threadid;
    printf("Hello World from thread: %d\n", tid);
    pthread_exit(NULL);
}

int main() {

    pthread_t threads[10];
    for(int i=0;i<10;i++) {
        if(pthread_create(&threads[i], NULL, PrintHello, (void*)&i) != 0) {
            printf("failed to create thread %d\n", i);
        }
    }
    for(int i=0;i<10;i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
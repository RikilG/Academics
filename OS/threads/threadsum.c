#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int sum = 0;

void* fun(void* val) {
    sum += *(int*)val;
    return NULL;
}

int main(int argc, char* argv[]) {
    pthread_t threads[argc-1];
    int data[argc-1];
    for(int i=1;i<argc;i++) {
        data[i-1] = atoi(argv[i]);
        if(pthread_create(&threads[i-1], NULL, fun, (void*)&data[i-1]) != 0) {
            perror("pthread_create");
        }
    }
    for(int i=1;i<argc;i++) {
        pthread_join(threads[i-1], NULL);
    }
    printf("%d\n", sum);
}
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>

typedef struct shm_st {
    int x;
    char y;
} Shared;

int main() {

    key_t key;
    int shmid;
    Shared *sh = NULL;

    if((key = ftok("shmtest.c", 'A')) == -1) {
        perror("ftok");
        exit(1);
    }

    switch(fork()) {
        case 0: //child
            // sleep(2);
            if((shmid = shmget(key, sizeof(Shared), 0)) == -1) {
                perror("shmget");
                exit(3);
            }
            sh = shmat(shmid, 0, 0);
            printf("%d\n", sh->x);
            break;
        case -1: //error
            perror("fork");
            break;
        default: // parent
            if((shmid = shmget(key, sizeof(Shared), 0666 | IPC_CREAT)) == -1) {
                perror("shmget");
                exit(2);
            }
            // sleep(4);
            sh = shmat(shmid, 0, 0);
            sh->x = 9998;
            wait(NULL);
            if(shmctl(shmid, IPC_RMID, NULL) == -1) {
                perror("shmctl");
                exit(4);
            }

    }

    return 0;
}
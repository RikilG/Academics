#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/msg.h>

typedef struct msgbuf {
    long mtype;
    char mtext[500];
} Msgbuf;

int main() {

    Msgbuf buf;
    key_t key;
    int msgqid;

    if((key = ftok("writer.c", 'A')) == -1) {
        perror("ftok");
        exit(1);
    }

    if((msgqid = msgget(key, 0644)) == -1) {
        perror("msgget");
        exit(2);
    }

    while(1) {
        if(msgrcv(msgqid, &buf, sizeof(buf.mtext), 0, 0) == -1) {
            perror("msgrcv");
            exit(3);
        }
        printf("Reader: %s\n", buf.mtext);
    }

    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
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

    if((msgqid = msgget(key, 0644 | IPC_CREAT)) == -1) {
        perror("msgget");
        exit(2);
    }

    buf.mtype = 1;

    while(fgets(buf.mtext, sizeof buf.mtext, stdin) != NULL) {
        int len = strlen(buf.mtext);
        if(buf.mtext[len-1] == '\n')
            buf.mtext[len-1] = '\0';
        if(msgsnd(msgqid, &buf, len+1, 0) == -1) {
            perror("msgsnd");
            exit(3);
        }
    }
    if(msgctl(msgqid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(4);
    }

    return 0;
}
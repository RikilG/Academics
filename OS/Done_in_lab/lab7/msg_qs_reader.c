#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>

#include<sys/ipc.h>
#include<sys/msg.h>

struct my_msgbuf {
	long mtype;
	char mtext[200];
};

int main(void) {
	struct my_msgbuf buf;
	int msgqid;
	key_t key;

	if ((key = ftok("msg_qs.c", 'B')) == -1) {
		perror("ftok");
		exit(1);
	}
	if((msgqid = msgget(key, 0644)) == -1) {
		perror("msgget");
		exit(1);
	}

	printf("reader is ready to receive messages.\n");

	while(1) {
		if(msgrcv(msgqid, &buf, sizeof buf.mtext, 0, 0) == -1) {
			perror("msgrcv");
			exit(1);
		}
		printf("Reader: %s\n", buf.mtext);
	}

	return 0;
}

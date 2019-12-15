#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
	int pfds[2];
	char buf[30];

	pipe(pfds);

	if(!fork()) { // no error in forking i.e. this is child block
		close(pfds[0]);
		printf("Child: writing to pipe\n");
		write(pfds[1], "test", 5);
		printf("Child exiting\n");
		exit(0);
	}
	else {
		close(pfds[1]);
		printf("Parent reading rom pipe\n");
		read(pfds[0], buf, 5);
		printf("Parent read: \" %s \" \n", buf);
		wait(NULL);
	}
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() {
	pid_t p;
	int status;
	p = fork();
	if(p<0) {
		perror("fork");
	}
	else if(p == 0) { //child process
		printf("Child Process: pid: %d, ppid: %d \n", getpid(), getppid());
		printf("End of child\n");
	}
	else { //parent process
		printf("Parent Process: pid: %d\n", getpid());
		printf("End of parent\n");
		wait(&status);
		printf("child status code: %d\n", status);
	}
	return 0;
}

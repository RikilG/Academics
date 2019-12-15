#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
	pid_t pid;
	int pfds[2];
	int s;
	char buf[30];

	pipe(pfds);
	pid = fork();

	if(pid == 0) {  // child block
		// 1: std output, 2: stderr, 0: stdin
		// ex: ls > file.txt // redirects stderr and stdout to file.txt
		// ex: ls 1> file.txt 2> errfile.txt // redirects stderr to errfile and stdout to file.txt
		dup2(pfds[1], 1); // pfds[1] now points to 1 which is stdout
		// same as dup but instead of using lowest available number, it uses the given number
		close(pfds[0]);
		close(pfds[1]);
		// execlp writes to stdout
		if(execlp("ls", "ls", NULL) == -1) { 
			perror("execlp ls");
		}
	}
	else {
		if(fork() == 0) { // new child block
			dup2(pfds[0], 0); // pfds[0] now points to stdin
			close(pfds[0]);
			close(pfds[1]);
			if(execlp("wc", "wc", "-l", NULL) == -1) { //error in execlp
				perror("execlp wc");
			}
		}
		else {
			close(pfds[0]);
			close(pfds[1]);
			wait(&s);
			wait(&s);
		}
	} return 0;
}

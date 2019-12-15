#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>

int main() {

	printf("ls .. | wc -l\n");
	int pfds[2];
	if((pipe(pfds)) == -1) {
		perror("pipe");
		exit(1);
	}

	if(fork() == 0) { // first child
		dup2(pfds[1], 1);
		close(pfds[0]);
		close(pfds[1]);
		if(execlp("ls", "ls", "..", "-lai", NULL) == -1) {
			perror("execlp");
			exit(1);
		}
	}
	else { // parent
		if(fork() == 0) { // second child
			dup2(pfds[0], 0);
			close(pfds[0]);
			close(pfds[1]);
			if(execlp("wc", "wc", "-l", NULL) == -1) {
				perror("execlp");
				exit(1);
			}
		}
		else { // parent
			close(pfds[0]);
			close(pfds[1]);
			wait(NULL);
			wait(NULL);
		}
	}
	
	return 0;
}

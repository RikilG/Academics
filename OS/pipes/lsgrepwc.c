#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>

int main(int argc, char* argv[]) {

	if(argc<2) {
		printf("insufficient args\n");
		exit(1);
	}

	printf("ls .. | grep <argv[1]> | wc -l\n");
	int pfds[2];
	int pfds2[2];
	if((pipe(pfds)) == -1) {
		perror("pipe");
		exit(1);
	}
	if((pipe(pfds2)) == -1) {
		perror("pipe2");
		exit(1);
	}

	if(fork() == 0) { // first child
		dup2(pfds[1], 1);
		close(pfds[0]);
		close(pfds[1]);
		close(pfds2[0]);
		close(pfds2[1]);
		if(execlp("ls", "ls", "..", "-lai", NULL) == -1) {
			perror("execlp");
			exit(1);
		}
	}
	else { // parent
		if(fork() == 0) { // second child
			dup2(pfds[0], 0);
			dup2(pfds2[1], 1);
			close(pfds[0]);
			close(pfds[1]);
			close(pfds2[0]);
			close(pfds2[1]);
			if(execlp("grep", "grep", argv[1], NULL) == -1) {
				perror("execlp");
				exit(1);
			}
		}
		else { // parent
			if(fork() == 0) { // third child
				dup2(pfds2[0], 0);
				close(pfds[0]);
				close(pfds[1]);
				close(pfds2[0]);
				close(pfds2[1]);
				if(execlp("wc", "wc", "-l", NULL) == -1) {
					perror("execlp");
					exit(1);
				}
			}
			else {
				close(pfds[0]);
				close(pfds[1]);
				close(pfds2[0]);
				close(pfds2[1]);
				wait(NULL);
				wait(NULL);
			}
		}
	}
	
	return 0;
}

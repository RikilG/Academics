#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/wait.h>
#include<sys/shm.h>
// shared memory header file

/*
in this program, parent writes first and then child reads.
child dosen't care if the parent has written or not.
*/

int main(void) {
	int shmid;
	char *shmptr;
	int n;

	if(fork() == 0) { // child process
		sleep(2);
		if((shmid = shmget(2041, 32, 0)) == -1) { // if error // shmget allocate system V mem segment (not POSIX)
			perror("shmget in child");
			exit(1);
		}
		shmptr = shmat(shmid, 0, 0);
		if(shmptr == (char *)-1) { // check if prev statement worked or not
			perror("shmat in child");
			exit(2);
		}
		printf("\nChild reading...\n");
		for(n=0;n<26;n++) {
			putchar(shmptr[n]);
		}
		putchar('\n');
	}

	else {
		if ((shmid = shmget(2041, 32, 0666 | IPC_CREAT)) == -1) { // if any eror
			perror("shmget in parent");
			exit(1);
		}
		shmptr = shmat(shmid, 0, 0);
		if(shmptr == (char*)-1) { // shm attach error
			perror("shmat in parent");
			exit(2);
		}
		for(n=0;n<26;n++) {
			shmptr[n] = 'a' + n;
		}
		printf("Parent Writing...\n");
		for(n=0;n<26;n++) {
			putchar(shmptr[n]);
		}
		putchar('\n');
		wait(NULL);
		if(shmctl(shmid, IPC_RMID, NULL) == -1) { // if error
			perror("shmctl");
			exit(-1);
		}
	}
	return 0;
}

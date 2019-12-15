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
here, child waits for parent to write and then reads the shared mem
*/

typedef struct shm_struct {
	int state;
	char *shmptr;
} SS;

int main(void) {
	int shmid;
	SS *ssptr;
	//char *shmptr;
	int n;

	if(fork() == 0) { // child process
		sleep(1);
		if((shmid = shmget(2041, sizeof(SS), 0)) == -1) { // if error // shmget allocate system V mem segment (not POSIX)
			perror("shmget in child");
			exit(1);
		}
		ssptr = shmat(shmid, 0, 0);
		if(ssptr == -1) { // check if prev statement worked or not
			perror("shmat in child");
			exit(2);
		}
		printf("\nChild reading...\n");
		printf(" %d\n", ssptr->state);
	}

	else {
		if ((shmid = shmget(2041, sizeof(SS), 0666 | IPC_CREAT)) == -1) { // if any eror
			perror("shmget in parent");
			exit(1);
		}
		ssptr = shmat(shmid, 0, 0);
		if(ssptr == -1) { // shm attach error
			perror("shmat in parent");
			exit(2);
		}
		printf("Parent Writing...\n");
		ssptr->state = 5;
		wait(NULL);
		if(shmctl(shmid, IPC_RMID, NULL) == -1) { // if error
			perror("shmctl");
			exit(-1);
		}
	}
	return 0;
}

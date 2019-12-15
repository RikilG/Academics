#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>

int main() {
	int pfds[2]; // pipe file descriptor
	char buf[30];

	if(pipe(pfds) == -1) { // pipe creation failed
		perror("pipeFailed");
		exit(1);
	}

	// always write to pfds[1] and read from pfds[0]

	printf("Writing to ile descriptor #%d\n", pfds[1]);
	write(pfds[1], "test", 5); // pfds[writeEnd], string, strlen incl \0
	printf("reading fron file descriptor #%d\n", pfds[0]);
	read(pfds[0], buf, 5); // pfds[readEnd], store location, characters to read
	printf("Read: %s \n", buf);

	return 0;
}

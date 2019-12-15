#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void sigint_handler(int sig) {
	write(1, "Changed SIGINT!\n", 20);
}

int main(void) {
	char s[200];
	struct sigaction sa; 		//defined in signal.h
	sa.sa_handler = sigint_handler; //expects a pointer to function
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);

	if (sigaction(SIGINT, &sa, NULL) == -1) {	// if there is any error
		perror("sigaction");
		exit(1);
	}

	printf("Enter a string: \n");
	if(fgets(s, sizeof(s), stdin) == NULL) 
		perror("fgets error");
	else 
		printf("You entered: %s\n", s);
	return 0;
}

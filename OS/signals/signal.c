#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <errno.h> 
#include <signal.h> 
 
void sigint_handler(int sig)
{
    write(1, "Changed SIGINT!\n", 14);
    exit(1);
}

int main(void)
{
    char s[200];
    struct sigaction sa;

    sa.sa_handler = sigint_handler;
    sa.sa_flags = 0; /* or SA_RESTART, to restart the interrupted syscall */
    sigemptyset(&sa.sa_mask); /* we don’t want to block any signal while in handler */

    if (sigaction(SIGINT, &sa, NULL) == -1) { /*3rd arg is for old action */
        perror("sigaction");
        exit(1);
    }

    printf("Enter a string:\n");
    while(1) {
        if (fgets(s, sizeof s, stdin) == NULL)
            perror("fgets error");
        else
            printf("You entered: %s", s);
    }

    return 0;
}
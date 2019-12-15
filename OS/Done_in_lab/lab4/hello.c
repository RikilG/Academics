#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {
	int n = atoi(argv[1]); // alpha to integer in stdlib.h
	printf("%d", n);
	for(int i=0;i<=n;i++) {
		printf("Hello world!\n");
	}
	return 0;
}

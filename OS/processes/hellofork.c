#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
	int x = 112;
	fork();
	printf("Hello world!");
	printf("%d\n", x);
	return 0;
}

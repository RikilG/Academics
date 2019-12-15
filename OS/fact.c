#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {
	int n = atoi(argv[1]);
	int x = 1;
	for (int i=2;i<=n;i++) {
		x *= i;
	}
	//printf("%d", x);
	return x;
}

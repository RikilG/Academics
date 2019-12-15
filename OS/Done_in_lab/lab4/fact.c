#include<stdio.h>
#include<stdlib.h>

long long int fact(int x) {
	if(x<=1) return 1;
	else return x*fact(x-1);
}

long long int main(int argc, char *argv[]) {
	long long int x = atoi(argv[1]); // alpha to integer
	//printf("%lld", fact(x));
	return fact(x);
}

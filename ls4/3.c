#include<stdio.h>
#include<string.h>

int main() {

	int arr[1000],n=0,xor=0;
	char ch = 97;
	do {
		scanf("%d%c", &arr[n++],&ch);
		xor ^= arr[n-1];
	}while(ch != '\n');
	printf("odd : %d\n",xor);

	return 0;
}

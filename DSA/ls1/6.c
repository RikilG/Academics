
#include<stdio.h>

int isPrime(int x) {
	for(int i=2;i*i<=x;i++) {
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}

int main() {

	int a,b;
	scanf(" %d %d",&a,&b);
	if(a<2)
		a=2;
	for(int i=a;i<=b;i++){
		if(isPrime(i)){
			printf("%d\n",i);
		}
	}

	return 0;
}

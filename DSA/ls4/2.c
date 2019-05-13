#include<stdio.h>
#include<string.h>

int formula(int v, int k) {
	//returns n
	int n=0,temp,i=0;
	int div = 1;
	while(1) {
		temp = v/div;
		if(temp>0)
			n += temp;
		else
			break;
		div *= k;
	}
	return n;
}

int main() {

	int n,k;
	scanf(" %d %d",&n,&k);
	int v = ((k-1)*n)/k-1;
	for(;v<n;v++) {
		int temp = formula(v,k);
		if(temp>=n){
			printf("value of v : %d\n",v);
			break;
		}
	}


	return 0;
}

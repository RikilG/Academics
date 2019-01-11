#include<stdio.h>

int getPrime(int n) {
	n++;
	for(int i=2;i*i<=n;i++) {
		if(n%i==0){
			n++;
			i=1;
			continue;
		}
	}
	return n;
}

int main() {

	int n;
	scanf(" %d",&n);
	int arr[n][n];
	int startj = n&1?n/2:n/2-1;
	int starti = n/2;
	//printf("init : starti = %d, startj = %d\n",starti,startj);
	
	//logic
	int count=1,sq=1;
	int dir = 0; // 0-down 1-right 2-up 3-left;
	int num = 2;
	while(count<=n*n) {
		arr[starti][startj] = num;
		//printf("starti = %d, startj = %d, count=%d, dir=%d\n",starti,startj,count,dir);
		if(count>sq*sq) {
			sq++;
			dir++;
		}
		else if(count == sq*sq-sq+1) {
			dir++;
		}
		switch(dir%4) {
			case 0 :
				starti++;
				break;
			case 1 :
				startj++;
				break;
			case 2 :
				starti--;
				break;
			case 3 :
				startj--;
				break;
		}
		count++;
		num = getPrime(num);
	}

	//to print matrix;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%2d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

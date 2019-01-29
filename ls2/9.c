
#include<stdio.h>

int calcSum(int n, int starti, int startj, int side, int arr[n][n]) {
	int sum = 0;
	for(int i=starti;i<starti+side;i++) {
		for(int j=startj;j<startj+side;j++) {
			sum += arr[i][j];
		}
	}
	return sum;
}

int main() {

	int n;
	printf("Enter size of matrix : ");
	scanf(" %d",&n);
	int arr[n][n];
	printf("Enter elements of matrix : \n");
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			scanf(" %d",&arr[i][j]);
		}
	}

	int sumOfMatrix = 0;
	//int maxSum = -9999;
	int m = n;
	while(m) {
		//sumOfMatrix = 0;
		int i=0,j=0;
		for(int q=0;q<(n-m+1)*(n-m+1);q++) {
			if(j<=n-m) {
				int temp = calcSum(n,i,j++,m,arr);
				if(m==n) {
					sumOfMatrix = temp;
				}
				else if(temp>sumOfMatrix) {
					sumOfMatrix = temp;
				}
			}
			else {
				j=0;
				i++;
				//if(i>n-m) {
				//	break;
				//}
			}
		}
		m--;
	}
	printf("max of sumOfMatrix = %d\n",sumOfMatrix);

	return 0;
}

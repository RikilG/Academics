
#include<stdio.h>

int main() {

	int n;
	scanf(" %d",&n);
	int arr[n][n];
	int saddleFound=0;
	//int leastinRow[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf(" %d",&arr[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		int least = 9999;
		int col = 0;
		for(int j=0;j<n;j++){
			if(arr[i][j]<least) {
				least = arr[i][j];
				col = j;
			}
		}
		int highest = 0;
		for(int j=0;j<n;j++){
			if(arr[j][col]>highest){
				highest = arr[j][col];
			}
		}
		if(highest == least){
			saddleFound = 1;
			printf("%d\n",least);
		}
		//leastinRow[i] = least;
	}
	if(saddleFound == 0)
		printf("No saddle point found...\n");

	return 0;
}

#include<stdio.h>
#include<string.h>

void swap(int arr[][2], int i, int j) {
	int temp0 = arr[i][0];
	int temp1 = arr[i][1];
	arr[i][0] = arr[j][0];
	arr[i][1] = arr[j][1];
	arr[j][0] = temp0;
	arr[j][1] = temp1;
}

int main() {

	int n,budget;
	scanf(" %d %d",&n,&budget);
	int arr[n][2];
	for(int i=0;i<n;i++) {
		scanf(" %d",&arr[i][0]);
		arr[i][1] = i+1;
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n-i-1;j++) {
			if(arr[j][0] > arr[j+1][0]) {
				swap(arr, j, j+1);
			}
		}
	}
	int minPrice = 99999,items = 0;
	int price=0;
	for(int k=1;k<=n;k++) {
		price = 0;
		for(int l=0;l<k;l++) {
			price += arr[l][0] + arr[l][1]*k;
		}
		if(price<=budget) {
			if(k>items){
				items = k;
				minPrice = price;
			}
			if(price < minPrice) {
				minPrice = price;
			}
		}
	}
	printf(" %d %d\n",items,minPrice);

	return 0;
}

//for(int i=0;i<n;i++) {
//	printf("%d ",arr[i][0]);
//}printf("\n");
//for(int i=0;i<n;i++) {
//	printf("%d ",arr[i][1]);
//}printf("\n");

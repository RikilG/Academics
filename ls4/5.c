#include<stdio.h>
#include<string.h>

int resItems(int n, int arr[], int time) {
	int temp = 0;
	for(int i=0;i<n;i++) {
		temp += time/arr[i];
	}
	return temp;
}

int bsearch(int n, int minTime, int arr[], int items) {
	int left = 0, right = minTime-1;
	int mid;
	int currItems;
	while(left<right) {
		mid = (left+right)/2;
		currItems = resItems(n,arr,mid+1);//mid+1 is time array
		//printf("right:%d mid:%d left:%d n:%d\n  arr[left]:%d arr[mid]:%d arr[right]:%d items:%d currItems:%d\n",right,mid,left,n,left+1,mid+1,right+1,items,currItems);
		if(currItems == items)
			left = right = mid;
		else if(currItems < items) {
			left = mid+1;
		}
		else {
			right = mid-1;
		}
	}
	return left;
}

int main() {

	int n,items;
	scanf(" %d %d",&n,&items);
	int arr[n];
	for(int i=0;i<n;i++) {
		scanf(" %d",&arr[i]);
	}
	//assuming array is sorted
	int maxTime = items*arr[0]; // where arr[0] is min(arr)

	//bsearch on time
	int temp = bsearch(n, maxTime, arr, items);
	printf(" time = %d\n",++temp);

	return 0;
}

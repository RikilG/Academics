#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void *a, const void *b) {
	return *((int*)a)-*((int*)b);
}

int main() {
	int n,k,start=0;
	scanf(" %d %d",&n,&k);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf(" %d",&arr[i]);
	qsort(arr, n, sizeof(int), cmp);
	while(arr[start]<k && start<n) {
		start++;
		arr[start] = arr[start-1] + 2*arr[start];
		//printf(" start=%d, arr[start]=%d\n",start,arr[start]);
		qsort(arr+start, n-start, sizeof(int), cmp);
	}
	//for(int i=start;i<n;i++)
	//	printf(" %d",arr[i]);
	printf("\noperations:%d\n",start);
}

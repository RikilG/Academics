#include<stdio.h>
#include<string.h>

int bsearch(int arr[], int left, int right, int k) {
	int ptr;
	while(left<right) {
		ptr = (left + right)/2;
		//printf("pos : ptr=%d, left=%d, right=%d\n",ptr,left,right);
		//printf("k = %d, arr[ptr] = %d\n",k,arr[ptr]);
		if(k>arr[ptr])
			left = ptr+1;
		else if(k<arr[ptr])
			right = ptr-1;
		else
			left = right = ptr;
	}
	if(left>right)
		return -1;
	if(arr[left]==k)
		return left;
	else
		return -1;
}

int abs(int x) {
	return (x>0)?x:-x;
}

int cmpfunc(const void *a, const void *b) {
	return *((int*)a) - *((int*)b);
}

int main() {

	int n,k;
	scanf(" %d",&n);
	int arr[n];
	for(int i=0;i<n;i++) {
		scanf(" %d",&arr[i]);
	}
	scanf(" %d",&k);
	qsort(arr,n,sizeof(int),cmpfunc);
	for(int i=0;i<n;i++) {
		int value = abs(k-arr[i]);
		int temp = bsearch(arr,0,n-1,value);
		//printf("i=%d, temp=%d arr[i]=%d arr[temp]=%d value=%d\n",i,temp,arr[i],arr[temp],value);
		if(temp != -1) {
			printf("key : %d\n",arr[i]+arr[temp]);
			return 0;
		}
	}

	return 0;
}
//for(int i=0;i<n;i++) {
//	printf(" %d",arr[i]);
//}printf("\n");

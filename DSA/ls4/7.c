#include<stdio.h>
#include<string.h>

int bsearch(int n, int arr[], int k) {
	int left = 0, right = n-1;
	int ptr;
	while(left<right) {
		ptr = (left + right)/2;
		if(arr[ptr]<arr[ptr+1] && arr[ptr-1]<arr[ptr]){
			if(k>arr[ptr])
				left = ptr+1;
			else if(k<arr[ptr])
				right = ptr-1;
			else
				left = right = ptr;
		}
		else if(arr[ptr+1] == k)
			return ptr+1;
		else if(arr[ptr-1] == k)
			return ptr-1;
		else if(arr[ptr] == k)
			return ptr;
		else if(k>arr[ptr])
			left = ptr+2;
		else
			right = ptr-2;
		//printf("pos : ptr=%d, left=%d, right=%d\n",ptr,left,right);
		//printf("k = %d, arr[ptr] = %d\n",k,arr[ptr]);
	}
	if(left>right)
		return -1;
	if(arr[left] == k) {
		return left;
	}
	return -1;
}

int main() {

	int n,k;
	scanf(" %d",&n);
	int arr[n];
	for(int i=0;i<n;i++) {
		scanf(" %d",&arr[i]);
	}
	scanf(" %d",&k);
	int temp = bsearch(n, arr, k);
	if(temp == -1)
		printf("-1\n");
	else
		printf("%d\n",temp+1);

	return 0;
}

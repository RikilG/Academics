#include<stdio.h>
#include<string.h>

int bsearch(int n, int arr[], int k) {
	int left = 0, right = n-1;
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
	if(arr[left] == k) {
		printf("Naruto %d\n",left+1);
	}
	else {
		if(k<arr[left])
			printf("Sasuke %d\n",left+1);
		else if(k>arr[left])
			printf("Sasuke %d\n",left+2);
	}
	//for sake of binary search return index
	return left;
}

int main() {

	int n,k;
	scanf(" %d",&n);
	int arr[n];
	for(int i=0;i<n;i++) {
		scanf(" %d", &arr[i]);
	}
	scanf(" %d", &k);
	bsearch(n, arr, k);

	return 0;
}

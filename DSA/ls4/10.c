#include<stdio.h>
#include<string.h>

int bsearch(int arr[], int left, int right) {
	int ptr=(left+right)/2;
	if(left == right) {
		return arr[left];
	}
	if(ptr&1 == 1) { // odd ptr case
		if(arr[ptr] == arr[ptr+1]) {
			// look before
			return bsearch(arr, left, ptr-1);
		}
		else if(arr[ptr] == arr[ptr-1]) {
			// look after
			return bsearch(arr, ptr+1, right);
		}
		else {
			return arr[ptr];
		}
	}
	else { // even ptr case
		if(arr[ptr] == arr[ptr+1]) {
			// look after
			return bsearch(arr, ptr+2, right);
		}
		else if(arr[ptr] == arr[ptr-1]) {
			// look before
			return bsearch(arr, left, ptr-2);
		}
		else {
			return arr[ptr];
		}
	}
}

int main() {

	int n;
	scanf(" %d", &n);
	int arr[n];
	for(int i=0;i<n;i++) {
		scanf(" %d",&arr[i]);
	}
	///solution 1
	//can be done while taking input
	int x=0;
	for(int i=0;i<n;i++) {
		x = x^arr[i];
	}printf(" solution 1 odd : %d\n",x);
	//solution 2
	//using binary search
	x = bsearch(arr, 0, n-1);
	printf(" solution 2 odd : %d\n",x);

	return 0;
}

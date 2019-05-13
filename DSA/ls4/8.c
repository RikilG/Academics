#include<stdio.h>
#include<string.h>

int bsearch(int arr[], int left, int right, int k) {
	int pos = (left+right)/2;
	while(left<right) {
		//printf("pos=%d left=%d right=%d arr[pos]=%d arr[left]=%d, arr[right]=%d\n",pos,left,right,arr[pos],arr[left],arr[right]);
		pos = (left+right)/2;
		if(k>arr[pos])
			left = pos+1;
		else if(k<arr[pos])
			right = pos-1;
		else
			left = right = pos;
	}
	if(left>right)
		return -1;
	if(arr[left] == k)
		return left;
	else
		return -1;
}

int point(int arr[],int left, int right){
	int pos;
	while(left<right) {
		pos = (left + right)/2;
		if(pos>0 && arr[pos-1]<arr[pos] && arr[pos]<arr[pos+1]) {
			if(arr[pos]>arr[right]){ // take right part
				return point(arr,pos+1,right);
			}
			else if(arr[pos]<arr[left]) { // take left part
				return point(arr,left,pos-1);
			}
			else {
				return -1;
			}
		}
		else if(arr[pos]>arr[pos+1]) {
			return pos;
		}
		else if(pos>0 && arr[pos-1]>arr[pos]) {
			return pos-1;
		}
	}
	return -1;
}

int main() {

	int n,k;
	scanf(" %d",&n);
	int arr[2*n+1];
	for(int i=0;i<n;i++) {
		scanf(" %d",&arr[i]);
	}
	scanf(" %d",&k);
	int start = point(arr,0,n-1)+1;
	int temp = bsearch(arr,0,start-1,k);
	if(temp == -1) {
		temp = bsearch(arr,start,n-1,k);
	}
	printf("pos : %d\n", temp+1);
	//for(int i=n;i<n*2;i++) {
	//	arr[i] = arr[i-n];
	//}
	//int temp = bsearch(arr, start, start + n - 1, k);
	//if(temp == -1){
	//	printf("got a -1\n");
	//	return 0;
	//}
	//if(temp>=n)
	//	temp -= n;
	//printf("pos : %d\n",++temp);

	return 0;
}
//for(int i=start;i<start+n;i++) {
//	printf(" %d",arr[i]);
//}printf("\n");

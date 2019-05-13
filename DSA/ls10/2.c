#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void *a, const void *b) {
    return *((int*)a)-*((int*)b);
}

int main() {
    int n,k,sum=0;
    scanf(" %d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++) {
        scanf(" %d",&arr[i]);
    }
    while(k--) {
        qsort(arr, n, sizeof(int), cmp);
        int temp = arr[n-1];
        sum += arr[n-1];
        arr[n-1] = temp/2;
    }
    printf(" Sum: %d\n",sum);
    return 0;
}
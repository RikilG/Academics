#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void *a, const void *b) {
    return *((int *)a)-*((int *)b);
}

int main() {

    int n,count=0;
    scanf(" %d",&n);
    int arr[n],sorted[n];
    for(int i=0;i<n;i++) {
        scanf(" %d",&arr[i]);
    }
    for(int i=0;i<n;i++) {
        sorted[i] = arr[i];
    }
    qsort(sorted, n, sizeof(int), cmp);
    for(int i=0;i<n;i++) {
        if(arr[i]!=sorted[i]) {
            int j=i;
            for(;j<n;j++) {
                if(arr[j] == sorted[i]) {
                    break;
                }
            }
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            count++;
        }
    }
    printf("swaps = %d\n",count);

    return 0;
}
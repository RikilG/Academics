#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void *a, const void *b) {
    return *((int *)a)-*((int *)b);
}

int binsearch(int start, int find, int n, int arr[]) {
    //printf(" start = %d find=%d arr[start]=%d\n",start,find,arr[start]);
    for(int i=start;i<n;i++) {
        //printf(" j=%d arr[j]=%d\n",i,arr[i]);
        if(arr[i] > find) {
            i--;
            //printf(" returning : %d\n",i);
            return i;
        }
    }
    return n-1;
}

int main() {

    int n,max=0,indi,indj,len;
    scanf(" %d",&n);
    int arr[n];
    for(int i=0;i<n;i++) {
        scanf(" %d",&arr[i]);
    }
    qsort(arr,n,sizeof(int),cmp);
    for(int i=0;i<n;i++) {
        int j = binsearch(i,2*arr[i],n,arr);
        if(j!=-1) {
            len = j-i+1;
            if (len > max) {
                max = len;
                indi = i;
                indj = j;
            }
        }
    }
    int count = n-max;
    while(arr[indi]==arr[indi+1]) {
        indi++;
        count++;
    }
    while(arr[indj] == arr[indj-1]) {
        indj--;
        count++;
    }
    //print ans
    //printf(" n=%d max=%d len=%d indi=%d indj=%d\n", n, max, len, indi, indj);
    printf(" to remove:%d\n list :",count);
    for(int i=indi;i<=indj;i++) {
        printf(" %d",arr[i]);
    }printf("\n");

    return 0;
}
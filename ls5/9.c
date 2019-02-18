#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int abs(int x) {
    return (x>0)?x:-x;
}

int cmp(const void *a, const void *b) {
    return *((int*)a)-*((int*)b);
}

int main() {

    int n;
    scanf(" %d",&n);
    int arr[n];
    for(int i=0;i<n;i++) {
        scanf(" %d",&arr[i]);
    }
    qsort(arr,n,sizeof(int),cmp);
    int hi=n-1,lo=0,count=0;
    while(arr[hi]>2*arr[lo]) {
        count++;
        double rmlo = abs(2 - ((double)arr[hi])/arr[lo+1]);
        double rmhi = abs(2 - ((double)arr[hi-1])/arr[lo]);
        if(rmlo == 0) {
            lo++;
            break;
        }
        else if(rmhi == 0) {
            hi--;
            break;
        }
        else if(rmlo<rmhi)
            lo++;
        else 
            hi--;
        //print
        for(int i=lo;i<=hi;i++) {
            printf(" %d",arr[i]);
        }printf("\n");
    }
    while(arr[lo] == arr[lo+1]) {
        count++;
        lo++;
    }
    while(arr[hi] == arr[hi-1]) {
        count++;
        hi--;
    }
    //print
    printf("final : ");
    for (int i = lo; i <= hi; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
    printf("count = %d\n",count);

    return 0;
}
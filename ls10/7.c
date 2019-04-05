#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void *a, const void *b) {
    return *((int*)a)-*((int*)b);
}

int main() {
    int n=0,arr[1000],count=0;
    char ch;
    do {
        scanf("%d%c",&arr[n++],&ch);
    }while(ch!='\n');
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            int count0 = 0, count1 = 0;
            for(int k=i;k<=j;k++) {
                if(arr[k]==0) count0++;
                if(arr[k]==1) count1++;
            }
            if(count0==count1) {
                // for (int k = i; k <= j; k++) {
                //     printf(" %d",arr[k]);
                // }printf("\n");
                count++;
            }
        }
    }
    printf(" count: %d\n",count);
    return 0;
}
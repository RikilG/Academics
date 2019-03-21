#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void *a, const void *b) {
    return *((int*)a)-*((int*)b);
}

int main() {
    int n1=0,n2=0,arr[1000],x,n=0;
    char c;
    do {
        scanf("%d%c",&x,&c);
        arr[n++] = x;
    }while(c!='\n');
    qsort(arr,n,sizeof(int),cmp);
    for(int i=0;i<n;i++) {
        if(i&1) n1=n1*10+arr[i];
        else n2=n2*10+arr[i];
    }
    printf("Min sum of possible no's: %d\n",n1+n2);
    return 0;
}
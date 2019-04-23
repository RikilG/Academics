#include<stdio.h>
#include<stdlib.h>

int n,m,l,r,c,p,q,s,*arr = NULL;

int calc() {
    for(int i=l;i<=r;i++) arr[i] += c;
    //for next round
    int oldL = l,oldR = r;
    l = (oldL*p + oldR)%n + 1;
    r = (oldR*q + oldL)%n + 1;
    c = (c*s)%1000000 + 1;
    if(l>r) { //swap
        int temp = l;
        l = r;
        r = l;
    }
}

int main() {
    int tc;
    scanf(" %d",&tc);
    while(tc--) {
        scanf(" %d %d %d %d %d %d %d %d",&n,&m,&l,&r,&c,&p,&q,&s);
        if(arr!=NULL) free(arr);
        arr = (int *)calloc(n+1,sizeof(int));
        while(m--) calc();
        int max = arr[1],ind=1;
        for(int i=1;i<=n;i++) 
            if(arr[i]>max) {
                max = arr[i];
                ind = i;
            }
        printf(" position: %d, profit:%d\n",ind,max);
    }
    return 0;
}
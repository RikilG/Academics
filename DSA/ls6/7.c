#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void *a, const void *b) {
    return *((int*)a)-*((int*)b);
}

int time(int f, int gas[], int k, int s) {
    int t=0;
    for(int i=0;i<k;i++) {
        if(2*gas[i] <= f)
            t+=gas[i];
        else if(gas[i]<=f) {
            int x1=f-gas[i],x2=2*gas[i]-f;
            t += x1 + 2*x2;
        }
        else {
            printf("waste: %d\n",f);
            return -1;
        }
        //printf("in :f=%d i=%d gas[i]=%d t=%d\n",f,i,gas[i],t);
    }
    return t;
}

int main() {
    int n,k,s,t;
    scanf(" %d %d %d %d",&n,&k,&s,&t);
    int cars[n][3],gas[k+1];
    for(int  i = 0; i < n; i++) {
        scanf(" %d %d",&cars[i][0],&cars[i][1]);
        cars[i][2] = 0;
    }
    for(int i=0;i<k;i++) {
        scanf(" %d",&gas[i]);
    }
    gas[k] = s;
    qsort(gas,k+1,sizeof(int),cmp);
    for(int i=1;i<k+1;i++) {
        gas[i] = gas[i] - gas[i-1];
    }
    for(int i=0;i<n;i++) {
        int temp = time(cars[i][1],gas,k+1,s);
        if(temp == -1) continue;
        else if(temp <= t) {
            cars[i][2] = 1;
        }
    }
    //print
    int min = 99999;
    for(int i=0;i<n;i++) {
        if(cars[i][2] == 1)
            if(cars[i][0]<min)
                min = cars[i][0];
    }
    printf("price : %d\n",min);
    return 0;
}
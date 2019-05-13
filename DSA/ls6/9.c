#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//recursion optimized by using best[] array. also works without it but takes long time.
int find(int n, int best[]) {
    if(n<7) return n;
    if(best[n]) return best[n];
    int max = 0;
    for(int i=n-3;i>0;i--) {
        int temp = find(i,best);
        temp *= (n-i-1);
        if(temp>max) max = temp;
    }
    best[n] = max;
    return max;
}

int main() {
    int best[100] = {0,1,2,3,4,5,6,0};
    int n;
    scanf(" %d",&n);
    int ans = find(n,best);
    printf("Ans : %d\n",ans);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int ans[10000] = {0,1,2,3};

int findAns(int i) {
    if(ans[i])  return 0;
    int min = INT_MAX;
    for(int j=2;j*j<=i;j++) {
        if(i%j==0) {
            int temp = i/j;
            if(ans[temp]<min) min = ans[temp];
        }
    }
    if(min!=INT_MAX)
        ans[i] = 1 + min;
    else
        ans[i] = 1 + ans[i-1];
}

int main() {
    int tc,n;
    scanf(" %d",&tc);
    while(tc--) {
        scanf(" %d",&n);
        for(int i=0;i<=n;i++) {
            findAns(i);
        }
        printf(" ans=%d\n",ans[n]);
    }
    return 0;
}
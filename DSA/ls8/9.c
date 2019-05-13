#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INF 99999

int main() {
    int n,ans=0,before=INF;
    scanf(" %d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf(" %d",&arr[i]);
    for(int i=0;i<n;i++) {
        if(before!=INF && before<arr[i]) {
            ans += arr[i] - before;
        }
        before = arr[i];
    }
    printf(" ans: %d\n",ans);
    return 0;
}
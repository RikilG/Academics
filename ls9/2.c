#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int n,m,k,count=0,sum = 0;
    scanf(" %d %d %d",&n,&m,&k);
    int stk1[n],stk2[m],tos1=0,tos2=0;
    for(int i=0;i<n;i++)
        scanf(" %d",&stk1[i]);
    for(int i=0;i<m;i++)
        scanf(" %d",&stk2[i]);
    while(tos1<n && tos2<m && sum<k) {
        sum += (stk1[tos1]<stk2[tos2])?stk1[tos1++]:stk2[tos2++];
        count++;
    }
    printf("count: %d\n",--count);
    return 0;
}
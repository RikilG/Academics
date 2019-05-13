#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n, m, k, count = 0, sum = 0, maxCount = 0;
int stk[2][1000], tos[2] = {0};

int selectELement(int no) {
    sum += stk[no][ tos[no]++ ];
    if(sum>k) {
        if(count>maxCount) maxCount = count;
        goto EXIT;
    }
    else if((no==0 && tos[0]>n) || (no==1&&tos[1]>m))
        goto EXIT;
    count++;
    printf("Selected from : %d, currSum: %d\n",no,sum);
    selectELement(0);
    selectELement(1);
    count--;
    printf("Deselected from : %d\n",no);
    EXIT:
        sum -= stk[no][ --tos[no] ];
        return 0;
}

int main() {
    scanf(" %d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++)
        scanf(" %d",&stk[0][i]);
    for(int i=0;i<m;i++)
        scanf(" %d",&stk[1][i]);
    selectELement(0);
    selectELement(1);
    printf("maxCount: %d\n",maxCount);
    return 0;
}
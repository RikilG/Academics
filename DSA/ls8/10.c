#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int queue[100000000];

int main() {
    int n,k,start=0,end=0,curShift,totShift=0,ans=0;
    char c;
    scanf(" %d %d",&n,&k);
    int lights[n];
    for(int i=0;i<n;i++) {
        scanf(" %c",&c);
        switch(c) {
            case 'R': case 'r': lights[i] = 1;break;
            case 'Y': case 'y': lights[i] = 2;break;
            case 'G': case 'g': lights[i] = 3;break;
        }
    }
    for(int i=0;i<n;i++) {
        if(i>=k)
            totShift -= queue[start++];
        lights[i] += totShift;
        curShift = (3-(lights[i]%3))%3;
        totShift += curShift;
        ans += curShift;
        queue[end++] = curShift;
        //printf("totShift:%d, curShift:%d, ans:%d, lights[i]:%d\n",totShift,curShift,ans,lights[i]);
    }
    printf("%d\n",ans);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int checkPath(int start,int n,int bunks[]) {
    int temp = start+1, sum = bunks[start];
    while(temp%n!=start) {
        if(sum < 0) return 0;
        sum += bunks[temp++];
    }
    return 1;
}

int main() {
    int n,a,b;
    scanf(" %d",&n);
    int bunks[n]; // bunks [petrol] [distance]
    for(int i=0;i<n;i++) {
        scanf(" %d %d",&a,&b);
        bunks[i] = a-b;
    }
    for(int i=0;i<n;i++) {
        if(bunks[i]<0) continue;
        if(checkPath(i,n,bunks)) {
            printf("start at: %d\n",i);
            return 0;
        }
    }
    printf("No starting point\n");
    return 0;
}
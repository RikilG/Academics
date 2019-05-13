#include<stdio.h>
#include<stdlib.h>

int main() {
    int n,k,t;
    scanf(" %d %d %d",&n,&k,&t);
    int arr[n];
    for(int i=0;i<n;i++) 
        scanf(" %d",&arr[i]);
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<=i+k && j<n;j++) {
            // printf(" pair: i:%d arr[i]:%d j:%d arr[j]:%d diff:%d\n",i,arr[i],j,arr[j],abs(arr[i]-arr[j]));
            if(abs(arr[i]-arr[j])<=t) {
                printf("Hogwarts wins\n");
                return 0;
            }
        }
    }
    printf("Voldemort wins\n");
    return 0;
}
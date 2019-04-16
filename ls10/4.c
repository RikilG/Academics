#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int n;
    scanf(" %d",&n);
    int arr[n];
    for(int i=0;i<n;i++) {
        scanf(" %d",&arr[i]);
    }
    for(int i=0;i<n;i++) {
        int lchild = 2*i+1, rchild = 2*i+2;
        if(lchild<n && arr[i]>arr[lchild]) {
            printf("False\n");
            return 0;
        }
        if(rchild<n && arr[i]>arr[rchild]) {
            printf("False\n");
            return 0;
        }
    }
    printf("True\n");
    return 0;
}
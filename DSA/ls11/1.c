#include<stdio.h>

int search(int start, int n, int arr[], int x) {
    for(int i=start+1;i<n;i++) if(arr[i]==x) return i;
    return -1;
}

int main() {
    int n,m;
    scanf(" %d %d",&m,&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf(" %d",&arr[i]);
    for(int i=0;i<n;i++)
        if(search(i,n,arr,m-arr[i])!=-1) {
            printf("%d %d",i+1,search(i,n,arr,m-arr[i])+1);
            break;
        }
    printf("\n");
    return 0;
}
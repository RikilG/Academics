#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int n,temp=0,min=0;
    scanf(" %d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf(" %d",&arr[i]);
    for(int start=0;start<n;start++) {
        for(int end=start;end<n;end++) {
            temp = arr[start];
            for(int i=start;i<=end;i++) {
                printf(" %d",arr[i]);
                if(arr[i]<temp)
                    temp = arr[i];
            }
            printf("\n");
            min+=temp;
        }
    }
    printf(" Sum of Mins: %d\n",min);
    return 0;
}
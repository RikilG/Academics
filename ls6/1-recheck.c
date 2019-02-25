#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findNo(int n, int arr[]) {
    int temp = 0;
    for(int i=0;i<n;i++)
        temp = temp*10 + arr[i];
    return temp;
}

int main() {
    int n,no,minNo=99999;
    scanf(" %d",&n);
    int arr[n],adj[n][n];
    for(int i=0;i<n;i++)
        scanf(" %d",&arr[i]);
    minNo = findNo(n,arr);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf(" %d",&adj[i][j]);
            if(adj[i][j]) {
                swap(&arr[i],&arr[j]);
                no = findNo(n,arr);
                swap(&arr[i],&arr[j]);
                if(no<minNo)
                    minNo = no;
            }
        }
    }
    printf("min permutation : %d\n",minNo);
    return 0;
}
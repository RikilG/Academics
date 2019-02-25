#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int k;

int cmp(const void *a, const void *b) {
    if(k)
        return *((int *)b)-*((int *)a);
    else
        return *((int *)a)-*((int *)b);
}

void swap(int n, int m, int row, int arr[][m], int ele, int col) {
    //search for element and swap with col
    for(int i=col;i<m;i++) {
        if(arr[row][i] == ele) {
            if(k) {
                int temp = col;
                col = i;
                ele = temp;
                break;
            }
            else {
                ele = i;
                break;
            }
        }
    }
    printf("swap: %d %d\n", col, ele);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(row==i || arr[i][col]>arr[i][ele]) {
                int temp = arr[i][col];
                arr[i][col] = arr[i][ele];
                arr[i][ele] = temp;
            }
        }
    }
}

int main() {
    int n,m,count=0;
    scanf(" %d %d %d",&n,&m,&k);
    int arr[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf(" %d",&arr[i][j]);
    for(int i=0;i<n;i++) {
        int temp[m];
        for(int j=0;j<m;j++) temp[j] = arr[i][j];
        qsort(temp, m, sizeof(int), cmp);
        // for(int j=0;j<m;j++) printf(" %d",temp[j]);
        // printf("\n");
        for(int j=0;j<m;j++) {
            if(temp[j] != arr[i][j]) {
                swap(n,m,i,arr,temp[j],j);
                count++;
            }
        }
    }
    printf("count:%d\n",count);
    return 0;
}

    // printf("after:\n");
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         printf(" %d",arr[i][j]);
    //     }printf("\n");
    // }printf("\n");
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int count=0;

void merge(int arr[], int l, int m, int r) {
    int n1 = m-l+1;
    int n2 = r-m;
    int i=0,j=0,k=l;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++)
        L[i] = arr[l+i];
    for(int i=0;i<n2;i++)
        R[i] = arr[m+1+i];
    while (i < n1 && j < n2) {
        if(L[i]<R[j]) {
            arr[k++] = L[i++];
        }
        else if(L[i]>R[j]) {
            arr[k++] = R[j++];
            count += n1-i;
        }
        else {
            arr[k++] = L[i++];
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[],int l,int r) {
    if(l<r) {
        int m = (l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main() {

    int n;
    scanf(" %d",&n);
    int arr[n];
    for(int i=0;i<n;i++) {
        scanf(" %d",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    printf(" no of pairs : %d\n",count);
    for(int i=0;i<n;i++) {
        printf(" %d",arr[i]);
    }printf("\n");

    return 0;
}
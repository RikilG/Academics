#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int n1,n2,i=0,j=0;
    scanf(" %d",&n1);
    int L[n1];
    for(int i=0;i<n1;i++) scanf(" %d",&L[i]);
    scanf(" %d",&n2);
    int R[n2];
    for(int i=0;i<n2;i++) scanf(" %d",&R[i]);
    while(i<n1 && j<n2) {
        if(L[i] >= R[j]) {
            int temp = R[j];
            for(int k=j;k>0;k--) {
                R[k] = R[k-1];
            }
            R[0] = L[n1-1];
            for(int k=n1-1;k>i;k--) {
                L[k] = L[k-1];
            }
            L[i] = temp;
            j++;
            i++;
        }
        else {
            i++;
        }
    }
    if(i==n1-1) {

    }
    if(j==n2-1) {
        
    }
    for(int i=0;i<n1;i++) printf(" %d",L[i]);
    for(int i=0;i<n2;i++) printf(" %d",R[i]);
    printf("\n");
    return 0;
}
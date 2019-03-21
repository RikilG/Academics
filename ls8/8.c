#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int k,ones=0,pts=0;
    scanf(" %d",&k);
    int arr[k][k];
    for(int i=0;i<k;i++) for(int j=0;j<k;j++) scanf(" %d",&arr[i][j]);
    for(int m=1;m<=k;m++) {
        for(int n=1;n<=k;n++) {
            for(int i=0;i<k-m+1;i++) {
                for(int j=0;j<k-n+1;j++) {
                    ones = 0;
                    //printf("i=%d, j=%d\n",i,j);
                    for(int p=i;p<m+i;p++) {
                        for(int q=j;q<n+j;q++) {
                            ones += arr[p][q];
                        }
                    }
                    if(ones==1)
                        pts++;
                }
            }
        }
    }
    printf("Life points: %d\n",pts);
    return 0;
}
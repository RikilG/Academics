#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int bits[33],num;

void genbin() {
    memset(bits, 0, sizeof(bits));
    int x = num--;
    for(int i=0;x>0;i++) {
        bits[i] = x&1;
        x = x>>1;
    }
}

int main() {
    
    int n,max=0;
    scanf(" %d",&n);
    num = (1<<n)-1;
    int arr[n];
    for(int i=0;i<n;i++) {
        scanf(" %d",&arr[i]);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j]<arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    while(num>0) {
        genbin();
        int temp=0;
        for(int i=0;i<n;i++) {
            if(bits[i]>0)
                temp = temp*10 + arr[i];
        }
        if(temp%3==0 && temp>max)
            max = temp;
    }
    printf("max no = %d\n",max);

    return 0;
}
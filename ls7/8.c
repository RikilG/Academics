#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define loop(n) for(int i=0;i<(n);i++)
#define log(exp) printf("value of %s is: %d\n",#exp,exp);

int adjOne(int *arr, int n) {
    loop(n - 1)
        if (abs(arr[i] - arr[i + 1]) != 1)
            return 0;
    return 1;
}

int main() {
    int n,count=0;
    scanf(" %d",&n);
    while(--n) {
        int temp = n,i=0;
        int *arr = (int*)calloc(100,sizeof(int));
        for(i=0;temp>0;i++) {
            arr[i] = temp%10;
            temp /= 10;
        }
        if(i==1 || adjOne(arr,i)) {
            count++;
            printf(" %d",n);
        }
    }
    printf(" 0 \ncount:%d\n",++count);
    return 0;
}
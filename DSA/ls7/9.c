#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define loop(a) for(int i=0;i<a;i++)

int digits(int x) {
    int digits = 0;
    while(x>0) {
        x /= 10;
        digits++;
    }
    return digits;
}

int power(int base, int pow) {
    int ans = 1;
    loop(pow)
        ans *= base;
    return ans;
}

int cmp(const void *a, const void *b) {
    int x = *((int*)a), y = *((int*)b);
    int xy = x*power(10,digits(y)) + y;
    int yx = y*power(10,digits(x)) + x;
    return yx-xy;
}

int main() {
    int n;
    scanf(" %d",&n);
    int arr[n];
    loop(n) {
        scanf(" %d",&arr[i]);
    }
    qsort(arr, n, sizeof(int), cmp);
    loop(n) {
        printf("%d",arr[i]);
    }printf("\n");
    return 0;
}
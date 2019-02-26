#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int maxA(int N) {
    int best[] = {0, 1, 2, 3, 4, 5, 6, 9, 12, 16, 20, 27, 36, 48, 64, 81};
    int q = N > 15 ? (N - 11) / 5 : 0;
    return best[N - 5*q] << 2 * q;
}

int main() {
    int n;
    scanf(" %d",&n);
    printf(" instant ans: %d\n",maxA(n));
    return 0;
}
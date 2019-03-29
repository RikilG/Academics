#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int nextNum(int num) {
    int divisors = 0, max;
    for(int i=1;i*i<=num;i++) {
        if(num%i==0){
            int temp = num/i;
            divisors++;
            max = (i>temp)?i:temp;
        }
    }
    if(divisors == 1)   return num-1;
    return max;
}

int main() {
    int n,num,moves;
    scanf(" %d",&n);
    while(n --> 0) {
        moves = 0;
        scanf(" %d",&num);
        while(num>0) {
            num = nextNum(num);
            moves++;
        }
        printf("Moves: %d\n",moves);
    }
    return 0;
}
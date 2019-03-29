#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stack[1000],minStack[1000],ts=-1,tms=-1;

void pop() {
    if(stack[ts]==minStack[tms])
        tms--;
    ts--;
}

void push(int x) {
    stack[++ts] = x;
    if(tms==-1 || minStack[tms]>x)
        minStack[++tms] = x;
}

void getMin() {
    printf("Min till now: %d\n",minStack[tms]);
}

int main() {
    printf("1) push\n2) pop\n3) get minimum\n0) quit\n");
    int x,temp;
    do {
        printf("Enter choice: ");
        scanf(" %d",&x);
        switch(x) {
            case 1: scanf(" %d",&temp);push(temp); break;
            case 2: pop(); break;
            case 3: getMin(); break;
            case 0: printf("bye\n");return 0;
            default:printf("Invalid choice\n");
        }
    }while(1);
    return 0;
}
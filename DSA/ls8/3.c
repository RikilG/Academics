#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stack[1000];
int tos=-1;

void push(char x) {
    stack[++tos]=x;
}

char pop() {
    tos--;
    return stack[tos+1];
}

char top() {
    return stack[tos];
}

int main() {
    char str[1000],ch;
    scanf("%[^\n]s",str);
    for(int i=0;str[i]!='\0';i++){
        ch = str[i];
        if(ch=='(' || ch=='{' || ch=='[')
            push(ch);
        else if( (ch==')' && top()=='(') || (ch=='}' && top()=='{') || (ch==']' && top()=='[') ) {
            if(tos==-1) {
                printf("False\n");
                return 0;
            }
            pop();
            continue;
        }
        else
            continue;
    }
    if(tos!=-1) {
        printf("False\n");
        return 0;
    }
    printf("True\n");
    return 0;
}
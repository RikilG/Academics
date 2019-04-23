//incomplete and long 
// because of trying to store bst in array.
#include<stdio.h>
#include<stdlib.h>
#define MAX 10000

int findNode(int bst[], int data) {
    for(int i=0;i<MAX;i++) {
        if(bst[i] == data)  return i;
    }
    return -1;
}

int main() {
    int n,temp,min,max;
    scanf(" %d",&n);
    int inputs[n][2], bst[MAX];
    for(int i=0;i<MAX;i++) bst[i] = -99999; // memset in style
    for(int i=0;i<n-1;i++)
        scanf(" %d %d",&inputs[i][0],&inputs[i][1]);
    scanf(" %d",&bst[0]);
    for(int j=0;j<n-1;j++) {
        for(int i=0;i<n-1;i++) {
            temp = findNode(bst,inputs[i][0]);
            if(temp!=-1) {
                if(inputs[i][0]<inputs[i][1])
                    bst[2*temp+2] = inputs[i][1];
                else
                    bst[2*temp+1] = inputs[i][1];
            }
        }
    }
    scanf(" %d %d",&min,&max);
    for(int i=0;i<MAX;i++) {
        if(bst[i]<min) {
            setright(bst,i);
        }
        else if(bst[i]>max) {
            setleft(bst,i);
        }
    }
    for(int i=0;i<MAX;i++) {
        if(bst[i]!=-99999)
            printf(" %d",bst[i]);
    }printf("\n");
    return 0;
}
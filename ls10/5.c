#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int heap[1000],len=0;

int insert(int no) {
    heap[len++] = no;
    int parent,temp;
    for(int i=len-1;i>0;i--) {
        parent = (i&1)?(i-1)/2:(i-2)/2;
        if(parent>=0 && heap[parent]<heap[i]) {
            temp = heap[i];
            heap[i] = heap[parent];
            heap[parent] = temp;
        }
    }
}

int main() {
    int n,temp;
    scanf(" %d",&n);
    for(int i=0;i<n;i++) {
        scanf(" %d",&temp);
        insert(temp);
    }
    for(int i=0;i<n;i++) {
        printf(" %d",heap[i]);
    }
    printf("\n");
    return 0;
}
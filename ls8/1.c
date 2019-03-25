#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000

int heap[2][MAX];
int len[2],n,count;
double median;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int delete(int no) {
    len[no]--;
    int data = heap[no][0];
    heap[no][0] = heap[no][ len[no] ];
    int parent = 0, lchild = 2*parent+1, rchild = 2*parent+2;
    while(lchild<len[no] && rchild<len[no]) {
        if((no==0)?heap[no][parent]>heap[no][lchild]:heap[no][parent]<heap[no][lchild]) {
            swap(&heap[no][parent],&heap[no][lchild]);
            parent = lchild;
        }
        else if((no==0)?heap[no][parent]>heap[no][rchild]:heap[no][parent]<heap[no][rchild]) {
            swap(&heap[no][parent],&heap[no][rchild]);
            parent = rchild;
        }
        else 
            break;
        lchild = 2*parent+1;
        rchild = 2*parent+2;
    }
    return data;
}

void insert(int no, int num) {
    int temp = len[no], parent = (temp&1)?(temp-1)/2:(temp-2)/2;
    heap[no][ len[no]++ ] = num;
    while(parent>=0 && ( (no==0)?heap[no][parent]>heap[no][temp]:heap[no][parent]<heap[no][temp] ) ) {
        swap(&heap[no][parent],&heap[no][temp]);
        temp = parent;
        parent = (temp&1)?(temp-1)/2:(temp-2)/2;
    }
}

int balanceHeaps() { //returns which heap is greater(signum func)
    if(len[0]-len[1]>1) {
        insert(1,delete(0));
    }
    else if(len[1]-len[0]>1) {
        insert(0,delete(1));
    }
    if(len[0]==len[1]) return 0;
    return ( (len[1]>len[0])?1:-1 );
}

double findMedian(int num) {
    if(num < heap[1][0]) { // if num is less than root of maxHeap
        insert(1,num);
    }
    else {
        insert(0,num);
    }
    int weight = balanceHeaps();
    if(weight==0)
        return (double)(heap[0][0] + heap[1][0])/2; // both heaps equal, find average as median
    return ( (weight>0)?heap[1][0]:heap[0][0] );
}

int main() {
    scanf(" %d",&n);
    while(n --> 0) {
        int num;
        scanf(" %d",&num);
        median = findMedian(num);
        printf("Median : %.3lf\n",median);
    }
    return 0;
}

/*
    Maxheap: heap[1] - represents numbers lesser than current median
*/
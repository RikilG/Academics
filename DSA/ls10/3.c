#include<stdio.h>
#define INF 99999

int heap[2][1000],len[2];

int max(int no, int a, int b) { if(heap[no][a]>heap[no][b]) return a; else return b; }
int min(int no, int a, int b) { if(heap[no][a]<heap[no][b]) return a; else return b; }

int swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int insert(int no, int var) {
    heap[no][ len[no]++ ] = var;
    int i = len[no]-1, parent = (i&1)?(i-1)/2:(i-2)/2;
    while(parent>=0 && (no==1)?heap[no][parent]<heap[no][i]:heap[no][parent]>heap[no][i]) {
        swap(&heap[no][parent], &heap[no][i]);
        i = parent;
        parent = (i&1)?(i-1)/2:(i-2)/2;
    }
}

int delete(int no) {
    int temp = heap[no][0];
    heap[no][0] = heap[no][ --len[no] ];
    int parent = 0, lchild=1, rchild=2, flag = 1;
    while(flag && lchild<len[no]) {
        flag = 0;
        if(no==0) { //min heap
            if(heap[no][parent] > heap[no][ min(no,lchild,rchild) ]) {
                flag = 1;
                swap(&heap[no][parent], &heap[no][ min(no,lchild,rchild) ]);
                parent = min(no,lchild,rchild);
            }
        }
        else if(no==1) { //max heap
            if(heap[no][parent] < heap[no][ max(no,lchild,rchild) ]) {
                flag = 1;
                swap(&heap[no][parent], &heap[no][ max(no,lchild,rchild) ]);
                parent = max(no,lchild,rchild);
            }
        }
        lchild = 2*parent+1; rchild = 2*parent+2;
    }
    return temp;
}

float balanceHeaps() {
    int temp = (len[0]-len[1]);
    if(temp>1)      insert(1,delete(0));
    else if(temp<-1)insert(0,delete(1));
    temp = len[0]-len[1];
    return (temp==0)?((float)(heap[0][0]+heap[1][0])/2):( (temp==1)?heap[0][0]:heap[1][0] );
}

float findMedian(int num) {
    if(num<heap[1][0]) insert(1,num);
    else insert(0,num);
    return balanceHeaps();
}

int main() {
    int n,temp;
    float median=INF;
    scanf(" %d",&n);
    for(int i=0;i<n;i++) {
        scanf(" %d",&temp);
        median = findMedian(temp);
        printf("Median: %.2f\n",median);
    }
    return 0;
}
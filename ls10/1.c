#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int heap[3][1000], len[3], n, k, temp;

int cmp(const void *a, const void *b) {
    return *((int*)a)-*((int*)b);
}

int max(int no, int a, int b) { if(heap[no][a]>heap[no][b]) return a; else return b; }

int swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int insert(int no, int var) {
    heap[no][ len[no]++ ] = var;
    int i = len[no]-1, parent = (i&1)?(i-1)/2:(i-2)/2;
    while(parent>=0 && heap[no][parent]<heap[no][i]) {
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
        if(heap[no][parent] < heap[no][ max(no,lchild,rchild) ]) {
            flag = 1;
            swap(&heap[no][parent], &heap[no][ max(no,lchild,rchild) ]);
            parent = max(no,lchild,rchild);
        }
        lchild = 2*parent+1; rchild = 2*parent+2;
    }
    return temp;
}

int findmax(int n, int arr[]) {
    int temp = arr[0];
    for(int i=1;i<n;i++) {
        if(arr[i]>temp) temp = arr[i];
    }
    return temp;
}

int main() {
    scanf(" %d %d",&n,&k);
    for(int i=0;i<n;i++) {
        scanf(" %d",&temp);
        insert(0, temp);
    }
    for(int i=0;i<n;i++) {
        scanf(" %d",&temp);
        insert(1, temp);
    }
    //logic
    int ans[2][1000], ptr[2]={0,0};
    for(int i=0;i*i<k;i++) {
        ans[0][ptr[0]++] = delete(0);
    }
    for(int i=0;i*i<k;i++) {
        ans[1][ptr[1]++] = delete(1);
    }
    for(int i=0;i<ptr[0];i++) {
        for(int j=0;j<ptr[1];j++) {
            insert(2, ans[0][i]+ans[1][j]);
        }
    }
    for(int i=0;i<k;i++) {
        printf(" %d",delete(2));
    }printf(" \n");
    return 0;
}
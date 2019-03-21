#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int *heap[2],n,len[2]={0},ele=0;
double median;

void arrange(int no) {
    int temp = len[no]-1, parent = (temp&1)?(temp-1)/2:(temp-2)/2;
    while(parent>=0 && ( (no==0)?heap[no][parent]>heap[no][temp]:heap[no][parent]<heap[no][temp] ) ) {
        int tmp = heap[n][parent];
        heap[no][parent] = heap[no][temp];
        heap[no][temp] = tmp;
        temp = parent;
        parent = (temp&1)?(temp-1)/2:(temp-2)/2;
    }
}

void insert(int x) {
    if(ele==0) {
        median = x;
    }
    else if(ele == 1) {
        if(x>median) {
            heap[0][ len[0]++ ] = median;
            heap[1][ len[1]++ ] = x;
        }
        else {
            heap[0][ len[0]++ ] = x;
            heap[1][ len[1]++ ] = median;
        }
        median = (median + x)/2;
    }
    else {
        if(x<median) {
            heap[1][ len[1]++ ] = x;
        }
        else {
            heap[0][ len[0]++ ] = x;
        }
        arrange(0);
        arrange(1);
        median = (ele&1)? ((len[0]>len[1])?heap[0][0]:heap[1][0]) :(heap[0][0]+heap[1][0])/2;
    }
    ele++;
}

int main() {
    scanf(" %d",&n);
    heap[0] = (int*)malloc(n*sizeof(int));
    heap[1] = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) {
        int temp;
        scanf(" %d",&temp);
        insert(temp);
        printf("median now: %lf\n",median);
    }
    return 0;
}
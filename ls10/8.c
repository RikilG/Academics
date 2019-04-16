#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct { int start, count, end; } Slot;

Slot findMaxSlot(int n, int arr[]) {
    Slot temp;
    temp.start = temp.count = temp.end = -1;
    for(int i=0;i<n;i++) {
        if(arr[i]!=0) continue;
        for(int j=i+1;j<n;j++) {
            if(arr[j]!=0) {
                if(j-i > temp.count) {
                    temp.count = j-i;
                    temp.start = i;
                    temp.end = j-1;
                }
                i = j;
                break;
            }
        }
    }
    return temp;
}

int main() {
    int n,p;
    scanf(" %d %d",&n,&p);
    int arr[n+1];
    memset(arr, 0, sizeof(arr));
    arr[n] = 99999;
    char wants[n+1];
    scanf(" %s",wants);
    for(int i=0;i<p;i++) {
        Slot max = findMaxSlot(n+1, arr);
        if(max.count & 1)  //odd no of slots
            arr[ max.start+(max.count-1)/2 ] = i+1;
        else {
            if(wants[i]=='R' || wants[i]=='r')
                arr[ max.start+(max.count)/2 ] = i+1;
            else
                arr[ max.start+(max.count)/2-1 ] = i+1;
        }
    }
    for(int i=0;i<n;i++) {
        printf(" %d",arr[i]);
    } printf("\n");
    return 0;
}
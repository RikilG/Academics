#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n, k=0;
char arr[50][50], temp[50];

void insert(char *temp) {
    for(int i=0;i<k;i++) {
        if(!strcmp(temp,&arr[i][1])) {
            arr[i][0]++;
            return;
        }
    }
    strcpy(&arr[k][1],temp);
    arr[k++][0] = 1;
}

int cmp(const void *a, const void *b) {
    return *((int*)b)-*((int*)a);
}

int main() {
    scanf(" %d",&n);
    for(int i=0;i<n;i++) {
        scanf(" %s",temp);
        insert(temp);
    }
    qsort(arr, k, sizeof(arr[0]), cmp);
    //print names
    for(int i=0;i<k;i++) {
        printf(" %d %s\n",arr[i][0],&arr[i][1]);
    }printf("\n");
    return 0;
}
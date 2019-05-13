#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define log(exp) printf("value of %s is: %d\n",#exp,exp);

int main() {
    int rows,cols,count = 0;
    scanf(" %d %d",&cols,&rows);
    int top[cols],adj[rows][cols],side[rows];
    memset(adj, 0, sizeof(adj));
    memset(side, 0, sizeof(side));
    for(int i=0;i<cols;i++) {
        scanf(" %d",&top[i]);
    }
    for(int j=0;j<cols;j++) {
        for(int i=0;i<top[j];i++) {
            adj[i][j] = 1;
            side[i]++;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(adj[i][j]==1 && top[j]>1 && side[i]>1) {
                top[j]--;
                side[i]--;
                adj[i][j] = 0;
                count++;
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf(" %d",adj[i][j]);
        }printf("\n");
    }
    printf("count: %d\n",count);
    return 0;
}
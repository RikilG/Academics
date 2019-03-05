#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int rows,cols,count = 0,total=0;
    scanf(" %d %d",&cols,&rows);
    int top[cols],adj[rows][cols],side[rows];
    int sol[rows][cols];
    memset(adj, 0, sizeof(adj));
    memset(sol, 0, sizeof(sol));
    memset(side, 0, sizeof(side));
    for(int i=0;i<cols;i++) {
        scanf(" %d",&top[i]);
        total+=top[i];
    }
    for(int j=0;j<cols;j++) {
        for(int i=0;i<top[j];i++) {
            adj[i][j] = 1;
            side[i]=1;
        }
        top[j]=1;
    }
    for(int j=0;j<cols;j++) {
        for(int i=rows-1;i>=0;i--) {
            if(adj[i][j] && top[j] && side[i]) {
                top[j] = 0;
                side[i]=0;
                sol[i][j]=1;
                count++;
            }
        }
    }
    for(int j=0;j<cols;j++) {
        for(int i=rows-1;i>=0;i--) {
            if(adj[i][j] && top[j]) {
                top[j] = 0;
                sol[i][j]=1;
                count++;
            }
            else if(adj[i][j] && side[i]) {
                side[i]=0;
                sol[i][j]=1;
                count++;
            }
        }
    }
    //print
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            printf(" %d",sol[i][j]);
        }printf("\n");
    }
    printf("Answer: %d\n",total-count);
    return 0;
}
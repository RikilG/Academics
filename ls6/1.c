#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count = 1;

int cmp(const void *a, const void *b) {
    return *((int*)a)-*((int*)b);
}

int dfs(int start, int n, int adj[][n], int visited[]) {
    if(visited[start]) return 0;
    visited[start] = count;
    for(int i=0;i<n;i++)
        if(adj[start][i] && !visited[i])
            dfs(i,n,adj,visited);
}

int main() {
    int n;
    scanf(" %d",&n);
    int arr[n],adj[n][n],temp[n];
    for(int  i = 0; i < n; i++)
        scanf(" %d",&arr[i]);
    for(int i = 0; i < n; i++)
        for(int j=0;j<n;j++)
            scanf(" %d",&adj[i][j]);
    int visited[n];
    memset(visited, 0, sizeof(visited));
    for(int i=0;i<n;i++,count++)
        dfs(i,n,adj,visited);
    for(int i=1;i<=count;i++) {
        int c=0;
        for(int j=0;j<n;j++) {
            if(visited[j] == i)
                temp[c++] = arr[j];
        }
        qsort(temp, c, sizeof(int), cmp);
        for(int j=0,c=0;j<n;j++) {
            if(visited[j] == i)
                arr[j] = temp[c++];
        }
    }
    //print
    for(int i=0;i<n;i++) {
        printf(" %d",arr[i]);
    }printf(" \n");
    return 0;
}
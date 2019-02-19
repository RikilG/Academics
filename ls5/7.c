#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count,countmax,countmaxnode;

int dfs(int n, int start, int adj[][n], int visited[]) {
    if(visited[start] != 0) {
        return 0;
    }
    visited[start] = 1;
    if(count==countmax){
        countmaxnode = start;
        return 0;
    }
    count++;
    for(int i=0;i<n;i++) {
        if(adj[start][i]>0 && visited[i]==0) {
            dfs(n,i,adj,visited);
        }
    }
    count--;
    return 0;
}

int findNode(int len, int start, int n, int adj[][n]) {
    if(len == 0)
        return start;
    count = 0;countmax = len;countmaxnode = 0;
    int visited[n];memset(visited, 0, sizeof(visited));
    dfs(n, start, adj, visited);
    return countmaxnode;
}

void formCycle(int n, int adj[][n], int dist[]) {
    int arr[2],j=0;
    for(int i=0;i<n;i++) {
        if(dist[i] == 1 && j<2)
            arr[j++] = i;
    }
    if(j>=2) {
        adj[ arr[0] ][ arr[1] ] = 1;
        adj[ arr[1] ][ arr[0] ] = 1;
    }
    else if(j==1) {
        for(int i=0;i<n;i++)
            if(dist[i] == 2) {
                arr[1] = i;
                adj[ arr[0] ][ arr[1] ] = 1;
                adj[ arr[1] ][ arr[0] ] = 1;
            }
    }
    return;
}

int main() {

    int n, node, max = 0;
    scanf(" %d",&n);
    int dist[n];
    int adj[n][n];
    memset(adj, 0, sizeof(adj));
    for(int i=0;i<n;i++) {
        scanf(" %d",&dist[i]);
        if(dist[i] == 0)
            node = i;
        if(dist[i] > max)
            max = dist[i];
    }
    int len = 1;
    while(len<=max) {
        for(int i = 0; i < n; i++) {
            if(dist[i] == len) {
                int temp = findNode(len-1,node,n,adj);
                adj[temp][i] = 1;
                adj[i][temp] = 1;
            }
        }
        len++;
    }
    if(max>0 && n>2) {
        formCycle(n, adj, dist);
    }
    //printing
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf(" %d",adj[i][j]);
        }printf("\n");
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(adj[i][j]>0) {
                printf(" %d %d\n",i+1,j+1);
                adj[i][j] = 0;
                adj[j][i] = 0;
            }
        }
    }

    return 0;
}
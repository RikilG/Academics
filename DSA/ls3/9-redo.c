// 9.c
#include<stdio.h>
#include<string.h>

int dfs(int start, int n, int adj[n][n], int visited[n]) {
    if(visited[start] == 0) {
        return 0;
    }
    visited[start] = 1;
    for(int i=0;i<n;i++) {
        if(adj[start][i] > 0) {
            dfs(i,n,adj,visited);
        }
    }
    return 0;
}

int reachable(int n, int visited[n]) {
    for(int i=0;i<n;i++) {
        if(visited[i] != 1) {
            return 0;
        }
    }
    return 1;
}

int main() {

    int n,e;
    scanf(" %d %d",&n,&e);
    int adj[n][n];
    memset(adj, 0, sizeof(adj));
    for(int i=0;i<e;i++) {
        int a,b;
        scanf(" %d %d",&a,&b);
        adj[a][b] = 1;
    }
    int visited[n];
    for(int i=0;i<n;i++) {
        memset(visited, 0, sizeof(visited));
        dfs(i,n,adj,visited);
        for(int i=0;i<n;i++) {
            printf("%d ",visited[i]);
        }printf("\n");
        if(reachable(n, visited)) {
            printf("%d\n",i);
        }
    }

	return 0;
}

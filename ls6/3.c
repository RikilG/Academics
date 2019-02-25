#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int catsVisited = 0,m,count=0;

int dfs(int start, int n, int adj[][n], int cats[], int visited[]) {
    int flag = 0;
    if(visited[start]) {
        return 0;
    }
    visited[start] = 1;
    if(cats[start]) catsVisited++;
    if(catsVisited > m) {
        catsVisited--;
        return 0;
    }
    for(int i=0;i<n;i++) {
        if(adj[start][i] && !visited[i]) {
            flag = 1;
            adj[start][i] = 0;
            adj[i][start] = 0;
            dfs(i,n,adj,cats,visited);
            adj[start][i] = 1;
            adj[i][start] = 1;
        }
    }
    if(cats[start]) catsVisited--;
    if(flag == 0) {
        count++;
        printf("Reached node : %d\n",start);
    }
}

int main() {
    int n;
    scanf(" %d %d", &n,&m);
    int cats[n];
    for(int i=0;i<n;i++) scanf(" %d",&cats[i]);
    int adj[n][n];
    memset(adj, 0, sizeof(adj));
    for(int i=0;i<n-1;i++) {
        int a,b;
        scanf(" %d %d",&a,&b);
        a--;b--;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    int visited[n];
    memset(visited, 0, sizeof(visited));
    dfs(0, n, adj, cats, visited);
    printf("count:%d\n",count);
    return 0;
}
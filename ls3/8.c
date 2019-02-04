//8.c
#include<stdio.h>
#include<string.h>

int dfs(int start, int n, int adj[n][n], int visited[n]) {
    if(visited[start] == 1) {
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

int main() {

    int n,e,tc;
    printf("Enter nodes and edges : ");
    scanf(" %d %d",&n,&e);
    int adj[n][n];
    memset(adj, 0, sizeof(adj));
    for(int i=0;i<e;i++) {
        int a,b;
        scanf(" %d %d",&a,&b);
        adj[a][b] = 1;
    }
    scanf(" %d",&tc);
    int cases[tc][2];
    for(int i=0;i<tc;i++) {
        int a,b;
        scanf(" %d %d",&a,&b);
        cases[i][0] = a;
        cases[i][1] = b;
    }
    int visited[n];
    for(int i=0;i<tc;i++) {
        memset(visited, 0, sizeof(visited));
        dfs(cases[i][0], n, adj, visited);
        if(visited[ cases[i][1] ] == 1) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }

	return 0;
}

#include<string.h>
#include<stdio.h>

int nextVisit(int n, int visited[n]) {
    for(int i=0;i<n;i++) {
        if(visited[i] == 0) 
            return i;
    }
    return -1;
}

int dfs(int start, int n, int adj[n][n], int visited[n]) {
    if(visited[start] != 0) {
        return 0;
    }
    printf("%d ",start);
    visited[start] = 1;
    for(int i=0;i<n;i++) {
        if(adj[start][i] > 0) {
            dfs(i, n, adj, visited);
        }
    }
}

int main() {

    int n;
    printf("Enter no of vertices : ");
    scanf(" %d",&n);
    int f[n];
    printf("Enter factors : \n");
    for(int i=0;i<n;i++) {
        scanf(" %d",&f[i]);
    }
    int adj[n][n];
    memset(adj, 0, sizeof(adj));
    printf("Enter threshold value : ");
    int gamma;
    scanf(" %d",&gamma);
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int diff = f[i] - f[j];
            diff = (diff>0)?diff:-diff;
            if(diff>=gamma) {
                adj[i][j] = 1;
                adj[j][i] = 1;
            }
        }
    }
    int visited[n];
    memset(visited, 0, sizeof(visited));
    while(nextVisit(n,visited) != -1) {
        dfs(nextVisit(n,visited), n, adj, visited);
        printf("\n");
    }

    return 0;
}

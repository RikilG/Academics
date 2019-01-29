#include<string.h>
#include<stdio.h>
#define INF 9999

int flag = 0;

int path(int n, int u, int v, int next[n][n]) {
    if(next[u][v] == INF) 
        return 0;
    flag = 1;
    int path[500];
    memset(path, 0, sizeof(path));
    int i=0;
    path[i++] = u;
    do{
        u = next[u][v];
        path[i++] = u;
    }while(u != v);
    for(int j=0;j<i;j++) {
        printf("%d ",path[j]);
    }
    printf("\n");
    return 0;
}

int main() {
    int n;
    printf("Enter no of nodes : ");
    scanf(" %d",&n);
    int adj[n][n];
    int min[n][n];
    int next[n][n];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) next[i][j] = INF;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf(" %d",&adj[i][j]);
            if(adj[i][j] > 0) next[i][j] = j;
            if(adj[i][j] == 0 /*&& i!=j*/) adj[i][j] = INF;
        }
    }
    memcpy(min, adj, sizeof(min));
    //logic floyd-warshall algo
    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(((min[i][k] == INF || min[k][j] == INF)?INF:min[i][k] + min[k][j]) < min[i][j]) {
                    min[i][j] = min[i][k] + min[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
    printf("minimum cycle weight for each node : \n");
    int m = INF;
    for(int i=0;i<n;i++) {
        if(min[i][i] < m) {
            m = min[i][i];
        }
    }
    for(int i=0;i<n;i++) {
        if(min[i][i] == m) {
            path(n,i,i,next);
        }
    }
    if(flag == 0)
        printf("no cycle found!!!\n");
	return 0;
}

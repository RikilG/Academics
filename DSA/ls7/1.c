//form codeforces 813c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int bdist[9999],adist[9999];
int n,x;

int dfs(int start, int parent, int adj[][n], int dist[]) {
    dist[start] = dist[parent] + 1;
    for(int i=0;i<n;i++)
        if(i!=parent && adj[start][i])
            dfs(i,start,adj,dist);
}

int main() {
    scanf(" %d %d",&n,&x);
    x--;
    int adj[n][n],ans=0;
    memset(adj, 0, sizeof(adj));
    for(int i=0;i<n-1;i++) {
        int a,b;
        scanf(" %d %d",&a,&b);
        a--;b--;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    bdist[0] = adist[0] = -1;
    dfs(0,0,adj,adist);
    dfs(x,0,adj,bdist);
    for(int i=0;i<n;i++) {
        if(bdist[i]<adist[i]) {
            ans = (ans>2*adist[i])?ans:2*adist[i];
        }
    }
    printf("no of moves: %d\n",ans);
    return 0;
}
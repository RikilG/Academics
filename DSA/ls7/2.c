#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INF 99999

int num,bin[33];

void genBin() {
    int temp = num--;
    memset(bin, 0, sizeof(bin));
    for(int i=0;temp>0;i++) {
        bin[i] = temp&1;
        temp = temp>>1;
    }
}

int chkSecurity(int n,int adj[][n]) {
    int dist[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==j) dist[i][j]=0;
            else if(adj[i][j]==0) dist[i][j] = INF;
            else dist[i][j] = adj[i][j];
        }
    }
    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    int visited[n];memset(visited, 0, sizeof(visited));
    for(int i=0;i<n;i++) {
        if(bin[i]) {
            visited[i] = 1;
            for(int j=0;j<n;j++) {
                if(i!=j && dist[i][j]!=INF && dist[j][i]!=INF) {
                    visited[j] = 1;
                    // printf("loop: %d %d\n",i+1,j+1);
                }
            }
        }
    }
    for(int i=0;i<n;i++)
        if(!visited[i])
            return 0;
    return 1;
}

int main() {
    int n,m,minCost=INF,paths=0;
    scanf(" %d",&n);
    num = (1<<n)-1;
    int cost[n],adj[n][n];
    memset(adj, 0, sizeof(adj));
    for(int i=0;i<n;i++)
        scanf(" %d",&cost[i]);
    scanf(" %d",&m);
    for(int i=0;i<m;i++) {
        int a,b;
        scanf(" %d %d",&a,&b);
        a--;b--;
        adj[a][b] = 1;
    }
    while(num>0) {
        int tmpCost=0;
        genBin();
        if(chkSecurity(n,adj)){
            for(int i=0;i<n;i++) {
                if(bin[i])
                    tmpCost+=cost[i];
            }
            if(tmpCost<minCost) {
                minCost = tmpCost;
                paths = 1;
            }
            else if(tmpCost==minCost)
                paths++;
        }
    }
    printf("MinCost:%d\nPaths:%d\n",minCost,paths);
    return 0;
}
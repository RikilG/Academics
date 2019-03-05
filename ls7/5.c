#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define log(exp) printf("value of %s is: %d\n",#exp,exp);
#define INF 99999

int calcDist(int a, int b, int n, int adj[][n]) {
    int dist[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==j) dist[i][j] = 0;
            else if(adj[i][j]==0) dist[i][j] = INF;
            else dist[i][j] = adj[i][j];
        }
    }
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    return dist[a][b];
}

int main() {
    int n,m,s,t,count=0,actDist;
    scanf(" %d %d %d %d",&n,&m,&s,&t);
    s--;t--;
    int adj[n][n];
    memset(adj, 0, sizeof(adj));
    for(int i=0;i<m;i++) {
        int a,b;
        scanf(" %d %d",&a,&b);
        a--;b--;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    actDist = calcDist(s,t,n,adj);
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(i==j) continue;
            else if(adj[i][j]==1) continue;
            else {
                adj[i][j] = 1;adj[j][i] = 1;
                if(calcDist(s,t,n,adj)==actDist) {
                    printf(" connection: %d %d\n",i+1,j+1);
                    count++;
                }
                adj[i][j] = 0;adj[j][i] = 0;
            }
        }
    }
    printf("possibilites: %d\n",count);
    return 0;
}
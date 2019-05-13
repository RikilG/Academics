#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int arr[1000][1000],n,m,minCost=99999,cost=0,a,b,c;

int dfs(int start, int parent, int visited[]) {
    if(visited[start]) return 0;
    if(start==b && c>=-1) {
        if(cost < minCost) minCost = cost;
        return 0;
    } 
    visited[start] = 1;
    if(c<0) return 0;
    for(int i=0;i<n;i++) {
        if(i!=parent && arr[start][i] && !visited[i]) {
            c--;
            cost += arr[start][i];
            dfs(i,start,visited);
            cost -= arr[start][i];
            c++;
        }
    }
}

int main() {
    scanf(" %d %d",&n,&m);
    memset(arr, 0, sizeof(arr));
    for(int i=0;i<m;i++) {
        scanf(" %d %d %d",&a,&b,&c);
        arr[a][b] = c;
        arr[b][a] = c;
    }
    int tc, visited[n];
    scanf(" %d",&tc);
    while(tc--) {
        minCost = 99999;
        cost = 0;
        scanf(" %d %d %d",&a,&b,&c);
        memset(visited, 0, sizeof(visited));
        dfs(a,a,visited);
        printf("cost: %d\n",minCost);
    }
    return 0;
}
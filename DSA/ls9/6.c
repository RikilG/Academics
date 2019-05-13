#include<stdio.h>
#include<string.h>
#include<limits.h>

int n,arr[1000][1000];

int findPath(int x, int y, int level, int visited[][n]) {
    if(x==n-1 && y==n-1) return 1;
    if(x<0 || x>=n || y<0 || y>=n) return 0;
    visited[x][y] = 1;
    int ans = 0;
    if(arr[x+1][y]<=level && !visited[x+1][y]) ans = (ans>0)?1:findPath(x+1,y,level,visited);
    if(arr[x][y-1]<=level && !visited[x][y-1]) ans = (ans>0)?1:findPath(x,y-1,level,visited);
    if(arr[x-1][y]<=level && !visited[x-1][y]) ans = (ans>0)?1:findPath(x-1,y,level,visited);
    if(arr[x][y+1]<=level && !visited[x][y+1]) ans = (ans>0)?1:findPath(x,y+1,level,visited);
    return ans;
}

int isPath(int level) {
    int temp[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            temp[i][j] = (arr[i][j]>level)?arr[i][j]:level;
        }
    }
    int visited[n][n];
    memset(visited, 0, sizeof(visited));
    return findPath(0,0,level,visited);
}

int main() {
    scanf(" %d",&n);
    int min = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf(" %d",&arr[i][j]);
        }
    }
    while(1) {
        if(isPath(min++)) break;
    }
    printf("min time: %d\n",--min);
    return 0;
}
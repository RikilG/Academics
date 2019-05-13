#include<string.h>
#include <stdio.h>

int count=0,max = 0;

int dfs(int starti, int startj, int n, int adj[n][n], int visited[n][n]) {
    if(!(starti>=0 && startj>=0) || visited[starti][startj] != 0) {
        //printf("returning fun, starti=%d, startj=%d, visited[starti][startj]=%d\n",starti,startj,visited[starti][startj]);
        //printf("val1 = %d\n",!(starti>=0 && startj>=0));
        //printf("val2 = %d\n",visited[starti][startj]);
        return 0;
    }
    if(starti>=n || startj>=n) return 0;
    visited[starti][startj] = 1;
    count++;
    if(adj[starti+1][startj]>0 && starti+1>=0 && startj>=0)
         dfs(starti+1,startj,n,adj,visited);
    if(adj[starti+1][startj+1]>0 && starti+1>=0 && startj+1>=0)
        dfs(starti+1,startj+1,n,adj,visited);
    if(adj[starti+1][startj-1]>0 && starti+1>=0 && startj-1>=0)
        dfs(starti+1,startj-1,n,adj,visited);
    if(adj[starti-1][startj]>0 && starti-1>=0 && startj>=0)
        dfs(starti-1,startj,n,adj,visited);
    if(adj[starti-1][startj+1]>0 && starti-1>=0 && startj+1>=0)
        dfs(starti-1,startj+1,n,adj,visited);
    if(adj[starti-1][startj-1]>0 && starti-1>=0 && startj-1>=0)
        dfs(starti-1,startj-1,n,adj,visited);
    if(adj[starti][startj+1]>0 && starti>=0 && startj+1>=0)
        dfs(starti,startj+1,n,adj,visited);
    if(adj[starti][startj-1]>0 && starti>=0 && startj-1>=0)
        dfs(starti,startj-1,n,adj,visited);
    return 0;
}

int main()
{
    int n;
    printf("Enter side of matrix : ");
    scanf(" %d",&n);
    printf("Enter matrix");
    int adj[n][n];
    int final[n][n];
    int visited[n][n];
    memset(visited, 0, sizeof(visited));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf(" %d",&adj[i][j]);
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(adj[i][j] > 0) {
                for(int i=0;i<n;i++) for(int j=0;j<n;j++) visited[i][j] = 0;
                count = 0;
                dfs(i,j,n,adj,visited);
                if(count>max) {
                    max = count;
                    memcpy(final,visited,sizeof(final));
                }
            }
        }
    }
    printf("max = %d\n",max);
    if(max == 0) {
        printf("No one's in given matrix\n");
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%d ",final[i][j]);
        }printf("\n");
    }
    return 0;
}

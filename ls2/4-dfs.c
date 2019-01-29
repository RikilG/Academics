#include<string.h>
#include<stdio.h>
#define MAX 500

int parentptr = -1;
int usedColors = 1;

int dfs(int start, int n, int adj[][MAX], int visited[n], int parent[n], int color[n]) {
    if (visited[start] != 0) {
        return 0;
    }
    //printf("init start = %d, visited[start] = %d\n",start,visited[start]);
    visited[start] = 1;
    for(int i=0;i<n;i++) {
        //printf("i = %d, visited[i] = %d, adj[start][i] = %d\n",i,visited[i],adj[start][i]);
        if(adj[start][i] > 0 && i!= parent[parentptr]) {
            if(visited[i] != 0) {
                //printf("parent[parentptr] = %d\n",parent[parentptr]);
                printf("Found Loop : ");
                if(color[i] == color[start]) {
                    if(color[start] <= usedColors) color[i] = usedColors+1;
                    usedColors++;
                }
                int ptr = parentptr;
                while(parent[ptr] != i)
                    ptr--;
                while(ptr!=parentptr+1)
                    printf("%d ",parent[ptr++]);
                printf("%d %d\n",start,i);
                continue;
            }
            color[i] = 1-color[start];
            if(usedColors == 1) usedColors++;
            parent[++parentptr] = start;
            dfs(i, n, adj, visited, parent,color);
            parentptr--;
        }
    }
    //printf("done = %d\n",start);
    visited[start] = 2;
}

int main() {

    int n = 1;
    int adj[MAX][MAX];
    memset(adj, 0, sizeof(adj));
    printf("Press any alphabet to stop inputs\n");
    int x,y,z;
    while(scanf("%d %d %d",&x,&y,&z) == 3) {
        if(y!=0) adj[x][y] = 1;
        if(z!=0) adj[x][z] = 1;
        n++;
    }
    printf("Input complete\n");
    int visited[n];
    int parent[n];
    int color[n];
    memset(visited, 0, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    memset(color, 0, sizeof(visited));
    dfs(1,n,adj,visited,parent,color);
    //print colors
    printf("No of colors used : %d\n",usedColors);
    printf("colors used are : \n");
    for(int i=1;i<n;i++) {
        printf("%d ",i);
    }printf("\n");
    for(int i=1;i<n;i++){
        printf("%d ",color[i]);
    }printf("\n");

	return 0;
}

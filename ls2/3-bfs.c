#include<stdio.h>
#include<string.h>
#define MAX 1000

const int E = 0, R = 1, B = 2; //Empty Red Blue
int qs = 0, qe = 0, flag = 0;
int queue[MAX];

int nextVisit(int n, int visited[n]) {
    for(int i=0;i<n;i++) {
        if(visited[i]!= 1)
            return i;
    }
    return -1;
}

int bfs(int n, int adj[n][n], int color[n], int visited[n]) {
    int start = queue[qs];
    if(visited[start] != E) return 0;
    visited[start] = 1;
    //printf("in node : %d\n", start);
    for(int i=0;i<n;i++) {
        if(adj[start][i] > 0) {
            if(color[i] == E) {
                color[i] = 3-color[start];
                queue[qe++] = i;
            }
            else if(color[i] == 3-color[start]) {
            }
            else {
                flag = 1;
                break;
            }
        }
    }
    return 0;
}

int main() {

    int n;
    printf("Enter no of nodes : ");
    scanf(" %d",&n);
    int adj[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf(" %d",&adj[i][j]);
        }
    }
    int color[n];
    int visited[n];
    memset(color, 0, sizeof(color));
    memset(visited, 0, sizeof(visited));
    while(nextVisit(n,visited) != -1) {
        queue[qe++] = nextVisit(n,visited);
        while(qs!=qe) {
            bfs(n, adj, color, visited);
            qs++;
        }
    }
    if(flag == 0) {
        printf("Graph is bipartite.\n");
    }
    else {
        printf("Graph is not bipartite\n");
    }
    return 0;
}

#include<string.h>
#include<stdio.h>
#define MAX 555

int adj[MAX][MAX];
int loops[MAX][MAX];
int visited[MAX];
int path[MAX];
int pathp=0;
int loopp=0;
int n;

int dfs(int start) {
    if(visited[start] != 0) {
        return 0;
    }
    visited[start] = 1;
    //printf("in node=%d\n",start);
    path[pathp++] = start;
    for(int i=0;i<n;i++) {
        if(adj[start][i] > 0 && i!=start && i!=path[pathp-2]) {
            if(visited[i] == 1) {
                int tmp = pathp-2;
                while(path[tmp]!=i)
                    tmp--;
                int looptmp = 0;
                int loopsum = 0;
                path[pathp] = i;
                while(tmp!=pathp) {
                    loops[loopp][++looptmp] = path[tmp];
                    loopsum += adj[ path[tmp] ][ path[tmp+1] ];
                    //printf("%d ",path[tmp]);
                    //printf("%d ",loops[loopp][looptmp-1]);
                    tmp++;
                }
                loops[loopp][++looptmp] = i;
                loops[loopp][++looptmp] = MAX;
                loops[loopp][0] = loopsum;
                loopp++;
                //printf("%d\n",i);
            }
            else {
                dfs(i);
            }
        }
    }
    pathp--;
    visited[start] = 2;
}

int main() {

    //taking inputs
    printf("Enter no of nodes : ");
    scanf(" %d",&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf(" %d",&adj[i][j]);
        }
    }
    //logic
    dfs(0);
    //finding min of all loops
    int min = 9999;
    for(int i=0;i<loopp;i++) {
        if(loops[i][0] < min)
            min = loops[i][0];
    }
    //printing min of loops
    printf("out of loop 1 min=%d\n",min);
    for(int i=0;i<loopp;i++) {
        if(loops[i][0] == min) {
            int tmp = 1;
            while(loops[i][tmp] != MAX) {
                printf("%d ", loops[i][tmp]);
                tmp++;
            }
            printf("\n");
        }
    }

	return 0;
}

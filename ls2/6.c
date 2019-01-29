#include<string.h>
#include<stdio.h>

int count = 0;
int seqp = 0;
const int Empty = 0;
const int Proc = -1;
const int Visited = 1;
int flag = 0;

int nextVisit(int n, int visited[n]) {
    for(int i=0;i<n;i++) {
        if(visited[i]==Empty) {
            return i;
        }
    }
    return -1;
}

int dfs(int start, int n, int adj[n][n], int visited[n], int seq[n][n]) {
    if(visited[start] != Empty) {
        return 0;
    }
    //printf("%d ", start);
    seq[count][seqp++] = start;
    visited[start] = Proc;
    for(int i=0;i<n;i++) {
        if(adj[start][i] > 0) {
            dfs(i, n, adj, visited, seq);
        }
    }
    visited[start] = Visited;
    return 0;
}

int main() {
    //taking inputs
    int n,e;
    printf("Enter no of nodes : ");
    scanf(" %d",&n);
    printf("Enter no of edges : ");
    scanf(" %d",&e);
    int adj[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf(" %d",&adj[i][j]);
        }
    }
    //logic
    //forming edges
    int end[e][e];
    int edges[e][3];
    memset(edges, 0, sizeof(edges));
    memset(end, 0, sizeof(end));
    //printf("n = %d, e = %d, \n",n,e);
    for(int i=0;i<e;i++) {
        edges[i][2] = i;
    }
    for(int i=0,k=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            if(adj[i][j] > 0) {
                edges[k][0] = i;
                edges[k][1] = j;
                //printf("k = %d, edges[k][0] = %d, edges[k][1] = %d \n",k,edges[k][0],edges[k][1]);
                k++;
            }
        }
    }
    //forming end matrix
    for(int i=0;i<e;i++) {
        for(int j=i+1;j<e;j++) {
            if(edges[i][0] == edges[j][0] || edges[i][0] == edges[j][1] || edges[i][1] == edges[j][0] || edges[i][1] == edges[j][1]) {
                end[edges[i][2]][edges[j][2]] = 1;
                end[edges[j][2]][edges[i][2]] = 1;
            }
        }
    }
    int visited[e];
    for(int i=0;i<e;i++) {
        //printf("Removed vertex : %d\n", i);
        //creating new adj matrix without node i
        int adj2[e][e];
        int seq[e][e];
        memset(seq, 0, sizeof(seq));
        memset(visited, 0, sizeof(visited));
        memcpy(adj2, end, sizeof(adj2));
        for(int j=0;j<e;j++) {
            adj2[i][j] = 0;
            adj2[j][i] = 0;
        }
        //prints disconnected graphs
        count = 0;
        while(nextVisit(e, visited)!=-1) {
            seqp = 0;
            dfs(nextVisit(e, visited), e, adj2, visited, seq);
            seq[count][seqp] = 9999;
            count += 1;
        }
        if(count > 2) {
            flag = 1;
            for(int i=0;i<count;i++) {
                for(int j=0;seq[i][j] != 9999;j++) {
                    printf("%d ",seq[i][j]);
                }
                printf("\n");
            }
        }
    }
    if(flag == 0)
        printf("No such vertex exists\n");
    return 0;
}

    //printf("Edges set : \n");
    //for(int i=0;i<e;i++) {
    //    for(int j=0;j<3;j++) {
    //        printf("%d ",edges[i][j]);
    //    }
    //    printf("\n");
    //}

    ////print end matrix
    //printf("End matrix : \n");
    //for(int i=0;i<e;i++) {
    //    for(int j=0;j<e;j++) {
    //        printf("%d ",end[i][j]);
    //    }
    //    printf("\n");
    //}

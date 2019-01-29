#include<stdio.h>

int dfs(int start, int n, int e, int adj[n][n],int visited[n]) {
	if(visited[start]==1) {
		return 0;
	}
	visited[start] == 1;
	for(int j=0;j<n;j++) {
		if(adj[start][j]!=0) {
			dfs(j,n,e,adj);
		}
	}
}

int main() {

	//taking input as adjacency matrix
	int n,e;
	printf("enter no of nodes : ");
	scanf(" %d",&n);
	printf("enter no of edges : ");
	scanf(" %d",&e);
	int adj[n][n];
	int visited[n];
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			scanf(" %d",&adj[i][j]);
		}
	}

	return 0;
}

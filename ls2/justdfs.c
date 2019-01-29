#include<stdio.h>
#include<string.h>

int dfs(int start, int n, int adj[n][n], int visited[n]) { // 0=untouched -1=processing 1=done
	//printf("    In node=%d\n",start);
	if(visited[start]==1) {
		return 0;
	}
	visited[start] = -1;
	for(int j=0;j<n;j++) {
		if(adj[start][j]>0) {
			//to delete the traversed path, remove it from adj matrix
			adj[start][j] = 0;
			adj[j][start] = 0;
			dfs(j,n,adj,visited);
			adj[start][j] = 1;
			adj[j][start] = 1;
		}
	}
	visited[start] = 1;
	return 0;
}

int main() {
	//taking input as adjacency matrix
	int n;
	printf("enter no of nodes : ");
	scanf(" %d",&n);
	printf("input adjacency matrix : \n");
	int adj[n][n];
	int visited[n];
	memset(visited, 0, sizeof(visited));
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			scanf(" %d",&adj[i][j]);
		}
	}
	//taking input as edges
	int n,e;
	printf("Enter nodes and edges : ");
	scanf(" %d %d",&n,&e);
	int adj[n][n];
	int visited[n];
	memset(adj, 0, sizeof(adj));
	memset(visited, 0, sizeof(visited));
	printf("Enter all edge connections : \n");
	for(int i=0;i<e;i++) {
		int a,b;
		scanf(" %d %d",&a,&b);
		adj[a][b] = 1;
		adj[b][a] = 1;
	}
	//calling dfs
	for(int i=0;i<n;i++) {
		//make some variables 0 here
		//memset(visited, 0, sizeof(visited));
		dfs(i,n,adj,visited);
	}
	return 0;
}

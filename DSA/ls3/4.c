#include<stdio.h>
#include<string.h>

int count = 0;
int n,x,y;
int flag = 0;
int starting = 0, xpassed = 0;

int dfs(int start, int end, int adj[n][n], int visited[n]) {
	if(visited[start] != 0) {
		return 0;
	}
	if(start == x) xpassed = 1;
	if(start == y && xpassed == 1) {
		xpassed = 0;
		return 0;
	}
	visited[start] = 1;
	count++;
	//printf("in node : %d\n",start);
	if(start == end) {
		printf("dist b/w %d and %d is : %d\n",starting,end,count-1);
		flag = 1;
		return 0;
	}
	for(int i=0;i<n && flag==0;i++) {
		if(adj[start][i] > 0 && i!=starting && visited[i] == 0) {
			dfs(i,end,adj,visited);
		}
	}
	count--;
	xpassed = 0;
}

int main() {
	
	scanf(" %d %d %d",&n,&x,&y);
	x--;y--;
	int adj[n][n];
	memset(adj, 0, sizeof(adj));
	for(int i=0;i<n-1;i++) {
		int a,b;
		scanf(" %d %d",&a,&b);
		a--;b--;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}
	int visited[n];

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			//printf("for node %d %d\n",i,j);
			memset(visited, 0, sizeof(visited));
			count = 0;
			xpassed = 0;
			flag = 0;
			starting = i;
			if(j!=i)
				dfs(i,j,adj,visited);
		}
	}

	return 0;
}

#include<string.h>
#include<stdio.h>
#define MAX 200

const int E = 0, P = 1, V = 1;
int qs = 0, qe = 0;// queue start ,queue end

int bfs(int start, int n, int adj[n][n], int visited[n], int queue[MAX], int level[n]) {
	if(visited[start] != E) {
		if(qs>=qe){
			return 0;
		}
		bfs(queue[++qs], n, adj, visited, queue,level);
		return 0;
	}
	visited[start] = P;
	for(int i=0;i<n;i++) {
		if(adj[start][i] > 0 && visited[i] == E) {
			queue[++qe] = i;
			level[i] = level[start]+1;
		}
	}
	visited[start] = V;
	bfs(queue[++qs], n, adj, visited, queue,level);
	return 0;
}

int main() {
	//taking input
	int m,n;
	printf("enter no of cities : ");
	scanf(" %d",&n);
	int adj[n][n];
	memset(adj, 0, sizeof(adj));
	for(int i=0;i<n-1;i++) {
		int a,b;
		scanf(" %d %d", &a, &b);
		adj[a][b] = 1;
		adj[b][a] = 1;
	}
	printf("enter no of universities : ");
	scanf(" %d",&m);
	int visited[n],univ[n],level[n],queue[MAX];
	memset(visited, 0, sizeof(visited));
	memset(queue, 0, sizeof(queue));
	memset(univ, 0, sizeof(univ));
	memset(level, 0, sizeof(level));
	for(int i=0,a=0;i<m;i++) {
		scanf(" %d",&a);
		univ[a] = 1;
	}
	bfs(0,n,adj,visited,queue,level);
	//check nearest university
	int min = 9999;
	int node = 9999;
	for(int i=0;i<n;i++) {
		if(univ[i] > 0) {
			if(level[i] < min) {
				min = level[i];
				node = i;
			}
			else if(level[i] == min) {
				if(i<node){
					node = i;
					min = level[i];
				}
			}
		}
	}
	printf("Nearest university at city : %d\n",node);

	return 0;
}

//print level of all nodes
//for(int i=0;i<n;i++) {
//	printf("%d ",i);
//}printf("\n");
//for(int i=0;i<n;i++) {
//	printf("%d ",level[i]);
//}printf("\n");

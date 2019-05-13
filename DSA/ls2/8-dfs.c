#include<string.h>
#include<stdio.h>

int count = 0;
int starting = 0;
int l=0;
int foundPaths = 0;

int dfs(int start, int n, int arr[n][n], int visited[n]) {
	//printf("    In node=%d\n",start);
	if(visited[start]==1) {
		count--;
		return 0;
	}
	visited[start] = -1;
	if(count == l) {
		visited[start] = 1;
		foundPaths++;
		printf("  Ending at : %d\n",start);
		count--;
		return 0;
	}
	for(int j=0;j<n;j++) {
		if(arr[start][j]>0) {
			count+=1;
			arr[start][j] = 0;
			arr[j][start] = 0;
			dfs(j,n,arr,visited);
			arr[start][j] = 1;
			arr[j][start] = 1;
		}
	}
	visited[start] = 1;
	count--;
	return 0;
}

int main() {

	int n,e;
	printf("Enter nodes and edges : ");
	scanf(" %d %d",&n,&e);
	int arr[n][n];
	int visited[n];
	memset(arr, 0, sizeof(arr));
	memset(visited, 0, sizeof(visited));
	printf("Enter all edge connections : \n");
	for(int i=0;i<e;i++) {
		int a,b;
		scanf(" %d %d",&a,&b);
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	printf("Enter length : ");
	scanf(" %d",&l);

	for(int i=0;i<n;i++) {
		printf("starting at : %d\n",i);
		starting = i;
		memset(visited, 0, sizeof(visited));
		count = 0;
		dfs(i,n,arr,visited);
	}

	printf("Total no of paths found : %d\n",foundPaths/2);
	return 0;
}

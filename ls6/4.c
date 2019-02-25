#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void *a, const void *b) {
    return *((int*)a)-*((int*)b);
}
//disjoint set union stuff(new one here)
int dsu[10000];
int root(int u) {
    while(u!=dsu[u])
        u=dsu[u];
    return u;
}
void unon(int u, int v) {
    dsu[root(u)] = root(v);
}
void init(int n) {
    for(int i=0;i<n;i++)
        dsu[i]=i;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n,m,k;
    scanf(" %d %d %d",&n,&m,&k);
    int color[k],socks[k],arr[m][2];
    for(int i=0;i<k;i++) scanf(" %d",&color[i]);
    for(int i=0;i<k;i++) scanf(" %d",&socks[i]);
    for(int i=0;i<m;i++) scanf(" %d %d",&arr[i][0],&arr[i][1]);
    //try to swap
    for(int i=0;i<m;i++) {
        if(arr[i][0] == arr[i][1]) continue;
        else if(socks[ color[ arr[i][0]-1 ]-1 ]==1) continue;
        for(int j=0;j<m;j++) {
            if(i==j) continue;
            if(arr[i][0]==arr[j][0] && arr[j][0]!=arr[j][1])
                swap(&arr[i][1],&arr[j][0]);
            else if(arr[i][0]==arr[j][1] && arr[j][0]!=arr[j][1])
                swap(&arr[i][1],&arr[j][1]);
        }
    }
    init(n);
    for(int i=0;i<m;i++) unon(arr[i][0],arr[i][1]);
    int visited[n]; memset(visited, 0, sizeof(visited));
    for(int i=0;i<n;i++)
        visited[ root(i) ]++;
    int ans=0;
    for(int i=0;i<n;i++)
        if(visited[i]>0)
            ans+=(visited[i]-1);
    printf("Socks to be colored are: %d\n",ans);
    return 0;
}
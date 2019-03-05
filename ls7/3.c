#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int *dsu,*visited,count=1,otherRoot=0,changes=0;
int root(int u) {
    while(u!=dsu[u])
        u=dsu[u];
    return u;
}
int unon(int u, int v) {
    dsu[ root(u) ] = root(v);
}
int connected(int u, int v) {
    return root(u)==root(v);
}

int change(int start) {
    //printf("changing start: %d\n",start);
    if (otherRoot == 0)
        dsu[start] = start;
    else {
        dsu[start] = otherRoot;
        changes++;
    }
}

int pass(int start) {
    if(start==dsu[start]) {
        visited[start] = count;
        change(start);
        return 0;
    }
    while(start!=dsu[start]) {
        visited[start] = count;
        if(visited[ dsu[start] ]==count) {
            change(start);
            return 0;
        }
        start = dsu[start];
    }
    visited[start] = count;
}

int main() {
    int n;
    scanf(" %d",&n);
    dsu = (int *)calloc(n+1,sizeof(int));
    visited = (int *)calloc(n+1,sizeof(int));
    for(int i=1;i<=n;i++) {
        scanf(" %d",&dsu[i]);
    }
    for(int i=1;i<=n;i++) {
        if(!visited[i]) {
            pass(i);
            otherRoot = root(dsu[i]);
            count++;
        }
    }
    printf("Changes : %d\n",changes);
    for(int i=1;i<=n;i++) {
        printf(" %d",visited[i]);
    }printf("\n");
    for(int i=1;i<=n;i++) {
        printf(" %d",dsu[i]);
    }printf("\n");
    return 0;
}
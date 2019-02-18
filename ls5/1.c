#include<stdio.h>
#include<string.h>

int group = 0;

int isConnected(int arr[][3], int i, int j) {
    if(i==j) return 0;
    if(arr[i][0] >= arr[j][0] && arr[i][0] <= arr[j][1])
        return 1;
    else if(arr[i][1] >= arr[j][0] && arr[i][1] <= arr[j][1])
        return 1;
    return 0;
}

int recurse(int start, int n, int arr[][3], int visited[], int team[]) {
    if(visited[start] != 0) {
        return 0;
    }
    visited[start] = 1;
    arr[start][2] = group;
    team[group]++;
    for(int i=0;i<n;i++) {
        if(isConnected(arr,start,i) && !visited[i]) {
            recurse(i,n,arr,visited,team);
        }
    }
}

int main() {

    int tc;
    scanf(" %d",&tc);
    while(tc--) {
        int n;
        scanf(" %d", &n);
        int arr[n][3];
        int visited[n];
        int team[n];
        int cap = 0,im = 0;
        memset(visited, 0, sizeof(visited));
        memset(team, 0, sizeof(team));
        for(int i=0,a,b;i<n;i++) { // take input
            scanf(" %d %d",&a,&b);
            if(a>b) {
                arr[i][0] = b;
                arr[i][1] = a;
            }
            else {
                arr[i][0] = a;
                arr[i][1] = b;
            }
            arr[i][2] = 0;
        }
        for(int i=0;i<n;i++) {
            group = i;
            recurse(i, n, arr, visited, team);
        }
        for(int i=0;i<=group;i++) {
            int flag = 0;
            if(cap>im) {
                im += team[i];
                flag = -1;
            }
            else {
                cap += team[i];
                flag = -2;
            }
            for(int j=0;j<n;j++) {
                if(arr[j][2] == i) {
                    arr[j][2] = flag;
                }
            }
        }
    }

}

        // //print
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<3;j++) {
        //         printf(" %d",arr[i][j]);
        //     }printf("\n");
        // }
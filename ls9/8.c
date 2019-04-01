#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int k,w,n;
    scanf(" %d %d %d",&k,&w,&n);
    int arr[n][2], visited[n];
    memset(visited, 0, sizeof(visited));
    for(int i=0;i<n;i++) {
        scanf(" %d",&arr[i][0]);
    }
    for(int i=0;i<n;i++) {
        scanf(" %d",&arr[i][1]);
    }
    // sort
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-1;j++) {
            if(arr[j][0]<arr[j+1][0]) {
                int temp0 = arr[j][0], temp1 = arr[j][1];
                arr[j][0] = arr[j+1][0];
                arr[j][1] = arr[j+1][1];
                arr[j+1][0] = temp0;
                arr[j+1][1] = temp1;
            }
        }
    }
    while(k--) {
        for(int i=0;i<n;i++) {
            if(arr[i][1] <= w && !visited[i]) {
                w = w + arr[i][0];
                visited[i] = 1;
                break;
            }
        }
    }
    printf("Maximized profit: %d\n",w);
    return 0;
}
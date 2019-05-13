#include<stdio.h>
#include<string.h>

void swap(int arr[][3], int j) {
    int temp0 = arr[j][0],temp1 = arr[j][1],temp2 = arr[j][2];
    arr[j][0] = arr[j+1][0];
    arr[j][1] = arr[j+1][1];
    arr[j][2] = arr[j+1][2];
    arr[j+1][0] = temp0;
    arr[j+1][1] = temp1;
    arr[j+1][2] = temp2;
}

int main() {

    int tc;
    scanf(" %d",&tc);
    while(tc--) {
        int n;
        scanf(" %d", &n);
        int arr[n][3];
        int team[n];
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

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j][0] > arr[j + 1][0]) {
                    swap(arr, j);
                }
            }
        }
        int teamNo = 0;
        for(int i=0;i<n-1;i++) {
            if(arr[i][1] >= arr[i+1][0]) {
                arr[i+1][2] = arr[i][2];
            }
            else {
                arr[i+1][2] = ++teamNo;
            }
            team[teamNo]++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (team[j] > team[j + 1]) {
                    int temp = team[j];
                    team[j] = team[j+1];
                    team[j+1] = temp;
                }
            }
        }
        int cap = team[0], im = team[1];
        for(int i=2;i<n;i++) {
            if(cap>im){im+=team[i];}else{cap+=team[i];}
        }
        printf("cap:%d\nim:%d\n",cap,im);
    }


    return 0;
}
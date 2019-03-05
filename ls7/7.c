#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define log(exp) printf("value of %s is: %d\n",#exp,exp);

int arr[100];

int main() {
    char c='a';
    int n=0,swaps=0;
    do{
        scanf("%d%c",&arr[n++],&c);
    }while(c!='\n');
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j]>arr[j+1]) {
                swaps+=1;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i=0;i<n;i++) {
        printf(" %d",arr[i]);
    }printf("\n");
    printf("no of crossings: %d\n",swaps);
    // qsort(sorted,n,sizeof(int),cmp);
    // int adj[n][n];
    // memset(adj, 0, sizeof(adj));
    // for(int i=0;i<n;i++) {
    //     if(sorted[i]!=arr[i]) {
    //         int index = find(arr[i], n, sorted);
    //         if(index>i) {
    //             for(int k=i;k<index;k++) {
    //                 adj[ arr[i] ][ sorted[k] ] = 1;
    //                 adj[ sorted[k] ][ arr[i] ] = 1;
    //             }
    //         }
    //         else {
    //             for(int k=index+1;k<=i;k++) {
    //                 adj[ arr[i] ][ sorted[k] ] = 1;
    //                 adj[ sorted[k] ][ arr[i] ] = 1;
    //             }
    //         }
    //     }
    // }
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<n;j++) {
    //         if(adj[i][j]>0) {
    //             printf(" %d-%d\n",i,j);
    //             adj[i][j] = 0;
    //             adj[j][i] = 0;
    //         }
    //     }
    // }
    return 0;
}

// int cmp(const void *a, const void *b) {
//     return *((int*)a)-*((int*)b);
// }

// int find(int data, int n, int sorted[]) {
//     for(int i=0;i<n;i++)
//         if(sorted[i] == data)
//             return i;
//     return -1;
// }

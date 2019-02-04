#include<stdio.h>
#include<string.h>

int arr[1000];

int main() {
    
    int n,k,i=0;
    char c;
    do {
        scanf("%d%c",&n,&c);
        arr[i++] = n;
    }while(c!='\n');
    printf("input successfull\n");
    for(int j=0;j<i;j++) {
        printf("%d ",arr[j]);
    }
    printf("Input k : ");
    scanf(" %d",&k);
    int j=1;
    int arr2[i];
    int visited[i];
    memset(visited, -77, sizeof(visited));
    for(j=1;j*k-1<i;j++) {
        arr2[j-1] = arr[j*k-1];
        visited[j*k-1] = 1;
    }
    j--;
    for(int k=0,l=i-1;k<i;k++) {
        if(visited[k]!=1) {
            if(l<j){
                break;
            }
            arr2[l--] = arr[k];
        }
    }
    for(int j=0;j<i;j++) {
        printf("%d ",arr2[j]);
    }
    printf("\n");
    
    return 0;
}

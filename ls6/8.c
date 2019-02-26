#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int verify(int i,int n, int m, char arr[][m], char str[], int r, int c) {
    if(i==strlen(str))  return 1;
    if(c<m-1 && str[i]==arr[r][c+1])    {if(verify(i+1,n,m,arr,str,r,c+1)) return 1;}
    if(r>0 && str[i]==arr[r-1][c])      {if(verify(i+1,n,m,arr,str,r-1,c)) return 1;}
    if(c>0 && str[i]==arr[r][c-1])      {if(verify(i+1,n,m,arr,str,r,c-1)) return 1;}
    if(r<n-1 && str[i]==arr[r+1][c])    {if(verify(i+1,n,m,arr,str,r+1,c)) return 1;}
    else return 0;
}

void program(int n, int m, char arr[][m], char str[]) {
    for (int r=0;r<n;r++) {
        for (int c=0;c<m;c++) {
            if (arr[r][c] == str[0]) {
                if (verify(1, n, m, arr, str, r, c)) {
                    printf("YES\n");
                    return;
                }
            }
        }
    }
    printf("NO\n");
}

int main() {
    int n,m,tc;
    scanf(" %d %d",&n,&m);
    char arr[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf(" %c", &arr[i][j]);
        }
    }
    scanf(" %d",&tc);
    while(tc--) {
        // fflush(stdin);
        char str[1000];
        scanf(" %s",str);
        program(n,m,arr,str);
    }
    return 0;
}
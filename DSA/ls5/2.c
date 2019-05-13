#include<stdio.h>
#include<string.h>

int main() {

    int n,m;
    scanf(" %d %d",&n,&m);
    int a1[n][2],a2[m]; 
    int final[n],ptr = 0;
    memset(a1, 0, sizeof(a1));
    for(int i=0;i<n;i++) {
        scanf(" %d",&a1[i][0]);
    }
    for(int i=0;i<m;i++) {
        scanf(" %d",&a2[i]);
    }
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(a2[i] == a1[j][0]) {
                a1[j][1] = 1;
                final[ptr++] = a1[j][0];
            }
        }
    }
    int len = n-ptr;
    int arr[len],ptr2=0;
    for(int i=0;i<n;i++) {
        if(a1[i][1] == 0) {
            arr[ptr2++] = a1[i][0];
        }
    }
    for(int i=0;i<len;i++) {
        for(int j=0;j<len-i-1;j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    ptr2 = 0;
    for(int i=ptr;i<n;i++) {
        final[ptr++] = arr[ptr2++];
    }
    for(int i=0;i<n;i++) {
        printf(" %d",final[i]);
    }
    printf("\n");

    return 0;
}
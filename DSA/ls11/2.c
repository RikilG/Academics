#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int r,m, count=0;
    scanf(" %d %d",&m,&r);
    char mag[m][50], ransom[r][50];
    for(int i=0;i<m;i++)
        scanf(" %s",mag[i]);
    for(int i=0;i<r;i++)
        scanf(" %s",ransom[i]);
    for(int i=0;i<r;i++) {
        for(int j=0;j<m;j++) {
            if(!strcmp(ransom[i],mag[j])) {
                count++;
                memset(mag[j], 0, sizeof(mag[j]));
                break;
            }
        }
    }
    if(count == r) printf("Yes\n");
    else printf("No\n");
    return 0;
}
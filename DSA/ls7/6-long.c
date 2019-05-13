//useless
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n,k,size;
int *set,counter[1000],subs[1000];

int power(int b, int e) {
    int ans = 1;
    while(e--)
        ans *= b;
    return ans;
}

int incCount() {
    counter[0]++;
    for(int i=0;i<1000;i++) {
        if(counter[i]/k >= 1) {
            counter[i]=0;
            counter[i+1]++;
        }
    }
}

int subsGen(int size) {
    for(int i=0;i<size;i++) {
        subs[i] = set[ counter[i] ];
    }
    incCount();
}

int checkString(int allsubs[power(k,n)][1000]) {
    int temp = power(k,n);
    while(temp--) {
        int flag = 0;
        for(int i=0;i<size-n+1;i++) {
            for(int j=i;j<n+i;j++) {
                //printf("allsubs[temp][j-i]:%d subs[j]:%d\n",allsubs[temp][j-i],subs[j]);
                if(allsubs[temp][j-i] != subs[j]){
                    flag=1;
                    break;
                }
            }
            if(flag==1) {
                if(i==size-n) return 0;
                flag=0;
                continue;
            }
            else 
                break;
        }
    }
    printf(" YES\n");
    return 1;
}

int main() {
    scanf(" %d %d",&n,&k);
    set = (int *)calloc(k,sizeof(int));
    for(int i=0;i<k;i++)
        scanf(" %d",&set[i]);
    int temp = power(k,n);
    int allsubs[temp][1000];
    while(temp--) { // all substrings for set.
        subsGen(n);
        for(int i=0;i<n;i++)
            allsubs[temp][i] = subs[i];
    }
    memset(counter, 0, sizeof(counter));
    size = n;
    while(1) {
        temp = power(k,size);
        while(temp--) {
            subsGen(size);
            if(checkString(allsubs)) {
                //printf string.
                for(int i=0;i<size;i++)
                    printf("%d",subs[i]);
                printf("\n");
                return 0;
            }
        }
        memset(counter, 0, sizeof(counter));
        size++;
    }
    return 0;
}
    // temp = power(k,n);
    // while(temp--) { // all substrings for set.
    //     for(int i=0;i<n;i++)
    //         printf("%d",allsubs[temp][i]);
    //     printf("\n");
    // }
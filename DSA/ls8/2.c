#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int req;
int t[1000],s[1000];

int cmp(const void *a, const void *b) {
    return *((int*)a)-*((int*)b);
}

int main() {
    int wt=0,sum=0; //sum: time elapsed
    scanf(" %d",&req);
    for(int i=0;i<req;i++)
        scanf(" %d %d",&t[i],&s[i]);
    for(int start=0;start<req;start++) {
        int tt = s[start]+t[start],mark=start; //till time to be taken
        if(t[start]>sum) sum=tt;
        else sum+=s[start];
        // while(i+1<req && tt>=t[i+1])
        //     i++;
        // qsort(s+start+1,i-start,sizeof(int),cmp);
        for(int i=start+1;i<req;i++)
            if(t[i]<=tt)
                mark++;
        for(int i=start+1;i<mark+1;i++) {
            for(int j=start+1;j<mark;j++) {
                if(s[j]>s[j+1]) {
                    int tmps = s[j], tmpt = t[j];
                    s[j] = s[j+1];
                    s[j+1] = tmps;
                    t[j] = t[j+1];
                    t[j+1] = tmpt;
                }
            }
        }
        wt += sum - t[start];
        printf("wt=%d waiting time:%d, sum=%d\n",wt,sum-t[start],sum);
    }
    for(int i=0;i<req;i++) {
        printf(" %d",s[i]);
    }
    printf("\navg: %f\n",(float)wt/req);
    return 0;
}
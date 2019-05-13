#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int start;
    int end;
    int left;
    int extime;
} Prog;

int main() {
    int n, k, maxtime=0, busTime=0, wt=0;
    printf("Enter no of Programs and threshold: \n");
    scanf(" %d %d",&n,&k);
    Prog list[n];
    printf("Enter arrival and exec time: \n");
    for(int i=0;i<n;i++) {
        scanf(" %d %d",&list[i].start,&list[i].extime);
        list[i].left = list[i].extime;
        if(list[i].start + list[i].extime > maxtime) maxtime = list[i].start + list[i].extime + k;
    }
    while((maxtime-=k)>0) {
        for(int i=0;i<n;i++) {
            if(list[i].left>k) {
                list[i].left -= k;
                busTime += k;
            }
            else if(list[i].left<=k && list[i].left >0) {
                busTime += list[i].left;
                list[i].left = 0;
                list[i].end = busTime;
            }
            // printf("prog: %d, left: %d, bustime: %d\n",i+1,list[i].left,busTime);
        }
    }
    for(int i=0;i<n;i++) {
        wt += list[i].end - list[i].extime;
        // printf("prog: %d, indwt: %d, wt: %d\n",i+1,list[i].end - list[i].extime,wt);
    }
    printf("avg exec time: %2f\n",(float)wt/n);
    return 0;
}
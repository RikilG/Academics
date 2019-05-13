#include<stdio.h>
#include<string.h>

int n, stk[2][1000], tos[2] = {-1, -1}, score[1000], s = 0, temp;

int delete(int a, int b) {
    int arg = 1,flag = 0;
    START:
    flag = 0;
    for(int i=0;i<s-1;i++) {
        if( ((arg==1)?score[i]==a:score[i]==b) || flag) {
            flag = 1;
            score[i] = score[i+1];
        }
    }
    s--;
    if(arg==1 && b!=-9999) { /*set*/arg=2; goto START; }
}

int main() {
    char str[10];
    scanf(" %d",&n);
    while(n--) {
        temp = 0;
        scanf(" %s",str);
        if(!strcmp("push",str)) {
            scanf(" %d",&temp);
            score[s++] = temp;
            if(tos[0] == -1 || temp <= stk[0][ tos[0] ])
                stk[0][ ++tos[0] ] = temp;
            if(tos[1] == -1 || temp >= stk[1][ tos[1] ])
                stk[1][ ++tos[1] ] = temp;
        }
        else if(!strcmp("diff",str)) {
            if(tos[0] == -1 || tos[1] == -1) {
                printf(" 0\n");
                continue;
            }
            printf(" Diff b/w curr high and low: %d\n",stk[1][ tos[1] ]-stk[0][ tos[0] ]);
            (stk[0][tos[0]]==stk[1][tos[1]])?delete(stk[0][tos[0]], -9999):delete(stk[0][tos[0]], stk[1][tos[1]]);
            tos[0]--;tos[1]--;
        }
        else if(!strcmp("countHigh",str)) {
            for(int i=0;i<s;i++)
                if(score[i] == stk[1][tos[1]])
                    temp++;
            printf("highest count: %d\n", temp);
        }
        else if(!strcmp("countLow",str)) {
            for(int i=0;i<s;i++)
                if(score[i] == stk[0][tos[0]])
                    temp++;
            printf("lowest count: %d\n", temp);
        }
        else {
            printf(" Invalid command\n");n++;
        }
    }
    return 0;
}
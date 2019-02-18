#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {

    int x,p,a,m,cost=0; // x-xbox p-ps4 a-any m-maxProducts
    scanf(" %d %d %d %d",&x,&p,&a,&m);
    int price[m];
    char item[m];
    for(int i=0;i<m;i++) {
        char temp[8];
        scanf(" %d %s",&price[i],temp);
        item[i] = temp[0];
    }
    for(int i=0;i<m;i++) {
        for(int j=0;j<m-i-1;j++) {
            if(price[j] > price[j+1]) {
                int tempp = price[j],tempi = item[j];
                price[j] = price[j+1];
                item[j] = item[j+1];
                price[j+1] = tempp;
                item[j+1] = tempi;
            }
        }
    }
    for(int i=0;i<m;i++) {
        if(item[i] == 'p' || item[i] == 'P') {
            if(p>0){
                p--;
                cost += price[i];
            }
            else if(a>0) {
                a--;
                cost += price[i];
            }
        }
        else if(item[i] == 'x' || item[i] == 'X') {
            if(x>0){
                x--;
                cost += price[i];
            }
            else if(a>0) {
                a--;
                cost += price[i];
            }
        }
    }

    return 0;
}
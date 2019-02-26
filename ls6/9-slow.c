// will work OK till n=27 only
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n,ans=0,buffer=0,max=0;

int recurse() {
    if(n==0) {
        if(ans>max)
            max = ans;
        return 0;
    }
    if(n>=3 && ans>0) {
        int temp = buffer;
        n-=3;
        buffer = ans;
        ans*=2;
        recurse();
        ans/=2;
        buffer = temp;
        n+=3;
    }
    if(n>=1 && ans>0) {
        n-=1;
        ans += buffer;
        recurse();
        ans -= buffer;
        n+=1;
    }
    if(n>=1) {
        n-=1;
        ans += 1;
        recurse();
        ans -= 1;
        n+=1;
    }
}

int main() {
    scanf(" %d",&n);
    if(n>75){
        printf("-1\n");
        return 0;
    }
    recurse();
    printf("max A's: %d\n",max);
    return 0;
}
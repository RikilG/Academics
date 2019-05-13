#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isPalindrome(char str[]) {
    int n = strlen(str);
    for(int i=0;i<=n/2;i++) {
        if(str[i]==str[n-i-1]) {
            if(i==0) continue;
            if(!(str[i]-str[i-1]>=0)) {
                //printf("broke: %s\n", str);
                return 0;
            }
        }
        else {
            //printf("fail: %s\n", str);
            return 0;
        }
        
    }
    //printf("success : %s\n",str);
    return 1;
}

int main() {
    char str[1000];
    scanf(" %s",str);
    int len = strlen(str);
    char final[1000];
    memset(final, 0, sizeof(final));
    for(int i=3;i<=len;i++) {
        for(int j=0;j<=len-i;j++) {
            char temp[1000];
            strncpy(temp,str+j,i);
            temp[i] = '\0';
            if(isPalindrome(temp)) {
                if(strlen(temp)>strlen(final))
                    strcpy(final, temp);
                else if(strlen(temp)==strlen(final)) {
                    for(int k=0;k<strlen(final);k++) {
                        if(temp[k] == final[k]) continue;
                        if(temp[k] < final[k]) {
                            strcpy(final, temp);
                            break;
                        }
                        else if(temp[k] > final[k])
                            break;
                    }
                }
                //printf(" final: %s\n", temp);
            }
        }
    }
    printf(" final: %s\n",final);
    return 0;
}
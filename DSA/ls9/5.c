#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[1000];
int alpha[27];

int findMax(int excl) {
    int max = 0,ind,flag=0;
    for(int i=0;i<26;i++) {
        if(alpha[i]>max && i!=excl) {
            flag=1;
            max = alpha[i];
            ind = i;
        }
    }
    return (flag==1)?ind:-1;
}

int main() {
    scanf("%s",str);
    int temp = strlen(str);
    for(int i=0;i<temp;i++)
        alpha[str[i]-97]++;
    int letter = findMax(-1), next;
    while(letter!=-1 && temp --> 0) {
        printf("%c",letter+97);
        alpha[letter]--;
        letter = findMax(letter);
    }
    if (letter == -1 && temp>0) printf("\nImpossible\n");
    else printf("\nPossible\n");
    return 0;
}
/*
    printf("alphabets: \n");
    for(int i=0;i<26;i++) {
        printf(" %d",alpha[i]);
    }printf("\n");
*/
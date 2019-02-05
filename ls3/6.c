//6.c anagram of a palindrome
#include<string.h>
#include<stdio.h>

int main() {

    int count=0;
    char str[12];
    int alpha[26];
    memset(str, 0, sizeof(str));
    memset(alpha, 0, sizeof(alpha));
    scanf(" %s",str);
    int n = strlen(str);
    for(int i=0;i<n;i++) {
        alpha[str[i]-97]++;
    }
    for(int i=0;i<26;i++) {
        if(alpha[i]%2==0)
            continue;
        else
            count++;
    }
    if(count<=1)
        printf("Yes\n");
    else
        printf("No\n");

	return 0;
}

//int isPalindrome(int n, char str[]) {
//    for(int i=0;i<n/2;i++) {
//        if(str[i] == str[n-1-i]) {
//            continue;
//        }
//        else {
//            return 0;
//        }
//    }
//    return 1;
//}

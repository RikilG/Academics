//7.c Caesar cipher!!

#include<string.h>
#include<stdio.h>

int main() {

    char str[100];
    memset(str, 0, sizeof(str));
    scanf(" %s",str);
    for(int i=0;i<strlen(str);i++) {
        str[i] = ( ( str[i] - 97 + 3 ) % 26 ) + 97;
        printf("%c",str[i]);
    }
    printf("\n");

	return 0;
}

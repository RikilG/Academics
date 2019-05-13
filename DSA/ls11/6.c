#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct book {
    long cLoHash;
    long hiHash;
    long loHash;
    char name[20];
} Book;

Book *hash(char *str) {
    Book *temp = (Book*)malloc(sizeof(Book));
    int cLoHash=0,hiHash=0,loHash=0;
    for(int i=0;i<strlen(str);i++) {
        if(tolower(str[i])!='a' && tolower(str[i])!='e' && tolower(str[i])!='i' && tolower(str[i])!='o' && tolower(str[i])!='u') cLoHash = cLoHash*11 + tolower(str[i]);
        else cLoHash = cLoHash*11;
        hiHash = hiHash*11 + str[i];
        loHash = loHash*11 + tolower(str[i]);
    }
    strcpy(temp->name, str);
    temp->cLoHash = cLoHash;
    temp->hiHash = hiHash;
    temp->loHash = loHash;
    return temp;
}

int main() {
    int n,q;
    scanf(" %d",&n);
    Book books[n];
    for(int i=0;i<n;i++) {
        scanf(" %s",books[i].name);
        Book *temp = hash(books[i].name);
        books[i].cLoHash = temp->cLoHash;
        books[i].hiHash = temp->hiHash;
        books[i].loHash = temp->loHash;
        free(temp);
    }
    // printf("Hashset: \n");
    // for(int i=0;i<n;i++) {
    //     printf(" %5ld %8ld %8ld %s\n",books[i].cLoHash, books[i].hiHash, books[i].loHash, books[i].name);
    // }
    scanf(" %d",&q);
    NEW_QUERY:
    while(q--) {
        char str[20];
        scanf(" %s",str);
        Book *temp = hash(str);
        // printf(" %5d %8ld %8ld %s\n",temp->cLoHash,temp->hiHash,temp->loHash,temp->name);
        //find for exact match using hiHash.
        for(int i=0;i<n;i++) {
            if(books[i].hiHash == temp->hiHash) {
                printf("exact match: %s\n",books[i].name);
                // printf(" %5ld %8ld %8ld %s\n",temp->cLoHash,temp->hiHash,temp->loHash,temp->name);
                goto NEW_QUERY;
            }
        }
        //second first match for few captalizaiton errors using loHash.
        for(int i=0;i<n;i++) {
            if(books[i].loHash == temp->loHash) {
                printf("captalizations match: %s\n",books[i].name);
                // printf(" %5ld %8ld %8ld %s\n",temp->cLoHash,temp->hiHash,temp->loHash,temp->name);
                goto NEW_QUERY;
            }
        }
        //remove vowels and match
        for(int i=0;i<n;i++) {
            if(books[i].cLoHash == temp->cLoHash) {
                printf("voweless match: %s\n",books[i].name);
                // printf(" %5ld %8ld %8ld %s\n",temp->cLoHash,temp->hiHash,temp->loHash,temp->name);
                goto NEW_QUERY;
            }
        }
        printf(" No match found.\n");
    }
    return 0;
}
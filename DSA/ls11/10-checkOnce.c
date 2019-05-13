#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct node {
    char letter;
    int num;
    struct node *child[26];
} Node;

char stk[1000];
int k=0;

Node *newNode(char ch) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->letter = ch;
    temp->num = 0;
    for(int i=0;i<26;i++) temp->child[i] = NULL;
    return temp;
}

void createTree(Node *root, char *str) {
    char letter;
    for(int i=0;i<strlen(str);i++) {
        letter = str[i]-97;
        if(root->child[letter]!=NULL) {
            root = root->child[letter];
            continue;
        }
        root->num += 1;
        root->child[letter] = newNode(str[i]);
        root = root->child[letter];
    }
}

void printStk(int p) {
    for(int i=0;i<=p;i++) printf("%c",stk[i]);
    printf("\n");
}

void getPrefix(Node *temp, int p) {
    int flag=1;
    stk[k++] = temp->letter;
    if(temp->num>1) {
        p = k;
    }
    for(int i=0;i<26;i++) {
        if(temp->child[i]!=NULL) {
            flag=0;
            getPrefix(temp->child[i],p);
        }
    }
    if(flag) printStk(p);
    k--;
}

int main() {
    int n;
    Node *root = newNode(' ');
    scanf(" %d",&n);
    char str[n][100];
    for(int i=0;i<n;i++) {
        scanf(" %s",str[i]);
        for(int j=0;j<strlen(str[i]);j++) str[i][j] = tolower(str[i][j]);
    }
    for(int i=0;i<n;i++) {
        createTree(root,str[i]);
    }
    getPrefix(root,0);
    return 0;
}
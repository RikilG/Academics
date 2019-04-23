#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    int data;
    struct node *left, *right, *parent;
} Node;

typedef struct res { int size,isBst; Node *maxBst; } Result;

Node *findNode(int n, Node nodes[], int x) {
    for(int i=0;i<n;i++) if(nodes[i].data == x) return &nodes[i];
    return NULL;
}

Result *checkBST(Node *root) {
    Result *res = (Result*)malloc(sizeof(Result));
    if(root->left == NULL || root->right == NULL) {
        res->size = 1;
        res->isBst = 1;
        res->maxBst = root;
        return res;
    }
    Result *lcheck=NULL, *rcheck=NULL;
    lcheck = checkBST(root->left);
    rcheck = checkBST(root->right);
    if(lcheck->isBst && rcheck->isBst && root->left->data < root->data && root->data < root->right->data) {
        res->size = lcheck->size + rcheck->size + 1;
        res->isBst = 1;
        res->maxBst = root;
        return res;
    }
    else {
        lcheck->isBst = 0;
        rcheck->isBst = 0;
        return (lcheck->size > rcheck->size)?lcheck:rcheck;
    }
}

void preTraverse(Node *root) {
    printf(" %d",root->data);
    if(root->left!=NULL) preTraverse(root->left);
    if(root->right!=NULL) preTraverse(root->right);
}

int main() {
    int n,k=1;
    scanf(" %d",&n);
    int inputs[n][2];
    Node nodes[n];
    for(int i=0;i<n-1;i++)
        scanf(" %d %d",&inputs[i][0],&inputs[i][1]);
    for(int i=0;i<n;i++) { //memset...
        nodes[i].data = -99999;
        nodes[i].left = nodes[i].right = nodes[i].parent = NULL;
    }
    scanf(" %d",&nodes[0].data);
    //assign all nodes
    for(int i=0;i<n-1;i++) if(findNode(n,nodes,inputs[i][1])==NULL) nodes[k++].data = inputs[i][1];
    //create tree
    for(int i=0;i<n-1;i++) {
        Node *parent = findNode(n,nodes,inputs[i][0]);
        Node *child = findNode(n,nodes,inputs[i][1]);
        if(parent->left==NULL)
            parent->left = child;
        else
            parent->right = child;
        child->parent = parent;
    }
    Result *res = checkBST(&nodes[0]);
    printf("size: %d\n",res->size);
    preTraverse(res->maxBst);
    printf(" \n");
    return 0;
}
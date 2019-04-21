#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    int data;
    struct node *left, *right, *parent;
} Node;

Node *newNode(int x) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->left = temp->right = temp->parent = NULL;
    return temp;
}

int getIndex(int n, int arr[], int x) {
    for(int i=0;i<n;i++) if(arr[i]==x) return i;
    return -1;
}

Node *createTree(int n, int in[], int pre[]) {
    Node *mid = newNode(pre[0]);
    if(n==1) return mid;
    int midInd = getIndex(n,in,pre[0]); //this gives no of nodes before root in in[]
    mid->left = createTree(midInd, in, pre+1);
    mid->right= createTree(n-midInd-1, in+midInd+1, pre+midInd+1);
    return mid;
}

void postOrder(Node *root) {
    if(root->left!=NULL) postOrder(root->left);
    if(root->right!=NULL) postOrder(root->right);
    printf(" %d",root->data);
}

int main() {
    int n;
    scanf(" %d",&n);
    int in[n],pre[n];
    for(int i=0;i<n;i++)
        scanf(" %d",&in[i]);
    for(int i=0;i<n;i++)
        scanf(" %d",&pre[i]);
    Node *root = createTree(n, in, pre);
    postOrder(root);
    printf("\n");
    return 0;
}
    // //testing by bfs
    // int l=0,r=0;
    // Node *queue[1000];
    // queue[r++] = root;
    // printf("BFS:");
    // while(l!=r) {
    //     printf(" %d",queue[l]->data);
    //     if(queue[l]->left != NULL) queue[r++] = queue[l]->left;
    //     if(queue[l]->right != NULL) queue[r++] = queue[l]->right;
    //     l++;
    // }printf("\n");
#include<stdio.h>

typedef struct node {
    int data;
    struct node *left, *right, *parent;
} Node;

Node *findNode(int n, Node nodes[], int data) {
    for(int i=0;i<n;i++) if(nodes[i].data == data) return &nodes[i];
    return NULL;
}

int main() {
    int n,temp,min,max,k=1; // k=1 as we have head node
    scanf(" %d",&n);
    int inputs[n][2];
    Node nodes[n], *queue[1000], *head = &nodes[0];
    for(int i=0;i<n;i++) { //initialize nodes to NULL
        nodes[i].data = -99999;
        nodes[i].left = NULL;
        nodes[i].right = NULL;
        nodes[i].parent = NULL;
    }
    //store inputs
    for(int i=0;i<n-1;i++)
        scanf(" %d %d",&inputs[i][0],&inputs[i][1]);
    //get root node and save to head
    scanf(" %d",&nodes[0].data);
    //store nodes
    for(int i=0;i<n-1;i++) {
        if(findNode(n,nodes,inputs[i][1])==NULL)
            nodes[k++].data = inputs[i][1];
    }
    //create tree
    for(int i=0;i<n-1;i++) {
        if(inputs[i][0]<inputs[i][1])
            findNode(n,nodes,inputs[i][0])->right = findNode(n,nodes,inputs[i][1]);
        else
            findNode(n,nodes,inputs[i][0])->left = findNode(n,nodes,inputs[i][1]);
        findNode(n,nodes,inputs[i][1])->parent = findNode(n,nodes,inputs[i][0]);
    }
    //logic
    scanf(" %d %d",&min,&max);
    for(int i=0;i<n;i++) { // more code for root checking required
        if(head==&nodes[i]) {
            if(nodes[i].data<min) head = head->right;
            else if(nodes[i].data>max) head = head->left;
        }
        else if(nodes[i].data<min)
            (nodes[i].parent)->left = nodes[i].right;
        else if(nodes[i].data>max)
            (nodes[i].parent)->right = nodes[i].left;
    }
    //do bfs traversal
    int l=0,r=0;
    queue[r++] = head;
    while(l!=r) {
        printf(" %d",queue[l]->data);
        if(queue[l]->left != NULL)  queue[r++] = queue[l]->left;
        if(queue[l]->right != NULL) queue[r++] = queue[l]->right;
        l++;
    }printf("\n");
    return 0;
}
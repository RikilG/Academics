#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}Node;

Node *head[3],*tail[3];

void append(int n, Node *temp) {
    if(head[n]==NULL) {
        head[n] = temp;
        head[n]->next = NULL;
        tail[n] = head[n];
    }
    else {
        tail[n]->next = temp;
        tail[n] = temp;
        tail[n]->next = NULL;
    }
}

void traverse(int n) {
    Node *temp = head[n];
    while(temp!=NULL) {
        printf(" %d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n1, n2, temp;
    scanf(" %d",&n1);
    for(int i=0;i<n1;i++) {
        scanf(" %d",&temp);
        Node *tmp = (Node*)malloc(sizeof(Node));
        tmp->data = temp;
        append(1,tmp);
    }
    scanf(" %d",&n2);
    for(int i=0;i<n2;i++) {
        scanf(" %d",&temp);
        Node *tmp = (Node*)malloc(sizeof(Node));
        tmp->data = temp;
        append(2,tmp);
    }
    //tail[1]->next = head[2];
    Node *ptr1=head[1],*ptr2=head[2];
    while(ptr1!=NULL && ptr2!=NULL) {
        if(ptr1->data >= ptr2->data) {
            Node *next = ptr2->next;
            append(0, ptr2);
            ptr2 = next;
        }
        else {
            Node *next = ptr1->next;
            append(0, ptr1);
            ptr1 = next;
        }
    }
    while(ptr1!=NULL) {
        Node *next = ptr1->next;
        append(0, ptr1);
        ptr1 = next;
    }
    while(ptr2!=NULL) {
        Node *next = ptr2->next;
        append(0, ptr2);
        ptr2 = next;
    }
    traverse(0);
    return 0;
}
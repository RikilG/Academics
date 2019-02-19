// FAILED to implement linked list
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
}Node;

Node *head = NULL;
Node *tail = NULL;
int length = 0;

Node *getPtr(int value) {
    Node *temp = head;
    while(temp!=NULL) {
        if(temp->data == value)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void printArray() {
    Node *temp = head;
    while(temp!=NULL) {
        printf(" %d",temp->data);
        temp = temp->next;
    }printf(" \n");
}

void insert(int value) {
    Node *temp = head;
    if(value<head->data) {
        Node *temp2 = (Node *)malloc(sizeof(Node));
        temp2->data = value;
        temp2->next = head;
        temp2->prev = NULL;
        head->prev = temp2;
        head = temp2;
        printArray();
        return;
    }
    while(temp != NULL) {
        if(temp->data > value) {
            Node *temp2 = (Node*)malloc(sizeof(Node));
            temp2->data = value;
            temp2->next = temp;
            temp2->prev = temp->prev;
            temp->prev->next = temp2;
            temp->prev = temp2;
            printArray();
            return;
        }
        temp = temp->next;
    }
    if(temp==NULL) {
        Node *temp2 = (Node *)malloc(sizeof(Node));
        temp2->data = value;
        temp2->next = NULL;
        temp2->prev = tail;
        tail->next = temp2;
        tail = temp2;
        printArray();
        return;
    }
}

void delete(int value) {
    Node *ptr = getPtr(value);
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
    printArray();
}

void swap(int a, int b) {
    Node *ptr1 = getPtr(a);
    Node *ptr2 = getPtr(b);
    int temp = ptr1->data;
    ptr1->data = ptr2->data;
    ptr2->data = temp;
    printArray();
}

int cmp(const void *a, const void *b) {
    return *((int*)a)-*((int*)b);
}

void sort() {
    int arr[length],i=0;
    Node *tmp = head;
    while(tmp != NULL) {
        arr[i++] = tmp->data;
    }
    qsort(arr,length,sizeof(int),cmp);
    tmp = head,i=0;
    while(tmp != NULL) {
        tmp->data = arr[i++];
    }
    printArray();
}

int main() {

    char ch;
    Node *ptr=NULL;
    do{
        int a;
        scanf("%d%c",&a,&ch);
        length++;
        if(head == NULL) {
            head = (Node*)malloc(sizeof(Node));
            ptr = head;
            head->data = a;
            head->next = NULL;
            head->prev = NULL;
            continue;
        }
        Node *temp = (Node*)malloc(sizeof(Node));
        temp->data = a;
        ptr->next = temp;
        temp->prev = ptr;
        temp->next = NULL;
        ptr = temp;
    }while(ch != '\n');
    tail = ptr;
    printArray();

    int n,tmp,tmp2;
    scanf(" %d",&n);
    char str[4];
    for(int i=0;i<n;i++) {
        scanf(" %s %d",str,tmp);
        printf(" %s %d\n",str,tmp);
        if (strlen(str)-1) { //single letter
            switch (str[0]) {
                case 'i':
                case 'I':
                    insert(tmp);
                    break;
                case 'd':
                case 'D':
                    delete(tmp);
                    break;
                default:
                    printf("Invalid choice\n");
            }
        }
        else { // double letter
            switch (str[1]) {
                case 'o':
                case 'O':
                    sort();
                    break;
                case 'w':
                case 'W':
                    scanf(" %d",tmp2);
                    swap(tmp,tmp2);
                    break;
                default:
                    printf("Invalid choice\n");
            }
        }
    }

    return 0;
}
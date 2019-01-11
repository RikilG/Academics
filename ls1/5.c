#include<stdlib.h>
#include<stdio.h>

typedef struct node {
	int data;
	struct node *next;
}Node;

void traverse(Node* head) {
	while(head!=NULL) {
		printf("%d ",head->data);
		head = head->next;
	}
	printf("\n");
}

void search(Node *head, int x) {
	int pos = 1;
	while(head!=NULL) {
		if(head->data == x){
			printf("Found %d at position %d in list\n",x,pos);
			return;
		}
		pos++;
		head = head->next;
	}
	printf("Number %d is not present in list\n",x);
}

void delete(Node *head, int x) {
	int found = 0;
	Node *temp = head;
	if(head->data == x) {
		found = 1;
	}
	temp = temp->next;
	while(temp!=NULL) {
		if(temp->data == x) {
			if(found == 0){
				found = 1;
			}
			else {
				//delete node
				Node *tmp = temp->next;
				free(temp);
				head->next = tmp;
				temp = tmp;
				continue;
			}
		}
		temp = temp->next;
		head = head->next;
	}
}

void swap(Node *head, int x) {
	while(head!=NULL) {
		if(head->data == x) {
			//swap and return from func
			int temp = head->data;
			head->data = head->next->data;
			head->next->data = temp;
			return;
		}
		head = head->next;
	}
	printf("given data not present in list.\n");
}

int main() {

	Node *head=NULL,*temp=NULL;
	printf("Enter numbers seperated by space below.\n>> ");
	int d=0,first=0,count=0,last=0;
	char ch;
	while(last == 0) { //take input
		ch = getchar();
		if(ch == ' ' || ch == '\n') {
			if(first==0) {
				first = 1;
				head = (Node*)malloc(sizeof(Node));
				head->next = NULL;
				head->data = d;
				temp = head;
			}
			else {
				Node *tmp = (Node *)malloc(sizeof(Node));
				tmp->next = NULL;
				tmp->data = d;
				temp->next = tmp;
				temp = temp->next;
			}
			count++;
			d = 0;
			if(ch == '\n') {
				break;
			}
		}
		else {
			d = d*10 + ch-48;
		}
	}

	printf("Enter number to perform operations in list : ");
	int x;
	scanf(" %d",&x);
	search(head, x);
	delete(head, x);
	printf("list after deleting %d : ",x);
	traverse(head);
	swap(head, x);
	printf("list after swapping %d : ",x);
	traverse(head);
	return 0;
}

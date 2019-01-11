//Code for double linked list
#include<stdlib.h>
#include<stdio.h>

typedef struct node {
	int data;
	struct node *next;
	struct node *prev;
}Node;

void traverse(Node* head) {
	while(head!=NULL) {
		printf("%d ",head->data);
		head = head->next;
	}
	printf("\n");
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
				head->prev = NULL;
				head->data = d;
				temp = head;
			}
			else {
				Node *tmp = (Node *)malloc(sizeof(Node));
				tmp->next = NULL;
				tmp->data = d;
				temp->next = tmp;
				tmp->prev = temp;
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
	traverse(head);
	Node *revHead = head;
	while(revHead->next!=NULL){
		revHead = revHead->next;
	}
	//traverse(revHead);
	int pos;
	printf("Enter no to retrive from last position :");
	scanf(" %d", &pos);
	pos--;
	temp = revHead;
	for(int i=0;i<pos;i++){
		if(temp!=NULL) {
			temp = temp->prev;
		}
		else {
			printf("No such position.\n");
			break;
		}
	}
	if(temp!=NULL) {
		printf(" %d is at %d position from last in the list\n",temp->data,pos+1);
	}

	return 0;
}

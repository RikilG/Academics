//Code for circular linked list
#include<stdlib.h>
#include<stdio.h>

typedef struct node {
	int data;
	struct node *next;
}Node;

void traverse(Node* head) {
	Node* act = head;
	while(head!=NULL) {
		printf("%d ",head->data);
		head = head->next;
		if(head == act) {
			head = NULL;
		}
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
	
	temp->next = head;
	traverse(head);
	int pos;
	printf("Enter no to retrive from last position : ");
	scanf(" %d", &pos);
	pos--;
	Node *ptr = head;
	while(ptr->next!=head) {
		ptr= ptr->next;
		count++;
	}
	if(pos>count) {
		printf("No such position is possible.\n");
		return 0;
	}
	temp = head;
	for(int i=0;i<count-pos;i++){
		temp = temp->next;
	}
	printf(" %d is at %d position from last in the string\n",temp->data,pos+1);

	return 0;
}

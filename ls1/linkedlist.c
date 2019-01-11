//Code for single linked list
#include<stdlib.h>
#include<stdio.h>

typedef struct node {
	int data;
	struct node *next;
}Node;

int main() {

	Node *head,*temp;
	printf("Enter size of linked list : ");
	int size;
	scanf(" %d",&size);
	for(int i=0;i<size;i++) {
		int d;
		printf("Enter node %d data : ",i+1);
		scanf(" %d",&d);
		if(i==0) {
			head = (Node*)malloc(sizeof(Node));
			head->next = NULL;
			head->data = d;
			temp = head;
			continue;
		}
		Node *tmp = (Node *)malloc(sizeof(Node));
		tmp->next = NULL;
		tmp->data = d;
		temp->next = tmp;
		temp = temp->next;
	}

	return 0;
}

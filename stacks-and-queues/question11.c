/*
Implement a queue using linked list

//The circular array case rear was always incremented before inserting element and front was incrementing
before deleting element, to save the space. In this case both rear and front can point to the same
element in the begining and while removing no need to increment front for removal. Front is incremented
after removal
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
} *rear = NULL,*front = NULL;

struct node *newNode(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

void enqueue(int data){
	struct node *temp = newNode(data);
	if(!rear){
		rear = front = temp;
		return;
	}
	rear->next = temp;
	rear = rear->next;
}

int dequeue(){
	if(!front){
		return -1;
	}
	struct node *temp = front;
	front = front->next;
	if(!front){
		front = rear= NULL;
	}
	return temp->data;
}

int main(){
	int step; int elm;
	int data;
	
	while(1){
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Exit\n");
		scanf("%d",&step);
		switch(step){
			case 1: printf("enter element\n");
				scanf("%d", &elm);
				enqueue(elm);
				break;
			case 2: data = dequeue();
				if(data < 0){
					printf("queue is now empty\n");
				}else{
					printf("%d was removed\n", data);
				}
				break;
			case 3: exit(1);
				break;
		}

	}
	return 0;
}
/*
Move the last node to the begining of a linked list
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;

};

void printList(struct node *t, struct node *head){
	//printing
	while(t){
		printf("%d --> ", t->data);
		t=t->link;
	}
	printf("\n");
	//head points to
	printf("head is at: %d\n", head->data);	
}

int main(){

	struct node *head = (struct node *)malloc(sizeof(struct node));
	
	struct node *t;
	t = head;

	int counter = 1; //creating a list dynamically
	while(counter <=5){
		t->data = counter*10;	
		if(counter == 5){
			t->link = NULL;
		}else{
			t->link = (struct node *)malloc(sizeof(struct node));
		}
		t = t->link;
		counter++;
	}

	t = head;
	printList(t,head);
	struct node *p;
	while(t->link){
		p = t;
		t = t->link;
	}
	t->link = NULL;
	// free(t);
	p->next = head;
	head = p;

	t = head;
	printList(t,head);

}
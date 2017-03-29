/*
Program to traverse a single linked list

Time complexity: O(n)
Space complexity: O(1)
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
	//assigning the head
	struct node *head = (struct node *)malloc(sizeof(struct node));
	
	struct node *t;
	t = head;

	int counter = 1; //creating a list dynamically
	while(counter <=10){
		t->data = counter*10;	
		if(counter == 10){
			t->link = NULL;
		}else{
			t->link = (struct node *)malloc(sizeof(struct node));
		}
		t = t->link;
		counter++;
	}

	t = head;
	printList(t,head);
	
	//inserting one at the start
	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->data = 0;
	new->link = head;
	head = new;
	t= head;
	
	printList(t,head);

	t = head;
	while(t->link){
		t = t->link;
	}
	//inserting node at the end
	//t is now at the end so..
	t->link = (struct node *)malloc(sizeof(struct node));
	t = t->link;
	t->data = 200;
	t->link = NULL;
	printf("t link is %d\n", t->data);
	t = head;

	//printing the whole thing
	printList(t,head);
	t = head;

	//inserting the new node after value is 30
	while(t->data != 30){
		t = t->link;
	}
	struct node *n2 = (struct node *)malloc(sizeof(struct node));
	n2->data = 9999;
	n2->link = t->link;
	t->link = n2;

	t = head;
	printList(t,head);
	t = head;
	
	//deleting a node from beginning
	head = t->link;
	free(t);
	t = head;
	printList(t,head);
	t = head;

	//deleting node from the ending
	while(t->link->link){
		t = t->link;
	}
	
	free(t->link);
	t->link = NULL;
	t = head;
	printList(t,head);
	t = head;

	//deleting a node after value is 30
	while(t->link->data != 9999){
		t=t->link;
	}
	struct node *t1 = t->link;
	t->link = t1->link;
	free(t1);
	t = head;
	printList(t,head);
	t = head;
}
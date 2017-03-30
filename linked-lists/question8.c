/*
Given a single linked list. Check if it has a loop

Cannot be done by brute force (that is by checking for first node and then second and then third whether it is
repeating or not by traversing once for each node. There is a chance that it may enter an infinite loop 
because of a loop ahead in the linked list)

METHOD1:
we can use a hash table and store addresses in by node number as we visit each node. If an address is encountered
again that means there is a loop
Time complexity: O(n)
Space complexity: O(1)

METHOD2:
In the design of the structure itself a new field can be introduced called visited. Whenever you visit
a node make that field one. It will be initialized to zero by default.
If you visit it again it will already be one, that means linked list has a loop
Time complexity: O(n)
Space complexity: O(n) //for new field n extra bits will be used
There is another possibility that we make a normal structure and later we make a new structure with that field
and copy all that data which may take up a lot of space. (so not recommended)

METHOD3:
We can have two pointers. One fast pointer can move ahead with two nodes each time and slow pointer with one node.
If there is a loop these two pointers will definately meet at a node.
It can be proved that this will happen in less than or equal to traversal of n nodes by slow node
Time complexity: O(n)
Space complexity: O(1)
*/

//METHOD1
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};

void printList(struct node *t){
	if(t){
		//interchanging these lines will print it in reverse order
		printf("%d\n", t->data);
		printList(t->link);
	}
}

int checkLoop(struct node *head){
	int hash[10];
	int counter = 1;
	struct node *t = head;
	while(t->link){
		if(hash[t->link-head]==t->link-head){
			return 1;
		}else{
			hash[t->link-head] = t->link-head;	
		}
		t = t->link;
	}
	return 0;
}

int main(){

	struct node *head = (struct node *)malloc(sizeof(struct node));

	struct node *t = head;

	int counter = 1;
	while(counter<=5){

		t->data = counter*10;
		if(counter == 5){
			t->link = head;
		}else{
			t->link = (struct node *)malloc(sizeof(struct node));
		}

		t = t->link;

		counter++;
	}
	t = head;
	// printList(t);

	//detecting if this has a loop
	if(checkLoop(head)){
		printf("there is a loop\n");
	}else{
		printf("there is no loop\n");
	}

}

//================================================================================
//METHOD2
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	int visited;
	struct node *link;
};

void printList(struct node *t){
	if(t){
		//interchanging these lines will print it in reverse order
		printf("%d\n", t->data);
		printList(t->link);
	}
}

int checkLoop(struct node *head){
	struct node *t = head;
	while(t){
		printf("visited value is %d\n", t->visited);
		if(!t->visited){
			t->visited = 1;
		}else{
			return 1;
		}
		t = t->link;
	}
	return 0;	
}	

int main(){

	struct node *head = (struct node *)malloc(sizeof(struct node));

	struct node *t = head;

	int counter = 1;
	while(counter<=5){

		t->data = counter*10;
		t->visited = 0;
		if(counter == 5){
			t->link = NULL;
		}else{
			t->link = (struct node *)malloc(sizeof(struct node));
		}

		t = t->link;

		counter++;
	}
	t = head;
	// printList(t);

	//detecting if this has a loop
	if(checkLoop(head)){
		printf("there is a loop\n");
	}else{
		printf("there is no loop\n");
	}

}

//==============================================================================================
//METHOD3
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};

void printList(struct node *t){
	if(t){
		//interchanging these lines will print it in reverse order
		printf("%d\n", t->data);
		printList(t->link);
	}
}

int checkLoop(struct node *head){
	struct node *slow,*fast = head;
	for(slow=head,fast=head; fast && slow && fast->link;){
		fast = fast->link->link;
		slow = slow->link;
		if(slow==fast){	return 1;}	
	}
	return 0;
}	

int main(){

	struct node *head = (struct node *)malloc(sizeof(struct node));

	struct node *t = head;

	int counter = 1;
	while(counter<=5){

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
	// printList(t);

	//detecting if this has a loop
	if(checkLoop(head)){
		printf("there is a loop\n");
	}else{
		printf("there is no loop\n");
	}

}





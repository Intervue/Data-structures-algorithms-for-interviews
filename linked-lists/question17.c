/*
Consider a single linked list with each node having an arbitrary pointer with 
initial value NULL.Give an algorithm to make the arbitrary pointer point to the greatest value node on 
its right side.

METHOD1:
Naive approach where you compare each element to right of it find max for each and make arb point towards it.
Time complexity: O(n^2)
Space complexity: O(1)

METHOD2:
Reverse the list.
Find max element towards left and make arb pointer point towards it in one traversal only.
Reverse again
Time complexity: O(n)
Space complexity: O(1)
*/

//METHOD2
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *arb;
	struct node *link;
};

void printList(struct node *head){
	for(;head;head=head->link){
		if(head->arb){
			printf("%d %d --> ", head->data, head->arb->data);	
		}else{
			printf("%d %s --> ", head->data, "null");	
		}
		
	}
	printf("\n");
}

void makeList(struct node *head){
	int count = 1;
	while(count <= 5){
		head->data = count*10;
		head->arb = NULL;
		if(count == 5){
			head->link = NULL;
		}else{
			head->link = (struct node *)malloc(sizeof(struct node));
		}
		head = head->link;
		count++;
	}
}

struct node *reverseList(struct node *head){
	struct node *prev = NULL, *curr = head, *next;
	while(curr){
		next = curr->link;
		curr->link = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
	return head;
}

struct node *getMax(struct node *curr_max, struct node *prev){

	if(!curr_max){
		return (!prev)?NULL: prev;
	}
	return (curr_max->data > prev->data)? curr_max: prev;

}

void assignArb(struct node *head){
	head = reverseList(head);
	struct node *t = head;
	struct node *curr_max = NULL;
	struct node *prev = NULL;
	for(;t;t=t->link){
		curr_max = getMax(curr_max, prev);
		t->arb = curr_max;
		prev = t;
	}	

	head = reverseList(head);
}

int main(){

	struct node *head = (struct node *)malloc(sizeof(struct node));
	makeList(head);
	assignArb(head);
	printList(head);
	return 0;
}
/*
Implement stack with push ,pop, find middle element, delete middle element in 0(1)

METHOD1:
Using arrays.
Pop and push & finding middle can be done in O(1), but deleting middle will require moving the remaining
elements to fill the gap made which will take O(n) time, so not the right data structure for this algo

METHOD2:
Using single linked list
Pop and push can be done in O(1) but finding middle will take O(n) every time as we can only traverse the
list in one direction and each time if an element is removed or list is updated we cannot move it
backwards when element is removed. Hence we will have to compute find middle each time even if we have to 
delete the middle element. So not the right DS for this algo

METHOD3:
Using double linked list
In this push and pop will take O(1) time and finding middle can be done using a ptr and deleting middle
will even take O(1) time. Even if the list is updated we can move the middle ptr in both the directions
to update the middle value which makes it the right DS for this approach
*/
//METHOD3
#include <stdio.h>
#include <stdlib.h>

struct node *head = NULL;
struct node *middle = NULL;

struct node{
	int data;
	struct node *prev, *next;
};

void push(int data){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode == NULL){
		printf("heap memory is full\n");
		return;
	}
	newnode->data = data;
	newnode->prev = NULL;
	if(head){
		head->prev = newnode;
	}
	newnode->next = head;
	head = newnode;
}

int pop(){
	if(head == NULL){
		return -1;
	}
	middle = middle->next;
	struct node *temp = head;
	head = head->next;
	if(head){
		head->prev = NULL;	
	}
	int result = temp->data;
	free(temp);
	return result;
}

void getMiddle(){
	if(head == NULL){
		middle = head;
		return;
	}
	struct node *t = head, *fast= head;
	while(fast->next){
		t=t->next;
		fast = fast->next->next;
	}
	middle = t;
}

int deleteMiddle(){ 
	if(middle == NULL){
		return -1;
	}
	struct node *t = middle;
	int result = t->data;
	middle->prev = middle->next;
	middle->next->prev = middle->prev;
	free(t);
	return result;
}

int main(){
	int result,elm,step;

	while(1){
		printf("1. PUSH element\n");
		printf("2. POP element\n");
		printf("3. Get Middle\n");
		printf("4. Delete Middle\n");
		printf("5. EXIT \n");
		scanf("%d",&step);

		switch(step){
			case 1: printf("enter element to be pushed\n");
				scanf("%d",&elm);
				push(elm);
				break;
			case 2: result = pop();
				if(result < 0){
					printf("already empty\n");
				}else{
					printf("%d was popped\n", result);
				}	
				break;
			case 3:	getMiddle();
				printf("%d is the current middle element\n", middle->data);
				break;
			case 4:	result = deleteMiddle();
				if(result >= 0){
					printf("%d was deleted\n", result);
				}else{
					printf("stack is empty now\n");
				}
				break;
			case 5: exit(1);
				break;
		}
	}

	return 0;
}
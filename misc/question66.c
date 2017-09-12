/*
http://practice.geeksforgeeks.org/problems/sort-a-stack

Given a stack, sort it using recursion. 
Use of any loop constructs like while, for..etc is not allowed. 
We can only use the following ADT functions on Stack S:

is_empty(S)  : Tests whether stack is empty or not.
push(S)	     : Adds new element to the stack.
pop(S)	     : Removes top element from the stack.
top(S)	     : Returns value of the top element. Note that this
               function does not remove element from the stack.
*/

#include <stdio.h>
#include <stdlib.h>

//array of linked list using this struct
struct stack{
	int data;
	struct stack *next;
};

struct stack *head = NULL;

int top() {
	struct stack *temp = head;
	return temp->data;
}

int is_empty(){
	return head == NULL;
}

struct stack *newNode(int data){
	struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void push(int data){
	struct stack *temp = newNode(data);
	if(head){
		temp->next = head;
	}
	head = temp;
}

int pop() {
	struct stack *temp = head;
	head = head->next;
	struct stack *result = temp;
	free(temp);
	return result->data;
}

void displayStack(){
	struct stack *temp = head;
	while(temp){
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}

void insertAfterSorting(int elm) {
	//if empty just push
	if(is_empty() || elm > top()) {
		push(elm);
		return;
	}

	//if not then pop the element and try inserting this one again
	int x = pop();
	insertAfterSorting(elm);

	//push all the popped elements as recursion stack pops off
	push(x);

}

void sort() {
	if(!head){
		return;
	}
	
	int elm = pop();
	sort();
	insertAfterSorting(elm);
}

int main(){

	push(30);
    push(-5);
    push(18);
    push(14);
    push(-3);

    displayStack();

    sort();

    printf("\nafter sort..\n");
    displayStack();

	return 0;
}
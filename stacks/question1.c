/*
Implement a stack using arrays & linked-list

METHOD1: Using array
For pushing: 
Time complexity:O(1)
For popping: 
Time complexity:O(1)

METHOD2: Using linked list
For pushing: 
Time complexity:O(1)
For popping: 
Time complexity:O(1)

*/
// //METHOD1:
// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 100

// void push(int arr[],int elm, int *top){
	
// 	if(*top == MAX-1){
// 		printf("overflow\n");
// 		return;
// 	}
// 	arr[++*top] = elm;
// 	printf("VAL %d\n", *top);
// 	return;
// }

// int pop(int arr[], int *top){
	
// 	int temp;
// 	if(*top == -1){
// 		printf("underflow\n");
// 		return -1;
// 	}
// 	temp = arr[(*top)--];
// 	printf("VAL %d\n", *top);
// 	return temp;
// }
	
// int main(){
// 	int arr[MAX];
// 	int top = -1;
// 	int step, elm;

// 	while(1){
// 		printf("1. PUSH element\n");
// 		printf("2. POP element\n");
// 		printf("3.EXIT \n");
// 		scanf("%d",&step);

// 		switch(step){
// 			case 1: printf("Enter the number to be pushed\n"); 
// 				scanf("%d",&elm);
// 				push(arr,elm, &top);
// 				break;
// 			case 2: elm = pop(arr, &top);
// 				if(elm == -1){
// 					printf("Already empty\n");
// 				}else{
// 					printf("%d was popped\n", elm);	
// 				}
				
// 				break;
// 			case 3: exit(1); 
// 				break;
// 		}
// 	}

// 	return 0;
// }
//==================================================================================
//METHOD2
#include <stdio.h>
#include <stdlib.h>

struct node *head = NULL;

struct node{
	int data;
	struct node *next;
};

void push(int data){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode == NULL){
		printf("heap memory is full\n");
		return;
	}
	newnode->data = data;
	newnode->next = head;
	head = newnode;
}

int pop(){
	int data;
	if(head == NULL){
		return -1;
	}
	struct node *temp;
	temp = head;
	data = temp->data;
	head = head->next;
	free(temp);
	return data;
}
	
int main(){
	int step,elm;
	while(1){
		printf("1. PUSH element\n");
		printf("2. POP element\n");
		printf("3.EXIT \n");
		scanf("%d",&step);

		switch(step){
			case 1: printf("Enter the number to be pushed\n"); 
				scanf("%d",&elm);
				push(elm);
				break;
			case 2: elm = pop();
				if(elm == -1){
					printf("Already empty\n");
				}else{
					printf("%d was popped\n", elm);	
				}
				break;
			case 3: exit(1); 
				break;
		}
	}

	return 0;
}

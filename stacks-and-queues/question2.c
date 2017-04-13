/*
Implement a queue using circular array

For pushing: 
Time complexity:O(1)
For popping: 
Time complexity:O(1)

*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void push(int arr[], int *front, int *rear, int elm){
	*rear = (*rear+1)%MAX; //modulus after incrementing is imp.
	if(*rear == *front){
		printf("Overflow\n");
		if(*rear == 0){
			*rear = MAX - 1;
		}else{
			*rear = *rear-1;
		}
		return;
	}
	arr[*rear] = elm;
	return;
}

int pop(int arr[], int *front, int *rear){
	if(*front == *rear){ //this is where we started from when both were pointing to zero
		return -1;
	}	
	*front = (*front + 1)%MAX; //modulus after incrementing is imp.
	int data = arr[*front];
	return data;
}
	
int main(){
	int arr[MAX];
	int front,rear = 0, step, elm;

	while(1){
		printf("1. PUSH element\n");
		printf("2. POP element\n");
		printf("3.EXIT \n");
		scanf("%d",&step);

		switch(step){
			case 1: printf("Enter the number to be pushed\n"); 
				scanf("%d",&elm);
				push(arr, &front, &rear, elm);
				break;
			case 2: elm = pop(arr,&front,&rear);
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
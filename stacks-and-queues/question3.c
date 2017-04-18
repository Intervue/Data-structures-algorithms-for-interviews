/*
Implement a queue using two stacks

It means ENQUEUE and DEQUEUE should use push and pop operations inside it.

If n elements are to be inserted on to a queue implemented using two stacks and m have to be deleted
          Push Pop
Best case m+n  2m
Work Case 2n   n+m
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

void push(int arr[],int data, int *ptr){
	if(*ptr == MAX-1){
		printf("overflow\n");
		return;
	}	
	arr[++(*ptr)] = data;
}

int pop(int arr[],int *ptr){
	if(*ptr == -1){
		printf("underflow\n");
		return -1;
	}
	int data = arr[(*ptr)--];
	return data;
}

void enqueue(int arr[],int data, int *top1){
	push(arr,data,top1);
}

int dequeue(int arr1[], int arr2[],int *top1, int *top2){
	int data, result;
	if(*top2 == -1 && *top1 == -1){
		return -1;
	}else{
		while(*top1 != -1){
			data = pop(arr1,top1);
			push(arr2,data,top2);
		}
		result = pop(arr2,top2);
	}
	return result;
}

int main(){
	int stack1[MAX],stack2[MAX];
	int top1 = -1, top2 = -1;
	int step, elm, result;

	while(1){
		printf("1. PUSH element\n");
		printf("2. POP element\n");
		printf("3.EXIT \n");
		scanf("%d",&step);

		switch(step){
			case 1: printf("enter element to be pushed\n");
				scanf("%d",&elm);
				enqueue(stack1,elm, &top1);
				break;
			case 2: result = dequeue(stack1, stack2,&top1, &top2);
				if(result < 0){
					printf("already empty\n");
				}else{
					printf("%d was deleted\n", result);
				}	
				break;
			case 3: exit(1);
				break;
		}
	}

	return 0;
}
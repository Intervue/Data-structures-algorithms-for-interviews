/*
Implement a queue using two stacks

If n elements are to be inserted on to a queue implemented using two stacks and m have to be deleted
          Push Pop
Best case m+n  2m
Work Case 2n   n+m
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

void push(int arr[],int data,int *top){
	if(*top == MAX-1){
		printf("overflow\n");
		return;
	}
	arr[++*top]=data;
}

void insert(int arr[],int data, int *top){
	push(arr,data,top);
}

int pop(int arr[], int *top){
	int data = arr[*top];
	*top--;
	return data;
}

int delete(int arr2[], int arr1[],int *top2, int *top1){
	int elm;
	if(*top2==-1){
		if(*top1==-1){
			return -1; //this can be an error code
		}
	}else{
		while(*top2 >= 0){
			int data = pop(arr2, *top2);
			*top2--;
			push(arr1,data,*top1);
		}
		elm = pop(arr1,top1);
		return elm;
	}
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
				insert(stack2,elm, &top2);
				break;
			case 2: result = delete(stack2,stack1,&top2,&top1);
				if(result == -1){
					printf("already empty\n");
				}else{
					printf("%d was popped\n", result);
				}

				break;
			case 3: exit(1);
				break;
		}
	}

	return 0;
}
/*
Implement a stack using queues

It can be implemented in two ways
One is while pushing, pushing in one Q and while popping, popping from this Q and pushing in other Q and then 
popping that one
OR
While pushing, pushing in empty Q and dequeing the other one and enqueuing in this one for every push this 
can be done.

Time complexity: (depending on the method that is applied)
For each push: O(n)
For each pop: O(1)

OR
For each push: O(1)
For each pop: O(n)
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void enqueue(int arr[],int data,int *front, int *rear){
	int size = MAX;
	*rear = (*rear+1)%size;
	if(*rear == *front){
		printf("overflow\n");
		if(*rear != 0){
			*rear = *rear-1;
		}else{
			*rear = size-1;
		}
		return;
	}
	arr[*rear]=data;
}

int dequeue(int arr[], int *front, int *rear){
	int data;
	int size = MAX;
	if(*front == *rear){
		printf("already empty\n");
		return -1;
	}else{
		*front = (*front+1)%size;
		data = arr[*front];
	}
	return data;
}

void push(int q1[],int elm, int *f1, int *r1){
	enqueue(q1,elm,f1,r1);
}

int pop(int q1[],int q2[],int *f1,int *r1, int *f2, int *r2){
	int temp,data;
	if((*f1 == *r1) && (*f2==*r2)){
		printf("already empty\n");
		return -1;
	}else{
		while(*f1!=*r1){
			temp = dequeue(q1,f1,r1);
			enqueue(q2,temp,f2,r2);
		}
		data = temp;	
		while(*f2 != *r2){
			temp = dequeue(q2,f2,r2);
			enqueue(q1,temp,f1,r1);	
		}
	}
	return data;
}

int main(){
	int q1[MAX],q2[MAX],step,elm,result;
	int f1=0,r1=0,f2=0,r2=0;

	while(1){
		printf("1. PUSH element\n");
		printf("2. POP element\n");
		printf("3.EXIT \n");
		scanf("%d",&step);

		switch(step){
			case 1: printf("enter element to be pushed\n");
				scanf("%d",&elm);
				push(q1,elm, &f1,&r1);
				break;
			case 2: result = pop(q1,q2,&f1,&r1,&f2,&r2);
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

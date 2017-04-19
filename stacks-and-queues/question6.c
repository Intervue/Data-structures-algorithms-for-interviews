/*
Given an array, find the closest greater element which is present on the right side of the element

METHOD1:
naive approach where for each element you can the remaining elements to the right of it to find the greater
closest one.
Time complexity: O(n^2)
Space complexity: O(n)

METHOD2:
Here we maintain a stack. As we iterate for each element if the greatest element closest to the right is not
found, we push that element along with its index onto the stack. For each element we scan, we keep comparing 
the elements on the stack with it and popp it if it is less and we insert the element at the respective index
taken from the stack in the output array. We repeat this exercise for all elements. If element is not found
then we write -infinity in the output
Time complexity: O(n) for n pushes and n pops
Space complexity: O(n) //for stack
*/

//METHOD2
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 20
#define large -999

struct stack *stack = NULL;

struct stack{
	int data;
	int index;
};

void printFinal(int arr[], int size){
	for(int i=0; i<size; i++){
		printf("%d\n", arr[i]);
	}
}

void findClosestMaxRight(int arr[],struct stack *stack, int size, int *top){
	int output[size], index;
	for(int i=0; i<size; i++){
		if(*top == -1){
			*top = *top + 1;
			stack[*top].data=arr[i];
			stack[*top].index=i;
		}else{
			while(*top != -1){
				if(arr[i]>stack[*top].data){
					index = stack[*top].index;
					output[index]=arr[i];
					*top = *top-1;
				}else{
					break;
				}	
			}
			*top = *top + 1;
			stack[*top].data=arr[i];
			stack[*top].index=i;
		}
	}

	while(*top !=-1){
		index = stack[*top].index;
		output[index]=large;
		*top = *top-1;
	}
	printFinal(output, size);
}

int main(){
	stack = (struct stack *)calloc(MAX,sizeof(struct stack));
	int top = -1;
	int arr[] = {10,20,1,5,25,500,60};
	int size = sizeof(arr)/sizeof(arr[0]);
	findClosestMaxRight(arr,stack, size, &top);
	return 0;
}
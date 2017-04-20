/*
This is a financial problem where we have a series of n-daily price quotes and we need to calculate
span of stock's price for all n-days

Span of a stock is nothing but the count of prev consecutive days at which when the stock is sold
as compared to today there wont be any loss.

METHOD1:
naive approach.
For each number compare it with all the numbers on the left till you get a greater number and maintain
a count.
Time complexity: O(n^2)
Space complexity: O(1)

METHOD2:
We maintain a stack to push the elements on it.
As we iterate through the array containing stock prices, we compare each price with the top of the stack (
assuming first element was pushed as is), if the top of the stack is greater we push the element else,
we pop the element from the stack. If the element is popped, its index is subtracted with the one it was
compared with and 1 is subtracted from it. That is the span of the element for the current iteration.
Repeat this exercise for all the elements. Keep popping for every smaller element on the stack till you
find a greater element else keep pushing onto the stack.

Time complexity: O(n)
Space complexity: O(n)
*/

//METHOD2
#include <stdio.h>
#include <stdlib.h>

void push(int arr[],int *top, int size, int data){
	if(*top == size-1){
		printf("overflow\n");
		return;
	}
	arr[++(*top)] = data;
}

void pop(int arr[],int *top){
	if(*top == -1){
		return;
	}
	*top = *top-1;
}

void display(int arr[],int size){
	for(int i=0;i<size;i++){
		printf("%d\t", arr[i]);
	}
}

void evaluateSpan(int arr[],int size){
	int stack[size],output[size];
	int top = -1, index;

	output[0]=0;
	push(stack,&top,size,0);

	for(int i=1;i<size;i++){
		if(arr[i]>=arr[stack[top]]){
			while(top!=-1 && arr[i]>arr[stack[top]]){
				pop(stack,&top);
			}
		}
		output[i]=(top==-1)?i:i-stack[top]-1;
		push(stack,&top,size,i);
	}

	printf("output array is");
	display(output,size);

}

int main(){
	int arr[] = {1,30,10,20,25,40,26,35,45};
	int size = sizeof(arr)/sizeof(arr[0]);

	evaluateSpan(arr,size);
	return 0;
}
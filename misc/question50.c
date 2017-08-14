/*
http://practice.geeksforgeeks.org/problems/stock-span-problem/0
*/

#include <stdio.h>
#include <stdlib.h>


int top = -1;

struct pair{
	int value;
	int index;
};

struct pair stack[201];

void push(int data, int index){
	++top;
	stack[top].value = data;
	stack[top].index = index;
}

struct pair pop(){
	return stack[top--];
}

void findSpan(int *arr, int size){

	int j;
	int ref[size];
	int i;
	for(i=0;i<size;i++){
		ref[i] = 1;
	}

	ref[0] = 1;
	push(arr[0],0);

	for(i=1;i<size;i++){
		int count = 0;
		while(top >= 0 && arr[i] >= stack[top].value){
			struct pair temp = pop();
			count += ref[temp.index];
		}
		ref[i] += count;
		push(arr[i],i);
	}

	for(i=0;i<size;i++){
		printf("%d ", ref[i]);
	}
	printf("\n");
}

int main(){
	int cases;
	scanf("%d",&cases);
	int i;
	for(i=0;i<cases;++i){
		int n;
		scanf("%d",&n);
		int arr[n];
		int j;
		for(j=0;j<n;j++){
			scanf("%d",&arr[j]);
		}
		findSpan(arr, n);
	}
	return 0;
}
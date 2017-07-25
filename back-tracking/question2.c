/*
Program to generate all strings of n bits

Here we use recursion
*/

#include <stdio.h>
#include <stdlib.h>

void display(int *arr, int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void generate(int start, int end, int *arr, int size){
	if(start == end){
		display(arr,size);
		return;
	}
	arr[start] = 0;
	generate(start + 1,end, arr, size);
	arr[start] = 1;
	generate(start + 1,end, arr, size);
}

int main(){
	
	printf("enter the value of n:\n");
	int n;
	scanf("%d",&n);

	int arr[n];

	generate(0,n,arr,n);

	return 0;
}
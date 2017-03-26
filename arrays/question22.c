/*
Given an array of n-integers, construct product array such that prod[i] is 
equal to product of all elements except arr[i] without using division operator

NOTE: we can find the product of all the elements and divide by the respective element which is not to be included, 
but since division is not allowed we cannot use it

METHOD1
we can use a for loop and apply continue statement on the index which is not required
Time complexity: O(n^2)
Space complexity: O(1)

METHOD2
we can use two temp array two include cumulative product from left and right respectively.
Then we combine the two results to get result for each index
Time complexity: O(n)
Space complexity: O(n)
*/

//METHOD1
#include <stdio.h>
#include <stdlib.h>

int findProd(int index, int arr[],int size){
	int prod = 1;
	for(int j=0; j<size;j++){
		if(j==index){
			continue;
		}
		prod = prod*arr[j];
	}
	return prod;
}

void printArr(int arr[], int size){
	for(int i=0; i<size; i++){
		printf("%d\n", arr[i]);
	}
}

int main(){
	
	int a[] = {10,20,30,40};
	int size = sizeof(a)/sizeof(a[0]);
	int prod[size];

	for(int i=0; i<size;i++){
		prod[i] = findProd(i, a, size);
	}
	printArr(prod, size);
}

//METHOD2
#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int size){
	for(int i=0; i<size; i++){
		printf("%d\n", arr[i]);
	}
}

void computeLeftProd(int leftProd[],int parent[], int size){
	int prod = 1;
	for(int i=0; i<size; i++){
		prod = prod*parent[i];
		leftProd[i] = prod;
	}
}

void computeRightProd(int rightProd[], int parent[], int size){
	int prod = 1;
	for(int i=size-1; i>0; i--){
		prod = prod*parent[i];
		rightProd[i] = prod;
	}
}

void computeFinalArr(int final[], int left[], int right[], int size){
	for(int i=0; i<size; i++){
		if(i == 0){
			final[i] = right[i+1];
		}
		else if(i==size-1){
			final[i] = left[i-1];
		}else{
			final[i] = left[i-1]*right[i+1];	
		}
	}
}
	
int main(){
	int a[] = {10,20,30,40};
	int size = sizeof(a)/sizeof(a[0]);

	int left[size],right[size], prod[size];

	computeLeftProd(left,a,size);
	computeRightProd(right,a,size);
	computeFinalArr(prod,left,right,size);
	printArr(prod,size);
}

/*
Given an array, create a max heap

METHOD1:
Sorting in descending order for max heap and ascending for min heap
Time complexity: O(nlogn)
Space complexity: O(1)

METHOD2:
Using max heapify algorithm
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void maxHeapify(int arr[],int i, int size){
	int left = 2*i+1, right = 2*i+2;
	int heapSize = size, largest, temp;

	if(left <= heapSize-1 && arr[i] > arr[left]){
		largest = i;
	}else{
		largest = left;
	}
	if(right <= heapSize-1){
		if(arr[largest] < arr[right]){
			largest = right;	
		}
	}
	if(largest <= heapSize && largest != i){
		temp = arr[largest];
		arr[largest] = arr[i];
		arr[i] = temp;
		maxHeapify(arr,largest,size);
	}
}

void display(int arr[],int size){
	for(int i=0; i<size;i++){
		printf("%d\t", arr[i]);
	}
}

void makeHeap(int arr[],int size){
	int start = floor(size/2)-1;

	for(int i=start;i>=0;i--){
		maxHeapify(arr,i,size);
	}

	display(arr,size);
}

int main(){
	int arr[] = {9,6,5,0,8,2,1,3};
	int size = sizeof(arr)/sizeof(arr[0]);

	makeHeap(arr,size);

	return 0;
}
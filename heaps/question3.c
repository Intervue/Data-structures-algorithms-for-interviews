/*
Program to write heap sort

Time complexity: O(nlogn)
because max heapify is called n times and for nearly n/2 times the height of the tree remains same (maximum),
therefore here it will be nlogn only
*/

#include <stdio.h>
#include <stdlib.h>

void maxHeapify(int arr[],int i,int size){
	if(size < 1){
		return;
	}
	int left = 2*i+1,right=2*i+2,largest, temp, heapSize = size;
	if(left <= heapSize-1 && arr[left] > arr[i]){
		largest = left;
	}else{
		largest = i;
	}
	if(right <= heapSize-1 && arr[right] > arr[largest]){
		largest = right;
	}
	
	if(largest <= heapSize-1 && largest != i){
		temp = arr[largest];
		arr[largest] = arr[i];
		arr[i]=temp;
		maxHeapify(arr,largest,size);
	}
}

void display(int arr[],int size){
	for(int i=0;i<size;i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

void heapSort(int arr[], int size){
	int temp;
	for(int i=size-1;i>=1;i--){
		temp = arr[0];
		arr[0] = arr[i];
		arr[i]=temp;
		maxHeapify(arr,0,i);
	}
	display(arr,size);
}

int main(){
	int heap[] = {100,20,30,10,15,7,16};
	int size = sizeof(heap)/sizeof(heap[0]);

	heapSort(heap,size);

	return 0;
}
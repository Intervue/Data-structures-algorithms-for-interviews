/*
Consider n-ropes with different length. Find algo to tie up all the rope into a single rope with min cost

Cost in this case is l1+l2 (if lengths of two ropes to be combined is l1 and l2 resp)

METHOD:
This approach is similar to huffman coding. The max lies closer to root and min lies far away from root so 
that the cost can be minimized. So we repeat min more than max. Therefore we make a min heap of the given
inputs and each time we extract min twice. Combine those and insert again to the min heap

Time complexity: O(3*nlogn)+O(n) //extract min twice + insert + create min heap
Space complexity: O(1) //everything done inplace in the given input array
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void minHeapify(int *arr, int i, int size){
	int left = 2*i+1;
	int right = 2*i + 2;
	int smallest;
	int heapSize = size;
	if(left < heapSize && arr[left]<arr[i]){
		smallest = left;
	}else{
		smallest = i;
	}
	if(right < heapSize && arr[right] < arr[smallest]){
		smallest = right;
	}
	if(smallest <heapSize && smallest != i){
		swap(&arr[smallest],&arr[i]);
		minHeapify(arr,smallest,size);
	}
}

void buildMinHeap(int *arr, int size){
	int index = (size/2)-1;
	int i;
	for(i=index;i>=0;i--){
		minHeapify(arr,i,size);
	}
}

int extractMin(int *arr, int *size){
	if(*size == 0){
		return 0;
	}
	int temp = arr[0];
	arr[0] = arr[*size-1];
	*size = *size - 1;
	minHeapify(arr,0,*size);
	return temp;
}

void decreaseKey(int *arr, int *size, int key, int data){
	int i=key, temp;
	arr[i] = data;
	minHeapify(arr,i,*size);
}

void printHeap(int *arr, int size){
	printf("heap now is,.,......\n");
	for(int i=0; i<size;i++){
		printf("%d\n", arr[i]);
	}
}

int findMinCost(int *arr, int size){
	buildMinHeap(arr,size);
	printHeap(arr,size);
	int cost = 0;
	while(size > 1){
		int value = extractMin(arr,&size)+extractMin(arr,&size);
		cost += value;
		arr[size] = INT_MAX;
		size++;
		decreaseKey(arr,&size,size-1, value);
	}
	return cost;
}	

int main(){
	int size, i;
	printf("enter the size of the array\n");
	scanf("%d",&size);
	int arr[MAX];
	for(i=0;i<size;i++){
		printf("enter the %d element\n", i);
		scanf("%d",&arr[i]);
	}

	int cost = findMinCost(arr,size);	
	printf("min cost is %d", cost);
	return 0;
}


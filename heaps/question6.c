/*
Find k largest elements from an array

METHOD1:
Find max element from the array. Now output that element and replace it with the last element and decrease the
size of the array. Again find the max element and repeat the steps above. Keep doing it k times.
Time complexity: O(kn) //assuming k is less than n
Space complexity: O(1)

METHOD2:
Sort the array and display the last k elements.
Time complexity: O(nlogn)
Space complexity: O(1)

METHOD3:
Build a max heap from the given array. Delete max k times and print
Time complexity: O(n) + O(klogn) //n for building the heap klogn as for deleting max k times. If k is almost 
equal to n here, time complexity will become O(nlogn), if small then O(n)
Space complexity: O(1)

METHOD4:
Create a binary search tree from the given elements. Find the maximum each time from the BST and remove it 
fromt the tree and repeat it k times.
Time complexity: O(n^2) + O(kn) //n^2 to make the binary search tree as in worst case the tree can be skewed.
n to search for each element. Since it is done k times O(kn)
Space complexity: O(2^n) OR O(n) //BST using array or linked list

METHOD5:
Make a min heap using the first k elements in the array and assume that they are the largest k elements in the
array. Now from k+1th element start comparing each n-k remaining elements with the root of the heap and replace
if the root of the heap is smaller than that element and apply heapify again.
Repeat these steps for all n-k remaining elements and in the end the min-heap will have k largest elements 
from the array
Time complexity: O(k) + O((n-k)logk) //k for building the heap having k elements and (n-k)logk elements because
that many time minheapify will be called
Space complexity: O(1) //min heap and max heap do not require additional data structure. Same array can
be manipulated unless mentioned in the question
*/
//METHOD1 - naive so not doing
//METHOD2 - sorting and simple method done in arrays
//METHOD3
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void maxHeapify(int *arr,int i, int size){
	int left = 2*i+1;
	int right = 2*i+2;
	int temp, largest;

	if(left < size && arr[left]>arr[i]){
		largest = left;
	}else{
		largest = i;
	}
	if(right < size && arr[right]>arr[largest]){
		largest = right;
	}
	if(largest < size && largest != i){
		temp  = arr[largest];
		arr[largest] = arr[i];
		arr[i] = temp;
		maxHeapify(arr, largest, size);
	}
}

void display(int arr[],int size){
	for(int i=0; i<size;i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

void makeMaxHeap(int *arr, int size){
	int index = size/2 -1;
	for(int i=index;i>=0;i--){
		maxHeapify(arr,i,size);
	}
	display(arr,size);
}

int main(){
	int arr[MAX], size;
	printf("Enter the array size\n");
	scanf("%d",&size);
	for(int i=0; i<size;i++){
		printf("enter the %d th element\n", i);
		scanf("%d",&arr[i]);
	}

	makeMaxHeap(arr,size);	
	return 0;
}



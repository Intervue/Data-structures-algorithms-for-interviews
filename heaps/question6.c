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

int deleteMax(int *arr, int *size){
	if(*size < 1){
		return -1;
	}
	int temp = arr[0];
	arr[0]=arr[*size-1];
	arr[*size-1]=temp;
	*size = *size-1;
	maxHeapify(arr,0,*size);
	return temp;
}

void getKLargest(int *arr, int k, int size){
	if(k > size){
		printf("the value of k is incorrect\n");
		return;
	}
	int result;
	printf("first %d largest elements are: \n", k);
	for(int i=1; i<=k;i++){
		result = deleteMax(arr,&size);
		if(result > 0){
			printf("%d\n", result);
		}else{
			printf("heap is now empty\n");
			break;
		}
	}
}

int main(){
	int arr[MAX], size,k;
	printf("Enter the array size\n");
	scanf("%d",&size);
	for(int i=0; i<size;i++){
		printf("enter the %d th element\n", i);
		scanf("%d",&arr[i]);
	}

	makeMaxHeap(arr,size);	
	printf("enter the number of largest elements needed\n");
	scanf("%d",&k);

	getKLargest(arr,k, size);

	return 0;
}
//=============================================================================================
//METHOD4
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void minHeapify(int *arr,int i, int size){
	int left = 2*i+1,right=2*i+2,smallest, heapSize = size;
	if(left <= heapSize-1 && arr[i] < arr[left]){
		smallest = i;
	}else{
		smallest = left;
	}
	if(right <= heapSize-1 && arr[right] < arr[smallest]){
		smallest = right;
	}
	if(smallest <= heapSize - 1 && smallest !=i){
		swap(&arr[smallest],&arr[i]);
		minHeapify(arr,smallest,size);
	}
}

void makeMinHeapForK(int *arr, int k, int size){
	int index;
	if(k%2==0){
		index = k/2-1;
	}else{
		index = k/2;
	}
	for(int i=index; i>=0;i--){
		minHeapify(arr,i,k);
	}
}

void display(int arr[], int size){
	printf("first %d largest elements are ...\n", size);
	for(int i=0; i<size;i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

void getKLargest(int *arr, int k, int size){
	int temp;
	for(int i=k; i<size;i++){
		if(arr[i]>arr[0]){
			temp = arr[i];
			arr[i] = arr[0];
			arr[0] = temp;
			minHeapify(arr,0,k);
		}
	}

	display(arr,k);
}

int main(){
	int arr[MAX], size,k,temp;
	printf("Enter the array size\n");
	scanf("%d",&size);
	for(int i=0; i<size;i++){
		printf("enter the %d th element\n", i);
		scanf("%d",&arr[i]);
	}

	printf("Enter the value of k\n");
	scanf("%d",&k);

	makeMinHeapForK(arr,k,size);

	getKLargest(arr,k,size);
	
	return 0;
}


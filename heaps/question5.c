/*
Build a min-heap and write algo to delete an arbitrary element


Time complexity: O(n) 
because finding that element will take O(n) time linear search and deleting will take O(logn) time
Total in O(n)
Space complexity: O(1)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void minHeapify(int *arr,int i, int size){
	int left = 2*i+1,right=2*i+2,smallest, heapSize = size;
	if(left < heapSize-1 && arr[i] < arr[left]){
		smallest = i;
	}else{
		smallest = left;
	}
	if(right < heapSize-1 && arr[right] < arr[smallest]){
		smallest = right;
	}
	if(smallest < heapSize - 1 && smallest !=i){
		swap(&arr[smallest],&arr[i]);
		minHeapify(arr,smallest,size);
	}
}

void buildMinHeap(int *arr, int size){
	int index = floor(size/2);
	printf("value of index is...%d\n", index);
	for(int i=index; i>=0;i--){
		minHeapify(arr,i,size);
	}
}

void display(int *arr,int size){
	for(int i=0;i<size;i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

int deleteElement(int *arr, int index, int *size){
	if(*size < 1){
		return -1;
	}
	int result = arr[index];
	int temp = arr[index];
	arr[index]=arr[*size-1];
	arr[*size-1]=temp;
	*size = *size-1;
	minHeapify(arr,index,*size);
	return result;
}

int findIndex(int *arr, int size, int value){
	for(int i=0;i<size;i++){
		if(arr[i]==value){
			return i;
		}
	}
	return -1;
}

int main(){
	int *arr, size, elm, result;
	printf("enter the size of the min-heap\n");
	scanf("%d",&size);
	arr = (int *)malloc(sizeof(int)*size);

	for(int i=0; i<size;i++){
		printf("enter %d th element\n", i);
		scanf("%d",&arr[i]);
	}

	buildMinHeap(arr,size);
	display(arr, size);

	while(1){
		printf("enter the element to be deleted\n");
		scanf("%d",&elm);
		int index  = findIndex(arr,size,elm);
		if(index >= 0){
			result = deleteElement(arr,index,&size);
			if(result < 0){
				printf("underflow\n");
			}else{
				printf("%d was removed\n", result);
			}
			printf("updated heap is..\n");
			display(arr,size);
		}else{
			printf("element not found\n");
		}
	}
	return 0;
}
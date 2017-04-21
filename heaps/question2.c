/*
Given a max heap, apply different heap operations 
(find max, delete max,increase key, insert key, decrease key.)
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define large INT_MIN
#define MAX_VALUE 100

void display(int arr[], int size){
	printf("new heap is..\n");
	for(int i=0;i<size;i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

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

int deleteMax(int arr[], int *size){
	if(*size < 1){
		return -1;
	}
	int result = arr[0];
	arr[0] = arr[*size-1];
	*size = *size-1;
	maxHeapify(arr,0,*size);
	return result;
}

int increaseKey(int arr[], int index, int value, int size){
	if(size < 1){
		return -1;
	}
	if(value < arr[index]){
		return -2;
	}
	int i=index, temp;
	arr[i] = value;

	while(i>=1 && arr[(i-1)/2]<arr[i]){
		temp = arr[i/2];
		arr[(i-1)/2] = arr[i];
		arr[i]=temp;
		i = (i-1)/2;
	}
	return value;
}

int decreaseKey(int arr[], int index, int value, int size){
	if(size < 1){
		return -1;
	}
	if(value > arr[index]){
		return -2;
	}
	int i=index, temp;
	arr[i] = value;
	maxHeapify(arr,i,size);
	return value;
}

int findMax(int arr[],int size){
	printf("size value is .. %d\n", size);
	if(size == 0){
		return -1;
	}
	return arr[0];
}

int main(){
	int heap[MAX_VALUE]={9,8,5,3,6,2,1,0}; //max heap
	int size = 8;

	int step, value, max, result, index;

	while(1){
		printf("1. find max element \n");
		printf("2. delete max element \n");
		printf("3. increase key \n");
		printf("4. decrease key \n");
		printf("5. insert key \n");
		printf("6. exit \n");
		scanf("%d",&step);

		switch(step){
			case 1: max = findMax(heap,size);
				if(max < 0){
					printf("heap is empty\n");
				}else{
					printf("max value is %d\n", max);
				}
				break;
			case 2: result = deleteMax(heap,&size);
				if(result < 0){
					printf("heap is already empty\n");
				}else{
					printf("%d was deleted\n", result);
				}
				display(heap,size);
				break;
			case 3: printf("enter the index you want to increase\n");
				scanf("%d",&index);
				printf("enter the new value\n");
				scanf("%d",&value);
				result = increaseKey(heap,index,value,size);
				if(result == -1){
					printf("heap is already empty\n");
				}else if(result == -2){
					printf("value is less than current value at that index\n");
				}else{
					printf("updated value is ..%d\n", result);
				}		
				display(heap,size);	
				break;
			case 4: printf("enter the index you want to decrease\n");
				scanf("%d",&index);
				printf("enter the decreased value\n");
				scanf("%d",&value);
				int output = decreaseKey(heap,index,value,size);
				if(output == -1){
					printf("heap is already empty\n");
				}else if(output == -2){
					printf("value is greater than current value at that index\n");
				}else{
					printf("updated value is ..%d\n", output);
				}		
				display(heap,size);	
				break;
			case 5: printf("enter the value to be inserted\n");
				scanf("%d",&value);
				size = size+1;
				if(size == MAX_VALUE){
					printf("heap memory full\n");
					return 0;
				}
				heap[size-1] = INT_MIN;
				result = increaseKey(heap,size-1,value,size);
				if(output == -1){
					printf("heap is already empty\n");
				}else if(output == -2){
					printf("value is lesser than current value at that index\n");
				}else{
					printf("updated value is ..%d\n", output);
				}		
				display(heap,size);	
				break;
			case 6: exit(1);
				break;
		}

	}

}
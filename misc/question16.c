/*
http://practice.geeksforgeeks.org/problems/chinky-and-diamonds/0
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>


void maxHeapify(int *arr, int i, int size){

	int left = 2*i + 1;
	int right = 2*i + 2;
	int largest,temp;
	if(left <= size-1 && arr[left] > arr[i]){
		largest = left;
	}else{
		largest = i;
	}

	if(right <= size-1 && arr[right] > arr[largest]){
		largest = right;
	}

	if(largest <= size-1 && i != largest){
		temp = arr[largest];
		arr[largest] = arr[i];
		arr[i] = temp;
		maxHeapify(arr,largest,size);
	}

}

int extractMax(int *arr, int *size){
	if(*size < 1){
		return 0;
	}
	int result = arr[0];
	arr[0] = arr[*size-1];
	*size = *size - 1;
	maxHeapify(arr,0,*size);
	return result;
}


void maxHeap(int *arr, int size){
	int mid = (size/2)-1;
	int i;
	for(i=mid;i>=0;i--){
		maxHeapify(arr,i,size);
	}

}

void increaseKey(int *arr, int index, int key, int size){
	if(size < 1){
		return;
	}
	arr[index] = key;
	int i = index, temp;
	while(i>=1 && arr[(i-1)/2] < arr[i]){
		temp = arr[(i-1)/2];
		arr[(i-1)/2] = arr[i];
		arr[i] = temp;
		i = (i-1)/2;
	}
}

int maxDiamonds(int size, int min, int *arr){

	maxHeap(arr,size);

	int sum = 0;

	int i;
	for(i=0;i<min;i++){

		int key = extractMax(arr,&size);
		sum += key;
		key = key/2;

		size = size + 1;
		arr[size-1] = INT_MIN;

		increaseKey(arr,size-1,key,size);
	}

	return sum;
}

int main(){
	int cases;
	scanf("%d",&cases);
	int i;
	for(i=0;i<cases;i++){
		int n,k;
		scanf("%d %d",&n,&k);
		int arr[100000];
		int j;
		for(j=0;j<n;j++){
			scanf("%d",&arr[j]);
		}

		printf("%d\n", maxDiamonds(n,k,arr));

	}
	return 0;
}
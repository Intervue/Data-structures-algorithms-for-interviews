/*
Find a max element in a min-heap

TIme complexity: O(n)

We know that the max element in a min-heap is going to be in the leaves only.
There are atleast n/2 leaves and if we scan through these elements (which is the only way), it will take
O(n) time
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findMax(int arr[], int size){
	int index = floor(size/2) + 1;
	int max = arr[index];
	for(int i=index+1;i<size;i++){
		if(arr[i]>max){
			max = arr[i];
		}
	}

	return max;

}

int main(){	
	int minHeap[] = {1,3,5,7,9,8,10,11,12};
	int size = sizeof(minHeap)/sizeof(minHeap[0]);
	int max = findMax(minHeap, size);

	printf("max element in the min heap is %d\n", max);

	return 0;
}
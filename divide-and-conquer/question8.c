/*
Given an array with 2n integer in the formal a1,a2,a3...b1,b2,b3.. 
Shuffle the array to a1b1 a2b2 a3b3 ...

Lets say the array is 1 2 3 4 | 5 6 7 8
outout should be 15 26 37 48

METHOD1:
Simply maintain two pointers, one at start and one at mid+1, and make a new array of equal size
and write to that array these values one by one and increment them.
Time complexity: O(n)
Space complexity: O(n)

METHOD2:
Using binary search. Here we break the solutions into two parts and take the second half of the
first part and first half of the second part and swap them. Then we divide the left and right halves
again into two parts, and repeat the above steps till our size goes to 2 we keep doing that.
One it is 2 we will have the desired solution.
Time complexity: O(nlogn) //same as merge sort because at each step work done will be equal to
dividing the array into two parts T(n/2) + swapping O(n)
Space complexity: O(logn) //height of the binary tree formed, which will be the space occupied by
the stack
*/
//METHOD1 is too simple
//METHOD2
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void combineArrays(int *arr, int start, int end, int size){
	if(end-start+1 <= 2){
		return;
	}
	int mid = (start + end)/2;
	int i=(start+mid+1)/2,j=mid+1;
	while(i<=mid && j<=(mid+end)/2){
		swap(&arr[i],&arr[j]);
		for(int i=0; i<size;i++){
			printf("%d\t", arr[i]);
		}
		i++;j++;
	}
	combineArrays(arr,start,mid, size);
	combineArrays(arr,mid+1,end, size);
}

void combineArraysIterative(int *arr, int start, int end, int size){
	// int counter = 0;
	while(end-start+1>2){
		int mid = (start+end)/2;
		int i=(start+mid+1)/2,j=mid+1;
		while(i<=mid && j<=(mid+end)/2){
			printf("swapping %d and %d\n", arr[i], arr[j]);
			swap(&arr[i],&arr[j]);
			i++;j++;
		}
		if(end-start+1 <= 2){
			end = mid;	
		}
		if(end-start+1 > 2){
			start = mid+1;
			// counter++;
		}
	}
}

int main(){
	int arr[] = {1,2,3,4,5,6,7,8};
	int size = sizeof(arr)/sizeof(arr[0]);
	combineArraysIterative(arr,0,size-1,size);

	for(int i=0; i<size;i++){
		printf("%d\n", arr[i]);
	}	
	return 0;
}
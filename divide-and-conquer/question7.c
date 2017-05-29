/*
Given an array containing 1's and 0's in which all 0's appear before all 1's, count the number of 1's in 
the array

METHOD1:
linear search and sum
Time complexity: O(n)
Space complexity: O(1)

METHOD2:
Binary search to find where 1 starts
Time complexity: O(logn)
Space complexity: o(1)  or O(logn) //iterative or recursive
*/
#include <stdio.h>
#include <stdlib.h>

int countOnes(int *arr, int start, int end,int size){
	if(start > end){
		return -1;
	}
	int mid = (start + end)/2;
	if(arr[mid] && !arr[mid-1]){
		return (size-mid);
	}
	if(arr[mid] && arr[mid-1]){
		return countOnes(arr,start,mid-1, size);
	}
	return countOnes(arr,mid+1,end,size);
}

int countOnesIterative(int *arr, int start, int end, int size){
	while(start <= end){
		int mid = (start + end)/2;
		if(arr[mid] && !arr[mid-1]){
			return (size-mid);
		}
		if(arr[mid] && arr[mid-1]){
			start = start;
			end = mid-1;
		}else{
			start = mid + 1;
			end = end;
		}
	}
}

int main(){
	int arr[] = {0,0,0,0,1,1,1,1,1};
	int size = sizeof(arr)/sizeof(arr[0]);
	int count = countOnesIterative(arr,0,size-1, size);
	if(count < 0){
		printf("there are no 1s in the array\n");
	}else{
		printf("number of 1s are %d\n", count);
	}
	return 0;
}
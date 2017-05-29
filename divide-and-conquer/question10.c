/*
Find the maximum element index in an array which is first increasing and then decreasing

It means that there is an increasing sequence till i and then after that i+1 to n is a decreasing
sequence. We need to find the value of i

METHOD1:
Linear search
Time complexity: O(n)
Space complexity: O(1)

METHOD2:
Binary search. 
Here we find middle and if the element at the middle lies in the increasing sequence 
search the right array else search the left array. Also for successful condition we see the the middle
element has its immediate right and left lesser than it, then that is the required number.
Time complexity: O(logn) //because T(n/2) + O(1)
Space complexity: O(1) or O(logn) //iterative or recursive
*/
#include <stdio.h>
#include <stdlib.h>

int findIndex(int *arr,int start, int end){
	if(start > end){
		return -1;
	}
	int mid = (start+end)/2;
	if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
		return mid;
	}
	if(arr[mid] < arr[mid+1] && arr[mid] > arr[mid-1]){
		return findIndex(arr,mid+1,end); //increasing sequence search the right one
	}
	return findIndex(arr,start,mid-1);
}

int main(){
	int arr[] = {1,2,3,4,5,6,5,4,3,2,1};
	int size = sizeof(arr)/sizeof(arr[0]);
	int index = findIndex(arr,0,size-1);
	if(index < 0){
		printf("no such element exists\n");
	}else{
		printf("index with peak is %d\n", index);
	}
	return 0;
}
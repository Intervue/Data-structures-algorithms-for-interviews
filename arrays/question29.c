/*
Program to implement binary search in an array
*/

#include <stdio.h>
#include <stdlib.h>

int findElmIterative(int *arr, int start, int end, int elm){
	while(start < end){
		int mid = (start+end)/2;
		if(arr[mid] > elm){
			end = mid - 1;
		}else if(arr[mid] < elm){
			start = mid + 1;
		}else{
			return mid;
		}	
	}
	return -1;
}

int findElmRecursive(int *arr, int start, int end, int elm){
	if(start >= end){
		return -1;
	}
	int mid = (start + end)/2;
	if(arr[mid] > elm){
		return findElmRecursive(arr,start,mid-1,elm);
	}
	if(arr[mid] < elm){
		return findElmRecursive(arr,mid+1,end,elm);
	}
	return mid;
}

int main(){
	int arr[] = {2,5,8,12,16,23,38,56,72,91};
	int size = sizeof(arr)/sizeof(arr[0]);
	int elm = 23;
	int step;
	printf("1. Do Iteration\n");
	printf("2. Do Recursion\n");
	scanf("%d",&step);
	int index;
	switch(step){
		case 1: index = findElmIterative(arr,0, size-1, elm);
			break;
		case 2: index = findElmRecursive(arr,0,size-1,elm);
			break;
	}
	if(index < 0){
		printf("no such element is present\n");
	}else{
		printf("element is present at index %d\n", index);	
	}
	
	return 0;
}
/*
Given a sorted array of non repeated integers a[1--n].
Check whether there is an index i for which a[i]=i

METHOD1:
Linear search
Time complexity: O(n)
Space complexity: O(1)

METHOD2:
Ideally this question is not valid, if the numbers are starting from 1 and indexes are starting
from zero, there cannot exist a case where a[i]=i because numbers cannot repeat also and they
will atleast have to increase by one as they are sorted.

Just in case an example of repitition is taken, the way to solve the problem is using binary search
We take the middle element and see if its value is greater than index, if yes then we search on left
because it cannot exist in right as value atleast will increase by 1 each time and so does the index.
So it can never catchup. In case value is lesser then index we will search right because value
can atleast increase by one and can catch up.
Time complexity: o(logn)
Space complexity: O(logn) or O(1) //recursive or iterative
*/
#include <stdio.h>
#include <stdlib.h>

int checkIndex(int *arr, int start, int end){
	if(start > end){
		return -1;
	}
	int mid = (start+end)/2;
	if(arr[mid]==mid){
		return mid;
	}
	if(arr[mid] > mid){
		return checkIndex(arr,start,mid-1);
	}
	return checkIndex(arr,mid+1,end);
}

int checkIndexIterative(int *arr, int start, int end){
	while(start <= end){
		int mid = (start+end)/2;
		if(arr[mid] == mid){
			return mid;
		}
		if(arr[mid]>mid){
			end = mid-1;
		}else{
			start = mid+1;
		}
	}
	return -1;
}

int main(){
	int arr[] = {0,0,1,2,2,3,4,7,8};
	int size = sizeof(arr)/sizeof(arr[0]);
	int index = checkIndexIterative(arr,0,size-1);
	if(index < 0){
		printf("such an element does not exist\n");
	}else{
		printf("index at which such element exists is %d\n", index);
	}
	return 0;
}
/*
Perfect hill longest subsequence

Longest subsequence of length 2k+1 where the first k+1 are strictly increasing, and last k+1 are strictly 
decreasing.

METHOD:
Here we need to find the longest increasing sub sequence for the given array as did earlier.
We will store it in an array. In a separate array we will find longest decreasing sub sequence.

Then we will traverse both of these arrays to find the longest perfect hill sequence.
If for a number longest increasing sequence (from left) is 3 and longest decreasing sequence 
towards right is 5. that means for a perfect hill sequence numbers need to be balanced on both the sides.
There we take the min of the two and subtract 1. Multiply the number with 2 and add 1. That will be the
size of perfect hill sequence. The maximum one will be the answer

Time complexity: O(n^2) + O(n)  == O(n^2) only
//to compute LIS and LDS, then its just traversing once

Space complexity: O(n) //to store the arrays
*/
#include <stdio.h>
#include <stdlib.h>

int findMin(int a, int b){
	return (a<b)?a:b;
}

void findLis(int *arr, int *lis, int size){
	int i,j;
	lis[0] = 1;
	for(i=1;i<size;i++){
		int max = 1;
		for(j=i-1;j>=0;j--){
			int key = 1;
			if(arr[i] > arr[j]){
				key = key + lis[j];
				if(max < key){
					max = key;
				}
			}
		}
		lis[i] = max;
	}
}

void findLds(int *arr, int *lds, int size){
	int i,j;
	lds[size-1] = 1;
	for(i=size-2;i>=0;i--){
		int max = 1;
		for(j=i+1;j<size;j++){
			int key = 1;
			if(arr[i] > arr[j]){
				key = key + lds[j];
				if(max < key){
					max = key;
				}
			}
		}
		lds[i] = max;
	}
}

int computePHS(int *arr, int *lis, int *lds, int size){

	findLis(arr,lis,size);
	findLds(arr,lds,size);

	int i;
	int max = 1;
	for(i=0;i<size;i++){
		int len = (findMin(lis[i],lds[i])-1)*2 + 1;
		if(max < len){
			max = len;
		}
	}
	return max;
}

int main(){
	int arr[] = {10,15,16,9,4,3,11,1};
	int size = sizeof(arr)/sizeof(arr[0]);

	int *lis = (int *)malloc(sizeof(int)*size);
	int *lds = (int *)malloc(sizeof(int)*size);

	int max = computePHS(arr,lis, lds,size);

	printf("max length of perfect hill sequence is %d\n", max);

	return 0;
}
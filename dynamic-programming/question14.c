/*
Find the longest decreasing sub sequence in a given array

METHOD:
It remains the same as that of increasing sub sequence (question13), here either we can reverse
the array and apply that or reverse the loop

Time complexity: O(n^2)
Space complexity: O(n)
*/
#include <stdio.h>
#include <stdlib.h>

int lonDecreasingSub(int *arr, int size){
	int *sol = (int *)malloc(sizeof(int)*size);
	int i,j;
	int maxLength = 1;
	sol[size-1] = 1;
	for(i=size-2;i>=0;i--){
		int max = 1;
		for(j=i+1;j<size;j++){
			int key = 1;
			if(arr[i] > arr[j]){
				key = key + sol[j];
				// printf("key value for i =  %d and j= %d is %d\n",i,j,key);
				if(key > max){
					// printf("updating max to %d\n", key);
					max = key;
				}
			}	
		}
		// printf("sol of i =  %d is now %d\n", i, max);
		// printf("==================================\n");
		sol[i] = max;
		if(maxLength < sol[i]){
			maxLength = sol[i];
		}
	}
	return maxLength;
}

int main(){
	int *arr, size = 8;
	arr = (int *)malloc(sizeof(int)*size);

	int i;
	for(i=0;i<size;i++){
		printf("Enter the %d element\n", i);
		scanf("%d",&arr[i]);
	}

	int len = lonDecreasingSub(arr,size);
	printf("length of longest decreasing subsequence is %d\n", len);
	return 0;
}
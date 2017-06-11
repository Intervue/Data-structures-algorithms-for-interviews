/*
Max sum increasing subsequence

In this we need to find a subsequence which is increasing and has the max sum

METHOD:
We will maintain another array here and for each index this array will have the max sum resulting
from adding numbers satisfying criteria given in the question by traversing back.
Each time we keep doing that for all the numbers and then we will have the max sum possible

Time complexity: O(n^2)
Space complexity: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

int getMaxSum(int *arr, int i){
	int index, sum = 0, maxSum = 0;
	for(index = i-1; index >=0; index--){
		if(arr[i] > arr[index]){
			sum = arr[i]+arr[index];	
		}
		if(sum > maxSum){
			maxSum = sum;
		}
	}
	return maxSum;
}

void maxIncreaseSubSequence(int *arr, int size){
	int sum;
	int cumulative[size];
	int i, j, index;
	int maxSum = 0;
	cumulative[0] = arr[0];
	for(i=1; i<size;i++){
		cumulative[i] = getMaxSum(arr,i);
		if(maxSum < cumulative[i]){
			maxSum = cumulative[i];
			index = i;
		}
	}	
	printf("max sum possible in this array is %d at index %d\n", maxSum, index);
}

int main(){
	int arr[] = {20,3,1,15,16,2,12,13};

	int size = sizeof(arr)/sizeof(arr[0]);

	maxIncreaseSubSequence(arr, size);
	return 0;
}
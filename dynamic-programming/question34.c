/*

Find the max product sub array

METHOD:
Here we traverse the array from both the sides, handling corner cases.
Also the algorithm takes into account the number of negative numbers

This is not a DP question.

Another method listed at GFG
http://www.geeksforgeeks.org/maximum-product-subarray/



*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void maxProductSubArray(int *arr, int size){
	int i;
	int countNegatives = 0;
	for(i=0;i<size;i++){
		if(arr[i] < 0){
			countNegatives++;
		}
	}
	int lastCountNegativesValues = countNegatives;

	int curr = 1, max = INT_MIN;

	for(i=0;i<size;i++){
		curr = curr*arr[i];

		if(curr > max){
			max = curr;
		}

		if(arr[i] < 0){
			countNegatives--;
		}

		if((curr < 0 && countNegatives <= 0) || (curr == 0)){
			curr = 1;
		}
	}

	curr = 1;
	countNegatives = lastCountNegativesValues;

	for(i=size-1;i>=0;i--){
		curr = curr*arr[i];
		if(curr > max){
			max = curr;
		}

		if(arr[i] < 0){
			countNegatives--;
		}

		if((curr < 0 && countNegatives <= 0) || (curr == 0)){
			curr = 1;
		}
	}

	printf("%d\n", max);
}	

int main(){
	int cases;
	scanf("%d",&cases);
	int i;
	for(i=0;i<cases;i++){
		int size;
		scanf("%d",&size);
		int j;
		int arr[size];
		for(j=0;j<size;j++){
			scanf("%d",&arr[j]);
		}
		maxProductSubArray(arr, size);

	}
	return 0;
}
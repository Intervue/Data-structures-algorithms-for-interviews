/*
Find the max diff b/w two elements in an array such that larger element appears after the smaller number

METHOD1

Time complexity: O(n^2)
Space complexity: O(1)

*/
#include <stdio.h>

int main(){

	int a[] = {1,4,8,3,10,21,5};

	int length = sizeof(a)/sizeof(a[0]);

	int i,j, curr_max = 0, max,min, key;

	for(i=0; i<length; i++){
		key = a[i];
		for(j = i+1; j<length; j++){

			if(key < a[j]){

				if(a[j]-key > curr_max){
					curr_max = a[j]-key;
					max = a[j];
					min = key;

				}

			}

		}

	}	

	printf("the max difference is %d between %d and %d\n", curr_max, min, max);

}

/*
METHOD2

Time complexity: O(n)
Space complexity: O(n) //difference matrix

*/
#include <stdio.h>

int maxSum(int arr[], int size){

	int diff, currSum, maxSum, index;
	diff = arr[1]-arr[0];
	currSum = diff;
	maxSum = currSum;

	for(index=1; index<size; index++){
		diff = arr[index+1]-arr[index];
		currSum = currSum>0? currSum + diff: diff;
		if(maxSum < currSum){
			maxSum = currSum;
		}
	}

	return maxSum;

}

int main(){

	int a[] = {1,4,8,3,10,21,5};

	int length = sizeof(a)/sizeof(a[0]);
	int max = maxSum(a,length);

	printf("max sum is %d\n", max);

}

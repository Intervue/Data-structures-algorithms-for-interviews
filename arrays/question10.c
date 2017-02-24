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
find the difference array for given array and then finding max sum sub array in the difference array
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


/*
METHOD3

Finding the max number. And then find the min number in the prev numbers that lie before max number

*/
#include <stdio.h>

int maxDiff(int arr[], int size){

	int min = arr[0], maxDiff = 0, a,b;

	for(int i=1; i<size-1; i++){
		if(min > arr[i]){
			min = arr[i];
		}

		if(maxDiff < (arr[i+1]-min)){
			maxDiff = arr[i+1]-min;
			b = arr[i+1];
			a = min;
		}
	}
	printf("max diff is %d which is between %d and %d", maxDiff, a,b);
	return maxDiff;
}

int main(){
	int a[] = {4,3,10,2,9,1,6};
	int length = sizeof(a)/sizeof(a[0]);
	int max = maxDiff(a,length);
}

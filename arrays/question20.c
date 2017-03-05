/*
Find the subarray with the given sum

SUBARRAY: part of the array which is contiguous and satisfied the given condition

METHOD1
Take all possible combos
Time complexity: O(n^2)
Space complexity: O(1)

METHOD2 (only for positive numbers)
Taking two pointers and scanning. Moving start index if sum is more, more end index if sum is less
Array in worst case will be traversed twice
Time complexity: O(n)
Space complexity: O(1)

METHOD3(for both negative and positive)
Maintaining a hash for sum so far and subtracting given sum each time to see if the result is present in the hash table
If present that means sub array exists which if subtracted can give a subarray which has the req sum
Time complexity: O(n)
Space complexity: O(n)

*/

//METHOD1
#include <stdio.h>
#include <stdlib.h>

void printSubArray(int *arr,int start, int end){
	for(int i=start; i<=end;i++){
		printf("%d", arr[i]);
	}
}

int main(){
	int a[] = {5,4,6,7,9,8,3,1,2};
	int length = sizeof(a)/sizeof(a[0]);
	int start, end, sum;
	for(int i=0; i<length; i++){
		sum = 0;
		start = a[i];
		sum += start;
		for(int j=i+1; j<length; j++){
			end = a[j];
			sum += end;
			if(sum == 21){
				printSubArray(a,i,j);
			}
		}
	}
}

//METHOD2
#include <stdio.h>
#include <stdlib.h>

void printSubArray(int *arr,int start, int end){
	for(int i=start; i<=end;i++){
		printf("%d", arr[i]);
	}
}

int main(){
	int a[] = {5,4,6,7,9,8,3,1,2};
	int length = sizeof(a)/sizeof(a[0]);
	int reqSum = 27;
	int leftIndex = 0, rightIndex = 0, sum=0;

	if(a[leftIndex] == reqSum){
		printf("%d\n", a[leftIndex]);
		return 1;
	}else{
		rightIndex++;
		sum = a[leftIndex] + a[rightIndex];	
	}
	
	while(rightIndex<=length){

		if(sum == reqSum){
			printSubArray(a, leftIndex, rightIndex);
			break;
		}
		if(sum < reqSum){
			rightIndex++;
			sum += a[rightIndex];
		}else{
			int temp = leftIndex;
			leftIndex++;
			sum = sum - a[temp];
		}
	}
	if(sum != reqSum){
		printf("sub array could not be found with sum given\n");
	}

}

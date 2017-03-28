/*
Given n non negative integers representing an elevation map where width of each bar is 1. 
Find the amt. of water that is trapped in between these bars after raining

METHOD1:
Find the highest bar to the left and right of each bar including that bar.
Then take the minimum of those two and subtract it from the height of the bar. That is the amount
of water it will store for itself. Repeat for each bar.
Time Complexity: O(n^2)
Space Complexity: O(1)

METHOD2:
Find the highest bar to the left of each bar including that bar and store it in an array (left).
Repeat the above exercise for right and store in array right.
Now water it can hold will be min(left[i],right[i])-height of ith index. Find the sum of all.
Time complexity: O(n)
Space complexity: O(n)
*/

//METHOD1
#include <stdio.h>
#include <stdlib.h>

int findMin(int a, int b){
	return (a<b)?a:b;
}

int findMaxLeft(int arr[], int index){
	int max = arr[index];
	for(int i=index-1; i>=0;i--){
		if(arr[i] > max){
			max = arr[i];
		}
	}
	return max;
}

int findMaxRight(int arr[], int index, int size){
	int max = arr[index];
	for(int i=index; i<size; i++){
		if(max < arr[i]){
			max = arr[i];
		}
	}
	return max;
}

int main(){
	int arr[] = {1,0,2,0,1,3,1,0,2};
	int size = sizeof(arr)/sizeof(arr[0]);
	int sum = 0, maxLeft, maxRight, min;
	
	for(int i=1; i<size; i++){
		maxLeft = findMaxLeft(arr,i);
		maxRight = findMaxRight(arr,i, size);
		min = findMin(maxLeft, maxRight);
		sum += min-arr[i];
	}

	printf("the max amount of water it can store is %d\n", sum);
}

//METHOD2
#include <stdio.h>
#include <stdlib.h>

int findMin(int a, int b){
	return (a<b)?a:b;
}

void computeLeftMax(int arr[], int compute[],int size){
	
	int curr_max = compute[0] = arr[0];
	for(int i=1; i<size;i++){
		if(curr_max >= arr[i]){
			compute[i] = curr_max;
		}else{
			compute[i] = arr[i];
			curr_max = arr[i];
		}
	}

}

void computeRightMax(int arr[],int compute[], int size){
	int curr_max = compute[size-1] = arr[size-1];
	for(int i=size-2;i>=0;i--){
		if(curr_max >= arr[i]){
			compute[i] = curr_max;
		}else{
			compute[i] = arr[i];
			curr_max = arr[i];
		}
	}	
}

int main(){
	int arr[] = {1,0,2,0,1,3,1,0,2};
	int size = sizeof(arr)/sizeof(arr[0]);

	int leftMax[size],rightMax[size];

	computeLeftMax(arr,leftMax, size);
	computeRightMax(arr,rightMax, size);
	int sum = 0;
	for(int i=0; i<size;i++){
		sum += findMin(leftMax[i],rightMax[i]) - arr[i];
	}
	printf("the max amount of water it can store is %d\n", sum);
}

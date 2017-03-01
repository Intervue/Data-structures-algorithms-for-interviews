/*
Find the equilibrium index of an array

METHOD1:
Using two pointers i and j finding the sum from either sides and stopping when they are equal.
If right is more, incrementing left, if left is more decrementing right
Time complexity: O(n^2)
Space complexity: O(1)

METHOD2:
Take an two additional arrays. One will store the cumulative sum for left to right and other
from right to left. In a loop compare the kth with n-k remaining using these two arrays. Where the sum
is equal the value of k is the equilibrium index

Time complexity: O(n)
Space complexity: O(n)

*/


//METHOD1
#include <stdio.h>
#include <stdlib.h>

int findEquilibriumIndex(int a[],int n){
	int i = 0,j, sumLeft = 0, sumRight;

	for(i = 0;i<n-1;i++){
		sumLeft += a[i];
		sumRight = 0;
		for(j=i+1; j<n; j++){
			sumRight += a[j];
		}
		if(sumLeft == sumRight){
			return i;	
		}
	}	
	return 0;
}

int main(){
	int arr[] = {10,5,15,3,4,21,2};
	int length = sizeof(arr)/sizeof(arr[0]);

	int index = findEquilibriumIndex(arr, length);
	if(index){
		printf("equilibrium index is %d\n", index);
	}else{
		printf("no index found\n");
	}

}

//METHOD2
#include <stdio.h>
#include <stdlib.h>

int findEquilibriumIndex(int a[],int n){
	int i = 0,j;
	int sumLeft[n], sumRight[n], sum = 0;

	for(i=0; i<n-1; i++){
		sum += a[i];
		sumLeft[i] = sum;
	}
	sum = 0;
	for(j=n-1; j>0; j--){
		sum += a[j];
		sumRight[j] = sum;
	}

	for(i=0; i<n; i++){
		if(sumLeft[i] == sumRight[i+1]){
			return i;
		}
	}
	return 0;
	
}

int main(){
	int arr[] = {10,5,15,3,4,21,2};
	int length = sizeof(arr)/sizeof(arr[0]);

	int index = findEquilibriumIndex(arr, length);
	if(index){
		printf("equilibrium index is %d\n", index);
	}else{
		printf("no index found\n");
	}

}

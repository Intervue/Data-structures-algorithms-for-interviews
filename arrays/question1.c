/*
INSERTION SORT
Can be remembered as deck of cards taken one by one

Best case:
Time complexity (comparisions and movements): O(n^2)

Worst case:
Time complexity: omega(n)

For both cases:
Space complexity: O(1)

The time complexity of this algo cannot be reduced even by using binary search or linked list (instead of linear
search and arrays)
*/
#include <stdio.h>

void print_array(int a[], int n){
	for(int i = 0; i<n; i++){
		printf("%d ", a[i]);
	}
}

int main(){

	int arr[10] = {9,6,5,0,3,4,1,2, 14,10}; //input array
	int key, j, i;
	for(i = 0; i < 10; i++){
		key = arr[i];
		j = i-1;
		while(j>=0 && key < arr[j]){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1]=key; 
		//j has been decremented so in the end will be at one less than the position desired, so adding one
	}

	printf("the sorted array is:\n");
	print_array(arr,10);
}


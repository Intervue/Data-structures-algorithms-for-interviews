/*
Insertion sort
Can be remembered as deck of cards taken one by one
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


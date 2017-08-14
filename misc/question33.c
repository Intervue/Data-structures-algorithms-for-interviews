/*
http://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos/0

Arrays
*/

#include <stdio.h>
#include <stdlib.h>

void displayResult(int *arr, int size){
	
	int arr1[50],arr2[50];
	int i;
	for(i=0; i<50;i++){
		arr1[i] = -2000;
		arr2[i] = -2000;
	}
	
	
	int j=0,k=0;
	for(i=0;i<size;i++){
		if(arr[i] >= 0){
			arr1[j] = arr[i];
			j++;
		}
		if(arr[i] < 0){
			arr2[k] = arr[i];
			k++;
		}

	}

	
	int count = 0;
	i=0;
	while(count < size){
		if(arr1[i] != -2000){
			printf("%d ", arr1[i]);
			count++;	
		}
		if(arr2[i] != -2000){
			printf("%d ", arr2[i]);	
			count++;
		}
		i++;
	}
	printf("\n");
}

int main(){
	int cases;
	scanf("%d",&cases);
	int i;
	for(i=0;i<cases;i++){
		int n;
		scanf("%d",&n);
		int j;
		int arr[n];
		for(j=0;j<n;j++){
			scanf("%d",&arr[j]);
		}
		displayResult(arr, n);
	}
	return 0;
}
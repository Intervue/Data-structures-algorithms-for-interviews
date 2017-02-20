/*
MERGE PROCEDURE

Time complexity: O(n)
Space complexity: O(n)
as we are nearly creating DS of sizes same as input
*/
#include <stdio.h>
#include <math.h>

void print_array(int a[], int n){
	for(int i = 0; i<n; i++){
		printf("%d ", a[i]);
	}
}

int merge(int arr[], int p, int q, int r){
	long unsigned int f = INFINITY;
	int n1 = q-p+1;
	int n2 = r-q;	
	
	int i, j;
	int arr1[n1+1];
	int arr2[n2+1];

	for(int i=0; i<(n1);i++){
		arr1[i] = arr[i];
	}
	for(int j=0; j<(n2);j++){
		arr2[j] = arr[q+j+1];	
	}

	arr1[n1] = arr2[n2]= f;

	i=0;j=0;

	for(int z=0; z<10; z++){

		if(arr1[i] <= arr2[j]){
			arr[z] = arr1[i];
			i++;
		}else{
			arr[z] = arr2[j];
			j++;
		}

	}

	print_array(arr,10);

	return 0;
}

int main(){
	int arr1[10] = {1,2,4,8,10,3,5,7,9,11};
	merge(arr1, 0,4,9);
}

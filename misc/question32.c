/*
http://practice.geeksforgeeks.org/problems/sum-of-bit-differences/0

Bit difference
*/
#include <stdio.h>
#include <stdlib.h>

int findDifferenceinBits(int a, int b){

	// printf("finding bits for %d and %d\n", a,b);

	int arr1[4], arr2[4];

	int k;
	for(k=0;k<4;k++){
		arr1[k] = 0;
		arr2[k] = 0;
	}

	int rem, i = 0;
	// printf("for %d it is....\n",a);
	while(a > 1){
		rem = a%2;
		arr1[i] = rem;
		a = a/2;
		i++;
	}
	arr1[i] = a;

	
	// int l;
	// for(l=0;l<4;l++){
	// 	printf("%d ", arr1[l]);
	// }
	// printf("\n");

	i = 0;
	// printf("for %d it is....\n",b);
	while(b > 1){
		rem = b%2;
		arr2[i] = rem;
		b = b/2;
		i++;
	}
	arr2[i] = b;


	
	
	// for(l=0;l<4;l++){
	// 	printf("%d ", arr2[l]);
	// }
	// printf("\n");


	int sum = 0;
	int j = 3;
	for(i=3;i>=0;i--){
		
		sum += abs(arr1[j] - arr2[i]);
		j--;
	}
	return sum;
}

int sumIs(int *arr, int size){
		
	int sum = 0;	

	int i,j;
	for(i=0;i<size-1;i++){
		for(j=i+1;j<size;j++){
			sum += findDifferenceinBits(arr[i],arr[j]);
		}
	}	
	return sum*2;
}

int main(){
	int cases;
	int i;
	scanf("%d",&cases);
	for(i=0;i<cases;i++){
		int n;
		scanf("%d",&n);
		int j;
		int arr[n];
		for(j=0;j<n;j++){
			scanf("%d",&arr[j]);
		}

		printf("%d\n", sumIs(arr,n));

	}
	return 0;
}
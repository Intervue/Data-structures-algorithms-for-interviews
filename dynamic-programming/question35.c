/*
Finding the maximum square sub-matrix with all equal elements

This is similar to finding the largest square sub matrix with all 1s. The only difference here is
that the numbers can be any. So basically in this case we maintain another matrix initiazed as zero.
Then if there is a match between all the four elements, considering the right bottom most element
to be the reference, we increment the count in the ref matrix at the place as min(i,j) + 1
everytime. 

Time and space complexity is same as that of prev matrix question with all 1's

O(n^2) each

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int findMin(int a, int b){
	return a < b? a: b;
}

void initRef(int rows, int cols, int ref[rows][cols]){
	int i,j;
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			ref[i][j] = 0;
		}
	}
}

void findLargestMatrix(int rows, int cols, int arr[rows][cols]){
	
	int i, j, max = 0;	
	int a,b,c;
	int ref[rows][cols];

	initRef(rows, cols, ref);

	for(i=1;i<rows;i++){
		for(j=1;j<cols;j++){	
			a = arr[i-1][j-1];
			b = arr[i-1][j];
			c = arr[i][j-1];
			if(a == b && b == c && c == arr[i][j]){
				ref[i][j] = findMin(i,j) + 1;
				if(max < ref[i][j]){
					max = ref[i][j];
				}
			}
		}
	}

	printf("%d\n", max);
}

int main(){
	
	int arr[4][4] = {
		{9,9,9,9},
		{9,9,9,9},
		{9,9,9,9},
		{9,9,9,9}
	};

	int rows = sizeof(arr)/sizeof(arr[0]);

	int cols = sizeof(arr[0])/sizeof(arr[0][0]);

	findLargestMatrix(rows, cols, arr);

	return 0;
}
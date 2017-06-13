/*
Given a binary matrix, find the largest square sub matrix with all 1's

METHOD:
Naive approach

METHOD2:
We can assume each cell in the matrix to be the bottom right most cell of a square matrix of size starting
1X1  and check if it can be of size nXn. The way we do this is, we take this number and find the min
of the upper, left and the diagnal number to it. Whatever the min number is, if this number is 1, we add
that min to it, if its zero we simply write it as zero. Reason being a matrix containing zero cannot be
a square matrix containing all 1's. In this process we find the max size and print it.

Time complexity: O(n^2)
Space complexity: O(n^2)
*/

#include <stdio.h>
#include <stdlib.h>

int num = 4;

int findMin(int a, int b, int c){
	return (a<b)?((a<c)?a:c):((b<c)?b:c);
}

void findLargestMatrix(int arr[][num], int rows, int columns){
	int i, j;
	int myArr[rows][columns];
	int max = 0;
	
	//setting top and leftmost rows
	for(i=0; i<columns;i++){
		myArr[0][i] = (arr[0][i] == 0)?0:1;
		myArr[i][0] = (arr[i][0] == 0)?0:1;
		if(max < myArr[i][0]){
			max = myArr[i][0];
		}
		if(max < myArr[0][i]){
			max = myArr[0][i];
		}
	}

	int k,l;
	for(k=1;k<rows;k++){
		for(l=1;l<columns;l++){
			myArr[k][l] = (arr[k][l] == 1)? findMin(myArr[k-1][l], myArr[k][l-1], myArr[k-1][l-1])+arr[k][l]: 0;
			if(max < myArr[k][l]){
				max = myArr[k][l];
			}
		}
	}

	printf("max array possible is %d", max);
}

int main(){
	int arr[][4] = {
		{1,0,1,2},
		{0,1,1,1},
		{1,1,1,1},
		{0,1,1,1}
	};

	int rows = sizeof(arr)/sizeof(arr[0]);
	int columns = sizeof(arr[0][0]);

	printf("size of total %d\n", rows);
	printf("size of first row %d\n", columns);

	findLargestMatrix(arr,rows, columns);
	
	return 0;
}


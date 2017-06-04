/*
Algorithm to find optimized soln for matrix chain multiplication

METHOD1: bottom up approach.
In this the input given is an array of sizes of matrix and then we create two 2d matrices of size nXn.
The first one will store the number of operations (most optimized) required to multiply each each combination.
This will be computed using a for loop inside two other for loops which will actually traverse this matrix.
This inner for loop will actually be used to find each partition of the given number of matrices (the ways 
that they can be multiplied). The second matrix is going to store the place where the partition was done
such that we got least number of operations.

METHOD2: Top down approach: to be done later
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findOptimizedSolution(int arr[], int size){
	int num_matrices = size-1;
	int m[num_matrices][num_matrices], s[num_matrices][num_matrices];
	int i,j,k,l;
	for(i=0; i<num_matrices;i++){
		m[i][i] = 0;
	}

	for(i=1;i<num_matrices;i++){
		for(k=0; k<num_matrices-i;k++){
			j = i+k+1;
			printf("(%d, %d)\n", i,j);
			m[i][j] = INT_MAX;
			for(l=i; l<j;l++){
				int val = m[i][l] + m[l+1][j] + arr[i-1]*arr[l]*arr[j];
				if(val < m[i][j]){
					printf("updated value of (%d, %d) is %d\n", i,j,val);
					m[i][j] = val;
					s[i][j] = l;
				}
			}
			printf("-------------------------\n");
		}
	}

	
	printf("most optimized adsasdasdasd solution can be done in %d\n",m[1][num_matrices]);
}

int main(){
	int sizes[] = {1,2,1,4,1};
	int size = sizeof(sizes)/sizeof(sizes[0]);
	findOptimizedSolution(sizes, size);
	return 0;
}


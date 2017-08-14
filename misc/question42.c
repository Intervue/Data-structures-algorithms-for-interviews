/*
http://practice.geeksforgeeks.org/problems/minimum-points-to-reach-destination/0


*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int min(int a, int b){
	return a<b?a:b;
}

int max(int a, int b){
	return a>b?a:b;
}

int findPoints(int rows, int cols, int arr[rows][cols]){

	int dp[rows][cols];

	int i,j;
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			dp[i][j] = 1;
		}
	}

	dp[rows-1][cols-1] = (arr[rows-1][cols-1] > 0)?1: abs(arr[rows-1][cols-1]) + 1;

	// printf("total is ...%d \n", total);

	for(i=rows-2;i>=0;i--){
		dp[i][cols-1] = max(dp[i+1][cols-1] - arr[i][cols-1], 1);
	}

	for(j=cols-2;j>=0;j--){
		dp[rows-1][j] = max(dp[rows-1][j+1] - arr[rows-1][j], 1);
	}

	for(i=rows-2;i>=0;i--){
		for(j=cols-2;j>=0;j--){
			int minpts = min(dp[i][j+1],dp[i+1][j]);
			dp[i][j] = max(minpts - arr[i][j],1);
		}
	}

	return dp[0][0];

}

int main(){
	int cases;
	scanf("%d",&cases);
	int i;
	for(i=0;i<cases;i++){
		int rows, cols;
		scanf("%d %d", &rows, &cols);
		int arr[rows][cols];
		int k,l;
		for(k=0;k<rows;k++){
			for(l=0;l<cols;l++){
				scanf("%d", &arr[k][l]);
			}
		}

		printf("%d\n", findPoints(rows, cols, arr));

	}
	return 0;
}
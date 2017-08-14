/*
Number of paths
http://practice.geeksforgeeks.org/problems/number-of-paths/0
*/
#include <stdio.h>
#include <stdlib.h>

int totalPaths(int rows, int columns){
	int dp[rows][columns];

	int i,j;
	dp[0][0] = 0;
	for(i=1;i<columns;i++){
		dp[0][i] = 1;
	}
	for(i=1;i<rows;i++){
		dp[i][0] = 1;
	}

	for(i=1;i<rows;i++){
		for(j=1;j<columns;j++){
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}

	return dp[rows-1][columns-1];

}

int main(){
	int cases;
	scanf("%d",&cases);
	int i;
	for(i=0;i<cases;i++){
		int m,n;
		scanf("%d %d",&m, &n);
		printf("%d\n", totalPaths(m,n));
	}
	return 0;
}

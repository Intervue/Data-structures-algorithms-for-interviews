/*
http://practice.geeksforgeeks.org/problems/shortest-path-from-1-to-n/0
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findMin(int a, int b) {
	return a < b ? a : b;
}

int numEdges(int n) {

	int i,j;

	int dp[n+1][n+1];

	for(i=0;i<=n;i++){
		dp[0][i] = 0;
		dp[i][0] = 0;
	}

	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++) {
			if(j-i-1 >= 0 && j-3*i >= 0){
				dp[i][j] = 1 + findMin(dp[i][j-i-1],dp[i][j-3*i]);
			}else if(j-3*i < 0 && j-i-1 >=0){
				dp[i][j] = 1 + dp[i][j-i-1];
			}else{
				dp[i][j] = 200;
			}
		}
	}

	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			printf("%d\t", dp[i][j]);
		}
		printf("\n");
	}

	return dp[1][n];

}

int main() {
	int cases;
	int i;
	scanf("%d",&cases);
	for(i=0;i<cases;i++) {
		int n;
		scanf("%d",&n);
		printf("%d\n", numEdges(n));
	}
}
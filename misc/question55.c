/*
http://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items/0
*/

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
	return a > b? a: b;
}

int maxValue(int *weights, int *values, int size, int cap){

	int dp[size+1][cap+1];

	int i,j;
	for(i=0;i<=cap;i++){
		dp[0][i] = 0;
	}
	for(i=0;i<=size;i++){
		dp[i][0] = 0;
	}

	for(i=1;i<=size;i++){
		for(j=1;j<=cap;j++){
			if(weights[i-1] <= j) {
				dp[i][j] = max(values[i-1] + dp[i][j-weights[i-1]], dp[i-1][j]);
			}else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[size][cap];
}

int main(){
	int cases;
	int i;
	scanf("%d", &cases);
	for(i=0;i<cases;++i){
		
		int n, w;
		scanf("%d %d", &n, &w);
		int weights[n], values[n];
		int j;
		for(j=0;j<n;j++){
			scanf("%d", &values[j]);
		}
		for(j=0;j<n;j++){
			scanf("%d", &weights[j]);
		}

		printf("%d\n", maxValue(weights, values, n, w));

	}
	return 0;
}
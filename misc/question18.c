/*
Min coin
http://practice.geeksforgeeks.org/problems/min-coin/0
*/
/*
Min coin
http://practice.geeksforgeeks.org/problems/min-coin/0
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minCoins(int *arr, int n, int amount){
		
	int dp[amount+1];
	dp[0] = 0;
	int i,j;
	for(i=1;i<=amount;i++){
		dp[i] = 2000;
	}	
	
	for(j=0;j<n;j++){
		for(i=1;i<=amount;i++){
			if(i >= arr[j]){
				if(dp[i-arr[j]] + 1 < dp[i]){
					dp[i] = dp[i-arr[j]] + 1;
				}
			}
		}
	}
			

	if(dp[amount] == 2000){
		return -1;
	}

	return dp[amount];
}

int main(){
	int cases;
	scanf("%d", &cases);
	int i;
	for(i=0;i<cases;i++){
		int n, amount;
		scanf("%d %d",&n, &amount);
		int arr[n];
		int j;
		for(j=0;j<n;j++){
			scanf("%d", &arr[j]);
		}
		printf("%d\n", minCoins(arr,n,amount));
	}
	return 0;
}

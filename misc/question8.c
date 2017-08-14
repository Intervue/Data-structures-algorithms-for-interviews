#include <stdio.h>
#include <stdlib.h>

int subsetSum(int *arr, int n, int sum){
	int dp[n+1][sum + 1];

	int i,j;

	dp[0][0] = 1;

	for(i=1;i<=sum;i++){
		dp[0][i] = 0;
	}

	for(i=1;i<=n;i++){
		dp[i][0] = 1;
	}

	int max = 0;

	for(i=1; i<=n; i++){
		for(j=1;j<=sum;j++){
			if(arr[i-1] <= j){
				dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
			}else{
				dp[i][j] = dp[i-1][j];
			}
			if(j == sum){
				if(max < dp[i][j]){
					max = dp[i][j];
				}	
			}
			
		}
	}

	return max;

}


int main(){
	int cases;
	scanf("%d", &cases);
	int i, sum;

	for(i=0;i<cases;i++){
		int n;
		scanf("%d", &n);
		int j;
		int arr[n];
		for(j=0;j<n;j++){
			scanf("%d",&arr[j]);
		}
		scanf("%d", &sum);
		printf("%d\n", subsetSum(arr,n, sum));
	}
	return 0;
}
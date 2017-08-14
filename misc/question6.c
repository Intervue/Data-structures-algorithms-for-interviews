/*
http://practice.geeksforgeeks.org/problems/pick-values/0
*/

#include <stdio.h>
#include <stdlib.h>

int findMin(int start, int end, int *arr){
	int min = arr[start];
	int i;
	for(i=start + 1; i <= end; i++){
		if(min > arr[i]){
			min = arr[i];
		}
	}
	return min;
}

int calculate(int *arr, int n){
	int dp[n];

	if(n == 1){
		return arr[0];
	}
	if(n == 2){
		return findMin(0,1,arr);
	}
	if(n == 3){
		return findMin(0,2,arr);
	}
	if(n == 4){
		return findMin(0,3,arr);
	}

	dp[0] = arr[0];
	dp[1] = arr[1];
	dp[2] = arr[2];
	dp[3] = arr[3];

	int i;
	for(i=4; i<n; i++){
		dp[i] = arr[i] + findMin(i-4,i-1,dp);
	}


	return findMin(n-4,n-1, dp);

}

int main(){
	int cases;
	scanf("%d", &cases);
	int i;
	for(i=0;i<cases;i++){
		int n;
		scanf("%d",&n);
		int arr[n];
		int j;
		// printf("value of n is: %d\n", n);
		for(j=0;j<n;j++){
			scanf("%d",&arr[j]);
		}
		printf("%d\n", calculate(arr, n));
	}
	return 0;
}
/*
http://practice.geeksforgeeks.org/problems/letter-writer/0
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 3000

int min(int a, int b) {
	return a < b? a: b;
}

int minHours(int hours) {

	int arr[]  = {10,12};
	int size = sizeof(arr)/sizeof(arr[0]);
	int dp[size+1][hours+1];

	int i,j;

	for(i=0;i<=size;i++) {
		for(j=0;j<=hours; j++) {
			dp[i][j] = MAX;
		}
	}

	for(i=1;i<=hours;i++){
		dp[0][i] = MAX;
	}

	for(i=0;i<=size;i++) {
		dp[i][0] = 0;
	}

	for(i=1;i<=size;i++){
		for(j=1;j<=hours;j++) {
			if(arr[i-1] <= j) {
				dp[i][j] = min(1 + dp[i][j-arr[i-1]], dp[i-1][j]);
			}else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	if(dp[size][hours] == MAX) {
		return -1;
	}

	return dp[size][hours];

}

int main(){
	int cases;
	int i;
	scanf("%d", &cases);
	for(i=0;i<cases;++i){
		
		int n;
		scanf("%d",&n);

		printf("%d\n", minHours(n));

	}
	return 0;
}
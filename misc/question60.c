/*
http://practice.geeksforgeeks.org/problems/cutted-segments/0

This is similar to coin sum problem just that max coins are to be found
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int max(int a, int b){
	return a > b? a:b;
}

int cuttedSegments(int length, int x, int y, int z) {

	int arr[] = {x,y,z};
	int size = sizeof(arr)/sizeof(arr[0]);		
	
	int dp[size+1][length+1];
	int i,j;
	for(i=0;i<=size;i++){
		dp[i][0] = 0;
	}

	for(i=0;i<=length;i++){
		dp[0][i] = INT_MIN;	
	}

	dp[0][0] = 0;
	
	for(i=1;i<=size;i++){
		for(j=1;j<=length;j++){
			if(arr[i-1] <= j){
				dp[i][j] = max(1+dp[i][j-arr[i-1]], dp[i-1][j]);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[size][length];


}

int main(){	
	
	int cases;
	scanf("%d",&cases);
	int i;
	for(i=0;i<cases;i++){
		int n;
		scanf("%d",&n);
		int x,y,z;
		scanf("%d %d %d",&x, &y,&z);

		printf("%d\n", cuttedSegments(n,x,y,z));

	}
	return 0;
}

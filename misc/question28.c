/*
Minimum steps
http://practice.geeksforgeeks.org/problems/minimum-steps/0
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int findMin(int a,int b){
	return a>b?a:b;
}

int totalWays(int stairs, int x, int y){
	int arr[100000];
	int size = 0;

	int i  = 1;

	int num1 = x;
	int num2 = y;

	while(num1 <= stairs || num2 <= stairs){
		if(num1 <= stairs){
			arr[i-1] = num1;	
			size++;
			num1 = num1*x;
			i++;	
		}
		if(num2 <= stairs){
			arr[i-1] = num2;	
			size++;
			num2 = num2*y;	
			i++;
		}
	}
	
	int dp[stairs+1];
	dp[0] = 0;
	int j;
	
	for(j=0;j<size;j++){
		for(i=1;i<=stairs;i++){
			if(dp[i] == 0){
				dp[i] = 1000001;
			}
			if(i >= arr[j]){
				if(dp[i-arr[j]] + 1 < dp[i]){
					dp[i] = dp[i-arr[j]] + 1;
				}
			}
		}
	}
			

	if(dp[stairs] == 1000001){
		return -1;
	}

	return dp[stairs];
}

int main(){
	int cases;
	scanf("%d",&cases);
	int i;
	for(i=0;i<cases;i++){
		int p,x,y;
		scanf("%d %d %d",&p,&x,&y);
		printf("%d\n", totalWays(p,x,y));
	}
	return 0;
}
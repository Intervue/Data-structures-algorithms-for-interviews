/*
http://practice.geeksforgeeks.org/problems/maximize-dot-product/0

Maximum dot product
*/

#include <stdio.h>
#include <stdlib.h>

unsigned long long int findMax(unsigned long long int a, unsigned long long int b){
	return a>b?a:b;
}

unsigned long long int findProd(int lenA, int lenB, unsigned long long int *arrayA, unsigned long long int *arrayB){

	int i,j;
	unsigned long long int dp[lenA + 1][lenB + 1];

	for(i=0;i<=lenA;i++){
		dp[i][0] = 0;
	}
	for(i=0;i<=lenB;i++){
		dp[0][i] = 0;
	}

	for(i=1;i<=lenA;i++){
		for(j=1;j<=lenB;j++){
			dp[i][j] = findMax(arrayA[i-1]*arrayB[j-1] + dp[i-1][j-1], dp[i-1][j]);
		}
	}

	return dp[lenA][lenB];

}

int main(){

	int cases;
	scanf("%d",&cases);
	int i;
	for(i=0;i<cases;i++){
		int n,m;
		scanf("%d %d",&n,&m);
		int j;
		unsigned long long int arrayA[n],arrayB[m];
		for(j=0;j<n;j++){
			scanf("%lld", &arrayA[j]);
		}
		for(j=0;j<m;j++){
			scanf("%lld", &arrayB[j]);
		}

		printf("%llu\n",findProd(n,m,arrayA,arrayB));

	}

	return 0;
}
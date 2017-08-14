/*
Good pairs
*/

#include <stdio.h>
#include <stdlib.h>

int cmpfnc(const void *a, const void *b){
	return (*(int *)a - *(int *)b);
}


int goodPairs(int *arr, int size){
	int i;

	int dp[size];

	dp[0] = 0;

	for(i=size-1; i>0; i--){
		if(arr[i] > arr[i-1]){
			dp[i] = i;
		}else{
			dp[i] = 0;
		}
	}

	// printf("......\n");
	// for(i=0;i<size;i++){
		// printf("%d ", dp[i]);
	// }
	// printf("\n");
	// printf("........\n");
	
	for(i=1; i<size;i++){
		if(dp[i] > dp[i-1]){
			dp[i] = i;
		}else{
			dp[i] = dp[i-1];
		}	
	}
	
	int sum = 0;
	// printf("......\n");
	// for(i=0;i<size;i++){
	// 	printf("%d ", dp[i]);
	// }
	// printf("\n");
	// printf("........\n");
	for(i=0;i<size;i++){
		sum += dp[i];
	}

	return sum;

}

int main(){
	int cases;
	scanf("%d",&cases);

	int i;
	for(i=0;i<cases;i++){
		int n;
		scanf("%d",&n);
		int arr[n];
		int j;
		for(j=0;j<n;j++){
			scanf("%d",&arr[j]);
		}

		qsort(arr,n,sizeof(int),cmpfnc);

		printf("%d\n", goodPairs(arr, n));

	}

}

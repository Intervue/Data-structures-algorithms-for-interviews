/*
Given a rod of length 'n' inches and an array of prices that contains prices of all pieces of size smaller 
than n, find the max value obtainable by cutting the rod and selling the pieces

There are two methods to solve this:
One is 0/1 knapsack with a twist that is you can include as many as you want

Other is array method as mentioned in geek for geek
 
*/

//METHOD: 0/1 knapsack with duplicate items

int max(int a, int b){
	return a>b?a:b;
}

int cutRod(int *arr, int size){
	int length = size;

	int dp[size+1][size+1];

	int i,j;
	

	for(i=0;i<=size;i++){
		for(j=0;j<=size;j++){
			dp[i][j] = 0;
		}
	
	}

	for(i=1;i<=size;i++){
		for(j=1;j<=size;j++){
			if(i <= j) {
				dp[i][j] = max(dp[i-1][j], arr[i-1] + dp[i][j-i]);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	for(i=0;i<=size;i++){
		for(j=0;j<=size;j++){
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}

	return dp[size][size];

}	

int main()
{
    int arr[] = {1,5,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Obtainable Value is %d\n", cutRod(arr, size));
    
    return 0;
}

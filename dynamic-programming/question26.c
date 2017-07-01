/*
Given an amount and some coints, find out in how many ways can this amount be formed 
1) given that each coin can be included any number of times.
2) given that each coin can be included only once if included

Case 1)

METHOD1:

Suppose there are 3 coints 1 2 3 and amount to be formed is 5 given that all coins can be repeated any
number of times.
Naive approach: Here number of ways will be 5/1*5/2*5/3 which is amount^n (if n is the number of coins given)
which is exponential. Therefore we need to use a better approach.

METHOD2:
DP: Here we need to find the recursive equations. In any scenario, if I talk about the ith coin, either it will
be included (if coin is less than or equal to sum given) or cannot be included
second scenario is it cannot be included if value is greater than sum given, hence recursive equation
will look like this
NW: No of ways
NW(i,j) = No of ways of forming a sum j taking i coins at a time
{
	NW(i-1,j) + NW(i,j-c[i]) //if c[i] <=j //i is not included and sum remains same, 
	i included and sum decreases by the coin value

	NW(i-1,j) //c[i]>j //if i cannot be included as value of coin is higher
}

Now if this recursive equation is converted to a tree, it will actually end up giving repeating sub problems,
hence this can be improved using DP.

Number of unique sub problems will be

NW(i,j) //here i can take value from o to m (therefore m+1 ways)
        //j can take values from j till 0 - sum will eventaully be zero (which is n + 1 )

Therefore we need a matrix of size n+1 * m+1   

Time complexity: O(mn) //if m is the number of coins and n is the sum
Space complexity: O(mn)
*/
#include <stdio.h>
#include <stdlib.h>

int findWays(int *arr, int amount, int size){
	int ways[size+1][amount+1];

	int i,j;
	for(j=0;j<=amount;j++){
		ways[0][j] = 0;
	}
	for(i=0;i<=size;i++){
		ways[i][0]=1;
	}
	for(i=1;i<=size;i++){
		for(j=1;j<=amount;j++){
			if(arr[i-1] > j){
				ways[i][j] = ways[i-1][j];
			}else{
				ways[i][j] = ways[i-1][j] + ways[i][j-arr[i-1]];
			}
		}
	}

	printf("printing the solution matrix\n");

	for(i=0;i<=size;i++){
		for(j=0;j<=amount;j++){
			printf("%d ", ways[i][j]);
		}
		printf("\n");
	}

	return ways[size][amount];
}

int main(){
	int coins[] = {1,2,3};

	int amount = 5;

	int size = sizeof(coins)/sizeof(coins[0]);

	int ways = findWays(coins,amount,size);
	printf("number of ways are %d\n", ways);

	return 0;
}

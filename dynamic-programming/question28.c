/*
Given a cost matrix mxn having a cost at each cell. Find the min cost that it will take to 
reach cell (m-1,n-1) from top left corner cell (0,0) if the only allowed directions to move are right, 
down and diagnal down

METHOD:
In this case we cannot use greedy as each time we will try to find the min from the node and traverse that
path, but we may end up with a node having max as the only option or min as the max number which may not
be the shortest path

Hence we use DP:
Assume the matrix is something like this:

10  3   4
5   6   7
13  4  11

and we need to reach from 0,0 to n-1,m-1

Therefore at each node I have three choices, recursive equation may look like this:

C(0,0) = min{
	10 + C(0,1),
	10 + C(1,1),
	10 + C(1,0)
}

Hence if we convert it into a tree, we can see repeating sub problems. The number of unique problems are clearly
n*m and c(i,j)// i can take n values and j can take m values (entire row and columns)

Now we make a matrix of size m*n and reverse engineer the solution. If we start from 0,0, it is the bigger
problem we need to solve, but if we start from n-1,m-1, it is the smallest problem. Hence we try to construct
the bottom most row, as 

28 15 11

as from cell in the middle it will take (4+11) 15 cost to reach 11 and similarly from cell 13 it will take(15+13)

Now for the next rows, we keep taking the min of the three ways we have been given in the question and 0,0
will be the answer.

Time complexity: O(mn)
Space complexity: O(mn)

Here we can even construct the path by just finding min starting from 0,0 in this matrix
We can also save the space complexity in case path is not required by just maintaing the values of two rows
at a time at any given time.
*/
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b, int c){
	return (a<b?(a<c?a:c):(b<c?b:c));
}

int findCost(int rows, int columns,int arr[rows][columns]){

	int cost[rows][columns];

	int i,j;

	cost[rows-1][columns-1] = arr[rows-1][columns-1];

	for(i=rows-1;i>=0;i--){
		for(j=columns-1;j>=0;j--){
			if(i == rows-1){
				cost[i][j] = arr[i][j] + cost[i][j+1];
			}
			else if(j == columns-1){
				cost[i][j] = arr[i][j] + cost[i+1][j];
			}else{
				cost[i][j] = arr[i][j] + min(cost[i+1][j+1],cost[i][j+1],cost[i+1][j]);	
			}
		}
	}


	//printing the array
	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++){
			printf("%d ", cost[i][j]);
		}
		printf("\n");
	}

	printf("the path is: \n");
	i=0,j=0;
	while(i<=rows-1 && j<=columns-1){
		printf("%d ", arr[i][j]);
		if(cost[i+1][j+1] < cost[i+1][j]){
			if(cost[i+1][j+1] < cost[i][j+1]){
				i = i+1;
				j = j+1;
			}else{
				i = i;
				j = j+1;
			}
		}else{
			if(cost[i+1][j] < cost[i][j+1]){
				i = i+1;
				j = j;
			}else{
				i = i;
				j = j+1;
			}
		}
	}

	return cost[0][0];
}

int main(){

	int cost[3][3] = {
		{10,3,4},
		{5,6,17},
		{13,4,11},
	};

	int rows = sizeof(cost)/sizeof(cost[0]);
	int columns = sizeof(cost[0])/sizeof(cost[0][0]);

	int total = findCost(rows,columns,cost);
	printf("total cost of reaching is %d\n", total);

	return 0;
}


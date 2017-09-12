/*
Travelling sales man problem.

Here a salesman has to start from a village and cover all the village only once and come back to
his village in the min cost possible.

Now given a graph using the cost matrix we have weights of all edges with us. Assume the graph
to be a square with 4 vertices {1,2,3,4}

Now we always need min of T(1,{2,3,4}) = min(T(1,2) + T(2,{3,4}))  and other combinations
So we evaluate them. By building the recursion tree it is found out that there are
(n-1)* 2^(n-2) unique subproblems for which DP is to be applied.

Therefore space complexity will be that huge (exponential) even after applying DP.
To solve each sub problem O(n) time is required, hence time complexity is O(n^2*2^n)

If this is done using brute force method it will take O(n!) time complexity which is way more
bigger than 2^n

Build the algo yourself as it will involve a big matrix and two for loops with bottom-up approach.   
*/

#include <stdio.h>
#include <stdlib.h>

int cost = 0;

int tsp(int city, int vertices, int arr[vertices][vertices], int *visited){
	int i, nearest_city = 999;
	int min = 999, temp;
	for(i=0;i<vertices;i++) {
		if(arr[city][i] && visited[i] == 0) {
			if(min > arr[city][i]){
				min = arr[i][0] + arr[city][i];
			}
			temp = arr[city][i];
			nearest_city = i;
		}
	}
	if(min != 999) {
		cost = cost + temp;
	}
	return nearest_city;
}

void minCost(int city, int vertices, int arr[vertices][vertices], int *visited) {
	
	int nearest_city;
	visited[city] = 1;
	nearest_city = tsp(city, vertices, arr, visited);
	if(nearest_city == 999) {
		nearest_city = 0;
		cost = cost + arr[city][nearest_city];
		return;
	}
	minCost(nearest_city, vertices, arr, visited);
}

int main() {
	int vertices = 4;
	int visited[vertices];
	int i;
	for(i=0;i<vertices;i++){
		visited[i] = 0;
	}
	int arr[4][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{3,8,5,6},
		{9,8,4,3},
	};
	minCost(0,vertices, arr, visited);
	printf("cost is %d\n", cost);

	return 0;
}
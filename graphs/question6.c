/*
Given a 2D boolean matrix, find the number of islands

One island is a single element or a group of ones. Group should be traversable from 1 to another in all directions
but should be contigous
Eg;

101
010
101 

forms a single island only

1010001
1100000

one with 101
         11  

and other with 1

forms two islands and so on

METHOD:
We assume this matrix to be a graph where each cell is a node and adjacent nodes are all surrounding ones
at 1 distance from it. At max a cell can have 8 adjacent nodes. There will only exist an edge between a node
and its adjacent nodes if the value is 1 at the node surrounding it assumed to be the adjacent node.

Time complexity: O(n^2 + 8n^2) //for each cell in worst case 8 other nodes will be traversed

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int rows, columns;

int isSafe(int arr[rows][columns], int i, int j, bool visited[rows][columns]){

	return (i >= 0) && (i < rows) && (j >= 0) && (j < columns) && (arr[i][j] && !visited[i][j]);

}

void dfs(int arr[rows][columns], int i, int j, bool visited[rows][columns]){
	static int rowNbr[] = {-1,-1,-1,0,0,1,1,1};
	static int colNbr[] = {-1,0,1,-1,1,-1,0,1};

	visited[i][j] = true;

	int k;
	for(k=0;k<8;k++){
		if(isSafe(arr, i+rowNbr[k],j+colNbr[k],visited)){
			dfs(arr, i+rowNbr[k], j+ colNbr[k], visited);
		}
	}

}

int findIslands(int arr[rows][columns]){

	bool visited[rows][columns];

	int i,j;

	int count = 0;

	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++){
			if(arr[i][j] && !visited[i][j]){
				dfs(arr,i,j,visited);
				count++;
			}
		}
	}
	

	return count;
}	

int main(){
	
	int arr[][5] = {  
		{1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };
 

	rows = sizeof(arr)/sizeof(arr[0]);
	columns = sizeof(arr[0])/sizeof(arr[0][0]);

	printf("There are in total %d islands in the given matrix\n", findIslands(arr));

	return 0;
}



/*
http://www.geeksforgeeks.org/find-number-of-islands/
*/
#include <stdio.h>
#include <stdlib.h>
#define ROW 5
#define COL 5

int isValid(int i,int j, int visited[ROW][COL], int arr[ROW][COL]){
	if(i>=0 && i<ROW && j>=0 && j<COL && !visited[i][j] && arr[i][j]){
		return 1;
	}
	return 0;
}

void dfs(int i, int j, int visited[ROW][COL], int arr[ROW][COL]){

	visited[i][j] = 1;

	int a1[] = {-1,-1,-1,0,0,1,1,1};
	int a2[] = {-1,0,1,-1,1,-1,0,1};

	int k;

	for(k=0; k<8;k++){
		if(isValid(i+a1[k], j+a2[k], visited, arr)){
			dfs(i+a1[k], j+a2[k], visited, arr);
		}
	}

}

int countIslands(int arr[ROW][COL]){
	int visited[ROW][COL];
	int i,j;
	for(i=0;i<ROW;i++){
		for(j=0;j<COL;j++){
			visited[i][j] = 0;
		}	
	}

	int count = 0;

	for(i=0;i<ROW;i++){
		for(j=0;j<COL;j++){
			if(arr[i][j] && visited[i][j] == 0){
				count++;
				dfs(i,j,visited,arr);

			}
		}	
	}

	return count;

}	

int main()
{
    int arr[ROW][COL]= {  
    	{1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };
 
    printf("Number of islands is: %d\n", countIslands(arr));
 
    return 0;
}

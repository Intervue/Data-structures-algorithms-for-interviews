/*
http://practice.geeksforgeeks.org/problems/hamiltonian-path/0

The solution below is not complete. Follow link to understand.

http://www.geeksforgeeks.org/backtracking-set-7-hamiltonian-cycle/
*/

#include <stdio.h>
#include <stdlib.h>
#define v 5

int isSafe(int index, int graph[v][v], int *path, int pos, int *visited){
	if(graph[path[pos-1]][index] == 0){
		return 0;
	}
	if(visited[index] == 1){
		return 0;
	}
	return 1;
}

int hamCycleUtil(int graph[v][v], int *path, int pos, int *visited){
	int i;

	if(pos == v){
		if(graph[path[pos-1]][path[0]] == 1){
			return 1;
		}else{
			return 0;
		}
	}

	for(i=1;i<v;i++){
		if(isSafe(i,graph, path, pos, visited)){
			path[pos] = i;

			if(hamCycleUtil(graph,path, pos+1, visited) == 1){
				return 1;
			}

			path[pos] = -1;

		}
	}

	return 0;
}

void printSolution(int path[])
{
    printf ("Solution Exists:"
            " Following is one Hamiltonian Cycle \n");
    for (int i = 0; i < v; i++)
        printf(" %d ", path[i]);
 
    // Let us print the first vertex again to show the complete cycle
    printf(" %d ", path[0]);
    printf("\n");
}

void hamCycle(int graph[v][v]){

	int path[v], visited[v];
	int i;
	for(i=0;i<v;i++){
		path[i] = -1;
		visited[i] = 0;
	}
	path[0] = 0;
	visited[0] = 1;

	if(hamCycleUtil(graph, path, 1, visited) == 0){
		printf("there is not cycle...\n");
		return;
	}

	//display path
	printSolution(path);

}


int main(){
		
	int graph[v][v] = {
			{0, 1, 0, 1, 0},
          	{1, 0, 1, 1, 1},
          	{0, 1, 0, 0, 1},
          	{1, 1, 0, 0, 0},
          	{0, 1, 1, 0, 0},
         };	

    hamCycle(graph);

	return 0;
}
/*
Hamiltonian cycle in a graph
*/
#include <stdio.h>
#include <stdlib.h>
#define vertices 5

int isSafe(int index, int graph[vertices][vertices], int *path, int pos) {
	if(graph[path[pos-1]][index] == 0) {
		return 0;
	}
	int i;
	for(i=0;i<pos;i++) {
		if(path[i] )
	}
}

int hamCycleUtil(int graph[vertices][vertices], int *path, int pos) {
	if(pos == vertices) {

	}

	int i;
	for(i=1;i<vertices;i++) {
		if(isSafe(i, graph, path, pos)) {

		}
	}
}

int hamCycle(int graph[vertices][vertices]) {
	int path[vertices];
	int i;
	for(i=0;i<vertices;i++) {
		path[i] = -1;
	}
	path[0] = 0;
	if(hamCycleUtil(graph, path, 1) == 0) {
		printf("solution does not exist\n");
		return 0;
	}
	displayPath(path);
	return 1;
}

int main() {
	int graph1[vertices][vertices] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };

     hamCycle(graph1)

	return 0;
}
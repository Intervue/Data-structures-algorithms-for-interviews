/*
Dijkstra algorithm for adj matrix
*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define vertices 9

int minDistance(int *dist, int *visited) {
	int min = INT_MAX, min_index;
	int i;
	for(i=0;i<vertices;++i) {
		if(visited[i] == 0 && dist[i] < min) {
			min = dist[i], min_index = i;
		}
	}
	return min_index;
}

void displayResult(int *dist){
	int i;
	printf("Vertex\tDistance from Source\n");
	for(i=0;i<vertices;i++){
		printf("%d\t%d\n", i, dist[i]);
	}
}

void dijkstra(int graph[vertices][vertices], int src) {
	int dist[vertices];
	int visited[vertices];
	
	int i;
	for(i=0; i<vertices; ++i) {
		visited[i] = 0;
		dist[i] = INT_MAX;
	}
	dist[src] = 0;

	for(i=0;i<vertices;i++) {
		int u = minDistance(dist, visited);
		visited[u] = 1;
		int j;

		for(j=0;j<vertices;j++){
			if(visited[j] == 0 && graph[u][j] && dist[u] != INT_MAX && dist[u] + graph[u][j] < dist[j]) {
				dist[j] = dist[u] + graph[u][j];
			}
		}

	}

	displayResult(dist);

}

int main() {

	int graph[vertices][vertices] = {
					  {0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
  
    dijkstra(graph, 0);

	return 0;
}
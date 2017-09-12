/*
Program for DIJKSTRA algorithm

In this the source is initialized to zero and rest of the nodes are given value infinity
, then min heap is made. From the min heap min is extracted and decrease key operation is applied
for the node which is nearest to the source (that is with min edge weight). Now its value is decreased
from infinity to a particular value. This is the decrease key operation. Like this each time decrease key
is applied and each time every outgoing edge is relaxed (decrease key is applied).
The nodes that are already relaxed for that an array is maintained so that we do not relax them again.
Like this we will get the min values for each node from the source.

Note: If the graph is undirected, then then every edge incident on the node must be relaxed rather than
just the outgoing edges

Time complexity: O(Elogv) + O(VlogV)

Dijsktra algo cannot be applied to graphs having -ve weight edges
*/
//adjacency list
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct adjListNode{
	int vertex;
	int cost;
	struct adjListNode *next;
};

struct adjList{
	struct adjListNode *head;
};

struct graph{
	int vertices, edges;
	struct adjList *arr;
};

struct pair{
	int vertex;
	int cost;
};

struct adjListNode *newNode(int vertex, int cost) {
	struct adjListNode *temp = (struct adjListNode *)malloc(sizeof(struct adjListNode));
	temp->vertex = vertex;
	temp->cost = cost;
	temp->next = NULL;
	return temp;
}

void addEdge(struct graph *newGraph, int start, int end, int cost) {
	struct adjListNode *temp = newNode(end, cost);
	if(newGraph->arr[start].head){
		temp->next = newGraph->arr[start].head;
	}
	newGraph->arr[start].head = temp;
	temp = newNode(start, cost);
	if(newGraph->arr[end].head){
		temp->next = newGraph->arr[end].head;
	}
	newGraph->arr[end].head = temp;
}

void minHeapify(struct pair *minHeap, int index, int vertices, int *position) {
	int left = 2*index + 1, right = 2*index + 2, smallest;
	struct pair *temp = (struct pair *)malloc(sizeof(struct pair));

	if(left <= vertices-1 && minHeap[left].cost < minHeap[index].cost) {
		smallest = left;
	}else {
		smallest = index;
	}

	if(right <= vertices-1 && minHeap[right].cost < minHeap[smallest].cost) {
		smallest = right;
	}

	if(smallest <= vertices-1 && smallest != index) {

		//update pos array
		position[minHeap[index].vertex] = smallest;
		position[minHeap[smallest].vertex] = index;

		//replace
		temp->vertex = minHeap[smallest].vertex;
		temp->cost = minHeap[smallest].cost;
		minHeap[smallest].vertex = minHeap[index].vertex;
		minHeap[smallest].cost = minHeap[index].cost;
		minHeap[index].vertex = temp->vertex;
		minHeap[index].cost = temp->cost;

		minHeapify(minHeap, smallest, vertices, position);
	}
}

void buildHeap(struct pair *minHeap, int vertices, int *position) {
	int start = (vertices/2) - 1;
	int i;
	for(i=start; i>=0; i--) {
		minHeapify(minHeap, i, vertices, position);
	}
}

struct pair *extractMin(struct pair *minHeap, int *vertices, int *position) {
	if(*vertices == 0) {
		return NULL;
	}
	struct pair *result = (struct pair *)malloc(sizeof(struct pair));
	result->cost = minHeap[0].cost;
	result->vertex = minHeap[0].vertex;
	
	minHeap[0].cost = minHeap[*vertices-1].cost;
	minHeap[0].vertex = minHeap[*vertices-1].vertex;
	

	//update pos array
	position[result->vertex] = *vertices-1;
	position[minHeap[*vertices-1].vertex] = 0;

	*vertices = *vertices - 1;

	minHeapify(minHeap, 0, *vertices, position);

	return result;
}

void decreaseKey(struct pair *minHeap, int index, int value, int *position, int vertices) {
	if(minHeap[index].cost < value) {
		return;
	}
	int i = position[index];
	minHeap[i].cost = value;

	struct pair *temp = (struct pair *)malloc(sizeof(struct pair));
	while(i && minHeap[(i-1)/2].cost > minHeap[i].cost) {
		
		//update pos
	 	position[minHeap[i].vertex] = (i-1)/2;
	 	position[minHeap[(i-1)/2].vertex] = i;

		temp->cost = minHeap[(i-1)/2].cost;
		temp->vertex = minHeap[(i-1)/2].vertex;
		minHeap[(i-1)/2].cost = minHeap[i].cost;
		minHeap[(i-1)/2].vertex = minHeap[i].vertex;	
	 	minHeap[i].cost = temp->cost;
	 	minHeap[i].vertex = temp->vertex;

	 	i = (i-1)/2;
	}

}

void displayDist(int *dist, int vertices) {
	printf("\nvertex\tdist from src\n");
	int i;
	for(i=0;i<vertices;i++) {
		printf("%d\t%d\n", i, dist[i]);
	}
}

void displayGraph(struct graph *newGraph) {
	int i;
	struct adjListNode *temp;
	for(i=0;i<newGraph->vertices;i++) {
		temp = newGraph->arr[i].head;
		printf("%d ----> ", i);
		while(temp){
			printf("%d (%d)    ", temp->vertex, temp->cost);
			temp = temp->next;
		}
		printf("\n");
	}
}

void dijsktra(struct graph *newGraph, int src) {
	int vertices = newGraph->vertices;
	int dist[vertices], visited[vertices], position[vertices];
	struct pair minHeap[vertices];

	int i;
	for(i=0;i<vertices;i++) {
		dist[i] = INT_MAX;
		visited[i] = 0;
		position[i] = i;
		minHeap[i].vertex = i;
		minHeap[i].cost = INT_MAX;
	}
	dist[src] = 0;
	minHeap[src].cost = 0;

	buildHeap(minHeap, vertices, position);

	while(vertices) {
		
		struct pair *min = extractMin(minHeap, &vertices, position);
		int u = min->vertex;
		int cost = min->cost;
		
		//updating visited
		visited[u] = 1;

		struct adjListNode *temp = newGraph->arr[u].head;
		while(temp) {
			int v = temp->vertex;

			//updating dist
			if(visited[v] == 0 && dist[v] > cost + temp->cost && dist[u] != INT_MAX) {
				dist[v] = cost + temp->cost;
				decreaseKey(minHeap, v, dist[v], position, vertices);
			}
			temp = temp->next;
		}
	}

	displayDist(dist, newGraph->vertices);
}

int main() {
	int vertices = 9;
	struct graph *newGraph = (struct graph *)malloc(sizeof(struct graph));
	newGraph->arr = (struct adjList *)calloc(vertices, sizeof(struct adjList));
	int src = 0;
	newGraph->vertices = vertices;

	addEdge(newGraph, 0, 1, 4);
    addEdge(newGraph, 0, 7, 8);
    addEdge(newGraph, 1, 2, 8);
    addEdge(newGraph, 1, 7, 11);
    addEdge(newGraph, 2, 3, 7);
    addEdge(newGraph, 2, 8, 2);
    addEdge(newGraph, 2, 5, 4);
    addEdge(newGraph, 3, 4, 9);
    addEdge(newGraph, 3, 5, 14);
    addEdge(newGraph, 4, 5, 10);
    addEdge(newGraph, 5, 6, 2);
    addEdge(newGraph, 6, 7, 1);
    addEdge(newGraph, 6, 8, 6);
    addEdge(newGraph, 7, 8, 7);

    displayGraph(newGraph);

	dijsktra(newGraph, src);

	return 0;
}
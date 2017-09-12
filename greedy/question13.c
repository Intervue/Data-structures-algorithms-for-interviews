/*
Program for PRIMS algorithm

PRIMS algo is used to find the min cost spanning tree for a weighted graph given cost matrix and set of 
edges

METHOD1:
Here we first find the min edge from the set of edges given and from the cost matrix we can see that the
edge is between which two vertices. Those vertices are then stored in an array t. We will make a tree out
of it
Then we will make another array near where we will calculate for all the vertices of the graph if they are
nearer to edge that connects to nodes (they will be nearer to only one of them), The one to which they will
be nearer will be written in the array.
Now we will see for which combination given in the near array the cost is minimum, the one for which it is
minimum will be pushed to array t and then near array will be updated for the newly added node.
This way we keep on complete until the array t is full and all values in near array are zero.
Note: we will keep making the values zero once the nodes corresponding to them are already a part of the tree

Time complexity: O(n^2) //as for each node in the near array we need to compute its cost compared to the 
remaining nodes where n is the number of vertices

METHOD2:
Using heap.

Google and code this algorithm
*/
//normal implementation

// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>
// #define V 5

// int minKey(int *near, int *visited) {
// 	int min = INT_MAX, index;
// 	int i;
// 	for(i=0; i<V; i++) {
// 		if(min > near[i] && visited[i] == 0) {
// 			min = near[i];
// 			index = i;
// 		}
// 	}
// 	return index;
// }

// void printMST(int *parent, int graph[V][V]) {
// 	printf("\nedge\tweight\n");
// 	int i;
// 	for(i=1;i<V;i++ ) {
// 		printf("%d-%d\t%d\n", parent[i],i,graph[i][parent[i]]);
// 	}
// }

// void primMST(int graph[V][V]) {
// 	int visited[V];
// 	int parent[V];
// 	int near[V];
// 	int i, j;
// 	for(i=0;i<V;i++) {
// 		visited[i] = 0;
// 		near[i] = INT_MAX;
// 	}

// 	near[0] = 0;
// 	parent[0] = -1;

// 	for(i=0;i<V-1;i++) {
// 		int u = minKey(near, visited);
// 		visited[u] = 1;
// 		for(j=0;j<V;j++) {
// 			if(graph[u][j] && visited[j] == 0 && graph[u][j] < near[j]) {
// 				near[j] = graph[u][j];
// 				parent[j] = u;
// 			}
// 		}
// 	}

// 	printMST(parent,graph);

// }

// int main()
// {
// /* Let us create the following graph
// 		2 3
// 	(0)--(1)--(2)
// 	| / \ |
// 	6| 8/ \5 |7
// 	| /	 \ |
// 	(3)-------(4)
// 			9		 */
// 	int graph[V][V] = {
// 					{0, 2, 0, 6, 0},
// 					{2, 0, 3, 8, 5},
// 					{0, 3, 0, 0, 7},
// 					{6, 8, 0, 0, 9},
// 					{0, 5, 7, 9, 0},
// 					};

// 	// Print the solution
// 	primMST(graph);

// 	return 0;
// }



//using min heap
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

void displayDist(int *arr, int vertices, int *near) {

	for (int i = 1; i < vertices; ++i){
        printf("%d - %d\n", arr[i], i);
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

void primMST(struct graph *newGraph) {
	int vertices = newGraph->vertices;
	int parent[vertices];
	int visited[vertices];
	int near[vertices];
	int position[vertices];

	struct pair minHeap[vertices];
	int i;
	for(i=0	;i<vertices;i++) {
		parent[i] = -1;
		visited[i] = 0;
		near[i] = INT_MAX;
		position[i] = i;
		minHeap[i].vertex = i;
		minHeap[i].cost = INT_MAX;
	}

	near[0] = 0;
	minHeap[0].cost = 0;

	buildHeap(minHeap, vertices, position);

	while(vertices) {
		struct pair *min = extractMin(minHeap, &vertices, position);
		int u = min->vertex;
		int cost = min->cost;
		visited[u] = 1;

		struct adjListNode *temp = newGraph->arr[u].head;
		while(temp) {
			int v = temp->vertex;
			if(visited[v] == 0 && near[v] > temp->cost) {
				near[v] = temp->cost;
				parent[v] = u;
				decreaseKey(minHeap, v, near[v], position, vertices);
			}
			temp = temp->next;
		}
	}

	displayDist(parent, newGraph->vertices, near);	
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

	primMST(newGraph);

	return 0;
}
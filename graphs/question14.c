/*
Articulation points in a graph and bridges in a graph

http://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/

Vertex which if removed will disconnect the graph

Naive approach:
Remove each edge and see if graph if no longer connected, that edge is a bridge or two points
making the bridge are articulation points.


*/
#include <stdio.h>
#include <stdlib.h>

struct adjListNode{
	int data;
	struct adjListNode *next;
};

struct adjList{
	struct adjListNode *head;
};

struct graph{
	int vertices;
	int time;
	struct adjList *arr;
};

struct adjListNode *newNode(int data){
	struct adjListNode *temp = (struct adjListNode *)malloc(sizeof(struct adjListNode));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void createEdge(int start, int end, struct graph *newGraph){
	struct adjListNode *temp = newNode(end);
	if(newGraph->arr[start].head){
		temp->next = newGraph->arr[start].head;
		newGraph->arr[start].head = temp;
	}else{
		newGraph->arr[start].head = temp;
	}

	temp = newNode(start);
	if(newGraph->arr[end].head){
		temp->next = newGraph->arr[end].head;
		newGraph->arr[end].head = temp;
	}else{
		newGraph->arr[end].head = temp;
	}
}

void displayGraph(struct graph *newGraph){

	int i;
	struct adjListNode *temp;
	for(i=0;i<newGraph->vertices;i++){
		printf("%d -----> ", i);
		temp = newGraph->arr[i].head;
		while(temp) {
			printf("%d  ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}

}

void dfs(int v, struct graph *newGraph, int *visited, int *visitedTime, int *low, int parent, int *ap) {
	
	visited[v] = 1;

	visitedTime[v] = newGraph->time;
	low[v] = newGraph->time;
	(newGraph->time)++;
	int children = 0;

	struct adjListNode *temp = newGraph->arr[v].head;
	while(temp) {
		int u = temp->data;
		if(!visited[u]){
			children++;
			int parent = v;
			visited[u] = 1;
			dfs(u, newGraph, visited, visitedTime, low, parent, ap);

			if(parent == -1 && children > 1){
				ap[v]  = 1;
			}

			if(visitedTime[v] < low[u]){
				printf("bridge found between %d and %d\n", v, u);
				ap[v] = 1;
			}

			if(low[v] > low[u]) {
				low[v] = low[u];
			}
		}else if(parent != u){
			if(low[v] > low[u]){
				low[v] = low[u];
			}
		}
		temp = temp->next;
	}

}

void checkArticulationPoints(struct graph *newGraph) {
	displayGraph(newGraph);
	int vertices = newGraph->vertices;
	int visited[vertices];
	int visitedTime[vertices];
	int low[vertices];
	int ap[vertices];
	// int children[vertices];

	int i;
	for(i=0;i<vertices;i++) {
		visited[i] = 0;
		visitedTime[i] = 0;
		low[i] = 0;
		ap[i] = 0;
		// children[i] = 0;
	}

	for(i=0;i<vertices;i++) {
		if(visited[i] == 0) {
			dfs(i, newGraph, visited, visitedTime, low, -1, ap);
		}
	}

	printf("articulation points are:\n");
	for(i=0;i<vertices;i++) {
		if(ap[i]){
			printf("%d ", i);
		}
	}

}

int main(){
	struct graph *newGraph = (struct graph *)malloc(sizeof(struct graph));
	int vertices = 5;
	newGraph->vertices = vertices;
	newGraph->time = 0;
	newGraph->arr = (struct adjList *)calloc(vertices, sizeof(struct adjList));

	createEdge(1,0, newGraph);
	createEdge(0,2, newGraph);
	createEdge(2,1, newGraph);
	createEdge(0,3, newGraph);
	createEdge(3,4, newGraph);
	
	checkArticulationPoints(newGraph);

	return 0;
}
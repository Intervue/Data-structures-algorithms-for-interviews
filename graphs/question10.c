/*
Euler path and circuit for undirected graph

Following conditions must be true:

An undirected graph has Eulerian cycle if following two conditions are true.
….a) All vertices with non-zero degree are connected. 
We don’t care about vertices with zero degree because they don’t belong to Eulerian Cycle or Path 
(we only consider all edges).
….b) All vertices have even degree.


An undirected graph has Eulerian Path if following two conditions are true.
….a) Same as condition (a) for Eulerian Cycle
….b) If zero or two vertices have odd degree and all other vertices have even degree.
 Note that only one vertex with odd degree is not possible in an undirected graph 
 (sum of all degrees is always even in an undirected graph)

Note that a graph with no edges is considered Eulerian because there are no edges to traverse.

Time complexity: O(V+E) //dfs

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

void dfs(int index, struct graph *newGraph, int *visited){

	visited[index] = 1;

	struct adjListNode *temp = newGraph->arr[index].head;
	while(temp){
		if(visited[temp->data] == 0){
			dfs(temp->data, newGraph, visited);
		}
		temp = temp->next;
	}
}


void init(int *visited, int vertices){
	int i;
	for(i=0;i<vertices;i++){
		visited[i] = 0;
	}
}

void updateDegree(struct graph *newGraph, int *degree){
	int i;
	struct adjListNode *temp;
	for(i=0;i<newGraph->vertices;i++){	
		temp = newGraph->arr[i].head;
		while(temp){
			degree[temp->data]++;
			temp = temp->next;
		}
	}
}

void display(struct graph *newGraph){
	int i;
	struct adjListNode *temp;
	for(i=0;i<newGraph->vertices;i++){
		temp = newGraph->arr[i].head;
		printf("%d --> ", i);
		while(temp){
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

int checkEulerian(struct graph *newGraph, int *degree, int *visited){

	display(newGraph);

	updateDegree(newGraph, degree);
	int i = 0;
	while(degree[i] == 0){
		i++;
	}
	dfs(i,newGraph,visited);

	//counting vertices with odd degrees
	//also checking for vertex who indegree is non zero visited cannot be false if eulerian path
	//or circuit is there
	int odd = 0, zero = 0;
	for(i=0;i<newGraph->vertices;i++){
		if(degree[i] > 0 && visited[i] == 0){
			return 0;
		}
		if(degree[i] == 0){
			zero++;
		}
		if(degree[i]%2!=0){
			odd++;
		}
	}

	if(zero == newGraph->vertices){
		return 2;
	}

	if(odd > 2){
		return 0;
	}
	if(odd == 0){
		return 2;
	}
	return 1;
}

int main(){
	struct graph *newGraph = (struct graph *)malloc(sizeof(struct graph));
	int vertices = 5;
	newGraph->vertices = vertices;
	newGraph->arr = (struct adjList *)calloc(vertices, sizeof(struct adjList));

	createEdge(1,0, newGraph);
	createEdge(0,2, newGraph);
	createEdge(2,1, newGraph);
	createEdge(0,3, newGraph);
	createEdge(3,4, newGraph);
		
	int degree[vertices];
	init(degree, vertices);	

	int visited[vertices];

	init(visited, vertices);

	int value = checkEulerian(newGraph, degree, visited);
	if(value == 0){
		printf("given graph is not eulerian circuit and path\n");
	}else if(value == 1){
		printf("given graph is has eulerian path\n");
	}else{
		printf("given graph is has eulerian cycle\n");
	}	

	return 0;
}
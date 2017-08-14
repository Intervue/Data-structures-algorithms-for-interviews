/*
Euler path and circuit for directed graph

Following conditions must be true:

A directed graph has an eulerian cycle if following conditions are true (Source: Wiki)
1) All vertices with nonzero degree belong to a single strongly connected component.
2) In degree and out degree of every vertex is same.


Time complexity: O(V+E) + O(V) //kosaraju, dfs, reverse and we traversing the graph

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

void updateDegree(int *in, int *out, struct graph *newGraph){
	int i;
	struct adjListNode *temp;
	for(i=0;i<newGraph->vertices;i++){	
		temp = newGraph->arr[i].head;
		while(temp){
			in[temp->data]++;
			out[i]++;
			temp = temp->next;
		}
	}
}

void traverseGraphAndReverse(struct graph *reverse, struct graph *newGraph){

	int i;
	struct adjListNode *temp;
	for(i=0;i<newGraph->vertices;i++){
		temp = newGraph->arr[i].head;
		while(temp){
			createEdge(temp->data, i, reverse);
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

int checkEulerian(struct graph *newGraph, int *in, int *out, int *visited){

	display(newGraph);

	updateDegree(in, out, newGraph);

	//checking if in degree and out degree is same
	int i;
	for(i=0; i<newGraph->vertices; i++){
		if(in[i] != out[i]){
			return 0;
		}
	}

	//finding if vertex with degree non zero is connected fully
	i = 0;
	while(in[i] + out[i] == 0){
		i++;
	}

	int dfsCalledOn = i;
	dfs(i, newGraph, visited);

	for(i=0;i<newGraph->vertices;i++){
		if(in[i] + out[i] != 0 && visited[i] == 0){
			return 0;
		}
	}

	//finding if vertex with degree non zero is connected fully
	//reversing because this is a directed graph and reverse may be false in this case
	//unlike undirected
	struct graph *reverse = (struct graph *)malloc(sizeof(struct graph));
	reverse->vertices = newGraph->vertices;
	reverse->arr = (struct adjList *)calloc(newGraph->vertices, sizeof(struct adjList));
	traverseGraphAndReverse(reverse, newGraph);

	init(visited, newGraph->vertices);

	dfs(dfsCalledOn, newGraph, visited);

	for(i=0;i<newGraph->vertices;i++){
		if(in[i] + out[i] != 0 && visited[i] == 0){
			return 0;
		}
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
	createEdge(4,0, newGraph);
		
	int indegree[vertices], outdegree[vertices];;
	init(indegree, vertices);
	init(outdegree, vertices);	

	int visited[vertices];

	init(visited, vertices);

	int value = checkEulerian(newGraph, indegree,outdegree, visited);
	if(value == 0){
		printf("given graph is not eulerian\n");
	}else if(value == 1){
		printf("given graph is eulerian\n");
	}
	return 0;
}
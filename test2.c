/*
Kosaraju algorithm for strongly connected components

Time complexity: O(v+e), this happens thrice
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

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

void init(int *visited, int vertices){
	int i;
	for(i=0;i<vertices;i++){
		visited[i] = 0;
	}
}

int checkStronglyConnected(struct graph *newGraph, int *visited){

	//do dfs and push elements on stack in the decreasing order of their finishing time
	dfs(0, newGraph, visited);	
	int i;
	for(i=0;i<newGraph->vertices;i++){
		if(visited[i] == 0){
			return 0;
		}
	}		

	//reverse the graph
	struct graph *reverse = (struct graph *)malloc(sizeof(struct graph));
	reverse->vertices = newGraph->vertices;
	reverse->arr = (struct adjList *)calloc(newGraph->vertices, sizeof(struct adjList));
	traverseGraphAndReverse(reverse, newGraph);
	
	init(visited, newGraph->vertices);
	dfs(0,reverse,visited);
	
	for(i=0;i<reverse->vertices;i++){
		if(visited[i] == 0){
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

	createEdge(0,1, newGraph);
	createEdge(1,2, newGraph);
	createEdge(2,4, newGraph);
	createEdge(2,4, newGraph);
	createEdge(4,2, newGraph);
	createEdge(2,3, newGraph);
	createEdge(3,0, newGraph);
	

	int visited[vertices];

	init(visited, vertices);

	printf("%d",checkStronglyConnected(newGraph, visited));

	return 0;
}
/*
http://www.geeksforgeeks.org/detect-cycle-in-a-graph/

Detect a cycle in a directed graph
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


int dfs(int index, struct graph *newGraph, int *visited, int *stack){
		
	visited[index] = 1;
	stack[index] = 1;	

	struct adjListNode *temp = newGraph->arr[index].head;
	while(temp){

		if(visited[temp->data] == 1 && stack[temp->data] == 1){
			return 1;
		}
		else if(visited[temp->data] == 0 && dfs(temp->data,newGraph,visited,stack))
			return 1;
		temp = temp->next;
	}
	stack[index] = 0;
	return 0;
}

void init(int *visited, int vertices){
	int i;
	for(i=0;i<vertices;i++){
		visited[i] = 0;
	}
}

void checkCycle(struct graph *newGraph, int *visited, int *stack){
		
	display(newGraph);
	
	int value = 0;
	int i;
	for(i=0;i<newGraph->vertices;i++){
		if(visited[i] == 0){
			value = dfs(i,newGraph,visited,stack);
			if(value){

				break;
			}	
		}
	}

	if(value){
		printf("cycle...\n");
	}else{
		printf("no cycle\n");
	}
}

int main(){
	struct graph *newGraph = (struct graph *)malloc(sizeof(struct graph));
	int vertices = 4;
	newGraph->vertices = vertices;
	newGraph->arr = (struct adjList *)calloc(vertices, sizeof(struct adjList));

	createEdge(0,1, newGraph);
	createEdge(0,2, newGraph);
	createEdge(1,2, newGraph);
	// createEdge(2,0, newGraph);
	createEdge(2,3, newGraph);
	// createEdge(3,3, newGraph);
	
	int visited[vertices], stack[vertices];

	init(visited, vertices);
	init(stack, vertices);

	checkCycle(newGraph, visited, stack);

	return 0;
}
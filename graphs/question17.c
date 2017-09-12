/*
Longest path in directed acyclic graph

Here we take the max instead of the min and dist is initialized as -INFINITY

Longest path in normal graphs other than this is NP complete problem as it cannot be reduced to subproblems
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 1000

int stack[MAX];
int top = -1;
int elms = 0;

void push(int data){
	stack[++top] = data;
	elms++;
}

int pop(){
	elms--;
	return stack[top--];
}

int isStackEmpty(){
	return elms == 0;
}

int findMax(int a, int b) {
	return a > b? a:b;
}

struct adjListNode {
	int data;
	int cost;
	struct adjListNode *next;
};

struct adjList{
	struct adjListNode *head;
};

struct graph{
	int vertices;
	int edges;
	struct adjList *arr;
};

struct adjListNode *newNode(int data, int cost){
	struct adjListNode *temp = (struct adjListNode *)malloc(sizeof(struct adjListNode));
	temp->data = data;
	temp->cost = cost;
	temp->next = NULL;
	return temp;
}

void createEdge(int start, int end, int cost, struct graph *newGraph){
	struct adjListNode *temp = newNode(end, cost);
	if(newGraph->arr[start].head) {
		temp->next = newGraph->arr[start].head;
		newGraph->arr[start].head = temp;
	}else{
		newGraph->arr[start].head = temp;
	}
}

void displayGraph(struct graph *newGraph) {
	int i;
	struct adjListNode *temp;
	for(i=0;i<newGraph->vertices;i++){
		temp = newGraph->arr[i].head;
		printf("%d --> ", i);
		while(temp) {
			printf("%d(%d)  ", temp->data, temp->cost);
			temp = temp->next;
		}
		printf("\n");
	}
}

void dfs(int index, struct graph *newGraph, int *visited) {
	visited[index] = 1;
	struct adjListNode *temp = newGraph->arr[index].head;
	while(temp) {
		if(visited[temp->data] == 0){
			dfs(temp->data, newGraph, visited);
		}
		temp = temp->next;
	}

	push(index);
}

void computeLongestDistance(struct graph *newGraph, int *visited, int *dist, int src) {

	int i;
	int vertices = newGraph->vertices;

	for(i=0;i<vertices;i++) {
		if(visited[i] == 0) {
			dfs(i, newGraph, visited);
		}
	}

	dist[src] = 0;


	while(stack[top] != src) {
		pop();
	}
	
	while(!isStackEmpty()){
		int index = pop();
		struct adjListNode *temp = newGraph->arr[index].head;
		while(temp) {
			dist[temp->data] = findMax(dist[temp->data], temp->cost + dist[index]);
			temp = temp->next;
		}
	}

}

int main() {
	int vertices = 6;
	struct graph *newGraph = (struct graph *)malloc(sizeof(struct graph));
	newGraph->vertices = vertices;
	newGraph->arr = (struct adjList *)calloc(vertices, sizeof(struct adjList));

	int visited[vertices];
	int dist[vertices];

	int i;
	for(i=0; i<vertices; i++) {
		visited[i] = 0;
		dist[i] = INT_MIN;
	}

	createEdge(0,1,5,newGraph);
	createEdge(0,2,3,newGraph);
	createEdge(1,3,6,newGraph);
	createEdge(1,2,2,newGraph);
	createEdge(2,4,4,newGraph);
	createEdge(2,5,2,newGraph);
	createEdge(2,3,7,newGraph);
	createEdge(3,5,1,newGraph);
	createEdge(3,4,-1,newGraph);
	createEdge(4,5,-2,newGraph);

	displayGraph(newGraph);

	int src = 1;

	computeLongestDistance(newGraph, visited, dist, src);

	for(i=0;i<vertices;i++) {
		printf("%d ", dist[i]);
	}

	return 0;
}
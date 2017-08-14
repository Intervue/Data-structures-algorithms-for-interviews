/*
Kosaraju algorithm for strongly connected components

Time complexity: O(v+e), this happens thrice
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack[100];
int top = -1;

int isStackEmpty(){
	return top == -1;
}

void push(int data){
	stack[++top] = data;
}

int pop(){
	return stack[top--];
}

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
		printf("%d ---> ", i);
		while(temp){
			printf("%d  ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

void dfs(int index, struct graph *newGraph, int *visited){

	visited[index] = 1;
	printf("%d ", index);

	struct adjListNode *temp = newGraph->arr[index].head;
	while(temp){
		if(visited[temp->data] == 0){
			dfs(temp->data, newGraph, visited);
		}
		temp = temp->next;
	}
	
	push(index);
}

void dfsReverse(int index, struct graph *reverse, int *visited){

	visited[index] = 1;
	
	printf("%d  ", index);
	
	struct adjListNode *temp = reverse->arr[index].head;
	while(temp){
		if(visited[temp->data] == 0){
			dfsReverse(temp->data, reverse, visited);
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

void displayStronglyConnected(struct graph *newGraph, int *visited){

	//do dfs and push elements on stack in the decreasing order of their finishing time
	int i;
	for(i=0;i<newGraph->vertices;i++){
		if(visited[i] == 0){
			dfs(i, newGraph, visited);	
			printf("\n");
		}
	}

	//reverse the graph
	struct graph *reverse = (struct graph *)malloc(sizeof(struct graph));
	reverse->vertices = newGraph->vertices;
	reverse->arr = (struct adjList *)calloc(newGraph->vertices, sizeof(struct adjList));
	traverseGraphAndReverse(reverse, newGraph);
	printf("\n printing reverse \n");
	display(reverse);


	//do dfs as per stack on the reverse graph
	printf("\n printing components\n");
	init(visited, newGraph->vertices);
	while(!isStackEmpty()){
		int index = pop();
		if(visited[index] == 0){
			dfsReverse(index, reverse, visited);
			printf("\n");
		}
	}

}

int main(){
	struct graph *newGraph = (struct graph *)malloc(sizeof(struct graph));
	int vertices = 7;
	newGraph->vertices = 7;
	newGraph->arr = (struct adjList *)calloc(vertices, sizeof(struct adjList));

	createEdge(0,1, newGraph);
	createEdge(1,2, newGraph);
	createEdge(2,0, newGraph);
	createEdge(2,4, newGraph);
	createEdge(4,5, newGraph);
	createEdge(5,3, newGraph);
	createEdge(3,4, newGraph);
	createEdge(6,5, newGraph);

	display(newGraph);

	int visited[vertices];

	init(visited, vertices);

	displayStronglyConnected(newGraph, visited);

	return 0;
}
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

struct adjListNode  *newNode(int data){
	struct adjListNode *temp = (struct adjListNode *)malloc(sizeof(struct adjListNode));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void addEdge(struct graph *newGraph,int start, int end){
	struct adjListNode *temp = newNode(start);
	
	if(newGraph->arr[end].head){
		temp->next = newGraph->arr[end].head;
		newGraph->arr[end].head = temp;

	}else{
		newGraph->arr[end].head = temp;
	}

	temp = newNode(end);
	
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

int main(){

	struct graph *newGraph = (struct graph *)malloc(sizeof(struct graph));
	int vertices = 4;
	newGraph->vertices = 4;

	newGraph->arr = (struct adjList *)calloc(vertices,sizeof(struct adjList));	

	addEdge(newGraph, 0, 1);
	addEdge(newGraph, 0, 2);
	addEdge(newGraph, 1, 3);
	addEdge(newGraph, 2, 3);

	display(newGraph);

	return 0;
}
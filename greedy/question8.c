/*
Program to implement a simple graph

METHOD1: linked list
METHOD2: arrays

*/
//METHOD1
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct graph{
	int count;
	struct node *head;
};

struct node *newNode(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void addEdge(struct graph *myGraph,int src, int dest){
	struct node *temp;
	temp = newNode(dest);
	if(!myGraph[src].head){
		myGraph[src].head = temp;
	}else{
		temp->next = myGraph[src].head;
		myGraph[src].head = temp;
	}
	myGraph[src].count++;
	temp = newNode(src);
	if(!myGraph[dest].head){
		myGraph[dest].head = temp;
 	}else{
 		temp->next = myGraph[dest].head;
 		myGraph[dest].head = temp;
 	}
	myGraph[dest].count++;
}

void printGraph(struct graph *myGraph){
	printf("graph is...\n");
	for(int i=0; i<4;i++){
		struct node *temp = myGraph[i].head;
		printf("%d-->", i);
		while(temp){
			printf("%d --> ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main(){
	int size = 4;
	struct graph *myGraph = (struct graph *)calloc(size,sizeof(struct graph));
	addEdge(myGraph, 0, 1);
    addEdge(myGraph, 1, 2);
    addEdge(myGraph, 1, 3);
    addEdge(myGraph, 2, 3);

    printGraph(myGraph);
    return 0;
}
//====================================================================================================
//METHOD2
#include <stdio.h>
#include <stdlib.h>

void addEdge(int arr[][4],int src, int dest){
	arr[src][dest] = arr[dest][src] = 1;
}

void printGraph(int arr[][4]){
	for(int i=0;i<4;i++){
		printf("%d --> ", i);
		for(int j=0;j<4;j++){
			if(arr[i][j]){
				printf("%d --> ", j);	
			}
		}	
		printf("\n");
	}		
}

int main(){
	int size = 4;
	int graph[4][4] = {0};
	addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);

    printGraph(graph);
    return 0;
}
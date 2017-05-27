/*
Program to implement a simple graph


*/
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
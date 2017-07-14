/*
Implement a graph using adjacency matrix and list, implement DFS and BFS, BST and DST

Graphs is represented using two ways:
Adjacency list
Adjacency matrix

*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX];
int front, rear=0;

int vertexCount = 0;

struct node{
	int data;
	struct node *next;
};

struct adjList{
	struct node *head;
};

struct graph{
	int vertices;
	int edges;
	struct adjList *arr;
};

struct node *newNode(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void createEdge(struct graph *newGraph, int data1, int data2){
	struct node *temp;
	temp = newNode(data2);
	if(!newGraph->arr[data1].head){
		newGraph->arr[data1].head = temp;
	}else{
		temp->next = newGraph->arr[data1].head;
		newGraph->arr[data1].head = temp;
	}
	temp = newNode(data1);
	if(!newGraph->arr[data2].head){
		newGraph->arr[data2].head = temp;
	}else{
		temp->next = newGraph->arr[data2].head;
		newGraph->arr[data2].head = temp;
	}
}

void printAdjacencyList(struct graph *newGraph){
	int i;
	struct node *temp;
	for(i=0;i<newGraph->vertices;i++){
		temp = newGraph->arr[i].head;
		printf("%d -->",i);
		while(temp){
			printf("%d - ",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

struct graph *initGraph(int size, int edges){
	struct graph *newGraph = (struct graph *)malloc(sizeof(struct graph));
	newGraph->vertices = size;
	newGraph->edges = edges;
	newGraph->arr = (struct adjList *)malloc(sizeof(struct adjList)*size);
	int i;
	for(i=0;i<size;i++){
		newGraph->arr[i].head = NULL;
	}
	return newGraph;
}

void makeAdjacencyList(struct graph *newGraph,int vertices, int edges){
	
	int i;
	int v1, v2;	
	for(i=0;i<newGraph->edges;i++){
		printf("enter the %dth edge\n", i);
		scanf("%d %d", &v1, &v2);
		createEdge(newGraph,v1,v2);
	}	
}

void makeAdjacencyMatrix(int vertices, int adjMatrix[vertices][vertices]){
	int i,j;
	for(i=0;i<vertices;i++){
		for(j=0;j<vertices;j++){
			printf("Is there an edge between %d and %d\n", i,j);
			scanf("%d", &adjMatrix[i][j]);
		}
	}
}

void printAdjacencyMatrix(int vertices, int adjMatrix[vertices][vertices]){
	int i,j;
	for(i=0;i<vertices;i++){
		for(j=0;j<vertices;j++){
			printf("%d ", adjMatrix[i][j]);
		}
		printf("\n");
	}	
}

void initArray(int *arr, int size){
	int i;
	for(i=0;i<size;i++){
		arr[i] = 0;
	}
}

// void enqueue(int node){
// 	rear = (rear+1)%MAX;
// 	if(rear == front){
// 		printf("overflow...\n");
// 		if(rear == 0){
// 			rear = MAX - 1;
// 		}else{
// 			rear = rear-1;
// 		}
// 	}
// 	queue[rear] = node;
// }

// void dequeue(){
// 	if(front == rear){
// 		return -1;
// 	}
// 	front = (front + 1)%MAX;
// 	int data = queue[front];
// 	return data;
// }

// void bstList(struct graph *newGraph){
// 	int visited[newGraph->vertices + 1];
// 	initArray(visited, newGraph->vertices+1);
// 	visited[newGraph->arr[0]] = 1;
	
// 	int u = newGraph->arr[0];
// 	int i;
	
// 	enqueue(u);
	
// 	while(rear != front){
// 		int data = dequeue();
// 		if(data != -1){
// 			printf("%d\t", data);
// 		}
// 		struct node *t = newGraph->arr[counter].head;
// 		while(t){
// 			if(visited[t->data] != 1){
// 				enqueue()		
// 			}
// 			t = t->next;
// 		}
		
// 	}	

// }

int main(){
	int vertices, edges;

	int step;
	struct graph *newGraph;
	
	printf("enter the number of vertices in the graph\n");
	scanf("%d",&vertices);

	printf("enter the number of edges\n");
	scanf("%d",&edges);

	newGraph = initGraph(vertices, edges);
	int adjMatrix[vertices][vertices];	

	while(1){
		printf("1. Make graph using adjacency list\n");
		printf("2. Make graph using adjacency matrix\n");
		printf("3. Print adjacency list\n");
		printf("4. Print adjacency matrix\n");
		printf("5. Do breath first traversal in list\n");
		printf("6. Do breath first traversal in matrix\n");
		printf("7. Do depth first traversal in list\n");
		printf("8. Do depth first traversal in matrix\n");
		
		scanf("%d",&step);

		switch(step){
			case 1: makeAdjacencyList(newGraph,vertices, edges);
				break;
			case 2: makeAdjacencyMatrix(vertices,adjMatrix);
				break;
			case 3: printAdjacencyList(newGraph);
				break;
			case 4: printAdjacencyMatrix(vertices,adjMatrix);
				break;
			case 5: //bstList(newGraph);
				break;
			case 6: //bstMatrix();
				break;

		}
	}
	
	
	return 0;
}
/*
Implement a graph using adjacency matrix and list, implement DFS and BFS, BST and DST

Graphs is represented using two ways:
Adjacency list
Adjacency matrix

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int queue[MAX];
int front=0, rear=-1;

int vertexCount = 0;
int queueItemCount = 0;

struct CustomNode{
	char label;
	bool visited;
};

struct CustomNode *customNodes;

struct AdjListNode{
	int data;
	struct AdjListNode *next;
};

struct AdjList{
	struct AdjListNode *head;
};

struct Graph{
	int vertices, edges;
	struct AdjList *arr;
};

//queue methods
void enqueue(int data){
	queue[++rear] = data;
	queueItemCount++;
}

int dequeue(){
	queueItemCount--;
	return queue[front++];
}

bool isQueueEmpty(){
	return queueItemCount == 0;
}

//graph functions
void displayVertex(int index){
	printf(" %c\t", customNodes[index].label);
}

void initCustomNodes(int vertices, int edges){
	customNodes = (struct CustomNode *)malloc(sizeof(struct CustomNode)*vertices);
}

struct Graph *initGraph(int vertices, int edges){
	struct Graph *newGraph = (struct Graph *)malloc(sizeof(struct Graph));
	newGraph->vertices = vertices;
	newGraph->edges = edges;
	newGraph->arr = (struct AdjList *)malloc(sizeof(struct AdjList)*vertices);
	initCustomNodes(vertices, edges);
	return newGraph;
}

void addCustomNodes(vertices){
	char label;
	int i;
	for(i=0;i<vertices;i++){
		printf("Enter the name of the %d vertex\n", i);
		scanf(" %c",&label);
		customNodes[i].label = label;
		customNodes[i].visited = false;	
	}
}

struct AdjListNode *createEdge(int data){
	struct AdjListNode *temp = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
	temp->data = data;
	temp->next = NULL;
	return temp; 
}

void addEdge(struct Graph *newGraph, int node1, int node2){
	struct AdjListNode *temp = createEdge(node1);
	if(newGraph->arr[node2].head){
		temp->next = newGraph->arr[node2].head;
		newGraph->arr[node2].head = temp;
	}else{
		newGraph->arr[node2].head = temp;
	}

	temp = createEdge(node2);
	if(newGraph->arr[node1].head){
		temp->next = newGraph->arr[node1].head;
		newGraph->arr[node1].head = temp;
	}else{
		newGraph->arr[node1].head = temp;	
	}
}

void makeGraph(struct Graph *newGraph, int vertices, int adjMatrix[vertices][vertices]){
	int i,j;

	addCustomNodes(vertices);

	int edgeValue;
	for(i=0;i<vertices;i++){
		for(j=i+1;j<vertices;j++){
			printf("Is there an edge between %d, %d\n",i,j);
			scanf("%d",&edgeValue);
			if(edgeValue){
				addEdge(newGraph, i,j);
				adjMatrix[i][j] = 1;
				adjMatrix[j][i] = 1;
			}else{
				adjMatrix[i][j] = 0;
				adjMatrix[j][i] = 0;
			}
		}
	}

	//no self direction in the graph
	for(i=0;i<vertices;i++){
		adjMatrix[i][i] = 0;
	}
}

void restoreDefaults(int vertices){
	int i;

	for(i=0;i<vertices;i++){
		customNodes[i].visited = false;
	}
}

void makeVisitedAndDisplay(int index){
	customNodes[index].visited = true;
	enqueue(index);
	displayVertex(index);	
}

void breadthFirstSearchList(int index,struct Graph *newGraph){
	
	makeVisitedAndDisplay(index);
	
	while(!isQueueEmpty()){
		int tempVertex = dequeue();
	
		struct AdjListNode *temp = newGraph->arr[tempVertex].head;
		while(temp){
			if(customNodes[temp->data].visited == false){
	
				customNodes[temp->data].visited = true;
				displayVertex(temp->data);
				enqueue(temp->data);
	
			}
			temp = temp->next;
		}
	}
}

void bftList(struct Graph *newGraph){
	int i;
	for(i=0;i<newGraph->vertices;i++){
		if(!customNodes[i].visited){
			breadthFirstSearchList(i,newGraph);
		}
	}
	restoreDefaults(newGraph->vertices);
}

void breadthFirstSearchMatrix(int index, int vertices, int adjMatrix[vertices][vertices]){
	
	makeVisitedAndDisplay(index);

	while(!isQueueEmpty()){
		int tempVertex = dequeue();
		int i;
		for(i=0;i<vertices;i++){
			if(adjMatrix[tempVertex][i] && !customNodes[i].visited){
				customNodes[i].visited = true;
				displayVertex(i);
				enqueue(i);	
			}
		}
	}
}

void bftMatrix(int vertices, int adjMatrix[vertices][vertices]){
	int i;
	for(i=0;i<vertices;i++){
		if(!customNodes[i].visited){
			breadthFirstSearchMatrix(i,vertices,adjMatrix);
		}
	}
	restoreDefaults(vertices);
}

void printAdjList(struct Graph *newGraph, int vertices){
	int i;
	
	struct AdjListNode *temp;

	for(i=0;i<vertices;i++){
		temp = newGraph->arr[i].head;
		printf(" %c-->", customNodes[i].label);
		while(temp){
			printf("%c--> ", customNodes[temp->data].label);
			temp = temp->next;
		}
		printf("\n");
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

void depthFirstSearchList(int index, struct Graph *newGraph){
	
	makeVisitedAndDisplay(index);

	struct AdjListNode *temp = newGraph->arr[index].head;
	while(temp){
		if(!customNodes[temp->data].visited){
			depthFirstSearchList(temp->data,newGraph);
		}
		temp=temp->next;
	}

}

void depthFirstSearchMatrix(int index, int vertices, int adjMatrix[vertices][vertices]){

	makeVisitedAndDisplay(index);
	int i;
	for(i=0;i<vertices;i++){
		if(adjMatrix[index][i] && !customNodes[i].visited){
			depthFirstSearchMatrix(i,vertices,adjMatrix);
		}
	}
}

void dftList(struct Graph *newGraph){
	int i;
	for(i=0;i<newGraph->vertices;i++){
		if(!customNodes[i].visited){
			depthFirstSearchList(i,newGraph);
		}
	}
	restoreDefaults(newGraph->vertices);
}

void dftMatrix(int vertices, int adjMatrix[vertices][vertices]){
	int i;
	for(i=0;i<vertices;i++){
		if(!customNodes[i].visited){
			depthFirstSearchMatrix(i, vertices, adjMatrix);
		}
	}
	restoreDefaults(vertices);
}

int main(){
	int vertices, edges;

	int step;
	struct Graph *newGraph;
	
	printf("enter the number of vertices in the graph\n");
	scanf("%d",&vertices);

	printf("enter the number of edges\n");
	scanf("%d",&edges);

	newGraph = initGraph(vertices, edges);
	int adjMatrix[vertices][vertices];	

	while(1){
		printf("1. Make a graph\n");
		printf("2. Print adjacency list\n");
		printf("3. Print adjacency matrix\n");
		printf("4. Do breath first traversal in list\n");
		printf("5. Do breath first traversal in matrix\n");

		//@TODO
		printf("6. Do depth first traversal in list\n");
		printf("7. Do depth first traversal in matrix\n");
		
		scanf("%d",&step);

		switch(step){
			case 1: makeGraph(newGraph, vertices, adjMatrix);
				break;
			case 2: printAdjList(newGraph, vertices);
				break;
			case 3: printAdjacencyMatrix(vertices,adjMatrix);
				break;
			case 4: bftList(newGraph);
				break;
			case 5: bftMatrix(vertices, adjMatrix);
				break;
			case 6: dftList(newGraph);
				break;
			case 7: dftMatrix(vertices, adjMatrix);
				break;
		}
	}

	return 0;
}
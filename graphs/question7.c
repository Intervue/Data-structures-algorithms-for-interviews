/*
Check whether a given graph is bipartite or not

A bipartitie graph is one whose vertices can be divided into two independent sets U and V such that every (U,V)
either connects a vertex from U to V or V to U

Or a graph which if represented in the form of a tree, alternating levels belong to two different sets

METHOD:
We will do a BFS
1) A graph containing odd length of cycles is not bipartite.
2) We can start coloring the vertex starting from any vertex. The start vertex lets say is blue, all its
neighbours must be given yellow. Then all the ones with yellow its neighbours should be given blue.
At any given point if an already colored vertex is colored again in an opposite color, then the graph is
NOT bipartite else it is bipartite

Time complexity: O(E+V)

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define MAX 100

int queue[MAX];
int rear = -1, front = 0;

int queueElementCount = 0;

int visited[MAX];

int color[MAX];

struct AdjListNode{
	int data;
	struct AdjListNode *next;
};

struct AdjList{
	struct AdjListNode *head;
};

struct Graph{
	int vertices, edges;
	struct AdjList *map;
} *newGraph;

int dequeue(){
	queueElementCount--;
	return queue[front++];
}

void enqueue(int data){
	queueElementCount++;
	queue[++rear] = data;
}

bool isQueueEmpty(){
	return queueElementCount == 0;
}

struct AdjListNode *createNode(int data){
	struct AdjListNode *temp = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void addEdge(int start, int end){
	struct AdjListNode *newNode = createNode(end);
	if(newGraph->map[start].head){
		newNode->next = newGraph->map[start].head;
		newGraph->map[start].head = newNode;
	}else{
		newGraph->map[start].head = newNode;
	}
	newNode = createNode(start);
	if(newGraph->map[end].head){
		newNode->next = newGraph->map[end].head;
		newGraph->map[end].head = newNode;
	}else{
		newGraph->map[end].head = newNode;
	}
}

void displayAdjList(){
	int i;

	for(i=0;i<newGraph->vertices;i++){
		struct AdjListNode *temp = newGraph->map[i].head;
		printf("%d --> ", i);
		while(temp){
			printf("%d --> ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

void initColors(){
	int i;
	for(i=0;i<newGraph->vertices;i++){
		color[i] = -1;
		visited[i] = 0;
	}
}

bool isBipartite(){

	visited[0] = 1;
	enqueue(0);
	color[0] = 1;
	
	while(!isQueueEmpty()){
		int index = dequeue();
		struct AdjListNode *temp = newGraph->map[index].head;
		while(temp) {
			if(!visited[temp->data]){
				visited[temp->data] = 1;
				enqueue(temp->data);
				if(color[index] >=0 && color[temp->data] == -1){
					color[temp->data] = 1 - color[index];
				}else if(color[index] >=0 && color[temp->data] == color[index]){
					return false;
				}	
			} 
			else {
				if(color[index] >=0 && color[temp->data] == color[index]){
					return false;
				}	
			}
			temp = temp->next;
		}
		
	}
	return true;
}

int main(){

	int vertices = 3;

	newGraph = (struct Graph *)malloc(sizeof(struct Graph));
	newGraph->vertices = vertices;
	newGraph->map = (struct AdjList *)calloc(sizeof(struct AdjList),vertices);

	addEdge(0,1);
	addEdge(1,2);
	addEdge(2,0);
	
	displayAdjList();

	if(isBipartite()){
		printf("Graph is bipartite\n");
	}else{
		printf("Graph is not bipartite\n");
	}	

	// int i;
	// for(i=0;i<vertices;i++){
	// 	printf("%d ", color[i]);
	// }

	return 0;
}



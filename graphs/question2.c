/*
Implement a graph using adjacency matrix and do BFT in a different way for custom value of nodes

Here we define an array of structures. Each structure contains custom node. The position of the custom
node is decided by a global pointer which starts from 0.

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

struct Vertex{
	char label;
	bool visited;
};

int queue[MAX];
int rear = -1, front = 0;
int queueElementCount  = 0;

struct Vertex *lstVertices[MAX];

int vertexCount = 0;

int adjMatrix[MAX][MAX];

void enqueue(int data){
	queue[++rear] = data;
	queueElementCount++;
}

int dequeue(){
	queueElementCount--;
	return queue[front++];
}

bool isQueueEmpty(){
	return queueElementCount == 0;
}

void displayVertex(int vertexIndex){
	printf("%c\t", lstVertices[vertexIndex]->label);
}

void addVertex(char label){
	struct Vertex *newVertex = (struct Vertex *)malloc(sizeof(struct Vertex));
	newVertex->label = label;
	newVertex->visited = false;
	lstVertices[vertexCount++] = newVertex;
}

void addEdge(int start,int end){
	adjMatrix[start][end] = 1;
	adjMatrix[end][start] = 1;
}

int getAdjUnvisitedVertex(int vertexIndex){
	int i;

	for(i=0;i<vertexCount;i++){
		if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited ==  false){
			return i;
		}
	}

	return -1;
}

void breadthFirstSearch(){
	int i;
	lstVertices[0]->visited = true;
	displayVertex(0);
	enqueue(0);
	int unvisitedVertex;

	while(!isQueueEmpty()){
		int tempVertex = dequeue();	
		
		while((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1){
			lstVertices[unvisitedVertex]->visited = true;
			displayVertex(unvisitedVertex);
			enqueue(unvisitedVertex);
		}	
	}

	for(i = 0;i<vertexCount;i++) {
      lstVertices[i]->visited = false;
   	}  
}

int main(){
	int i,j;

	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			adjMatrix[i][j] = 0;
		}
	}

	addVertex('S');
	addVertex('A');
	addVertex('B');
	addVertex('C');
	addVertex('D');

	addEdge(0,1);
	addEdge(0,2);
	addEdge(0,3);
	addEdge(1,4);
	addEdge(2,4);
	addEdge(3,4);

	// printf("this is done\n");

	breadthFirstSearch();

	return 0;
}
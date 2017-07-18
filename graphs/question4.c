/*
Find if there is a path between two vertices Vi and Vj in a directed graph

Here path means, they there may or may not be some other vertices as well in the path.

METHOD:
We can use DFS or BFS and basically if the graph is connected containing these two vertices, if you
start from one, you will definately get the other one.

Time complexity: O(V+E);
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

int queue[MAX];
int rear = -1, front = 0;

int queueElementCount = 0;

int visited[MAX];

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

int checkDirectlyIfConnected(int v1, int v2){
	struct AdjListNode *temp = newGraph->map[v1].head;

	while(temp){
		if(temp->data == v2){
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}

int breadthFirstSearch(int v1, int v2){

	if(checkDirectlyIfConnected(v1, v2)){
		return 1;
	}

	visited[v1] = 1;
	enqueue(v1);

	while(!isQueueEmpty()){
		int tempVertex = dequeue();

		struct AdjListNode *temp = newGraph->map[tempVertex].head;

		while(temp){
			if(temp->data == v2){
				return 1;
			}else{
				enqueue(temp->data);
				visited[temp->data] = 1;
			}
			temp = temp->next;
		}

	}

	return 0;

}

int main(){

	int vertices = 6;

	newGraph = (struct Graph *)malloc(sizeof(struct Graph));
	newGraph->vertices = vertices;
	newGraph->map = (struct AdjList *)calloc(sizeof(struct AdjList),vertices);

	addEdge(0,2);
	addEdge(2,3);
	addEdge(3,4);
	addEdge(0,1);
	addEdge(5,1);

	displayAdjList();

	printf("basis the graph check enter two vertices to see if they are connected or not\n");
	int v1, v2;
	scanf("%d %d", &v1, &v2);

	int isConnected = breadthFirstSearch(v1,v2);
	if(isConnected){
		printf("YES they are connected\n");
	}else{
		printf("NO they are not connected\n");
	}

	return 0;
}


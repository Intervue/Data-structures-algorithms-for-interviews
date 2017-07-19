/*
Given an undirected graph, find if it has a cycle or not

METHOD1:
We can do DFS and if any node at any given point does not have any where to go as per DFS, i.e visited of all 
its neighbours are 1, then it will have a cycle

Time complexity: O(V+E) //in worst case we will end up visited every node twice

METHOD2:
We can use union and find algorithm
*/

//METHOD1
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

int dfs(int index, int parent){
	visited[index] = 1;

	struct AdjListNode *temp = newGraph->map[index].head;
	while(temp){
		if(visited[temp->data] != 1){
			parent = index;
			dfs(temp->data, parent);
		}else if(temp->data != parent){
			return 1;
		}
		temp = temp->next;
	} 
	return 0;
}

int isCyclePresent(){
	return dfs(0,-1);
}	

int main(){

	int vertices = 5;

	newGraph = (struct Graph *)malloc(sizeof(struct Graph));
	newGraph->vertices = vertices;
	newGraph->map = (struct AdjList *)calloc(sizeof(struct AdjList),vertices);

	addEdge(0,1);
	addEdge(1,4);
	addEdge(0,2);
	addEdge(0,3);
	addEdge(2,3);

	displayAdjList();

	if(isCyclePresent()){
		printf("Graph contains a cycle\n");
	}else{
		printf("Graph does not contain a cycle\n");
	}	

	return 0;
}


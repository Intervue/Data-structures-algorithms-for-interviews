/*
http://practice.geeksforgeeks.org/problems/euler-circuit-and-path/1
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

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

void dfs(int index, struct graph *newGraph, int *visited){

	visited[index] = 1;

	struct adjListNode *temp = newGraph->arr[index].head;
	while(temp){
		if(visited[temp->data] == 0){
			dfs(temp->data, newGraph, visited);
		}
		temp = temp->next;
	}
}

void init(int *visited, int vertices){
	int i;
	for(i=0;i<vertices;i++){
		visited[i] = 0;
	}
}

int main(){
	int cases;
	int i;
	for(i=0;i<cases;i++){
		int vertices,edges;
		scanf("%d %d", vertices, edges);
	}

	return 0;
}
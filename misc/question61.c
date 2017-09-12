/*
http://practice.geeksforgeeks.org/problems/circle-of-strings/0
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct adjListNode{
	int data;
	struct adjListNode *next;
};

struct adjList{
	struct adjListNode *head;
};

struct graph{
	int vertices, edges;
	struct adjList *arr;
};

struct adjListNode *newNode(int data){
	struct adjListNode *temp = (struct adjListNode *)malloc(sizeof(struct adjListNode));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void addEdge(struct graph *newGraph, char start, char end) {

	struct adjListNode *temp = newNode(end);
	if(newGraph->arr[start].head) {
		temp->next = newGraph->arr[start].head;
		newGraph->arr[start].head = temp;			
	}else{
		newGraph->arr[start].head = temp;
	}

}

void getDegrees(struct graph *newGraph, int *inDegree, int *outDegree) {
	int i;
	struct adjListNode *temp;
	for(i=0;i<newGraph->vertices;i++){
		temp = newGraph->arr[i].head;
		int count = 0;
		while(temp){
			inDegree[temp->data]++;
			temp = temp->next;
			count++;
		}
		outDegree[i] = count;
	}
}

void dfs(int index, struct graph *newGraph, int *visited) {
	visited[index] = 1;
	struct adjListNode *temp = newGraph->arr[index].head;
	while(temp) {
		if(!visited[temp->data]) {
			dfs(temp->data, newGraph, visited);
		}
		temp = temp->next;
	}
}

int isEuler(struct graph *newGraph) {
	int vertices = newGraph->vertices;
	int inDegree[vertices];
	int outDegree[vertices];
	int visited[vertices];

	int i;
	for(i=0;i<vertices;i++){
		inDegree[i] = 0;
		outDegree[i] = 0;
		visited[i] = 0;
	}

	getDegrees(newGraph, inDegree, outDegree);

	for(i=0;i<vertices;i++){
		if(inDegree[i] != outDegree[i]){
			return 0;
		}
	}

	i = 0;
	while(inDegree[i] + outDegree[i] <= 0){i++;}

	dfs(i, newGraph, visited);	

	for(i=0;i<vertices;i++){
		if(inDegree[i] + outDegree[i] > 0 && !visited[i]){
			return 0;
		}
	}

	return 1;

}

int isCircle(int n, int length, char arr[n][length]) {

	int i;

	struct graph *newGraph = (struct graph *)malloc(sizeof(struct graph));
	newGraph->arr = (struct adjList *)calloc(26,sizeof(struct adjList));

	newGraph->vertices = 26;

	for(i=0;i<n;i++) {

		int size = strlen(arr[i]);

		int start = arr[i][0] - 'a';
		int end = arr[i][size-1] - 'a';

		addEdge(newGraph,start,end);
	}

	if(isEuler(newGraph)){
		return 1;
	}

	return 0;
}

int main() {
	int cases;
	int i;
	scanf("%d",&cases);
	for(i=0;i<cases;i++) {
		int n;
		scanf("%d",&n);
		int length = 11;
		char arr[n][length];

		int j;
		for(j=0;j<n;j++){
			scanf("%s", arr[j]);
		}

		printf("%d\n", isCircle(n,length,arr));

	}
	return 0;
}
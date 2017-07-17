/*
Topological sort in a graph

In this a directed acyclic graph is given. That is it will be directed and there will be no cycles in it.
Find out an order in which the vertices can be written in such a way that if one vertex is pointing towards
other (i pointing towards j), then in ordering i will always come before j

This has wide applications in ordering things like if one thing has a dependency before it can be
executed for eg j has a dependency that i should be done first, then i will always come before j
and in between anything can be there.



 k ---> i ----> j

before you do anything to j, i has to be finished before which k has to be done, therefore
will sorting them in topological order, we need to find a node that does not have any dependencies.

Time complexity: O(V+E) //v for scanning for v vertices, finding the one with no incoming edge
using another data structure. If we do not use it then finding it will take o(v) for each vertex
that means O(V^2) overall

NOTE: It is not literally sorting is we did in arrays but it is about printing the order in which the
tasks will be executed given dependencies (incoming edges to a node)

METHOD:
Each time we need to identify a node with no incoming edges. This we can do by maintaining an array.
We traverse the matrix/list and whereever we find incoming edges we go to the array and increment the
count.

The initial count of the array is zero.

Then we scan the array and find each time whatever node has a count zero and we print it. Each time
we remove that node and its outgoing edges from the list, we also make sure that other nodes that
are effected because of that, there count is updated in the array as well.

Now each time if we traverse the array it will take us O(v) time, rather than doing that, in the first
iteration only while setting the values, we push all the nodes having value zero onto a queue. Each time
we update values in the array we push values in the queue and will printing we pop. This way
topological sort can be done


METHOD2:
While doing DFT we can push elements on stack and then pop them once DFT is done. The order in which 
elements are popped is the topological sort
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

int incidents[MAX];
int queue[MAX];
int rear = -1, front = 0;

int adjMatrix[MAX][MAX];

int vertexCount = 0;

int queueItemCount = 0;

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
} *newGraph;

struct CustomNode{
	char label;
} *customNodes;

void enqueue(int data){
	queueItemCount++;
	queue[++rear] = data;
}

int dequeue(){
	queueItemCount--;
	return queue[front++];
}

bool isQueueEmpty(){
	return queueItemCount == 0;
}

void addVertex(char label){
	customNodes[vertexCount++].label = label;
}

struct AdjListNode *createEdge(int data){
	struct AdjListNode *temp = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void addEdge(int start, int end){
	struct AdjListNode *temp;

	temp = createEdge(end);
	if(newGraph->arr[start].head){
		printf("head already here\n");
		temp->next = newGraph->arr[start].head;
		newGraph->arr[start].head = temp;
	}else{
		printf("there is no head\n");
		newGraph->arr[start].head = temp;	
	}

	//making a matrix as well
	adjMatrix[start][end] = 1;
}

void initArray(vertices){
	int i;
	for(i=0;i<vertices;i++){
		incidents[i] = 0;
	}
}

void findNodeWithZeroIncidents(){

	int i;
	struct AdjListNode *temp;
	
	for(i=0;i<newGraph->vertices;i++){
		temp = newGraph->arr[i].head;
		while(temp){
			incidents[temp->data]++;
			temp = temp->next;
		}
	}

	for(i=0;i<newGraph->vertices;i++){
		if(incidents[i] == 0){
			enqueue(i);
			printf("%c ", customNodes[i].label);
		}
	}

}

void topologicalSortList(){
	
	findNodeWithZeroIncidents();

	while(!isQueueEmpty()){
		int tempVertex = dequeue();
		incidents[tempVertex] = -1;
		struct AdjListNode *temp = newGraph->arr[tempVertex].head;

		while(temp){
			incidents[temp->data]--;
			if(incidents[temp->data] == 0){
				enqueue(temp->data);
				printf("%c ", customNodes[temp->data].label);
			}
			temp = temp->next;
		}
		
	}
}

void findNodeWithZeroIncidentsMatrix(int vertices){
	int i,j;

	bool noIncident = true;
	int count = 0;

	for(j=0;j<vertices;j++){
		for(i=0;i<vertices;i++){

			if(adjMatrix[i][j] != 0){
				count++;
				noIncident = false;
			}
		}
		incidents[j] = count;
		if(noIncident){
			// printf("enqueueing %d\n", j);
			enqueue(j);
			printf("%c ", customNodes[j].label);
		}
		noIncident = true;
		count = 0;
	}
}

void topologicalSortMatrix(int vertices){

	int j;

	findNodeWithZeroIncidentsMatrix(vertices);

	while(!isQueueEmpty()){
		int tempVertex = dequeue();
		// printf("dequeue %d\n", tempVertex);
		incidents[tempVertex]=-1;
		
		for(j=0;j<vertices;j++){
			if(adjMatrix[tempVertex][j] == 1){
				incidents[j]--;
				adjMatrix[tempVertex][j] = 0;
				if(incidents[j] == 0){
					// printf("enqueueing %d\n", j);
					enqueue(j);		
				}
			}
		}
	}
}

void printAdjList(struct Graph *newGraph, int vertices){
	int i;
	
	struct AdjListNode *temp;
	for(i=0;i<vertices;i++){
		temp = newGraph->arr[i].head;
		printf("%c-->", customNodes[i].label);
		while(temp){
			printf("%c--> ", customNodes[temp->data].label);
			temp = temp->next;
		}
		printf("\n");
	}
}

void initMatrix(int vertices){
	int i,j;

	for(i=0;i<vertices;i++){
		for(j=0;j<vertices;j++){
			adjMatrix[i][j] = 0;
		}
	}
}

int main(){
	int vertices = 6;

	initArray(vertices);

	initMatrix(vertices);

	//intializing the number of custom nodes as well the adjList basis number of vertices
	customNodes = (struct CustomNode *)malloc(sizeof(struct CustomNode)*vertices);
	newGraph = (struct Graph *)malloc(sizeof(struct Graph));
	newGraph->arr = (struct AdjList *)calloc(vertices,sizeof(struct AdjList));
	newGraph->vertices = vertices;

	addVertex('a');
	addVertex('b');
	addVertex('c');
	addVertex('d');
	addVertex('e');
	addVertex('f');

	addEdge(1,0);
	addEdge(4,0);
	addEdge(0,3);
	addEdge(0,2);
	addEdge(3,2);
	addEdge(2,5);
	addEdge(3,5);

	printAdjList(newGraph, vertices);

	printf("list:\n");
	topologicalSortList();

	initArray(vertices);
	printf("\n");
	printf("matrix:\n");
	topologicalSortMatrix(vertices);

	return 0;
}

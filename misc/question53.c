/*
http://practice.geeksforgeeks.org/problems/shortest-path-from-1-to-n/0
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

int queue[MAX];
int start = 0, rear = 0;
int elmCount = 0;


void enqueue(int data){
	queue[rear++] = data;
	elmCount++;
}

int dequeue(){
	elmCount--;
	return queue[start++];
}

int isQueueEmpty(){
	return elmCount == 0;
}

int minEdges(int vertices, int arr[vertices][vertices], int index, int *visited, int count){
	visited[index] = 1;
	enqueue(index);
	int i;
	int value;
	while(!isQueueEmpty()){
		int tempIndex = dequeue();
		if(arr[tempIndex][vertices-1] == 1){
			count++;
			printf("count is now...%d\n", count);
			return count;
		}
		for(i=0;i<vertices;i++){
			if(arr[index][i] == 1 && visited[i] == 0 && minEdges(vertices,arr,i,visited,count+1)){
				return minEdges(vertices,arr,i,visited,count+1);

			}else{
				enqueue(i);
			}
		}
	}
	return 0;		
}

void init(int *visited, int vertices){
	int i;
	for(i=0;i<vertices;i++){
		visited[i] = 0;
	}
}

int main(){

	int cases;
	scanf("%d",&cases);
	int i;
	for(i=0;i<cases;i++){
		int n;
		scanf("%d",&n);
		int arr[n+1][n+1];
		int i,j;
		for(i=1;i<n;i++){
			for(j=1;j<n;j++){
				if(i == j){
					arr[i][j] = 0;
				}else if(j==3*i || j==i+1){
					arr[i][j] = 1;
				}else{
					arr[i][j] = 0;
				}
			}
		}
		int visited[n+1];
		init(visited, n+1);
		printf("%d\n", minEdges(n+1,arr,1, visited, 0));
	}

	return 0;
}
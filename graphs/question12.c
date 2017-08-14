/*
Dijkstra algorithm
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define V 9

void minHeapify(int *arr, int index, int size){
	int left = 2*index + 1;
	int right = 2*index + 2;

	int temp, smallest;
	if(left <= size-1 && arr[left] < arr[index]){
		smallest = left;
	}else{
		smallest = right;
	}

	if(right <= size-1 && arr[right] < arr[smallest]){
		smallest = right;
	}

	if(smallest <= size-1 && arr[smallest] != arr[index]){
		temp = arr[smallest];
		arr[smallest] = arr[index];
		arr[index] =  temp;
		minHeapify(arr, smallest, size);	
	}
}

void buildHeap(int *arr, int size){
	int mid = (size/2)-1;
	int i;
	for(i=mid;i>=0;i--){
		minHeapify(arr,i,size);
	}
}

int extractMin(int *arr, int *size){
	if(*size < 1){
		return;
	}
	int res = arr[0];
	arr[0] = arr[*size - 1];
	*size = *size - 1;
	minHeapify(arr, 0, size);
	return res;
}

int decreaseKey(int index, int size, int key, int *arr){
	if(key > arr[index]){
		return;
	}	
	arr[index] = key;
	int i = index;
	while(i>=1 && arr[(i-1)/2] > arr[i]){
		int temp = arr[(i-1)/2];
		arr[(i-1)/2] = arr[i];
		arr[i] = temp;
		i = (i-1)/2;
	}
}

void dijkstra(int graph[V][V], int source){
	int dist[V]; //output array
	int visited[V];
	int i;
	int heap[V];
	heap[source] = 0;
	dist[source] = 0;
	for(i=0;i<V;i++){
		visited[i] = 0;
		if(i > 0){
			heap[i] = INT_MAX;
		}
	}
	int size = V;
	buildHeap(heap, size);
	
	while(size > 0){
		int index = extractMin(heap,&size);
		visited[index] = 1;
		int i;
		for(i=0; i<V;i++){
			if(graph[index][i] > 0 && visited[i] == 0){
				decreaseKey(i, size, graph[index][i], heap);
				visited[i] = 1;
			}
		}

	}	

	printf("Vertex\tDistance from source");
	for(i=0;i<V;i++){
		printf("%d\t", i);
		printf("%d\t", dist[i]);
		printf("\n");
	}

}

int main(){

	int graph[V][V] = {
		{0, 4, 0, 0, 0, 0, 0, 8, 0},
      	{4, 0, 8, 0, 0, 0, 0, 11, 0},
      	{0, 8, 0, 7, 0, 4, 0, 0, 2},
      	{0, 0, 7, 0, 9, 14, 0, 0, 0},
      	{0, 0, 0, 9, 0, 10, 0, 0, 0},
      	{0, 0, 4, 14, 10, 0, 2, 0, 0},
      	{0, 0, 0, 0, 0, 2, 0, 1, 6},
      	{8, 11, 0, 0, 0, 0, 1, 0, 7},
      	{0, 0, 2, 0, 0, 0, 6, 7, 0}
 	};

    dijkstra(graph, 0);                 

	return 0;
}
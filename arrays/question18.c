/*
Given an array and an integer K, find max element for each and every contiguous subarray of size k

METHOD1:
Naive approach, for each sub array we see the max
Time complexity: O(nk)
Space complexity: o(1)

METHOD2:
In this question we maintain a queue using a double linked list and each time if an element in the
queue from the rear is lesser than the next element we move the rear to the prev node and free
the memory. And in each iteration front is printed. Also if the last element in now no longer
a part of the queue as it is not in the window, it has to be removed from the queue.

Time complexity: O(n)
Space complexity: O(k) //queue will be of size k only in worst case

*/

//METHOD1
// #include <stdio.h>
// #include <stdlib.h>

// void printMaxInK(int *arr, int size, int k){
// 	int i,j;
// 	int max;
// 	for(i=0; i<size-k+1; i++){
// 		max = arr[i];
// 		for(j=i+1; j<k+i;j++){
// 			if(arr[j] > max){
// 				max = arr[j];
// 			}
// 		}
// 		printf("%d\n", max);
// 	}
// }

// int main(){
// 	int arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
// 	int k =3;
// 	int size = sizeof(arr)/sizeof(arr[0]);

// 	printMaxInK(arr,size,k);
// 	return 0;
// }

//METHOD2
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
} *rear = NULL, *front = NULL;

struct node *newNode(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

void enqueue(int data){
	struct node *temp;
	if(!rear){
		temp = newNode(data);
		front = rear = temp;
	}else{
		while(rear->data < data){
			struct node *temp = rear;
			rear = rear->prev;
			free(temp);
			if(!rear){
				front = rear;
				break;
			}
		}
		temp = newNode(data);
		if(!rear){
			front = rear = temp;
		}else{
			rear->next = temp;
			temp->prev = rear;
			if(!front->next){
				front->next = temp;
			}
			rear = rear->next;
		}
	}
}

void printList(){
	struct node *temp = front;
	while(temp){
		printf("%d\n", temp->data);
		temp=temp->next;
	}
	// printf("=======================\n");
}

void printMaxInK(int *arr, int size, int k){
	int i;
	for(i=0; i<k;i++){
		enqueue(arr[i]);
	}
	// printList();
	printf("%d\n", front->data);
	int last=i-k;
	for(;i<size;i++){
		// printf("enqueuing %d\n", arr[i]);
		enqueue(arr[i]);
		if(arr[last] == front->data){
			front=front->next;
			// printf("front now pointing to %d\n", front->data);
			front->prev = NULL;
		}
		printf("%d\n", front->data);
		// printList();
		last++;
	}
}

int main(){
	int arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
	int size = sizeof(arr)/sizeof(arr[0]);
	int k = 4;
	printMaxInK(arr, size, k);
}
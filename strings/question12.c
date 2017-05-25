/*
Find first non-repeating characters from a stream of characters

METHOD1:
In this case since there is a stream of characters which are coming at a regular interval, if we use out prev
approach, for each input we will have to use that approach resulting in O(n) time complexity for each
input. If n such inputs are there O(n^2)
Time complexity: O(n^2)
Space complexity: O(1)

METHOD2:
Here we store values in hash table as they come. Apart from increasing the counter we also store a pointer
to a linked list, which will be nodes having the values that come in. Each time if the value in hash Table
increases more than 1 we remove that node from the head and other node takes it place. Hence we always print
the top of the linked list after removing the repeatitions.

Note: we can also maintain a queue instead of linked list and pop everytime when size in hash table increases
to more than 1, and do not push that repeating element in the queue and print the top everytime

Time complexity: O(n) //total
Space complexity: O(n)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 256 //you can check for 256 chars

void push(int arr[], int *front, int *rear, int elm){
	*rear = (*rear+1)%max; //modulus after incrementing is imp.
	if(*rear == *front){
		printf("Overflow\n");
		if(*rear == 0){
			*rear = max - 1;
		}else{
			*rear = *rear-1;
		}
		return;
	}
	arr[*rear] = elm;
	return;
}

int pop(int arr[], int *front, int *rear){
	if(*front == *rear){ //this is where we started from when both were pointing to zero
		return -1;
	}	
	*front = (*front + 1)%max; //modulus after incrementing is imp.
	int data = arr[*front];
	return data;
}

void findFirstNonRepeating(char *str, int *arr,int *front, int *rear){
	printf("inside\n");
	int i;
	int length = strlen(str);
	printf("length is now %d\n", length);
	int hash[max] = {0};
	printf("value of hash of c is %d\n", hash[str[length-1]]);
	hash[str[length-1]]++;
	if(hash[str[length-1]] == 1){
		push(arr, front, rear, str[length-1]);
	}else if(hash[str[length-1]] > 0 && str[length-1]==arr[*rear]){
		pop(arr,front,rear);	
	}
	printf("value of array of rear is %c\n", arr[*rear]);
	while(hash[arr[*rear]] > 1){
		printf("inside\n");
		pop(arr,front,rear);		
	}
	printf("first non-repeating element now is: %c\n", arr[*rear]);
	
}

int main(){
	// char c;
	int i = 0;
	char str[max];
	int arr[max]; //queue
	int front,rear=0;
	while(1){
		printf("enter character\n");
		scanf("%c",&str[i]);
		findFirstNonRepeating(str,arr,&front,&rear);
		i++;
	}	
	return 0;
}
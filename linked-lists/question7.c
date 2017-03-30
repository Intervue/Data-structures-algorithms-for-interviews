/*
Find the kth node from the end of the linked list

METHOD1: 
same as prev. question6. kth element from end is (n-k)th from beginning.
use counter and all to determine and traverse twice
Time complexity: O(n)
Space complexity: O(1)

METHOD2:
Use two pointers at the distance of k from each other and advance them. As one reaches end, other will reach k
This can be done in one traversal only.
Time complexity: O(n)
Space complexity: O(1)

*/

//METHOD1
//already done in question6

//METHOD2
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

void printList(struct node *t){
	if(t){
		printf("%d --> ", t->data);
		printList(t->next);
	}
	printf("\n");
}

int findElement(struct node *head, int k){
	struct node *normal, *ahead;
	normal = ahead = head;
	int counter = 1;
	while(counter<k && ahead){
		ahead = ahead->next;
		counter++;
		if(ahead == NULL){
			return 0;
		}
	}

	while(ahead && ahead->next){
		ahead = ahead->next;
		normal = normal->next;
	}

	return normal->data;
	
}

int main(){

	int k = 2;
	struct node *head =(struct node *)malloc(sizeof(struct node));

	int counter = 1;
	struct node *t = head;
	while(counter<=5){
		t->data = counter*10;
		if(counter == 5){
			t->next = NULL;
		}else{
			t->next = (struct node *)malloc(sizeof(struct node));
		}
		t = t->next;
		counter++;
	}
	t = head;
	printList(t);
	t = head;
	
	printf("\nthe %dth element from the end is %d\n",k, findElement(head, 10));
}
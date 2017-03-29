/*
Traverse a Single linked list using recursion
Time complexity: O(n)


*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};

void printList(struct node *t){
	if(t){
		//interchanging these lines will print it in reverse order
		printf("%d\n", t->data);
		printList(t->link);
	}
}

int main(){

	struct node *head = (struct node *)malloc(sizeof(struct node));

	struct node *t = head;

	int counter = 1;
	while(counter<=5){

		t->data = counter*10;
		if(counter == 5){
			t->link = NULL;
		}else{
			t->link = (struct node *)malloc(sizeof(struct node));
		}

		t = t->link;

		counter++;
	}
	t = head;
	printList(t);

}
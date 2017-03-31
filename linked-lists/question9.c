/*
Find the starting node of cycle if cycle exists in a given linked list

METHOD:
If linked list has a loop, and two pointers are taken one moving at double the speed of other, 
they will meet at some point inside the loop. 
The distance from the start of the list to the first node where the loop starts is equal to the 
distance from where they meet to the first node.

Time complexity: O(n)
Space complexity: O(1)

There are others methods also like hash maps and visited thing in the structure as done prev through
which this question can be done

*/

//METHOD1 
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};

void printList(struct node *t){
	// int counter = 0;
	if(t){
		//interchanging these lines will print it in reverse order
		printf("%d-->", t->data);
		printList(t->link);	
	}
}

int checkLoop(struct node *head){
	struct node *slow,*fast = head;
	for(slow=head,fast=head; fast && slow && fast->link;){
		fast = fast->link->link;
		slow = slow->link;
		if(slow==fast){	
			slow = head;
			break;
		}	
	}

	for(slow=head;fast && fast->link;){
		fast = fast->link;
		slow = slow->link;
		if(slow == fast){
			return slow->data;
		}
	}
	return 0;
}

int main(){

	struct node *head = (struct node *)malloc(sizeof(struct node));

	struct node *t = head;

	int counter = 1;
	while(counter<=5){

		t->data = counter*10;
		if(counter == 5){
			t->link = head->link;
		}else{
			t->link = (struct node *)malloc(sizeof(struct node));
		}

		t = t->link;

		counter++;
	}
	t = head;
	// printList(t);
	int start = checkLoop(head);
	//detecting if this has a loop
	if(start){
		printf("there is a loop starting with %d\n", start);
	}else{
		printf("there is no loop\n");
	}

}

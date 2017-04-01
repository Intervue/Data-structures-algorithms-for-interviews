/*
Alternating split of a given linked list.

We can use a counter a split at even and odd numbers and move them to new list, but then we have 
dont have to create any new list but use the existing one and split it

METHOD:
take two pointers one pointing to head and one to head->next, then keep assigning them the next
node as per the pattern until one of them reaches null. Make the other one also null in the end
Time complexity: O(n)
Space complexity: O(1)
*/

//METHOD
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};

void makeList(struct node *t, int maxCounter, int mul){
	int counter = 1;
	while(counter <=maxCounter){
		t->data = counter*mul;
		if(counter == maxCounter){
			t->link = NULL;	
		}else{
			t->link = (struct node *)malloc(sizeof(struct node));;	
		}
		t = t->link;
		counter++;
	}
}

void printList(struct node *head){
	if(head){
		printf("%d-->", head->data);
		printList(head->link);
	}
	printf("\n");
}

void alternateList(struct node *head1, struct node *head2){
	for(;head1 && head2 && head1->link && head2->link && head2->link->link;
		head1=head1->link, head2=head2->link){
		
		head1->link = head2->link;
		head2->link = head2->link->link;
	}
	head1->link = head2->link = NULL;
}

int main(){
	struct node *head1 = (struct node *)malloc(sizeof(struct node));
	struct node *t = head1;
	makeList(t,8,10);
	struct node *head2 = head1->link;
	printList(head1);
	alternateList(head1,head2);
	printList(head1);
	printList(head2);

}
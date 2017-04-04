/*
Merge two sorted linked-lists into one sorted linked-list

METHOD1:
search each element of list 1 in list 2, and add at appropriate place in list2 by deleting from first element.
Time complexity: O(n^2)
Space complexity: O(1)

METHOD2: 
Compare first two nodes of both the lists and find the min. The one which is min, make it point by a temp
pointer and make the min point to the value with which it was compared
and move the other pointer on to the next node in that list having min, and compare again.
Keep moving the pointer until a list ends. Once any list is exhausted append the remaining list at the
end of list having min.
Time complexity: O(m+n)
Space complexity: O(1)

*/
//METHOD2

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};

void printList(struct node *head){
	for(;head;head=head->link){
		printf("%d-->", head->data);
	}
	printf("\n");
}

void makeList(struct node *first, struct node *second){
	first->data = 1;
	second->data = 2;
	first->link = (struct node *)malloc(sizeof(struct node));
	second->link = (struct node *)malloc(sizeof(struct node));
	first = first->link;
	second = second->link;
	first->data = 5;
	second->data = 3;
	first->link = NULL;
	second->link = (struct node *)malloc(sizeof(struct node));
	second = second->link;
	second->data = 4;
	second->link = NULL;
}

struct node *merge(struct node *first,struct node *second){
	struct node *head, *temp;
	
	if(first->data <= second->data){
		head = first;
		first = first->link;
	}else{
		head = second;
		second = second->link;
	}	
	temp = head;
	while(first && second){
		if(first->data <= second->data){
			temp->link = first;
			temp = temp->link;
			first = first->link;
		}else{
			temp->link = second;
			temp = temp->link;
			second = second->link;
		}
	}

	if(!first){
		temp->link = second;
	}else{
		temp->link = first;
	}

	return head;	
}

int main(){

	struct node *first = (struct node *)malloc(sizeof(struct node));
	struct node *second = (struct node *)malloc(sizeof(struct node));
	makeList(first,second);
	struct node *head = merge(first,second);
	printList(head);
	return 0;
}

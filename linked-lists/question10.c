/*
Suppose there are two single linked lists both of which merge at the same point and 
become a single linked list. Find the node at which they merge

METHOD1:
Brute force approach where in for every node in linked list1 you check if its present in the list 2 or not.
Time complexity: O(mn) //m and n are sizes of the two lists respectively
Space complexity: O(1)

METHOD2:
Hash table: store all the addresses of linked list 1 by traversing it in the hash table.
Then  traverse the other list and find where the first address matches
Time complexity: O(max(m,n))
Space complexity: O(m) OR O(n) whichever goes first

METHOD3:
Using Stacks:
Traverse the first linked list and store the result in one stack
Similarly for the other linked list store the result in the other stack
Then pop out both the stacks one by one, when the element does not match, the last popped out is the answer.
Time complexity: O(max(n,m, min(m,n)))
Space complexity: O(m) + O(n)

METHOD4:
Find the length of both the lists and subtract. Traverse the larger list by that difference and then move both 
the lists one by one, when the addresses are equal, thats the point of intersection
Time complexity: O(max(m,n))
Space complexity: O(1)

METHOD5:
Make the last node point to the beginning of any two lists. Now this problem has been converted to a loop
problem in a linked list where we need to find the first node. Same method as done in question9. Just that
after we solve the problem we need to revert the linked list back to its original form.
Time complexity: O(m+n) //total number of nodes in the linked list
Space complexity: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};

void printHash(int arr[], int size){
	for(int i=0; i<size; i++){
		printf("%d\n", arr[i]);
	}
}

void findMergeNode(struct node *l1, struct node *l2){

	//METHOD2
	//still to be discovered how to store addresses in hash table

	//METHOD3
	//still to be discovered how to use stacks

	//METHOD4
	struct node *t = l1;
	int length1 = 1;
	while(t->link){
		length1++;
		t=t->link;
	};
	int length2 = 1;
	t = l2;
	while(t->link){
		length2++;
		t = t->link;
	}
	int diff = (length1>length2)?length1-length2:length2-length1;
	
	if(length1>length2){
		t = l1;
		int counter = 1;
		while(counter<=diff){
			t = t->link;
			counter++;
		}
		struct node *t1 = l2;
		for(;t,t1;t1=t1->link,t=t->link){
			if(t1 == t){
				printf("the joining node is%d\n", t->data);
				break;
			}
		}
	}

	//METHOD5
	//aleady done in question9
	
}

void mergeList(struct node *l1, struct node *l2){
	struct node *t = l1;
	while(t->link){t = t->link;}
	t->link = l2->link->link;
}

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

int main(){

	struct node *head = (struct node *)malloc(sizeof(struct node));
	struct node *t = head;
	makeList(t,5,10);
	struct node *head1 = (struct node *)malloc(sizeof(struct node));
	t = head1;
	makeList(t,8,100);
	mergeList(head,head1);
	printList(head);
	printList(head1);
	findMergeNode(head,head1);
}





/*
Check whether a given list is a palindrome or not

METHOD1:
clone the list, reverse it and compare the first half of the list with the remaining half(that is first half
of cloned list.) 
Time complexity: O(n)
Space complexity: O(n)

METHOD2:
push all the elements of the linked list on to a stack. Now traverse the linked list and pop element from
the stack and compare the first half elements. 
Time complexity: O(n)
Space complexity: O(n) 

METHOD3:
Find the middle of the list, reverse the second half. Now compare the first half with the second half.
If its a match given linked list is a palindrome. Reverse the second half again to not distort the input.
Time complexity: O(n)
Space complexity: O(1)
*/

//METHOD1
#include <stdio.h>
#include <stdlib.h>

struct node{
	char data;
	struct node *link;
};

void printList(struct node *head){
	for(;head;head=head->link){
		printf("%c-->", head->data);
	}
}

void makeList(struct node *head){
	int count = 0;
	head->data = 'a';
	head->link = (struct node *)malloc(sizeof(struct node));
	head = head->link;
	head->data = 'r';
	head->link = (struct node *)malloc(sizeof(struct node));
	head = head->link;
	head->data = 'o';
	head->link = (struct node *)malloc(sizeof(struct node));
	head = head->link;
	head->data = 'r';
	head->link = (struct node *)malloc(sizeof(struct node));
	head = head->link;
	head->data = 'a';
	head->link = NULL;
}

struct node *cloneList(struct node *head){
	
	struct node *clone = (struct node *)malloc(sizeof(struct node));
	struct node *t = clone;
	while(head){
		clone->data = head->data;
		if(head->link){
			clone->link = (struct node *)malloc(sizeof(struct node));
		}else{
			clone->link = NULL;
		}
		head = head->link;
		clone = clone->link;
	}

	return t;

}	

struct node *reverseList(struct node *head){
	struct node *prev,*next,*curr;
	curr = head;
	prev = NULL;

	while(curr){
		next = curr->link;
		curr->link = prev;
		prev = curr;
		curr = next;
	}

	head = prev;
	return head;
}

int palindrome(struct node *head){
	if(head == NULL || head->link == NULL){
		return 1;
	}
	struct node *clone = cloneList(head);
	// printList(clone);
	clone = reverseList(clone);
	// printList(clone);

	for(;head && clone;head=head->link, clone=clone->link){
		if(head->data != clone->data){
			return 0;
		}
	}

	return 1;
}

int main(){
	struct node *head = (struct node *)malloc(sizeof(struct node));
	makeList(head);
	// printList(head);
	if(palindrome(head)){
		printf("linked list is a palindrome\n");
	}else{
		printf("linked list is NOT a palindrome\n");
	}
	return 0;
}

//===============================================================================================
//METHOD2: stack to be done later
//===============================================================================================
//METHOD3
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node{
	char data;
	struct node *link;
};

void printList(struct node *head){
	for(;head;head=head->link){
		printf("%c-->", head->data);
	}
	printf("\n");
}

void makeList(struct node *head){
	int count = 0;
	head->data = 'a';
	head->link = (struct node *)malloc(sizeof(struct node));
	head = head->link;
	head->data = 'r';
	head->link = (struct node *)malloc(sizeof(struct node));
	head = head->link;
	head->data = 'o';
	head->link = (struct node *)malloc(sizeof(struct node));
	head = head->link;
	head->data = 'r';
	head->link = (struct node *)malloc(sizeof(struct node));
	head = head->link;
	head->data = 'a';
	head->link = NULL;
}

struct node *reverseList(struct node *head){
	struct node *prev,*next,*curr;
	curr = head;
	prev = NULL;

	while(curr){
		next = curr->link;
		curr->link = prev;
		prev = curr;
		curr = next;
	}

	head = prev;
	return head;
}

struct node *reverseSecondHalf(struct node *head, int mid){
	int count = 1;
	while(count<=mid){
		head = head->link;
		count++;
	}
	head = reverseList(head);
	return head;
}

int palindrome(struct node *head){
	if(head == NULL || head->link == NULL){
		return 1;
	}
	struct node *t = head;
	int count = 1;
	while(t){
		count++;
		t=t->link;
	}
	t = head;
	int mid = ceil(count/2);
	struct node *other = reverseSecondHalf(head,mid);
	struct node *temp = other;
	for(;temp;temp=temp->link, t=t->link){
		if(t->data != temp->data){
			return 0;
		}
	}
	other = reverseList(other);
	return 1;
}

int main(){
	struct node *head = (struct node *)malloc(sizeof(struct node));
	makeList(head);
	
	if(palindrome(head)){
		printf("linked list is a palindrome\n");
	}else{
		printf("linked list is NOT a palindrome\n");
	}
	return 0;
}
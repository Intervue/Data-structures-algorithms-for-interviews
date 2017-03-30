/*
Find the middle node of a linked list

METHOD1:
counting the number of elements initially. Then finding the middle using that count.
Traverse the list again and then print that element
Time complexity: O(n)
Space complexity: O(1)

METHOD2: 
maintain a hash table of addresses (what node has what address) and once count
is there, simply the middle node can be accessed by its address. This will help us not
traverse the linked list again to print the element.
Time complexity: O(n)
Space complexity: O(n)

METHOD3:
Maintain two pointers (slow and fast). fast will take two steps at a time and slow will
take one step. This way when first reaches the end, slow will be in the middle and we will have to 
traverse the list only once
Time complexity: O(n)
Space complexity: O(1)


*/
//METHOD1
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
}

int main(){

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

	//finding the middle node
	int middle = ceil(counter/2);
	counter = 1;
	while(t){
		if(counter == 3){
			printf("\nthe middle element is: %d\n", t->data);
			break;
		}
		t=t->next;
		counter++;
	}

}
//=============================================================================================
//METHOD2
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

int main(){

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
	
	//finding the middle node
	int *hash = (int *)malloc(sizeof(int)*10);
	counter = 1;
	while(t){
		hash[counter] = (int)t;
		t = t->next;
		counter++;
	}
	
	int middle = ceil(counter/2);
	printf("\nthe middle element is %d\n", *(hash+middle));	 //@TODO facing prob here

}
//====================================================================
//METHOD3
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

int main(){

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
	
	struct node *slow, *fast;
	slow = fast = head;

	while(fast && fast->next){
		fast = fast->next->next;
		slow = slow->next;
	}
	
	printf("\nthe middle element is %d\n", slow->data);
}


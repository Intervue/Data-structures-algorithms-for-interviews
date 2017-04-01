/*
A linked list has three elements- data, link to next node and
 one random pointer pointing to a random node. Clone the linked list.

//space required to represent output is not included since its demand of the que.
We only take into account the extra space that we use

Applications for cloning the list with random pointers:
1) Snakes and ladders game. The next pointer will point to the next number in the sequence but the random
pointer will point to greater random number or smaller depending on ladder or snake.

METHOD1:
We can copy the entire list first and then copy random ptrs because then the nodes pointed by the
random ptrs will exist. We will tell whether they exist or node basis the data in the node.
We will have to search for that particular node in the newly created node for every random node in 
the linked list. 
Disadvantages of using this method: 
This method will fail if we have duplicate datas
Since comparision is to be made for data, if the data is some large thing, it will even be difficult to compare
it.
Time complexity: O(n^2)
Space complexity: O(1)

METHOD2:
We can store the mapping of addresses in the first list to the ones that we are creating respectively as 
key value in a hash table and create the list. Then to make random nodes we can see what node points to which
one in the first list and corresponding mapping in the second list and build random nodes.
Time complexity: O(n)
Space complexity: O(n) 

METHOD3:
Make each node corresponding to the first list by traversing. When a node is created, make the pointer of
the old list point to the corresponding node of the new list. Before that store the next node of the old list
in a temp variable (this variable will be overrided as we iterate). Also make the random node of new list point to the node of the old list.
Now keep repeating it. In the end  you will have a route to each and every random node in the list and
you can assign your random nodes right path.
Disadvantages: You will loose the old list
Time complexity: O(n)
Space complexity: O(1) 

METHOD4:
Traverse the first list and add all the new nodes just next to the node of the old list (in the middle)
everytime. Once that is done now you will have a reference to the older nodes random links. Traverse again
and update the random nodes of the newly created nodes that are in between the old nodes.
Now you can apply method of alternate split to separate the two linked lists.
Time complexity: O(n)
Space complexity: O(1)
*/

//METHOD1
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *arb;
	struct node *link;
};

void makeList(struct node *t, int maxCounter, int mul){
	int counter = 1;
	struct node *temp = t;
	while(counter <=maxCounter){
		t->data = counter*mul;
		if(counter == maxCounter){
			t->link = NULL;	
		}else{
			t->link = (struct node *)malloc(sizeof(struct node));	
		}
		t = t->link;
		counter++;
	}
	counter = 1;
	t = temp;
	while(counter <=maxCounter){
		if(t && t->link && t->link->link){
			t->arb = t->link->link;
		}else if(t && t->link){
			t->arb = t->link;
		}
		else if(temp->link){
			t->arb = temp->link;
		}	
		t=t->link;
		counter++;
	}
}

void cloneList(struct node *head, struct node *clone){
	for(;head; head=head->link, clone=clone->link){
		clone->data = head->data;
		if(head->link == NULL){
			clone->link = NULL;
		}else{
			clone->link = (struct node *)malloc(sizeof(struct node));	
		}
	}
}

void printList(struct node *head){
	if(head){
		printf("(%d, %p) -->", head->data, head->arb);
		printList(head->link);
	}
	printf("\n");
}

struct node *findPtrInClone(int val, struct node *clone){
	for(;clone; clone=clone->link){
		if(clone->data == val){
			return clone;
		}
	}
	return NULL;
}

void assignArb(struct node *head, struct node *clone){
	int val, cloneVal;
	struct node *clonehead = clone;
	for(;head;head=head->link,clone=clone->link){
		val = head->arb->data;
		struct node *temp = findPtrInClone(val, clonehead);
		clone->arb = temp;
	}
}

int main(){

	struct node *head = (struct node *)malloc(sizeof(struct node));
	struct node *t = head;
	makeList(t,8,100);
	printList(head);
	struct node *clone = (struct node *)malloc(sizeof(struct node));
	cloneList(head, clone);
	assignArb(head,clone);
	printList(clone);
}

//================================================================================================
//METHOD2: hash table to be done later
//METHOD3: coming soon

//METHOD4
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *arb;
	struct node *link;
};

void makeList(struct node *t, int maxCounter, int mul){
	int counter = 1;
	struct node *temp = t;
	while(counter <=maxCounter){
		t->data = counter*mul;
		if(counter == maxCounter){
			t->link = NULL;	
		}else{
			t->link = (struct node *)malloc(sizeof(struct node));	
		}
		t = t->link;
		counter++;
	}
	counter = 1;
	t = temp;
	while(counter <=maxCounter){
		if(t && t->link && t->link->link){
			t->arb = t->link->link;
		}else if(t && t->link){
			t->arb = t->link;
		}
		else if(temp->link){
			t->arb = temp->link;
		}	
		t=t->link;
		counter++;
	}
}

void cloneList(struct node *head){
	struct node *temp = head;
	while(temp){
		struct node *clone = (struct node *)malloc(sizeof(struct node));
		clone->data = temp->data;
		clone->link = temp->link;
		temp->link = clone;
		temp = clone->link;
	}
}

void setRandomNode(struct node *t1){
	while(t1){
		t1->link->arb = t1->arb->link;
		t1=t1->link->link;
	}

}

void printList(struct node *head){
	if(head){
		printf("(%d,%p) -->", head->data, head->arb);
		printList(head->link);
	}
	printf("\n");
}

struct node *separateClonedList(struct node *head1, struct node *head2){
	struct node *temp = head2;
	for(;head1 && head2 && head1->link && head2->link;
		head1=head1->link, head2=head2->link){
		
		head1->link = head2->link;
		head2->link = head2->link->link;
	}
	head1->link = head2->link = NULL;
	return temp;
}

int main(){
	struct node *head = (struct node *)malloc(sizeof(struct node));
	struct node *t = head;
	makeList(t,8,100);
	cloneList(head);
	setRandomNode(head);
	printList(head);

	struct node *clone = separateClonedList(head, head->link);

	printList(head);
	printList(clone);
}

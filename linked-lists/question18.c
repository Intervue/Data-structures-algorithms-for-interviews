/*
Insertion and deletion in memory efficient double linked lists

CONCEPT:
Memory efficient double linked lists:
In case of double linked lists you have two pointers one pointing to the next address and the other pointing
to the previous address. Rather than having the two pointers, we can have only one pointer and still
traverse it both ways as:
A XOR B XOR A = B
By the above rule.
if in each node pointer, rahter than storing the address of the next and prev nodes, in a single pointer we
store the XOR of next and previous node it can do the job.
That is
a = 0 XOR b
b = a XOR c
c = b XOR d
d = c XOR 0

For traversing from left:
Just remember the previous pointer everytime. If there is no previous pointer, just take it as 0.
for a going to b and so on
0 XOR 0 XOR b = b
a XOR a XOR c = c
b XOR b XOR d = d

for traversing from right
At d: 0 XOR 0 XOR c = c
At c: d XOR b XOR d = b

and so on. Therefore we save some memory by doing this.
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};

struct node *XOR(struct node *a, struct node *b){
	return (struct node*) ((unsigned int) (a) ^ (unsigned int) (b));
}

void printList(struct node *head){
	struct node *prev = NULL, *next;
	struct node *temp;
	while(head){
		// printf("%s\n","hell0" );
		temp = head;
		// printf("%d --> ", head->data);
		// if( XOR(head->link,0)->link == NULL){
			// printf("%s\n", "no data is there");
		// }else{
			printf("%p\n", XOR(head->link,0)->link);		
		// }
		
		if(!prev){
			// printf("inside no previous");
			head =XOR(0,head->link);
		}else{
			// printf("inside previous");
			head = XOR(prev,head->link);
		}
		prev = temp;

	}
}

void makeList(struct node *head){
	int count = 1;
	struct node *prev = NULL, *next;
	while(count<=5){
		
		head->data = count*10;
		next = (struct node *)malloc(sizeof(struct node));
		if(!prev){
			head->link = XOR(0,next);
		}else{
			head->link = XOR(prev,next);
		}
		count++;
		prev = head;
		head = next;
	}

}

int main(){

	struct node *head = (struct node *)malloc(sizeof(struct node));	

	makeList(head);
	printList(head);
	return 0;
}



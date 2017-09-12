/*
http://practice.geeksforgeeks.org/problems/game-of-death-in-a-circle/0
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *newNode(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next= NULL;
	return temp;
}

int chooseNum(int n, int k) {
	struct node *temp = newNode(1);
	struct node *head = temp;
	int i;
	for(i=1;i<n;i++) {
		temp->next = newNode(i+1);	
		temp = temp->next;
	}

	temp->next = head; //making it circular
	

	int remainingElem = n;
	struct node *p = head;
	struct node *prev = temp;
	// printf("here is prev %d\n", prev->data);
	
	struct node *help;
	int counter = 1;

	if(counter == k){
		help = p;
		p = p->next;
		prev->next = p;
		free(help);
		counter = 1;
		remainingElem--;
	}

	

	while(remainingElem > 1) {
		prev = p;
		
		p = p->next;
		
		counter++;
		if(counter == k) {
			help = p;
			p = p->next;
			prev->next = p;
			free(help);
			counter = 1;
			remainingElem--;
		}
		
	}	
	
	// printf("\nreturing %d\n", prev->data);
	return prev->data;
}

int main() {
	int cases;
	scanf("%d", &cases);
	int i;
	for(i=0;i<cases;i++) {
		int n,k;
		scanf("%d %d", &n, &k);

		printf("%d\n", chooseNum(n,k));

	}
}
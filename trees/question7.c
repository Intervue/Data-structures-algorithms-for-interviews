/*
Convert a binary tree into a double linked list in such a way that the order of nodes represents 
the inorder traversal of binary tree. Note this has to be done in place

METHOD1:
Convert the LST of the tree into a double linked list. Convert the RST of the tree into a double linked
list. Now join the root to the tail of the LST and join the root to the head of the RST. It will
form a linked list. Repeat the steps for each node using recursion. It will by default follow the inorder
fashion if done with a method like this. Since its inplace

Time complexity: T(n/2) + T(n/2) + O(n) = convert lst to dll + convert rst to dll + traverse to find head 
and tail = O(n^2) //worst case. Best case may be O(logn) for balanced tree
Space complexity: O(n)

METHOD2:
In the method above, the main time is lost in the traversal to find the head and tail while joining the 
three lists. If we somehow at each level during recursion return the head and tail, then in the end it
will take O(1) time to merge. Now in this method two values are to be returned head and tail which is very
complex process. Therefore, we return only one value that is the tail of the linked list and make the NULL
value point to the head, so that we can get it using tell at the time of merging
Therefore 
Time complexity: O(n)
Space complexity: O(h) which in worst case is O(n)
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newNode(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void printList(struct node *t){
	while(t){
		printf("%d -> ", t->data);
		t=t->next;
	}
	printf("\n");
}

struct node *convertToDll(struct node *root){
	if(!root){
		return NULL;
	}
	//@TODO
}

int main(){
	
	struct node *root = NULL;
	root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(6);
	root->left->right = newNode(9);
	root->right = newNode(3);
	root->right->left = newNode(8);
	root->right->right = newNode(12);

	struct node *head = convertToDll(root);

	printList(head);

	return 0;
}


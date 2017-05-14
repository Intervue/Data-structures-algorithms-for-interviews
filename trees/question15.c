/*
Print top view of a binary tree

Meaning that are visible from the top or at a different horizontal distance from the top

METHOD1:
Similar to method used in question12 3rd method, instead of storing all the nodes in a SLL attached to DLL,
we only add a node to the DLL if SLL is empty.
Then we print all of the nodes. Time and space complexity remains the same

METHOD2:
We just take the min and max into consideration from the above method and see if value greater than max 
and value less than min has been reached. If yes then only print the values else do not. This way
we print only nodes that are visible from the top.

Time complexity: O(n)
Space complexity: O(n) //recursion

*/
//METHOD2
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_NEGATIVE INT_MIN
#define MAX_POSITIVE INT_MAX

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newNode(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right= NULL;
	return temp;
}

void printTop(struct node *root, int *min, int *max, int dist){
	if(!root){
		return;
	}
	if(dist < *min){
		*min = dist;
		printf("%d\n", root->data);
	}
	if(dist > *max){
		*max = dist;
		printf("%d\n", root->data);
	}
	printTop(root->left, min, max, dist-1);
	printTop(root->right, min, max, dist+1);
}

int main(){
	int distance = 0;
	int min = MAX_POSITIVE, max = 0;
	struct node *root = newNode(10);
	root->left = newNode(12);
	root->left->left = newNode(14);
	root->left->right = newNode(16);
	root->left->right->left = newNode(106);
	root->left->right->left->left = newNode(116);
	root->left->right->left->left->left = newNode(126);
	root->left->right->left->left->left->left = newNode(136);
	root->left->right->left->left->left->left->left = newNode(146);
	root->right = newNode(20);
	root->right->left = newNode(22);
	root->right->right = newNode(26);

	printTop(root, &min, &max, distance);
	return 0;
}
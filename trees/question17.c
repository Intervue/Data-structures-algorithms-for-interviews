/*

Print left view of a binary tree

METHOD:
Left view means whatever is visible from the left. Therefore height is the main parameter here. We can check
if we have visited that much height before or not in pre order traversal by keep variable max height and 
current height. If max height is lesser than current height, we print the node else we dont.

Time complexity: O(n) //skewed tree
Space complexity: O(n) //skewed tree recursion
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
	temp->left = temp->right= NULL;
	return temp;
}

void printLeft(struct node *root, int height, int *max){
	if(!root){
		return;
	}
	if(*max < height){
		printf("%d\n", root->data);
		*max = height;
	}
	printLeft(root->left,height+1,max);
	printLeft(root->right,height+1,max);
}

int main(){
	int height = 0, max_height = -1;
	struct node *root = newNode(10);
	root->left = newNode(12);
	root->left->left = newNode(14);
	root->left->right = newNode(16);
	root->right = newNode(20);
	root->right->left = newNode(22);
	root->right->left->left = newNode(122);
	root->right->left->left->left = newNode(132);
	root->right->right = newNode(26);

	printLeft(root, height, &max_height);

	return 0;
}
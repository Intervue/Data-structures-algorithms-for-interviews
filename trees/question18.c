/*
Remove all paths of length k from root in a binary tree

METHOD:
Do a post order traversal, and if length of the path from the root should be less than k, then from LST it
should be less than k-1, and from RST it shold be less than k-1 and so on, delete the paths if thats true.
In case in the end LST and RST are found to be NULL delete the root as well.

Time complexity: O(n)
Space complexity: O(n)

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

struct node *deletePaths(struct node *root, int k){
	if(!root){
		return NULL; 
	}
	if(k == 0){
		return root;
	}
	root->left = deletePaths(root->left, k-1);
	root->right = deletePaths(root->right, k-1);

	if(!root->left && !root->right){
		free(root);
		return NULL;
	}
	return root;
}

void inorder(struct node *root){
	if(root){
		inorder(root->left);
		printf("%d\n", root->data);
		inorder(root->right);
	}
}

int main(){
	int k = 3;
	struct node *root = newNode(10);
	root->left = newNode(12);
	root->left->left = newNode(14);
	root->left->left->left = newNode(15);
	root->left->right = newNode(16);
	root->right = newNode(20);
	root->right->left = newNode(22);
	root->right->right = newNode(26);
	
	root = deletePaths(root, k);

	inorder(root);

}
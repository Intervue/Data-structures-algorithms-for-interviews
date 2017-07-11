#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
}*root = NULL, *root2 = NULL;

struct node *newNode(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

struct node *mirror(struct node *root, struct node *root2){
	
}

int main(){

	root = newNode(10);
	root->left = newNode(20);
	root->left->left = newNode(30);
	root->left->right = newNode(40);
	root->right = newNode(50);
	root->right->left = newNode(50);
	root->right->right = newNode(50);

	root2 = mirror(root, root2);

	return 0;
}
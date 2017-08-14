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
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void inorder(struct node *root){
	if(root){
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void displayTree(struct node *root){
	struct node *temp = root;
	inorder(temp);
}

int main(){

	struct node *root = newNode(10);

	root->left = newNode(20);
	root->right = newNode(30);
	root->left->left = newNode(40);
	root->left->right = newNode(50);

	root->right->left = newNode(60);
	root->right->right = newNode(70);

	displayTree(root);

	return 0;
}
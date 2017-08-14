/*
LCA for binary tree
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *right;
	struct node *left;
};

struct node *newNode(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int LCA(struct node *root, int n1, int n2){
	if(!root){
		return -1;
	}	
	int data = root->data;
	if(data == n1){
		return n1;
	}
	if(data == n2){
		return n2;
	}
	int left = LCA(root->left, n1, n2);
	int right = LCA(root->right, n1, n2);
	if(left == n1 && right == n2){
		return root->data;
	}
	return (left > 0)?left: right;
}

int main(){

	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(7);
	root->right->right = newNode(8);
	root->right->right->left = newNode(13);
	root->right->right->right = newNode(14);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->left->left = newNode(9);
	root->left->left->right = newNode(10);
	root->left->right->left = newNode(11);
	root->left->right->right = newNode(12);

	int res = LCA(root,8,13);

	if(res > 0){
		printf("LCA is....%d \n", res);	
	}else{
		printf("not present\n");
	}

	

	return 0;	
}
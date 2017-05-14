/*
Check whether the given binary tree is sum tree or not

Sum tree is the one where sum of values in the LST and sum of values in the RST is equal to the root. 
This is valid for all the nodes except the tree

METHOD:
We do post order traversal of the tree where first we compute LST, then RST then we compare if root value
is equal to LST value and RST value sum else we return -1. If equal we return sum of RST, LST and root->data

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

int checkSum(struct node *root){
	if(!root){
		return 0;
	}
	if(!root->left && !root->right){
		return root->data;
	}
	int left = checkSum(root->left);
	if(left == -1){
		return -1;
	}
	int right = checkSum(root->right);
	if(left == -1 ||  right == -1){
		return -1;
	}
	if(root->left && root->right && root->data == left + right){
		return 2*root->data;
	}
	return -1;
}

int main(){

	struct node *root = newNode(50);
	root->left = newNode(15);
	root->left->left = newNode(10);
	root->left->right = newNode(5);
	root->right = newNode(10);
	root->right->left = newNode(7);
	root->right->right = newNode(3);

	int isSumTree = checkSum(root);
	printf("RaAHUL ARORA %d\n", isSumTree);
	if(isSumTree > 0){
		printf("given tree is a sum tree\n");
	}else{
		printf("given tree is not a sum tree\n");
	}

	return 0;
}
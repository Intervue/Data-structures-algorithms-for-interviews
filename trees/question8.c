/*
Find the diameter of the given binary tree

Diameter of the binary tree is the max distance between any two nodes.

METHOD:
Using recursion we can find the height of the LST and the RST at each node. We can maintain a global
variable for diameter which can be updated if the new computed values is greater than the existing value.

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

int max_dia = 0;

struct node *newNode(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right= NULL;
	return temp;
}

int max(int left, int right){
	return (left < right)?right: left;
}

int findDiameter(struct node *root){
	if(!root){
		return 0;
	}
	int left = findDiameter(root->left);
	int right = findDiameter(root->right);
	int dia = left+right;
	if(max_dia < dia){
		max_dia = dia;
	}
	return 1 + max(left,right);
}

int main(){
	struct node *root = NULL;
	root = newNode(2);
	root->left = newNode(3);
	root->right = newNode(4);
	root->left->right = newNode(5);
	root->left->right->right = newNode(6);
	root->left->right->right->right = newNode(7);
	root->left->left = newNode(8);
	root->left->left->right = newNode(10);
	root->left->left->left = newNode(9);

	findDiameter(root);
	printf("max dia is...%d\n", max_dia);
	return 0;
}




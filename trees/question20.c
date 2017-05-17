/*
Check whether given two nodes are cousins in a binary tree

Two nodes in a tree are siblings if they are at the same level and have same parent, are cousins if they
are at same level but do not have same parent

METHOD1:
Method1 is that we can check for the level at which both the nodes are present. If the levels are same, we
can check for the parent. Eg: if the level if 4, we will just go till level 3 to check for parents.

Time complexity: O(n) + O(n) = O(n) //for finding level + traversal for parents
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

int checkHeight(struct node *root, int num1, int k){
	if(!root){
		return 0;
	}
	if(root->data == num1){
		return k;
	}
	int left = checkHeight(root->left, num1, k+1);
	int right = checkHeight(root->right, num1, k+1);
	return left?left:right; 
}           

int checkParent(struct node *root, int num1, int num2, int height, int k){
	if(!root){
		return 1;
	}
	if(k == height-1 && root->left->data == num1 && root->right->data == num2){
		return 0;
	}
	return (checkParent(root->left, num1, num2, height,k+1) && checkParent(root->right, num1, num2, height,k+1));
}

int checkCousins(struct node *root, int num1, int num2){
	int k = 0;
	int height1 = checkHeight(root,num1, k);//checking if they are at the same level or not
	int height2 = checkHeight(root,num2, k);//checking if they are at the same level or not
	if(height1 == height2){
		return checkParent(root, num1,num2,height1,k);
	}
 	return 0;
 }

int main(){
	struct node *root = newNode(10);
	root->left = newNode(12);
	root->left->left = newNode(14);
	root->left->right = newNode(16);
	root->right = newNode(20);
	root->right->left = newNode(22);
	root->right->right = newNode(26);

	int cousins	= checkCousins(root,14,22);
	printf("cousin value is %d\n", cousins);
	if(cousins){
		printf("Yes they are cousins\n");
	}else{
		printf("NOT cousins\n");
	}
}
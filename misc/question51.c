/*
http://practice.geeksforgeeks.org/problems/shortest-path-from-1-to-n/0
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *right;
	struct Node *left;
};

struct Node *newNode(int data){
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct Node *LCA(struct Node *root, int n1, int n2){

	if(!root){
		return NULL;
	}
	int data = root->data;
	if((n1 <= data && n2 >= data) || (n1 >= data && n2 <= data)){
		return root;
	}else if(n1 < data && n2 < data){
		return LCA(root->left, n1, n2);
	}
	return LCA(root->right, n1, n2);
}

int main(){
	struct Node *root = newNode(5);

	root->left = newNode(4);
	root->left->left = newNode(3);

	root->right = newNode(6);
	root->right->right = newNode(7);
	root->right->right->right = newNode(8);

	printf("%d ", LCA(root, 7,8)->data);

	return 0;	
}
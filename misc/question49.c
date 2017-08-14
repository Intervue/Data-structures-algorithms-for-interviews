/*
http://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1
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
	temp->left = NULL;
	temp->right = NULL;
}

int search(int *inorder, int key, int size){
	int i;
	for(i=0;i<size;i++){
		if(key == inorder[i]){
			return i;
		}
	}
}

struct node *constructTree(int start, int *postorder, int *inorder, struct node *root, int size){

	root = newNode(postorder[start]);

	int index = search(inorder, postorder[start]);

	root->left = inorder(index/2);
	root->right = inorder(index/2);

}	


void findTree(int *postorder, int *inorder, int size){

	struct node *root;

	root = constructTree(root);

}

int main(){
	int cases;
	int i;
	scanf("%d",&cases);
	for(i=0;i<cases;i++){
		int n;
		scanf("%d",&n);
		int postorder[n];
		int inorder[n];

		findTree(postorder, inorder, n);

	}
	return 0;
}
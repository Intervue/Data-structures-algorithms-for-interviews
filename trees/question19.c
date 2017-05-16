/*
Check whether a binary tree is a subtree of another binary tree

METHOD1:
Do a traversal of the main binary tree and see if the root element of referred binary tree equals to the data
in any node. If data equals, apply the check whether two trees are identical or not by passing root of
ref and matched root of main binary tree, if equal return else continue checking.

Time complexity: O(n*m) //n = number of nodes in main , m in smaller tree
Space complexity: O(n) + O(m) //can be considered as O(n) if value of m is small


METHOD2:
If two trees are identical, or if any traversal of a tree is done (be if inorder,preorder, postorder), the sub
tree in that tree will have nodes which occur together in a string but not necessarily in the same order but
will be a part of the same substring. Now if two trees are compared like this, If there any two traversals
are equal, i.e the smaller tree output is a substring of the bigger tree output following the same
sequence, then it can be said that smaller tree is a subtree of bigger one.
Finding a substring inside a string (comparison) can be done in linear time explained in strings

Time complexity: Since traversals + comparison is linear, time complexity is O(n), n>m
Space complexity: O(n) //since n>m and storing output as string and recursion stack 

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

int checkIdentical(struct node *root, struct node *ref){
	if(!root && !ref){
		return 1;
	}
	if(root->data == ref->data){
		return checkIdentical(root->left, ref->left) && checkIdentical(root->right, ref->right);
	}
	return 0;
	
}

struct node *checkSubTree(struct node *root, struct node *ref){
	if(!root){
		return NULL;
	}
	int identical;
	if(root->data == ref->data){
		identical = checkIdentical(root, ref);
		if(identical){
			return root;
		}
		return NULL;
	}
	struct node *left = checkSubTree(root->left, ref);
	struct node *right = checkSubTree(root->right, ref);
	return (left)?left: right;
}

int main(){
	int step, elm, level = 0;
	struct node *root = newNode(10);
	root->left = newNode(12);
	root->left->left = newNode(14);
	root->left->right = newNode(16);
	root->right = newNode(20);
	root->right->left = newNode(22);
	root->right->right = newNode(26);

	//second binary tree
	struct node *ref = newNode(20);
	ref->left = newNode(22);
	ref->right = newNode(28);

	struct node *isSubTree = checkSubTree(root,ref);

	if(isSubTree){
		printf("is a sub tree\n");
	}else{
		printf("is NOT a sub tree\n");
	}
}	

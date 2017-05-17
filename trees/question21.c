/*
Form a balanced binary search tree from a given sorted array

Since a sorted array will always give a skewed tree if done directly,

METHOD1:
To avoid skewed tree, if we check for every insertion if the tree needs to be rotated in order to be
balanced. For each element we will have to check logn level for thats

Time complexity: O(nlogn) //n is the total number of elements in the array
Space complexity: O(1) //if iterative

METHOD2:
We can simply pick the middle element and elements to the left of it will be LST and to the right of it
will be RST, then again from elements to the left we pick middle elemenet and keep repeating the process.

Time complexity T(n) = 1+T(n/2)+T(n/2) = O(n) //picking middle + doing the same process on LST and RST
Space complexity = O(1) // iterative
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newNode(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void printTree(struct node *root){
	if(root){
		printf("%d\n", root->data);		
		printTree(root->left);
		
		printTree(root->right);
	}
}

struct node *makeBBST(int *arr,struct node *root, int start,int end){
	if(start > end){
		return NULL;
	}
	int middle = start+floor((end-start)/2);	
	root = newNode(arr[middle]);
	root->left = makeBBST(arr,root,start,middle-1);
	root->right = makeBBST(arr,root,middle+1,end);
	return root;
}

int main(){
	struct node *root = NULL;
	int arr[] = {10,20,30,40,50,60,70};
	int size = sizeof(arr)/sizeof(arr[0]);
	root = makeBBST(arr, root,0,size-1);
	
	printTree(root);
}
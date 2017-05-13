/*
Get the level of a given key in a binary tree

METHOD:
Traversal. Any traversal can be used. Simply do it and check it its present at the node else check for RST 
and LST. Also keep track of the level by keeping another variable

Time complexity: O(n)
Space complexity: O(h) //worst case O(n) best case O(logn)

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

int searchLevel(struct node *root,int data, int *level){
	if(!root){
		return 0;
	}
	*level = *level + 1;
	if(root->data == data){
		return *level;
	}
	int left = searchLevel(root->left, data, level);
	int right = searchLevel(root->right, data, level);
	*level = *level - 1;
	return (left)?left:right;
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

	while(1){
		printf("1. Find element's level\n");
		printf("2. exit\n");
		scanf("%d",&step);
		switch(step){
			case 1: printf("enter the element to be searched\n");
				scanf("%d",&elm);
				level = searchLevel(root,elm, &level);
				if(level > 0){
					printf("level at which %d is present is %d\n", elm,level);
				}else{
					printf("element is not a part of the tree\n");
				}
				level = 0;
				break;
			case 2: exit(1);	
				break;
		}
	}

	return 0;
}
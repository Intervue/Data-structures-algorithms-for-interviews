/*
Largest sum independent set in a binary tree

Independent set means no two nodes are adjacent to each other. Eg:

		 		   10
			5		        6
		4		3         7		8
	   9 12    13 14	15 16  19 21
In the above tree if I choose 10, I cannot choose 5 and 6 as they are adjacent to 10.
If I choose 5, I cannot choose 10, 4 and 3 and so on.

METHOD:
Naive approach: Here there are two cases for every tree or subtree present (either to include the node
or to not include it)

Therefore LIS(root) = max {
	cost(root) + cost of all its grandchildren,
	cost of all its children of root
}

Therefore for each node the number of possibilities increase as we go down the tree. Hence,
exponential time complexity.

*/
//naive approach implementation
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
	temp->left = temp->right = NULL;
	return temp;
}

int findMax(int a,int b){
	return (a>b)?a:b;
}

int LISS(struct node *root){
	if(!root){
		return 0;
	}
	//size excluding the current node
	int size_excl = LISS(root->left) + LISS(root->right);
	//size including
	int size_incl = 1;
    if (root->left)
       size_incl += LISS(root->left->left) + LISS(root->left->right);
    if (root->right)
       size_incl += LISS(root->right->left) + LISS(root->right->right); 
   	return findMax(size_excl, size_incl);
}

int main(){
	struct node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);

    int size = LISS(root);
    printf("size of independent set with max sum is %d\n", size);
	return 0;
}


//dynamic programming approach
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	int liss;
	struct node *left;
	struct node *right;
};

struct node *newNode(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->liss = 0;
	temp->left = temp->right = NULL;
	return temp;
}

int findMax(int a,int b){
	return (a>b)?a:b;
}

int LISS(struct node *root){
	if(!root){
		return 0;
	}
	if(root->liss){
		return root->liss;
	}

	if(!root->left && !root->right){
		return (root->liss = 1);
	}
	//size excluding the current node
	int size_excl = LISS(root->left) + LISS(root->right);
	//size including
	int size_incl = 1;
    if (root->left)
       size_incl += LISS(root->left->left) + LISS(root->left->right);
    if (root->right)
       size_incl += LISS(root->right->left) + LISS(root->right->right); 
   	return findMax(size_excl, size_incl);
}

int main(){
	struct node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);

    int size = LISS(root);
    printf("size of independent set with max sum is %d\n", size);
	return 0;
}
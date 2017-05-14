/*
Vertical sum of the given binary tree

METHOD 1 of previous question (question12). Calculating sum by passing address of variable in print function.
Time and space complexity is the same.

METHOD2 (hashing) and METHOD3 (DLL) can also be applied, where the cell or node will contain the sum
apart from the pointers to the linked list containing different nodes from the tree. Time and space
complexity remains the same.

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
	temp->left = temp->right = NULL;
	return temp;
}

void findRange(struct node *root, int *min, int *max, int dist){
	if(!root){
		return;
	}
	if(dist < *min){
		*min = dist;
	}
	if(dist > *max){
		*max = dist;
	}
	findRange(root->left, min,max,dist-1);
	findRange(root->right, min,max,dist+1);
}

void printNodes(struct node *root, int dist,int k, int *sum){
	if(!root){
		return;
	}
	if(k == dist){
		*sum += root->data;
	}
	printNodes(root->left,dist-1,k,sum);
	printNodes(root->right,dist+1,k,sum);
}

int main(){
	int min = 0,max = 0, distance = 0,sum=0;
	struct node *root = newNode(10);
	root->left = newNode(12);
	root->left->left = newNode(14);
	root->left->right = newNode(16);
	root->right = newNode(20);
	root->right->left = newNode(22);
	root->right->right = newNode(26);

	findRange(root,&min, &max, distance);
	printf("min and max values are %d and %d\n", min,max);
	printf("printing numbers range-wise\n");

	for(int i=min; i<=max;i++){
		printf("printing for %d\n", i);
		printNodes(root, distance,i, &sum);
		printf("sum is %d\n", sum);
		sum = 0;
		printf("-----------------\n");
	}
	return 0;
}
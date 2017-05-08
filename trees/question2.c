/*
Check whether two trees are identical or not

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
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int checkIdentical(struct node *t1, struct node *t2){
	if(t1 == NULL && t2 == NULL){
		return 1;
	}
	if(t1->data == t2->data){
		return checkIdentical(t1->left, t2->left) && checkIdentical(t1->right, t2->right);
	}else{
		return 0;
	}
}

int main(){
	struct node *t1 = NULL;
	t1 = newNode(10);
	t1->left = newNode(20);
	t1->right = newNode(30);
	t1->left->left = newNode(40);
	t1->right->left = newNode(50);

	struct node *t2 = NULL;
	t2 = newNode(10);
	t2->left = newNode(20);
	t2->right = newNode(30);
	t2->left->left = newNode(40);
	t2->right->left = newNode(50);

	int isIdentical = checkIdentical(t1,t2);

	if(isIdentical){
		printf("both the trees are identical\n");
	}else{
		printf("trees are not identical\n");
	}
}
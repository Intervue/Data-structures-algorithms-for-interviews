/*
http://practice.geeksforgeeks.org/problems/two-mirror-trees/1

Check if one tree is mirror of another
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


int checkMirror(struct node *root1, struct node *root2){

	if((!root1 && root2) || (!root2 && root1)){
		return 0;
	}

	if(!root1 && !root2){
		return 1;
	}

	if(root1->data != root2->data){
		return 0;
	}

	return checkMirror(root1->left, root2->right) && checkMirror(root1->right, root2->left);
	
}

void preorder(struct node *root,int a,int b,int c){
	if(root){
		if(root->data == a){
			if(c == 'L'){
				root->left = newNode(b);
				return;
			}else{
				root->right = newNode(b);
				return;
			}
		}
		preorder(root->left,a,b,c);
		preorder(root->right,a,b,c);
	}
}

void inorder(struct node *root){
	if(root){
		inorder(root->left);
		printf("%d\n", root->data);
		inorder(root->right);
	}
}

struct node  *insertNode(struct node *temp, int a, int b, char c){
	if(!temp){
		temp = newNode(a);
		if(c == 'L'){
			temp->left = newNode(b);
		}else{
			temp->right = newNode(b);
		}
	}else{
		preorder(temp, a,b,c);	
	}
	return temp;
}	

int main(){
	int cases;
	scanf("%d",&cases);
	int i;
	for(i=0;i<cases;i++){
		int first,second;
		struct node *tree1;
		struct node *tree2;
		scanf("%d %d",&first, &second);
		int j;
		char c;
		int a,b;
		for(j=0;j<first;j++){
			scanf("%d %d %c",&a, &b, &c);	
			tree1 = insertNode(tree1,a,b,c);
		}

		for(j=0;j<second;j++){
			scanf("%d %d %c",&a, &b, &c);	
			tree2 = insertNode(tree2,a,b,c);
		}

		printf("%d\n",checkMirror(tree1, tree2));	

	}
	return 0;
}
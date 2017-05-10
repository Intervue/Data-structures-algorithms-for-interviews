/*
Find the lowest common ancestor given two nodes in a BINARY TREE

METHOD1:
Pre order traversal of a binary tree from top can give a path from the root of the tree to a particular node.
While doing pre order, if a particular node is unexplored (there are remaining children to the node that are 
not explored), we push it onto the stack till we find a node which is equal to the node we are looking for.
Once we find that node, we popp of elements from the stack and store them in the array. Repeat the steps
for node 2 and make another array. Now compare both the arrays and find the first common element. That is 
The LCS. In this case first is taken because array will be in the reverse order of the actual path taken.

Time complexity: O(n) //search + search + comparing array
Space complexity: O(h) = O(n)//worst case skewed tree


METHOD2:
We can do simultaneous search. For eg: if 9 and 12 are two nodes for which LCA is to be found, then, 
see if the root is equal to any of them, if yes, then that node is the LCA cos the other one will either be 
present on the left or right of it. Otherwise, go to the LST and RST and search for both the nodes. Now if in
LST it is not present on the root, again go to LST and RST of that. Keep repeating the steps and there will
be a point where both the nodes will be present on the left and right of a node. That node will be the
LCA. We can return 9 and 12 when found respectively from that particular subtrees, and -1 if not present
in a subtree.

Time complexity: O(n) //traversing the entire tree in a pre-order like fashion
Space complexity: O(n) //stack
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

struct node *lca(struct node *root, int num1, int num2){
	if(!root){
		return NULL;
	}
	if(root->data == num1 || root->data == num2){
		return root;
	}
	struct node *left = lca(root->left,num1,num2);
	struct node *right = lca(root->right, num1,num2);
	if(left && right){
		return root;
	}	
	return left?left: right;
}

int main(){
	int step, num1, num2;
	struct node *root = NULL;
	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(7);
	root->right->right = newNode(8);
	root->right->right->left = newNode(13);
	root->right->right->right = newNode(14);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->left->left = newNode(9);
	root->left->left->right = newNode(10);
	root->left->right->left = newNode(11);
	root->left->right->right = newNode(12);

	while(1){
		printf("1. Find LCA using METHOD 1\n");
		printf("2. Find LCA using METHOD 2\n");
		scanf("%d",&step);
		switch(step){
			case 1: 
				break;
			case 2: printf("Enter two elements for which LCA is to be found\n");
				scanf("%d",&num1);
				scanf("%d",&num2); 
				struct node *temp = lca(root,num1, num2);
				printf("Least common ancestor is... %d\n",temp->data);
				break;
		}
	}	
	return 0;
}

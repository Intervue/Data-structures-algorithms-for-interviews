/*
Print nodes which are at a k distance from the given key in a binary tree

METHOD:
Value of k = 3
Here we do a preorder traversal to find the node. Once the node if found, we have the distance of it from
the root, now with that node as root, we need to call preorder again with value of k given and print 
all the nodes which are in the LST and RST from that node.
Once that is done, this program will return to its parent 1 because it is at a distance of 1 from it.
Parent will understand, that in the right sub tree it needs to search for nodes which are at a distance
2 from the parent and print them as well. After that parent will return 2 to its parent. That parent 
needs to print all nodes in the RST at a distance 1. Keep doing this until value returned is equal to value
of k.
Time complexity: In worst case we will end up traversing the whole tree twice
O(n)
Space complexity: O(h) //worst case O(n), best O(logn)

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



int findElm(struct node *root, int elm, int *dist){
	if(!root){
		return 0;
	}
	if(root->data == elm){
		return *dist;
	}
	*dist = *dist + 1;
	int left = findElm(root->left,elm,dist);
	int right = findElm(root->right,elm,dist);
	*dist = *dist - 1;
	return (left)?left: right;
}

int main(){
	int step; int elm;int k;int distance =0;
	struct node *root = newNode(10);
	root->left = newNode(12);
	root->left->left = newNode(14);
	root->left->left->left = newNode(32);
	root->left->left->right = newNode(36);
	root->left->left->left->left = newNode(34);
	root->left->right = newNode(16);
	root->left->right->right = newNode(56);
	root->right = newNode(20);
	root->right->left = newNode(22);
	root->right->right = newNode(26);
	root->right->right->right = newNode(40);
	root->right->right->right->right = newNode(45);

	while(1){
		printf("1. Search from k distance from an element\n");
		printf("2. Exit\n");
		scanf("%d",&step);
		switch(step){
			case 1:  printf("enter the value of k\n");
				scanf("%d",&k);
				printf("enter the value of element\n");
				scanf("%d",&elm);
				int distance = findElm(root,elm,&distance);
				printf("%d\n", distance);
				if(distance < 0){
					printf("this key does not exist\n");
				}else{
					//NODES TODO
				}
				distance = 0;
				break;
			case 2: exit(1);
				break;
		}
	}
	return 0;
}
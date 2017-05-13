/*
Print nodes k-distance from the root

METHOD1:
We can do a pre order traversal and side by side maintain a distance from the root at each call. In case the 
distance is equal to the value of k we need, we print the element and return and do not go beyond that level.
In this case the value of distance will be incremented as we call the function recursively. This incremented
value will be passed in the arguments. 
Here the time complexity depends on the number of nodes we visited and so does the space complexity. At each
level number of nodes are 1+2+4+....2^k and each node is visited thrice, hence using GP formula

Time complexity: O(2^k)
Space complexity: O(2^k)
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

void printElementsByLevel(struct node *root, int k, int distance){
	if(root){
		if(distance == k){
			printf("%d\n", root->data);
			return;
		}
		printElementsByLevel(root->left,k,distance+1);
		printElementsByLevel(root->right,k,distance+1);
	}
}

int main(){
	struct node *root = newNode(10);
	root->left = newNode(12);
	root->left->left = newNode(14);
	root->left->right = newNode(16);
	root->right = newNode(20);
	root->right->left = newNode(22);
	root->right->right = newNode(26);

	int k = 2;
	int distance = 0;

	printElementsByLevel(root,k,distance);

	return 0;
}
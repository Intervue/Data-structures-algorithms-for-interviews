/*

Program to implement vertical tree order traversal


Vertical tree order traversal: Root is at a distance 0 from itself. When we move to the left child 
it is at a distance -1 from the root, the right child is at a distance 1 from the root.
If we keep doing -1 for every left child and +1 for every right child, we will have multiple nodes at 
the same distance value. The nodes having same distance value fall on a vertical line. 
If we traverse that line, it is called vertical tree order traversal


METHOD1:
We can do a pre-order traversal and print the numbers which fall at a horizontal distance lets say -2, then 
-1 then 0 then 1 and so on. But for that we need to find the lowest distance and the max distance possible.
Therefore, for that we do a pre order traversal and keep updating the two variable min and max whenever
lower then min and higher than max value is found in a pre order. For each LST and RST we subtract and add
1 to the distance and then compare with min and max. Once range is there (lets say -2 to 2), for each number
in range we do a pre order traversal and whenever distance is equal to number in range we print the element.

Time complexity: O(n) //if done k times considering k numbers in range O(kn) //if k is small
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

void printNodes(struct node *root, int dist,int k){
	if(!root){
		return;
	}
	if(k == dist){
		printf("%d\n", root->data);
	}
	printNodes(root->left,dist-1,k);
	printNodes(root->right,dist+1,k);
}

int main(){
	int min = 0,max = 0, distance = 0;
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
		printNodes(root, distance,i);
		printf("-----------------\n");
	}
	return 0;
}
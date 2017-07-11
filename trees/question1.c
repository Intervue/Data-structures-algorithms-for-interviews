	/*
Build a binary search tree and apply various operations on it

1.given normal numbers
2.given INORDER/ PREORDER/ POST ORDER

INORDER/PREORDER/POSTORDER traversal
=========================================
Time complexity:
O(n): we visit each node thrice and spend constant time there.
Space complexity:
O(n): recursion stack can be as big as n because in worst case tree can be skewed and function calls
will be stacked n times before anything pops off the stack
Same time complexity and space complexity is valid for PREORDER and POSTORDER

Recursive program to find number of nodes or leaves or non-leaves
======================================================================
Time complexity :O(n) //since we are visiting each node maximum 3 times and doing constant time operations
Space complexity: O(n) //worst case tree may be skewed and hence stack will contain all the functions

Recursive program to find the full nodes
=================================================
Time complexity :O(n) //since we are visiting each node maximum 3 times and doing constant time operations
Space complexity: O(n) //worst case tree may be skewed and hence stack will contain all the functions

Recursive program to the height of the tree
===============================================
Time complexity :O(n) //since we are visiting each node maximum 3 times and doing constant time operations
Space complexity: O(n) //worst case tree may be skewed and hence stack will contain all the functions

Find min and max (iterative version)
=======================================
Time complexity :O(n) //worst case tree can be skewed left or right ways
Space complexity: O(1) //iterative version

Check tree completeness
==============================

Time complexity :O(n) //worst case tree can be skewed left or right ways
Space complexity: O(1) //iterative version

*/
#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){
	return a>b?a:b;
}

struct node{
	int data;
	struct node *left;
	struct node *right;
}*root = NULL,*temp = NULL,*t2,*t1;

void create(int count){
	int elm;
	printf("enter the %d element\n", count);
	scanf("%d",&elm);
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = elm;
	temp->left = temp->right = NULL;
}

void search(struct node *t){
	if(temp->data < t->data && t->left){
		search(t->left);
	}else if(temp->data < t->data && !t->left){
		t->left = temp;
	}else if(temp->data > t->data && t->right){
		search(t->right);
	}else if(temp->data > t->data && !t->right){
		t->right = temp;
	}
}

void insert(){
	int num, counter = 0;
	printf("enter the number of elements to be inserted\n");
	scanf("%d", &num);

	while(counter < num){
		create(counter);
		if(root){
			search(root);
		}else{
			root = temp;
		}
		counter++;
	}
}

void findMin(){
	if(root){
		struct node *t = root;
		while(t->left){
			t = t->left;
		}
		printf("min element is %d\n", t->data);
	}else{
		printf("tree is empty\n");
	}
}

void findMax(){
	if(root){
		struct node *t = root;
		while(t->right){
			t = t->right;
		}
		printf("max element is %d\n", t->data);
	}else{
		printf("tree is empty\n");
	}
}

void preorder(struct node *t){
	if(t){
		printf("%d\n", t->data);
		preorder(t->left);
		preorder(t->right);
	}
}

void postorder(struct node *t){
	if(t){
		postorder(t->left);
		postorder(t->right);
		printf("%d\n", t->data);
	}
}

void inorder(struct node *t){
	if(t){
		inorder(t->left);
		printf("%d\n", t->data);
		inorder(t->right);
	}
}

int numNodes(struct node *t){
	if(!t){
		return 0;
	}
	return 1 + numNodes(t->left) + numNodes(t->right);
}

int numLeaves(struct node *t){
	if(!t){
		return 0;
	}
	if(!t->left && !t->right){
		return 1;
	}
	return numLeaves(t->left) + numLeaves(t->right);
}

int numFullNodes(struct node *t){
	if(!t){
		return 0;
	}
	if(t->left && t->right){
		return 1 + numFullNodes(t->left) + numFullNodes(t->right);
	}
	return numFullNodes(t->left) + numFullNodes(t->right);
}

int findTreeHeight(struct node *t){
	if(!t){
		return 0;
	}
	return 1 + max(findTreeHeight(t->left),findTreeHeight(t->right));	
}

int checkTreeCompleteness(struct node *t){
	if(!t){
		return 0;
	}
	if(!t->left && !t->right){
		return 1;
	}
	return checkTreeCompleteness(t->left) && checkTreeCompleteness(t->right);
}

struct node *findElement(struct node *root,int data){
	if(root){
		if(root->data == data){
			return root;
		}
		if(data > root->data){
			findElement(root->left, data);	
		}else{
			findElement(root->right, data);
		}
		
	}
	return NULL;
}

struct node *findPredecessor(struct node *root){
	while(root->right){
		root = root->right;
	}
	return root;
}

struct node *findElementAndDelete(struct node *root, int data){
	if(!root){
		printf("tree is empty\n");
		return NULL;
	}
	if(root->data == data){
		//case1: if no child
		if(!root->left && !root->right){
			free(root);
			return NULL;
		}

		//case2: one child
		if(!root->left && root->right){
			struct node *temp = root;
			free(temp);
			return root->right;
		}
		if(root->left && !root->right){
			struct node *temp = root;
			free(temp);
			return root->left;
		}

		//case3: two childs
		struct node *temp = findPredecessor(root->left);
		root->data = temp->data;
		root->left = findElementAndDelete(root->left,temp->data);
	}
	if(data > root->data){
		root->right = findElementAndDelete(root->right, data);
	}else{
		root->left = findElementAndDelete(root->left, data);
	}
	return root;
}

void delete(){
	int elm;
	printf("Enter the element to be deleted\n");
	scanf("%d",&elm);
	root = findElementAndDelete(root,elm);
}

int main(){
	int step, num, count;

	while(1){
		printf("1. Insert element\n");
		printf("2. Delete element\n");
		printf("3. Find max element\n");
		printf("4. Find min element\n");
		printf("5. PREORDER\n");
		printf("6. INORDER\n");
		printf("7. POSTORDER\n");
		printf("8. Give number of nodes\n");
		printf("9. Give number of leaves\n");
		printf("10. Give number of non leaves\n");
		printf("11. Give number of full nodes\n");
		printf("12. Height of the tree\n");
		printf("13. Check tree completeness\n");
		printf("14. exit\n");

		scanf("%d", &step);
		switch(step){
			case 1: insert();	
				break;
			case 2: delete();
				break;
			case 3: findMax();
				break;
			case 4: findMin();
				break;
			case 5: printf("preorder traversal is...\n"); 
				preorder(root);
				break;
			case 6: printf("inorder traversal is...\n"); 
				inorder(root);
				break;
			case 7: printf("postorder traversal is...\n"); 
				postorder(root);
				break;
			case 8: count = numNodes(root);
				printf("total number of nodes are %d\n", count);
				break;
			case 9: count = numLeaves(root);
				printf("total number of leaves are %d\n", count);
				break;
			case 10: count = numNodes(root) - numLeaves(root);
				printf("total number of non-leaves are %d\n", count);
				break;
			case 11: count = numFullNodes(root);
				printf("total number of full nodes are %d\n", count);
				break;
			case 12: count = findTreeHeight(root);
				printf("height of tree is %d\n", count-1);
				break;
			case 13: count = checkTreeCompleteness(root);
				if(count == 0){
					printf("tree is complete\n");
				}else{
					printf("tree is incomplete\n");
				}
				break;
			case 14: exit(1);
				break;

		}	
	}
	return 0;
}
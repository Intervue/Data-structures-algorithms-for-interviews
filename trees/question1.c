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


*/



#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
}*root=NULL, *temp = NULL, *t2, *t1;

void search(struct node *ptr){
	if((temp->data > ptr->data) && (ptr->right != NULL)){
		search(ptr->right);
	}else if((temp->data > ptr->data) && (ptr->right == NULL)){
		ptr->right = temp;
	}else if((temp->data < ptr->data) && (ptr->left != NULL)){
		search(ptr->left);
	}else if((temp->data < ptr->data) && (ptr->left == NULL)){
		ptr->left = temp;
	}
}

void create(){
	int data;
	printf("enter the data of the node to be inserted\n");
	scanf("%d",&data);
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right = NULL;
}

void insert(){
	create();
	if(root == NULL){
		root = temp;
	}else{
		search(root);
	}
}

// void delete(){
// 	if(root == NULL){
// 		printf("tree is already empty\n");		
// 		return;
// 	}
// 	int data;
// 	printf("Enter the data to be deleted\n");
// 	scanf("%d",&data);

// }

void inorder(struct node *t){
	if(t){
		if(t->left){
			inorder(t->left);	
		}
		printf("%d -> ", t->data);
		if(t->right){
			inorder(t->right);	
		}
	}	
}

void preorder(struct node *t){
	if(t){
		printf("%d -> ", t->data);
		if(t->left){
			preorder(t->left);	
		}
		if(t->right){
			preorder(t->right);	
		}
	}	
}

void postorder(struct node *t){
	if(t){
		if(t->left){
			postorder(t->left);	
		}
		if(t->right){
			postorder(t->right);	
		}
		printf("%d -> ", t->data);
	}	
}

int findMax(struct node *t){
	if(root==NULL){
		printf("tree is empty\n");
		return 0; 
	}
	while(t->right){
		t=t->right;
	}
	return t->data;
}

int findMin(struct node *t){
	if(root==NULL){
		printf("tree is empty\n");
		return 0; 
	}
	
	while(t->left){
		t=t->left;
	}
	return t->data;
}

int height(struct node *t){
	if(t == NULL){
		return 0;
	}
	if(!t->left && !t->right){
		return 0;
	}
	int l = height(t->left);
	int r = height(t->right);
	return 1+((l>r)?l:r);
}

int countFullNodes(struct node *t){
	if(!t){
		return 0;
	}
	if(!t->left && !t->right){
		return 0;
	}
	return countFullNodes(t->left)+countFullNodes(t->right)+((t->left && t->right)?1:0);
}

int countNonLeaves(struct node *t){
	if(t == NULL){
		return 0;
	}
	if(!t->left && !t->right){
		return 0;
	}else{
		return 1+countNonLeaves(t->left) + countNonLeaves(t->right);
	}
}

int countLeaves(struct node *t){
	if(t == NULL){
		return 0;
	}
	if(!t->left && !t->right){
		return 1;
	}else{
		return countLeaves(t->left) + countLeaves(t->right);
	}

}

int countNodes(struct node *t){
	if(t == NULL){
		return 0;
	}
	int num = 1 + countNodes(t->left) + countNodes(t->right);
	return num;
}

int main(){	
	int step,num, h;
	printf("BST...\n");
	while(1){
		printf("1. Insert element\n");
		printf("2. Delete element\n");
		printf("3. Find max element\n");
		printf("4. Find min element\n");
		printf("5. Make BST\n");
		printf("6. INORDER Traverse\n");
		printf("7. PREORDER Traverse\n");
		printf("8. POSTORDER Traverse\n");
		printf("9. Give number of nodes\n");
		printf("10. Give number of leaves\n");
		printf("11. Give number of non-leaves\n");
		printf("12. Give number of full-nodes\n");
		printf("13. Height of the tree\n");
		printf("16. exit\n");
		scanf("%d",&step);

		switch(step){
			case 1: insert();
				break;
			case 2: 
				// delete();
				break;
			case 3: num = findMax(root);
				printf("max is... %d\n", num);
				break;
			case 4: num = findMin(root);
				printf("min is... %d\n", num);
				break;
			case 5: 
				break;
			case 6: printf("INORDER...\n");
				inorder(root);
				printf("\n");
				break;
			case 7: printf("PREORDER...\n");
				preorder(root);
				printf("\n");
				break;
			case 8: printf("POSTORDER...\n");
				postorder(root);
				printf("\n");
				break;
			case 9: num = countNodes(root); 
				printf("number of nodes are %d\n", num);
				break;
			case 10: num = countLeaves(root);
				printf("number of leaves are: %d\n", num);
				break;
			case 11: num = countNonLeaves(root);
				printf("number of non leaves are: %d\n", num);
				break;
			case 12: num = countFullNodes(root);
				printf("number of full nodes are: %d\n", num);
				break;
			case 13: h = height(root);
				printf("the height of the tree is: %d\n", h);
				break;
			case 14: exit(1);
				break;
		}


	}		
	return 0;
}
/*
Find lowest common ancestor of given two nodes in a binary search tree

Where the path to the parent for two nodes meet for the first time, that is the lowest common ancestor

//METHOD1
Since this is a binary search tree, we can search for two elements given say (10,20) and we can store the path of it
that is the elements in the way in an array for both the searches. Then we can compare both the arrays and see 
where they are common at the max index. That index value is the least common incestor.
Time complexity: O(h) for search which in worst case can be O(n)
Space complexoty: O(h) for storing the path which in worst case can be O(n)


//METHOD2
We can do a simultaneous search for this. There is no need to store the path in an array in this case. If we see the
search splitting at a node, that is one element is smaller and one is greater than the node value, then that node
is the lowest common ancestor. If we see one value to be found as the node value itself, and the other node is
either greater or smaller than the node, then that node in this case also is the lowest common ancestor.
Time complexity: O(h) or O(n) //worst case
Space complexity: O(1) //if we do not do it using recursion else O(n)

Variation of this prob can be that, children have backlinks to the parent, then find the lowest common ancestor.
In this case we can apply a method similar to the linked list where two linkedlist were getting merged into a single 
one and we had to find the merging point. Therefore, in this case, we can see the height of both the nodes given from
the root and we can traverse from child to parent level by level alternatively and see where they meet. Both the nodes,
need to be brought at the same level for this. Therefore finding height is important. But there wont be any difference
to the time or space complexity given.
*/

//METHOD1
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root = NULL;

struct node *newNode(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void search(struct node *t, int data){
	if(data < t->data && t->left != NULL){
		search(t->left, data);
	}else if(data < t->data && t->left == NULL){
		t->left = newNode(data);
	}else if(data > t->data && t->right != NULL){
		search(t->right,data);
	}else{
		t->right = newNode(data);
	}
}

void insertNode(int data){
	if(!root){
		root = newNode(data);
		return;
	}
	search(root, data);
}

void inorder(struct node *t){
	if(t){
		if(t->left){
			inorder(t->left);	
		}
		printf("%d ->", t->data);
		if(t->right){
			inorder(t->right);	
		}
	}
}

void binarySearch(struct node *root,int *arr,int num){
	if(!root){
		return;
	}
	int size = sizeof(arr)/sizeof(arr[0]);
	printf("size inside whjiel filling is... %d\n", size);
	if(num > root->data){
		binarySearch(root->right,arr,num);
	}else if(num == root->data){
		return;
	}else{
		binarySearch(root->left,arr,num);
	}

}

void lowestAncestor(){
	int num1, num2;
	printf("Enter two numbers from the the BST\n");
	scanf("%d",&num1);
	scanf("%d",&num2);
	int arr1[MAX], arr2[MAX];

	binarySearch(root,arr1,num1);
	binarySearch(root,arr2,num2);

	int size1 = sizeof(arr1)/sizeof(arr1[0]);
	int size2 = sizeof(arr2)/sizeof(arr2[0]);

	int size = (size1 < size2)?size1:size2;

	printf("size is..... %d\n", size);

	int ancestor;
	for(int i=0; i<size; i++){
		printf("value from 1:  %d\n", arr1[i]);
		printf("value from 2:  %d\n", arr2[i]);
		if(arr1[i] == arr2[i]){
			ancestor = arr1[i];
		}
	}
	printf("ancestor is: %d\n", ancestor);
}

void multipleSearch(struct node *root, int num1, int num2){
	if(!root){
		return;
	}
	if(num1 < root->data && num2 < root->data){
		multipleSearch(root->left, num1,num2);
	}else if((num1 <= root->data && num2 >= root->data) || (num2 <= root->data && num1 >= root->data)){
		printf("ancestor is %d\n", root->data);
		return;
	}else{
		multipleSearch(root->right, num1, num2);
	}
}

void lowestAncestorDiversion(){
	int num1, num2;
	printf("enter two numbers from the BST\n");
	scanf("%d",&num1);
	scanf("%d",&num2);

	multipleSearch(root,num1, num2);
}

int main(){
	int step, data;
	while(1){
		printf("1. Insert element\n");
		printf("2. Print tree\n");
		printf("3. lowest common ancestor using arrays\n");
		printf("4. lowest common ancestor using diversion\n");
		scanf("%d",&step);
		switch(step){
			case 1: printf("enter element to be inserted\n");
				scanf("%d",&data);
				insertNode(data);
				break;
			case 2:inorder(root); 
				printf("\n");
				break;
			case 3: lowestAncestor(); 
				break;
			case 4: lowestAncestorDiversion();
				break;
		}
	}
	return 0;
}

/*
Extreme nodes in alternate order
http://practice.geeksforgeeks.org/problems/extreme-nodes-in-alternate-order/1
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *queue[100];
int size = 0, start = 0;
int elementsInQueue = 0;


void enqueue(struct node *root){
	queue[size] = root;
	size++;
	elementsInQueue++;
}

struct node *dequeue(){
	elementsInQueue--;
	return queue[start++];
}

int isQueueEmpty(){
	return elementsInQueue == 0;
}

struct node *newNode(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void inorder(struct node *root){
	if(root){
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void levelOrder(struct node *root){

	if(!root){
		return;
	}

	struct node *arr[100];
	int level = 0;
	int levelCount = 0;

	enqueue(root);
	levelCount++;
	int k = 0;
	while(levelCount > 0){
		while(!isQueueEmpty()){
			arr[k] = dequeue();
			k++;
			levelCount--;
		}
		if(levelCount == 0){
			if(level%2 == 0){
				printf("%d ", arr[k-1]->data);
			}else{
				printf("%d ", arr[0]->data);
			}
			level++;
			int i;
			for(i = 0; i<k; i++){
				struct node *temp = arr[i];
				if(temp->left){
					enqueue(temp->left);
					levelCount++;
				}
				if(temp->right){
					enqueue(temp->right);
					levelCount++;
				}
			}
		}
		k = 0;
	}	

}	

void displayTree(struct node *root){
	struct node *temp = root;
	// inorder(temp);
	
	levelOrder(temp);
}

int main(){

	struct node *root = newNode(10);

	root->left = newNode(20);
	root->right = newNode(30);
	root->left->left = newNode(40);
	root->left->right = newNode(50);

	root->right->left = newNode(60);
	root->right->right = newNode(70);

	root->left->left->left =newNode(80);
	root->left->left->right = newNode(90);

	root->left->right->left = newNode(100);
	root->left->right->right = newNode(110);

	root->right->left->left = newNode(120);
	root->right->left->right = newNode(130);
 
	root->right->right->left = newNode(140);
	root->right->right->right = newNode(150);

	displayTree(root);

	return 0;
}

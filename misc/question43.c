/*
http://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1
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

struct node *stack[1000];
int top = -1;

struct node *queue[10000];
int start = 0, rear = 0;
int totalElem = 0;

void enqueue(struct node *root){
	queue[rear++] = root;
	totalElem++;
}

struct node *dequeue(){
	totalElem--;
	return queue[start++];
}

int isQueueEmpty(){
	return totalElem == 0;
}

int isStackEmpty(){
	return top == -1;
}

void push(struct node *root){
	stack[++top] = root; 
}

struct node *pop(){
	return stack[top--];
}

void reverseLevelOrder(struct node *root){
	if(!root){
		return;
	}
	enqueue(root);
	while(!isQueueEmpty()){
		struct node *temp = dequeue();

		push(temp);

		if(temp->right){
			enqueue(temp->right);
		}
		if(temp->left){
			enqueue(temp->left);
		}
	}

	while(!isStackEmpty()){
		printf("%d ", pop()->data);
	}
}

int main(){

	struct node *root  = newNode(1);

	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	reverseLevelOrder(root);

	return 0;
}
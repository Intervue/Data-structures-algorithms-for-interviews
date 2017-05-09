/*
Implementation of Level order traversal in case of trees

//level order traversal has been explained in the readme under important concepts to solve algos

Time complexity: O(n)
Space complexity: O(n)
*/
//queue is implemented using an array
// #include <stdio.h>
// #include <stdlib.h>

// int size = 10;
// struct node *arr[10]; int front = 0, rear = 0;

// void queue(struct node *ptr){
// 	rear = (rear+1)%size;
// 	if(rear == front){
// 		printf("queue is full\n");
// 		if(rear == 0){
// 			rear = size - 1;
// 		}else{
// 			rear = rear-1;
// 		}
// 		return;
// 	}else{
// 		arr[rear] = ptr;	
// 	}
// 	return;
// }

// struct node *dequeue(){
// 	if(front == rear){
// 		printf("queue is empty\n");
// 		return NULL;
// 	}
// 	front = (front+1)%size;
// 	struct node *temp  = arr[front];
// 	return temp;
// }

// struct node{
// 	int data;
// 	struct node *left;
// 	struct node *right;
// };

// struct node *newNode(int data){
// 	struct node *temp = (struct node *)malloc(sizeof(struct node));
// 	temp->data = data;
// 	temp->left = NULL;
// 	temp->right = NULL;
// 	return temp;
// }

// void levelOrderTraversal(struct node *root){
// 	if(root){
// 		struct node *temp;
// 		queue(root);
// 		while(front != rear){
// 			temp = dequeue();
// 			printf("%d\n", temp->data);
// 			if(temp->left){
// 				queue(temp->left);
// 			}
// 			if(temp->right){
// 				queue(temp->right);
// 			}
// 		}
// 	}
// }

// int main(){
// 	struct node *root = NULL;
// 	root = newNode(10);
// 	root->left = newNode(20);
// 	root->right = newNode(30);
// 	root->left->left = newNode(40);
// 	root->left->right = newNode(50);
// 	root->right->left = newNode(60);
// 	root->right->right = newNode(70);

// 	levelOrderTraversal(root);

// 	return 0;
// }
//==========================================================================================
//queue is implemented as a linked list
#include <stdio.h>
#include <stdlib.h>

struct list{
	struct list *next;
	struct node *ptr;
};

void enqueue(struct node *root, struct node *base){
	base->ptr = root;
	
}

struct node *dequeue(){
	
}

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

void levelOrderTraversal(struct node *root){
	struct list *base = NULL;
	if(root){
		struct node *temp;
		enqueue(root, base);
		while(front != rear){
			temp = dequeue();
			printf("%d\n", temp->data);
			if(temp->left){
				enqueue(temp->left);
			}
			if(temp->right){
				queue(temp->right);
			}
		}
	}
}

int main(){
	struct node *root = NULL;
	root = newNode(10);
	root->left = newNode(20);
	root->right = newNode(30);
	root->left->left = newNode(40);
	root->left->right = newNode(50);
	root->right->left = newNode(60);
	root->right->right = newNode(70);

	levelOrderTraversal(root);

	return 0;
}
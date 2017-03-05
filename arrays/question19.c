/*
Count number of smaller elements on the right of each element in an array

METHOD1:
comparing each number with each number on its right
Time complexity: O(n^2)
Space complexity: O(1)

METHOD2:
Making a binary tree and traversing it
Binary tree has to start from rightmost element as we need their data in order to comment on other elements
Time complexity: O(n^2)
Time complexity: O(1)
*/

//METHOD1
#include <stdio.h>
int main(){
	int a[] = {10,3,4,5,7,1,3,2};
	int length = sizeof(a)/sizeof(a[0]);
	int elm1, counter;
	for(int i=0; i<length; i++){
		elm1 = a[i];
		counter = 0;
		for(int j=i+1;j<length;j++){
			if(elm1 > a[j]){
				counter++;
			}
		}
		printf("%d ", counter);
	}
}

//METHOD2
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data,height,size;
	struct node *left, *right;
}

int height(struct node *root){
	return !root?0: root->height;
}

int size(struct node *root){
	return !root?0: root->size;
}

int max(int a, int b){
	return (a>b)?a:b;
}

struct node *newNode(int data){

}

struct node *rightRotate(struct node *root){

}

struct node *leftRotate(struct node *root){

}

int getBalance(struct node *root){
	return !root?0: height(root->left)-height(root->right);
}

struct node *insert(struct node *root, int data, int *count){

}

void countSmallerArray(int *arr, int *smaller, int size){

}

void printArray(int *arr, int size){
	for(int i=0; i<size; i++){
		printf("%d", arr[i]);
	}
}

int main(){
	int a[] = {10,3,4,5,7,1,3,2};
}

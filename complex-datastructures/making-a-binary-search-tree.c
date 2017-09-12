#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root;

struct node *newNode(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void search(struct node *root, struct node *temp){
	if(temp->data < root->data && root->left){
		search(root->left, temp);
	}else if(temp->data < root->data && !root->left){
		root->left = temp;
	}else if(temp->data > root->data && root->right){
		search(root->right, temp);
	}else if(temp->data > root->data && !root->right){
		root->right = temp;
	}
}

int findMax(int a, int b){
	return a > b ? a : b;
}

void addNode(int data){
	struct node *temp = newNode(data);
	if(root){
		search(root, temp);
	}else{
		root = temp;
	}
}

void inorder(struct node *root){
	if(root){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

int totalNodes(struct node *root){
	int count = 0;
	if(root){
		count = count + 1;
		count += totalNodes(root->left);
		count += totalNodes(root->right);
	}
	return count;
}

int numLeaves(struct node *root){
	if(!root){
		return 0;
	}
	if(!root->left && !root->right){
		return 1;
	}
	int left = numLeaves(root->left);
	int right = numLeaves(root->right);

	return left + right;
}

int fullNodes(struct node *root){
	if(!root){
		return 0;
	}
	if(root->left && root->right){
		return 1;
	}
	int left = fullNodes(root->left);
	int right = fullNodes(root->right);
	return left + right;
}

int height(struct node *root){
	if(!root){
		return 0;
	}
	
	int left = height(root->left);
	int right = height(root->right);

	return 1 + findMax(left, right);
}

int searchMin(struct node *root){
	if(!root){
		return 0;
	}
	while(root->left){
		root = root->left;
	}
	return root->data;
}

int searchMax(struct node *root){
	if(!root){
		return 0;
	}
	while(root->right){
		root = root->right;
	}
	return root->data;
}

int isComplete(struct node *root){
	if(!root){
		return 0;
	}
	if((!root->left && !root->right) || (root->left && root->right)){
		return 1;
	}
	if((!root->left && root->right) || (root->left && !root->right) ){
		return 0;
	}
	int left = isComplete(root->left);
	int right = isComplete(root->right);

	return left && right;
}

struct node *getInorderSuccessor(struct node *root){
	if(root){
		while(root->left){
			root = root->left;
		}
		return root;
	}
	return NULL;
}

struct node *findAndDelete(struct node *root, int data){

	if(!root){
		return NULL;
	}
	if(data < root->data){
		root->left = findAndDelete(root->left, data);
	}else if(data > root->data) {
		root->right = findAndDelete(root->right, data);
	}else {

		//if node has only one child or not child
		if(!root->left){
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		if(!root->right){
			struct node *temp = root->left;
			free(root);
			return temp;
		}

		//if it has two children
		struct node *temp = getInorderSuccessor(root->right);

		root->data = temp->data;

		root->right = findAndDelete(root->right, temp->data);

	}
	return root;

}

int main(){
	
	int arr[] = {40,11,18,12,19,21,4,8};
	int i;
	int size =sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<size;i++) {
		addNode(arr[i]);		
	}
	printf("inorder is...\n");
	inorder(root);

	printf("\n no of nodes are: %d\n", totalNodes(root));
	printf("\n no of leaves are: %d\n", numLeaves(root));
	printf("\n no of non-leaves are: %d\n", totalNodes(root) - numLeaves(root));
	printf("\n no of full-nodes are: %d\n", fullNodes(root));
	printf("\n height is: %d\n", height(root));
	printf("\n min is: %d\n", searchMin(root));
	printf("\n max is: %d\n", searchMax(root));
	printf("\n tree is complete: %d\n", isComplete(root));

	//delete a node
	// printf("root of data is %d\n", root->data);
	root = findAndDelete(root, 11);
	printf("\ninorder is...\n");
	inorder(root);

	root = findAndDelete(root, 19);
	printf("\ninorder is...\n");
	inorder(root);

	root = findAndDelete(root, 40);
	printf("\ninorder is...\n");
	inorder(root);

	return 0;
}
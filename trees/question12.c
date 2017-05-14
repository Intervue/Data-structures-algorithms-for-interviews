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

METHOD2:
Intially when we are finding the elements, we are not able to print them all alongside, because we have to 
go in an order from least to max and we do not know the min and the max, so while traversing to find the min
and the max, we maintain a hashtable and store the values there. Max space that the hashtable will take 
is n-1 cells, if the tree is skewed on one side (positive or negative). While traversing we maintain a linked
list with each cell and attach all elements present at that distance. After min and max are found, we simply
traverse the hash table in that order and print the elements.

Time complexity: O(n) //total while pre-order traversal and even traversing the hash in worst case will take
O(n) time, so k factor has been eliminated
Space complexity: O(n) //since hash table also in worst case will take up O(n) space only.

METHOD3:
In method 2 since size of the hash table was not known as min and max values were not known a lot of space 
was wasted. To avoid that we can use a double linked list and create it on run time as and when its required.
Initially if we are at zero, we will insert 0 in the double linked list, and attach a single linked list to 
it, which will contain all the nodes on line 0. As we move to the left of the tree, we will pass this 0 to
left of the tree and it will check if further left node in DLL exists, if it doesnt it will create new and
follow the same process, when moving further left, node value will be decreased further. llarly for right 
as well.

Time complexity: O(n) //and is more efficient than hash table method as we declare only what is required
Space complexity: O(n) 

*/
//METHOD1
// #include <stdio.h>
// #include <stdlib.h>

// struct node{
// 	int data;
// 	struct node *left;
// 	struct node *right;
// };

// struct node *newNode(int data){
// 	struct node *temp = (struct node *)malloc(sizeof(struct node));
// 	temp->data = data;
// 	temp->left = temp->right = NULL;
// 	return temp;
// }

// void findRange(struct node *root, int *min, int *max, int dist){
// 	if(!root){
// 		return;
// 	}
// 	if(dist < *min){
// 		*min = dist;
// 	}
// 	if(dist > *max){
// 		*max = dist;
// 	}
// 	findRange(root->left, min,max,dist-1);
// 	findRange(root->right, min,max,dist+1);
// }

// void printNodes(struct node *root, int dist,int k){
// 	if(!root){
// 		return;
// 	}
// 	if(k == dist){
// 		printf("%d\n", root->data);
// 	}
// 	printNodes(root->left,dist-1,k);
// 	printNodes(root->right,dist+1,k);
// }

// int main(){
// 	int min = 0,max = 0, distance = 0;
// 	struct node *root = newNode(10);
// 	root->left = newNode(12);
// 	root->left->left = newNode(14);
// 	root->left->right = newNode(16);
// 	root->right = newNode(20);
// 	root->right->left = newNode(22);
// 	root->right->right = newNode(26);

// 	findRange(root,&min, &max, distance);
// 	printf("min and max values are %d and %d\n", min,max);
// 	printf("printing numbers range-wise\n");

// 	for(int i=min; i<=max;i++){
// 		printf("printing for %d\n", i);
// 		printNodes(root, distance,i);
// 		printf("-----------------\n");
// 	}
// 	return 0;
// }
//=======================================================================================================
// //METHOD2
// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 50 //this is the declared size of the hashTable. somehow if the numbers of the nodes in 
// //tree are known it can be optimized

// int balancer = 5; //assuming to balance the hash Table for negative values.

// struct node{
// 	int data;
// 	struct node *left;
// 	struct node *right;
// };

// //for linked list
// struct link{
// 	int data;
// 	struct link *next;
// };

// //for hash table
// struct hash{
// 	struct link *head;
// };

// struct node *newNode(int data){
// 	struct node *temp = (struct node *)malloc(sizeof(struct node));
// 	temp->data = data;
// 	temp->left = temp->right = NULL;
// 	return temp;
// }

// struct link *newLink(int data){
// 	struct link *temp = (struct link *)malloc(sizeof(struct link));
// 	temp->data = data;
// 	temp->next = NULL;
// 	return temp;
// }

// void insertInHash(struct hash *hashTable,int dist, struct node *root){
// 	dist = dist + balancer;
// 	if(!hashTable[dist].head){
// 		hashTable[dist].head = newLink(root->data);
// 	}else{
// 		struct link *temp = newLink(root->data);
// 		temp->next = hashTable[dist].head;
// 		hashTable[dist].head = temp;
// 	}
// }

// void findRange(struct node *root, int *min, int *max, int dist, struct hash *hashTable){
// 	if(!root){
// 		return;
// 	}
// 	insertInHash(hashTable,dist,root);
// 	if(dist < *min){
// 		*min = dist;
// 	}
// 	if(dist > *max){
// 		*max = dist;
// 	}
// 	findRange(root->left, min,max,dist-1, hashTable);
// 	findRange(root->right, min,max,dist+1, hashTable);
// }

// void printNodes(struct hash *hashTable, int i){
// 	struct link *temp = hashTable[i+balancer].head;
// 	while(temp){
// 		printf("%d\n", temp->data);
// 		temp = temp->next;
// 	}
// }

// int main(){
// 	struct hash *hashTable = (struct hash *)calloc(MAX, sizeof(struct hash));
// 	int min = 0,max = 0, distance = 0;
// 	struct node *root = newNode(10);
// 	root->left = newNode(12);
// 	root->left->left = newNode(14);
// 	root->left->right = newNode(16);
// 	root->right = newNode(20);
// 	root->right->left = newNode(22);
// 	root->right->right = newNode(26);

// 	findRange(root,&min, &max, distance, hashTable);
// 	printf("min and max values are %d and %d\n", min,max);
// 	printf("printing numbers range-wise\n");

// 	for(int i=min; i<=max;i++){
// 		printf("printing for %d\n", i);
// 		printNodes(hashTable,i);
// 		printf("----------------------\n");
// 	}
// 	return 0;
// }
//================================================================================================
//METHOD3
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

//for DLL table
struct doubleLink{
	int data;
	struct doubleLink *left; 
	struct doubleLink *right;
	struct link *head;
};

//for single linked list
struct link{
	int data;
	struct link *next;
};

struct node *newNode(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

struct doubleLink *newDouble(int data, struct doubleLink *left, struct doubleLink *right){
	struct doubleLink *temp = (struct doubleLink *)malloc(sizeof(struct doubleLink));
	temp->data = data;
	temp->left = left;
	temp->right = right;
	return temp;
}

struct link *newLink(int data){
	struct link *temp = (struct link *)malloc(sizeof(struct link));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void insertInList(struct node *root,struct doubleLink *middle,struct doubleLink **ref,int dist){
	printf("inserting...%d at\n", root->data);
	printf("supplied value is %d\n", dist);
	if(middle){
		printf("already exists...\n");
		printf("%d\n", middle->data);
		struct link *temp = newLink(root->data);
		temp->next = middle->head;
		middle->head = temp;
	}else{
		printf("creating new\n");
		if(dist < 0){
			middle = newDouble(dist,NULL,(*ref));	
		}else{
			middle = newDouble(dist, (*ref), NULL);
		}
		printf("created %d\n", middle->data);
		middle->head = newLink(root->data);
	}

	*ref = middle;
	printf("updating reference value. new value is %d\n", (*ref)->data);
	printf("==========================================\n");
}


void findRange(struct node *root, int *min, int *max, int dist, struct doubleLink *middle, struct doubleLink **ref){
	if(!root){
		return;
	}
	printf("now ref value %d\n", ref->data);
	insertInList(root,middle,ref,dist);
	if(dist < *min){
		*min = dist;
	}
	if(dist > *max){
		*max = dist;
	}
	findRange(root->left, min,max,dist-1, (*ref)->left, ref);
	findRange(root->right, min,max,dist+1, (*ref)->right, ref);
}

void printNodes(struct doubleLink *middle, int i){

}

int main(){
	struct doubleLink *middle = newDouble(0,NULL,NULL);
	struct doubleLink *ref = middle;
	int min = 0,max = 0, distance = 0;
	struct node *root = newNode(10);
	root->left = newNode(12);
	root->left->left = newNode(14);
	root->left->right = newNode(16);
	root->right = newNode(20);
	root->right->left = newNode(22);
	root->right->right = newNode(26);

	findRange(root,&min, &max, distance, middle, &ref);
	printf("min and max values are %d and %d\n", min,max);
	printf("printing numbers range-wise\n");
	
	printf("%s\n", );	
	
	
	while(middle->left){
		middle = middle->left;
	}
	printf("RAHUL ARORA  %d\n", ref->data);
	for(int i=min; i<=max;i++){
		printf("printing for %d\n", i);
		printNodes(middle,i);
		printf("----------------------\n");
	}
	return 0;
}

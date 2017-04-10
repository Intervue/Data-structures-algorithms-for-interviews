/*
Check whether two sets given are disjoint or not

METHOD1:
Pick one element from the array and traverse the other for each element to find if common exists
Time complexity: O(mxn)
Space complexity: O(1)

METHOD2:
Sort one array, Traverse the other and for each element in the other array apply binary search on
the sorted one to find it.
Time complexity: O(mlogm) + O(nlogm) //sorting + n times binary search on m elements
Space complexity: O(1)

METHOD3:
Sort both the arrays. Take two pointers, one at starting of each and compare elements, if not equal increment
the smaller element pointer to the next one and repeat the steps.
Time complexity: O(nlogn) + O(mlogm) + O(m+n) //sort1 + sort2 + merge or traversal
Space complexity: O(1)

METHOD4:
Make a balanced binary search tree for one of the arrays. Take the other array and search in the BBST.
TIme complexity: O(mlogm) + O(nlogm) //making balanced binary search tree + searching n elements for each logm 
                                     //time is required  
Space complexity: O(m) //for balanced binary search tree

METHOD5:
Make a hash table for one of the arrays. Traverse the other and search for each element in hash table
Time complexity: O(m+n) //traversal + insertion in hash table
Space complexity: O(m) OR O(n)
*/

//METHOD2 will be done later
//===============================================================================================
//METHOD3
#include <stdio.h>
#include <stdlib.h>

int compar(const void *a, const void*b){
	return (*(int *)a - *(int *)b);
}

int main(){
	int arr1[] = {1,5,11,24,32,8,7};
	int arr2[] = {2,3,6,12,9};

	int size1 = sizeof(arr1)/sizeof(arr1[0]);
	int size2 = sizeof(arr2)/sizeof(arr2[0]);

	qsort(arr1,size1,sizeof(int),compar);
	qsort(arr2,size2,sizeof(int),compar);

	int i=0,j=0, isDisjoint = 1;

	while(i<size1 && j<size2){
		if(arr1[i]==arr2[j]){
			isDisjoint = 0;
			break;
		}
		if(arr1[i]<=arr2[j]){
			i++;
		}else{
			j++;
		}
	}

	if(isDisjoint){
		printf("both the arrays have nothing in common\n");
	}else{
		printf("both the arrays have common elements\n");
	}

	return 0;
}
//==============================================================================================
//METHOD4 to be done later
//==============================================================================================
//METHOD5
#include <stdio.h>
#include <stdlib.h>

struct hash{
	int count;
	struct node *head;
};

struct node{
	int key;
	struct node *next;
};

struct node *createNode(int key,int hashIndex, struct hash *hashTable){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->key = key;
	newnode->next = NULL;	
	return newnode;
}

void insertInHash(int arr[],struct hash *hashTable, int size){
	int hashIndex;
	for(int i=0;i<size; i++){
		hashIndex = arr[i]%(size+1);
		struct node *newnode = createNode(arr[i],hashIndex,hashTable);
		if(!hashTable[hashIndex].head){
			hashTable[hashIndex].head = newnode;
			hashTable[hashIndex].count++;
		}else{
			newnode->next = hashTable[hashIndex].head;
			hashTable[hashIndex].head = newnode;
			hashTable[hashIndex].count++;
		}
	}
}

int searchInHash(int key, struct hash *hashTable, int size){
	printf("finding %d\n", key);
	int hashIndex = key%(size+1);
	if(!hashTable[hashIndex].head){
		return hashTable[hashIndex].count;
	}

	struct node *t = hashTable[hashIndex].head;
	while(t){
		if(t->key == key){
			return 1;
		}
		t=t->next;
	}
	return 0;	
}

void displayHash(struct hash *hashTable, int size){
	for(int i=0; i<size+1; i++){
		if(hashTable[i].head){
			struct node *t = hashTable[i].head;
			while(t){
				printf("%d-->", t->key);
				t=t->next;
			}
			printf("\n");
		}
	}
}

int isDisjoint(int size1, int size2,int arr1[], int arr2[]){
	struct hash *hashTable;
	if(size1 < size2){
		hashTable = (struct hash *)calloc(size1+1,sizeof(struct hash));
		insertInHash(arr1, hashTable, size1);
		for(int i=0; i<size1;i++){
			if(searchInHash(arr2[i], hashTable, size1)>0){
				return 0;
			}
		}
	}else{
		hashTable = (struct hash *)calloc(size2+1,sizeof(struct hash));
		insertInHash(arr2, hashTable, size2);
		displayHash(hashTable, size2);
		for(int j=0; j<size1;j++){
			if(searchInHash(arr1[j], hashTable, size2)>0){
				return 0;
			}
		}
	}
	return 1;
}


int main(){
	int arr1[] = {1,5,11,24,32,8,7};
	int arr2[] = {2,3,6,12,9};
	int size1 = sizeof(arr1)/sizeof(arr1[0]);
	int size2 = sizeof(arr2)/sizeof(arr2[0]);

	if(!isDisjoint(size1, size2,arr1, arr2)){
		printf("arrays have common elements\n");
	}else{
		printf("arrays do not have anything in common\n");
	}

	return 0;
}


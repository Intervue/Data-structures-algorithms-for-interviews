/*
Check whether given array contains duplicates in k-distance or not

METHOD1:
For every element in the array you can traverse the next k elements and find if there are any duplicates
Suppose array has N elements
Time complexity: O(kN)
Space complexity: O(1)

METHOD2:

*/

#include <stdio.h>
#include <stdlib.h>

struct hash{
	int count;
	struct node *head;
};

struct node{
	int value;
	struct node *next;
};

int searchInHash(struct hash *hashTable, int key, int size){
	int hashIndex = key%size;
	if(!hashTable[hashIndex].head){
		return 0;
	}

	struct node *t = hashTable[hashIndex].head;
	while(t){
		if(t->value==key){
			return 1;
		}
		t=t->next;
	}

	return 0;
}

void insertNewElement(int key,struct node *hashTable, int oldKey, int size){
	
	int hashIndex = key%size;
	//search and then delete
	//and then insert new one

}	

int findDuplicates(int arr[],int size, int k){
	struct hash *hashTable = (struct hash *)calloc(k,sizeof(struct hash));
	for(int i=2; i<size;i++){
		if(searchInHash(hashTable, arr[i],k)){
			return 1;
			break;
		}
		insertNewElement(arr[i], hashTable, arr[i-2],k);
	}
	return 0;
}

int main(){
	int arr[] = {1,1,2,3,4,5};
	int size= sizeof(arr)/sizeof(arr[0]);
	int k=2;
	if(!findDuplicates(arr, siz, k)){
		printf("no duplicates were found\n");
	}else{
		printf("duplicates present\n");
	}
	return 0;
}
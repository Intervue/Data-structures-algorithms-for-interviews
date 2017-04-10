/*
Group all the occurences of the elements order by their first occurence

METHOD1:
Just like quick sort, make an outer for loop to pick one element and then make an inner one to find the
same element again. Once the element is found, shift all the elements to the right till the place where
the element was found to make space for this element to group it. Repeat these steps for all elements
Time complexity: O(n^2)
Space complexity: O(1)

METHOD2:
Make a BBST-AVL. This tree will contain value of the element, and its frequency (no of times it has occured). Mkae
this tree by traversing the array. Now we will make a new array by visiting the binary search tree.
Now we will traverse the array, search value in the tree and basis the frequency we will repeat that element
in the new array that number of times and delete the element from the BBST. Deleting is imp so next time
when you visit this element in the array you do not repeat it as it has been grouped already
Time complexity: O(n) + O(nlogn) + O(nlogn) = O(nlogn)
Space complexity: O(n) (extra space for hashtable and output)

METHOD3: 
Applying the above method using a hashtable
Time complexity: O(n)
Space complexity: O(n) (for hashTable and output array)
*/

//METHOD2  to be done later
//================================================================================================
//METHOD3

#include <stdio.h>
#include <stdlib.h>

struct hash{
	int count;
	struct node *head;
};

struct node{
	int key,count;
	struct node *next;
};

struct hash *hashTable = NULL;

struct node *createNode(int key){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->next = NULL;
	newnode->key = key;
	newnode->count = 1;
	return newnode;	
}

struct node *searchInHash(int key, struct hash *hashTable, int size){
	int hashIndex = key%size;
	struct node *t;
	if(hashTable[hashIndex].head){
		t=hashTable[hashIndex].head;
		while(t){
			if(t->key==key){
				return t;
			}
			t=t->next;
		}
	}
	return NULL;	
}

void insertInHash(int key, int size){
	int hashIndex = key%size;
	//search if key exists already, if yes then increment its count else create a new node
	struct node *exist = searchInHash(key, hashTable,size);
	if(exist){
		exist->count++;
	}else{
		struct node *newnode = createNode(key);
		if(!hashTable[hashIndex].head){
			hashTable[hashIndex].head = newnode;
			hashTable[hashIndex].count++;
			return;
		}
		newnode->next = hashTable[hashIndex].head;
		hashTable[hashIndex].head = newnode;
		hashTable[hashIndex].count++;
		return;	
	}
}

void groupByElements(int arr[], int size){
	hashTable = (struct hash *)calloc(size+1,sizeof(struct hash));
	int hashSize = size+1;
	for(int i=0;i<size;i++){
		insertInHash(arr[i], hashSize);
	}

	int new_arr[size];
	struct node *exist = NULL; int max = 1;
	for(int j=0;j<size;j++){
		exist = searchInHash(arr[j],hashTable,hashSize);
		if(exist){
			for(int k=j; k<exist->count+j;k++){
				printf("%d\n", exist->key);
			}
			exist->count = 0;
		}
	}
}

int main(){
	int arr[] = {3,2,4,5,6,2,3,5,6,5};
	int size = sizeof(arr)/sizeof(arr[0]);

	groupByElements(arr,size);

	return 0;
}
/*
Find four elements i,j,k and l in an array such that i+j=k+l

METHOD1:
Brute force. We pick 4 elements from n elements. 4 for loops will be involved. Check the formula for each combination.
Time complexity: O(n^4)
Space complexity: O(1)

METHOD2:
Find out all possible pairs. Now for all pairs store the sum and the number of times it has occured in a Binary search
tree. Also it should point to the pair that is responsible for that sum. If there are more than 1 pair, then add the
pair to the linked list. 
Eg: (8,2) -> 5,3 -> 6,2
Binary node having sum 8 repeating two times pointing to a linked list with pairs
Now traverse it and node having more than 1 pair is the answer.
Time complexity: O(n^2)//to make pairs + O(n^2logn^2) //to store them in binary search tree
= O(n^2logn)
Space complexity: size of binary search tree having n^2 elements: O(n^2)

METHOD3:
Store the above in a hashtable instead of BST. The hashtable will have sum as indices and frequency. Also it will
contain pointer to a list.
Time complexity: O(n^2) //as insertion and search will now be in O(1)
Space complexity: O(n^2) //size of hash table
*/

//METHOD1: regular method implement yourself
//===========================================================================================
//METHOD2: binary search tree. to be done later
//===========================================================================================
//METHOD3: (open addressing used with a twist along with linked list)
#include <stdio.h>
#include <stdlib.h>

struct hash *hashTable = NULL;

struct hash{
	int sum, count;
	struct node *head;
};

struct node{
	int num1,num2;
	struct node *next;
};

void insertInHash(int num1, int num2, int size){
	int sum = num1+num2;
	int index = sum%size;
	int position = index;

	for(int count = 0; count < size; count++){
		if(!hashTable[position].sum){
			hashTable[position].sum = sum;
			struct node *newnode = (struct node *)malloc(sizeof(struct node));
			newnode->next = NULL;
			newnode->num1 = num1;
			newnode->num2 = num2;
			hashTable[position].head = newnode;
			hashTable[position].count++;
			break;
		}else{
			if(hashTable[position].sum == sum){
				struct node *newnode = (struct node *)malloc(sizeof(struct node));
				newnode->num1 = num1;
				newnode->num2 = num2;
				newnode->next = hashTable[position].head;
				hashTable[position].head = newnode;
				hashTable[position].count++;
				break;
			}else{
				position = (count + position)%size;
			}
		}
	}
}

void printCombinations(int size, int index){
	struct node *t = hashTable[index].head;
	printf("sum is %d\n", hashTable[index].sum);
	printf("for combinations\n");
	while(t){
		printf("%d\t,%d\n",t->num1,t->num2);
		t = t->next;
		printf("-----------------------------\n");
	}
	printf("==============================\n");
}

void display(int size){

	for(int i=0;i<size;i++){
		printf("sum is %d\n", hashTable[i].sum);
		printf("count is %d\n", hashTable[i].count);
		printf("===================\n");
	}

}

void findAllPairs(int arr[], int size){
	int hashSize = size+1;
	hashTable = (struct hash *)calloc(hashSize,sizeof(struct hash));
	for(int i=0; i<size-1; i++){
		for(int j=i+1; j<size;j++){
			insertInHash(arr[i],arr[j],hashSize);
		}
	}
	// display(hashSize);
	for(int j=0;j<hashSize;j++){
		if(hashTable[j].count > 1){
			printCombinations(hashSize, j);
		}
	}
}

int main(){
	int arr[] = {6,2,3,4,5,10,1};
	int size = sizeof(arr)/sizeof(arr[0]);
	findAllPairs(arr,size);

	return 0;
}
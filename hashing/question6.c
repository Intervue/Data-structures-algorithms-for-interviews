/*
Given an array, print all subarrays in the array which has sum 0

METHOD1:
Find all the sub arrays of the array. For each element there are n subarrays. Total elements are n.
Total subarrays = n*n = n^2. For all these subarrays find sum which will take O(n) time in worst case.
Time complexity: O(n^3)
Space complexity: O(1)

METHOD2:
Find the array containing cumulative sum for all the values.
Now find all the sub arrays and find the value for the sum of each sub array from cumulative sum array in constant
time.
Time complexity: O(n^2)
Space complexity: O(n)

METHOD3:
Store the cumulative sum array in a hashtable. Eg. if the sum is 11 is should be stored at 11th index of hashTable
with count 1. If 11 repeats again increment count to two.
Now scan the hashtable and see all values having count greater than 1. That will be the total number of sub arrays.
Time complexity: O(n)
Space complexity: O(n)
*/

//METHOD1
#include <stdio.h>
#include <stdlib.h>

int findSum(int temp[], int start,int size){
	int sum = 0;
	for(int i=start; i<=size;i++){
		sum += temp[i];
	}
	return sum;
}

void printIt(int temp[], int start,int size){
	for(int i=start; i<=size; i++){
		printf("%d\t",temp[i]);
	}
	printf("\n-----------------\n");
}

void printSubArrays(int arr[], int size){
	int sum;
	int temp[size];
	for(int i=0; i<size-1; i++){
		temp[i] = arr[i];
		for(int j=i+1;j<size;j++){
			temp[j] = arr[j];
			if(!findSum(temp, i,j)){
				printIt(temp,i,j);
			}
		}
	}	
}

int main(){
	int arr[] = {11,10,-5,-3,-2,10,5,-1,-6};
	int size = sizeof(arr)/sizeof(arr[0]);
	printSubArrays(arr,size);
	return 0;
}
//============================================================================================
//METHOD2
#include <stdio.h>
#include <stdlib.h>

int findSum(int arr[], int start, int end){
	return arr[end]-arr[start-1];
}

void printIt(int arr[], int start, int end){
	for(int i=start;i<=end; i++){
		printf("%d\t",arr[i]);
	}
	printf("\n====================\n");
}

void printSubArrays(int arr[], int size){

	int cumSum[size], sum=0;
	for(int i=0; i<size;i++){
		sum += arr[i];
		cumSum[i] = sum;
	}

	for(int i=0; i<size-1;i++){
		for(int j=i+1; j<size;j++){
			if(!findSum(cumSum, i,j)){
				printIt(arr,i,j);
			}
		}	
	}
}

int main(){
	int arr[] = {11,10,-5,-3,-2,10,5,-1,-6};
	int size = sizeof(arr)/sizeof(arr[0]);
	printSubArrays(arr,size);
	return 0;
}
//========================================================================================
//METHOD3 (done using open addressing with a twist but linked list used still)
#include <stdio.h>
#include <stdlib.h>

struct hash *hashTable = NULL;

struct hash{
	int num,key;
	struct node *head;
};

struct node{
	int end;
	struct node *next;
};

void printIt(int arr[], int start, int end){
	for(int i=start;i<=end; i++){
		printf("%d\t",arr[i]);
	}
	printf("\n====================\n");
}

void insertInHash(int size, int key, int end){
	int index = key%size;
	int position = index;

	for(int count = 0; count<size;count++){
		if(hashTable[position].num == 0){
			
			hashTable[position].key = key;
			struct node *newnode = (struct node *)malloc(sizeof(struct node));
			newnode->next = NULL;
			newnode->end = end;
			hashTable[position].head = newnode;
			hashTable[position].num++;
			break;
		}else{
			if(hashTable[position].key == key){
				hashTable[position].num++;
				struct node *newnode = (struct node *)malloc(sizeof(struct node));
				newnode->end = end;
				newnode->next = hashTable[position].head;
				hashTable[position].head = newnode;
				break;
			}else{
				position = (index + count)%size;
			}
		}
	}

}



void printList(int arr[],int index){
	struct node *t = hashTable[index].head;
	int start,end;
	while(t){
		end = t->end;
		t=t->next;	
		start = t->end+1;
		for(int i=start;i<=end;i++){
			printf("%d\t", arr[i]);
		}
		printf("\n");
		if(!t->next){
			break;
		}
	}
	
}

void displayHash(int size){
	for(int i=0; i<size;i++){
		printf("POSITION %d\n", hashTable[i].num);
		printf("KEY %d \n", hashTable[i].key);
	}
	printf("==============================\n");
}

void printSubArrays(int arr[], int size){
	int hashSize = size+1;
	hashTable = (struct hash *)calloc(hashSize,sizeof(struct hash));
	// displayHash(hashSize);
	int cumSum[size], sum=0;

	for(int i=0; i<size; i++){
		sum += arr[i];
		cumSum[i] = sum;
	}

	for(int j=0; j<size;j++){
		insertInHash(hashSize,cumSum[j],j);
	}

	// displayHash(hashSize);

	for(int k=0; k<hashSize; k++){
		if(hashTable[k].num > 1){
			printList(arr,k);
		}
	}
}

int main(){
	int arr[] = {11,10,-5,-3,-2,10,5,-1,-6};
	int size = sizeof(arr)/sizeof(arr[0]);
	printSubArrays(arr,size);
	return 0;
}


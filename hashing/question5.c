/*
Given an array and a range, find the elements that are in the range but not in the array

METHOD1:
Naive approach, check for each element in the range whether is present in the array or not
Time complexity: O(mn) //assuming m elements are there in the range
Space complexity: O(1)

METHOD2:
Sort the array. Now from the range use binary search to search the first element from the range 
If first element is not present in the array consider the next one. Now the bigger element from
the array till the end and the range are two sorted lists. We need to compare them to find the
missing numbers from the array that are in the range.

Time complexity: O(nlogn) + O(logn) + O(m+n)
If m is small then O(nlogn) otherwise if m is very big O(m) is answer
Space complexity: O(1)

METHOD3:
Create hash table of size n for the given array. Now search all elements from the range in the hash
If not found, print them.
Time complexity: O(m+n) //which ever is greater will dominate
Space complexity: O(n) //hash table

*/

//METHOD2 TO BE DONE LATER
//=================================================================================================
//METHOD3
#include <stdio.h>
#include <stdlib.h>

void insertInHash(int key, int hashSize, int hashTable[]){
	int temp = key%hashSize;
	int position = temp;
	for(int i=1; i<hashSize;i++){
		if(hashTable[position] != -1){
			position = (position + i)%hashSize;
		}else{
			hashTable[position]= key;
			break;
		}
	}	

}

int searchInHash(int index, int hashTable[], int hashSize){
	int temp = index%hashSize;
	int position = temp;
	for(int count = 1; count != hashSize-1; count++){
		if(hashTable[position] == index){
			return 1;
		}else{
			position = (temp + count)%hashSize;
		}
	}
	return 0;
}

void displayHash(int hashTable[],int hashSize){

	for(int i=0;i<hashSize;i++){
		printf("%d\t", hashTable[i]);
	}
	printf("\n");
}

void findMissingRange(int range[],int arr[], int size, int hashTable[],int hashSize){
	for(int i=0; i<size;i++){
		insertInHash(arr[i], hashSize, hashTable);
	}
	displayHash(hashTable, hashSize);
	for(int index = range[0]; index<=range[1];index++){
		if(!searchInHash(index, hashTable,hashSize)){
			printf("%d \t", index);
		}
	}
}

int main(){
	int arr[] = {2,3,24,11,45,6,9,13,14,18,20};
	int size = sizeof(arr)/sizeof(arr[0]);
	int hashSize = size+1;
	int hashTable[hashSize];
	for(int i=0;i<hashSize;i++){
		hashTable[i] = -1;
	}
	int range[] = {12,20};
	findMissingRange(range,arr,size,hashTable,hashSize);
	return 0;
}
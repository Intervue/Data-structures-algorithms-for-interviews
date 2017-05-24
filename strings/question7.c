/*
Find the first non-repeating character in a given string

METHOD1:
Naive approach, compare each element with the elements on its right.
Time complexity: O(n^2)
Space complexity: O(1)

METHOD2:
Maintain a hashtable to store count corresponding to each letter in the first scan of the array
Now in the second scan see which letter has count 1 at the first time.
Time complexity: O(n)
Space complexity: O(1) //256 is constant and not dependent on input

METHOD3:
Similar to the above method store values in the hash table but along with the value also store the index
at which the value is occuring. Now second time scan the hash table which at max will be 256 iterations
and is independent of N again. We look for value which has not repeated and carries the min index.
Time complexity: O(n)
Space complexity: O(1)
*/
//METHOD1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void findFirstUnique(char *arr, int length){
	int i,j;
	int isEqual = 0;
	for(i=0;i<length-1;i++){
		for(j=i+1;j<length;j++){
			if(arr[i] == arr[j]){
				isEqual = 1;
			}
		}
		if(!isEqual){
			printf("the letter is %c\n", arr[i]);
			break;
		}
		isEqual = 0;
	}
}

int main(){
	char arr[] = "abcabdef";
	int length = strlen(arr);
	findFirstUnique(arr,length);
	return 0;
}
//======================================================
//METHOD2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 256

void findFirstUnique(char *arr, int length){
	int hash[size] = {0};
	int i,j;
	for(i=0;i<length;i++){
		hash[arr[i]]++;
	}
	for(j=0;j<length;j++){
		if(hash[arr[j]] == 1){
			break;
		}
	}
}


int main(){
	char arr[] = "abcabdef";
	int length = strlen(arr);

	findFirstUnique(arr,length);

	return 0;
}
//==============================================================
//METHOD3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 256

struct hash{
	int data;
	int index;
};

void findFirstUnique(char *arr, int length){
	struct hash *hashTable = (struct hash *)calloc(size,sizeof(struct hash));
	int i,j;
	for(i=0;i<length;i++){
		hashTable[arr[i]].data++;
		hashTable[arr[i]].index = i;
	}
	int min = hashTable[arr[0]].index;
	for(j=0;j<size;j++){
		if(hashTable[arr[j]].data == 1 && min > hashTable[arr[j]].index){
			min = hashTable[arr[j]].index;
		}
	}
	printf("the letter is %c\n", arr[min]);
}

int main(){
	char arr[] = "abcabdef";
	int length = strlen(arr);

	findFirstUnique(arr,length);

	return 0;
}

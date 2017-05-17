/*
Find a maximum occuring character in a given string

METHOD1:
Naive apporach, take each character one by one and compare. Maintain max count and character responsible for
count.
Time complexity: O(n^2)
Space complexity: O(1)

METHOD2:
Sort the array and do a linear scan, maintain the max count and character responsible for count until
the char changes. Keep doing till the end.
Time complexity: O(nlogn) + O(n) = O(nlogn) //sort + linear scan
Space complexity: O(1) //assuming that inplace sorting has been done

METHOD3:
One of the main things that we are doing is searching, so we can make a BST out of the given character array.
With the BST we can also maintain the count of the characters and max count and alphabet responsible variable.
Time complexity: O(nlogn) //building BST and searching each element that will take logn time, in case tree is
skewed it will take O(n^2) time.
Space complexity: O(n) //for skewed tree

METHOD4:
We can maintain a hash table for characters. Size of hash table can be taken as 256 because max value of 
ASCII is 255 starting from zero. We can maintain max count in a separate variable and complete this
in a linear scan.
Time complexity: O(n)
Space complexity :O(1) //since size of hash now is not dependent on size of input. Asymptotically it is 1.
//we can further reduce the actual space if in question it is given that all characters are small or capital.
We can only have 26 slots for the hash table then and we can add the base value of ASCII to each when 
computing
*/
//METHOD1
#include <stdio.h>
#include <stdlib.h>

void findMaxValues(char *arr, int size, char *max_char, int *max_count){
	for(int i=0;i<size;i++){
		int key = arr[i];
		int count=1;
		for(int j=i+1;j<size;j++){
			if(key == arr[j]){
				count++;
				if(count > *max_count){
					*max_count = count;
					*max_char = key;
				}
			}
		}
	}
}

int main(){
	char arr[] = "acbccaacc";
	int size = sizeof(arr)/sizeof(arr[0]);
	
	char max_char;
	int max_count = 0;

	findMaxValues(arr,size,&max_char, &max_count);

	printf("max count is %d for %c\n", max_count, max_char);

	return 0;
}
//=================================================
//METHOD2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc(const void *a, const void *b){
	return *(char*)a-*(char*)b;
}

void findMaxValues(char *arr,int size,char *max_char,int *max_count){
	int count = 1;
	for(int i=0; i<size-1; i++){
		if(arr[i] == arr[i+1]){
			count++;
			if(count > *max_count){
				*max_count = count;
				*max_char = arr[i];
			}
		}else{
			count = 1;
		}
	}
}

int main(){
	char arr[] = "acbccaacc";
	int size = sizeof(arr)/sizeof(arr[0]);
	
	qsort(arr,(size_t)strlen(arr),(size_t)sizeof(char), cmpfunc);

	char max_char;
	int max_count = 0;

	findMaxValues(arr,size,&max_char, &max_count);

	printf("max count is %d for %c\n", max_count, max_char);

	return 0;
}
//===============================================================================
//METHOD4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

void findMaxValues(char *hash,char *arr, int size, char *max_char, int *max_count){
	for(int i=0; i<size;i++){
		hash[(int)arr[i]]++;
		if(hash[(int)arr[i]] > *max_count){
			*max_count = hash[(int)arr[i]];
			*max_char = arr[i];
		}
	}
}

void initializeHash(char *hash){
	for(int i=0; i<MAX;i++){
		hash[i] = 0;
	}
}

int main(){
	char hash[256];		
	initializeHash(hash);			
	char arr[] = "acbccaaccaaaaaaa";
	int size = sizeof(arr)/sizeof(arr[0]);
	
	char max_char;
	int max_count = 0;

	findMaxValues(hash,arr,size,&max_char, &max_count);
	printf("max count is %d for %c\n", max_count, max_char);
	return 0;
}
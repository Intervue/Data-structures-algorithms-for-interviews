/*
Remove duplicates from a given string

METHOD1:
Naive approach: Maintain another array, and scan the input one by one and copy to the other array if not
present in it. Similarly keep doing this for every element and check if that is already present in that 
array. Finally print that array.
Time complexity: O(n^2)
Space complexity: O(n) //for the other array

METHOD2:
Use a hash table, and increase count of each element as you insert them. Print the element only if count
if it in the hash table is currently zero.
Time complexity: O(n)
Space complexity: O(1) //since hash table size is not dependent on the input

METHOD3:
Use hash table along with two pointers in a loop. The pointer i can point to the value that has repeated
so that it can be replaced by a unique value and then can be incremented. The unique value so far will
be pointed by another pointer j. Once j reaches end of the array, we stop scanning and increment i and 
replace the element with NULL to mark the end of the string
Time complexity: O(n)
Space complexity: O(1) //hash table is considered as constant as explained earlier
*/
//METHOD2
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define MAX 256

// void removeDuplicates(char *arr,int size){
// 	int hash[MAX] = {0};
// 	for(int i=0; i<size; i++){
// 		hash[arr[i]]++;
// 		if(hash[arr[i]] == 1){
// 			printf("%c\n", arr[i]); //here you can copy to the other array as well and print that array as o/p
// 		}
// 	}
// }

// int main(){
// 	char arr[] = "abcaacdbaaefbfd";
// 	int size = strlen(arr);
	
// 	removeDuplicates(arr,size);
// 	return 0;
// }

//============================================================================================
//METHOD3 - modifying the same input array only rather than printing elements
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

void removeDuplicates(char *arr,int size){
	int hash[MAX] = {0};
	
}

int main(){
	char arr[] = "abcaacdbaaefbfd";
	int size = strlen(arr);
	
	removeDuplicates(arr,size);
	return 0;
}

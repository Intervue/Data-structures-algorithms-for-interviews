/*
Find the smallest window in the string containing all characters of another string

METHOD1:
Naive approach. Find all the substrings of the given string. Then for each substring
check if the string is present in it or not. For that a hash table can be used.

Time complexity: O(n^2) * O(n) = O(n^3) //total n^2 such substrings will be there and for each substring
it can be checked in O(n) time using a hash table.
Space complexity: O(1)

METHOD2:
We insert all the chars in the string to be searched in a hash table. Now, we remove all the
other characters in the main string which are not those characters that we have to search for with spaces.
Now we search for our first window in the main modifiedstring which should contain all the characters 
from the string. As we keep coming across characters we decrement the count of it in hashtable and we scan
the hashtable to see if all the characters have now been included (if the count is 0 or lesser). Note: if
the count is lesser that means a character is repeating more than once in the window. Now we try to shrink
the window from left or right. From left whatever character we have we see its count in the hashtable if 
its less than zero we shrink it to see if we can get a smaller window. Once done we note the shrinked window
size in a variable with start and end index. Now similarly we move ahead to find other windows and apply
shrink on it. This way we can compare each window and see which one is the smallest.
Time complexity: O(n) //since each character in main window in worst case will be visited twice
Space complexity: O(1) //hashtable size is not dependent on input
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkHash(int *arr, int length){
	int i;
	for(i=0; i<length;i++){
		if(arr[i] != 0){
			return 0;
		}
	}
	return 1;
}

void findSmallestSubString(char *arr, char *small){
	int small_length = strlen(small);
	int i,j,k,l;
	int length = strlen(arr);
	int min = length;
	int startIndex, endIndex;
	int hashLength = 256;
	int hash[hashLength];
	for(k=0;k<small_length;k++){
		hash[arr[k]]++;
	}
	for(i=0;i<length;i++){
		for(j=i+1;j<length-i;j++){
			for(l=i;l<j;l++){
				if(hash[arr[l]] > 0){
					hash[arr[l]]--;	
				}
				printf("value of j is %d\n", j);
					printf("value of i is %d\n", i);
					printf("value of min is %d\n",min);
				if(checkHash(hash,hashLength)){
					if(min > j-i){
						min = j-i;
						startIndex = i;
						endIndex = j;
					}
				}
			}
		}
	}
	printf("start index is now %d\n", startIndex);
	printf("end index is now %d\n", endIndex);
	printf("length is %d\n", min);
}

int main(){
	char str[] = "I am a string";
	char small[] = "ami";

	findSmallestSubString(str,small);
	return 0;
}

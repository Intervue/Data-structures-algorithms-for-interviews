/*
Check whether given two strings are anagrams of each other

Two strings are anagrams if they have same no of characters and they are composed of the same letters.
Even if there are repetitions, they are going to be same. 

METHOD1:
sort and scan
Time complexity: O(nlogn)
Space complexity: O(1) //for inplace sorting

METHOD2: 
use hash table and increment count for first string and decrement for second. In the end all count
values should be zero.
Time complexity: O(n)
Space complexity: O(1) //256 not dependent on input
*/
//sorting method not done as it is very basic

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 256

void checkAnagram(char *str1, char *str2, int l1, int l2){
	int hash[size] = {0};
	int i;
	for(i=0;i<l1;i++){
		hash[str1[i]]++;
	}	
	for(i=0;i<l2;i++){
		hash[str2[i]]--;
	}
	for(i=0;i<size;i++){
		if(hash[i] > 0){
			printf("two strings are NOT anagrams\n");
			return;
		}
	}
	printf("two strings are anagrams of each other\n");
}

int main(){
	char str1[] = "heater";
	char str2[] = "reheaa";
	int l1 = strlen(str1);
	int l2 = strlen(str2);
	if(l1 != l2){
		printf("two strings not NOT anagrams\n");
		return 0;
	}
	checkAnagram(str1,str2, l1, l2);
	return 0;
}

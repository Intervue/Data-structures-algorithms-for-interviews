/*
Check whether given string is palindrome or not

METHOD: 
Take two pointers, one at start and one at the end and start comparing the values in it till they meet each 
other, at every point value should be same

Time complexity: O(n)
Space complexity: O(1)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkPalindrome(char *arr,int size){
	int j = size-1;
	int i=0;
	int temp = 1;
	while(i<=j){
		if(arr[i] != arr[j]){
			temp = 0;
			break;
		}
		i++;
		j--;
	}
	return temp;
}

int main(){
	char arr[] = "arora";
	int size = strlen(arr);
	int isPalindrome = checkPalindrome(arr,size);
	if(isPalindrome){
		printf("The given string is a palindrome \n");	
	}else{
		printf("The given string is not a palindrome\n");
	}
	 
	return 0;
	
}
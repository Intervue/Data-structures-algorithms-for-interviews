/*
Reverse a given string

METHOD:
take two pointers, one at start and one at the end and swap the two values, then advance the pointers to the
right and left resp. and swap again. Keep repeating until the whole string is swapped
Time complexity: O(n)
Space complexity: O(1)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *arr,int size){
	int j = size-1;
	int i=0;
	while(i<=j){
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;
		j--;
	}
}

int main(){
	char arr[] = "rahul";
	int size = strlen(arr);
	reverse(arr,size);
	printf("the reverse string is %s\n", arr); 
	return 0;
}
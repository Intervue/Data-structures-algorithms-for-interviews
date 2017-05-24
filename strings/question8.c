/*
Run length encoding

Run length encoding means, traversing through the given character array and displaying which character
is repeating how many times along with the character as output. 
Eg: SSMMMAAARRT => S2M3A3R2T1

Applications: File compression

METHOD:
Just traverse and maintain a counter to solve the algo
Time complexity: O(n)
Space complexity: O(1)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void runLengthEncoding(char *arr, int size){
	int i,j=0;
	// char *finalStr = (char *)malloc(sizeof(char)*(size*2 + 1));
	int counter = 1;
	printf("%s\n", arr);
	for(i=0;i<size;i++){
		// finalStr[j++] = arr[i];
		if(arr[i] == arr[i+1]){
			counter++;
		}else{
			printf("%c%d", arr[i],counter);
			counter=1;
		}
	}
}

int main(){
	char arr[] = "SSMMMAAARRT";
	int length = strlen(arr);

	runLengthEncoding(arr,length);
	return 0;
}
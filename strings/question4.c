/*
Reverse the words in a given sentence

METHOD1:
First reverse the given letters in the sentence fully, then in the output received, reverse only the letters
in each word. A single function can be made to reverse the string which takes the starting and the ending
index. A loop can be used to identify the white spaces in the string and start and end index can be passed
to the function each time
Time complexity:O(n) //for full string of n characters it will take O(n) time and since words are part of
the sentence itself, overall time complexity will stay as O(n)
Space complexity:O(1)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *arr,int start, int end){
	int j=end;
	int i=start;
	while(i <=j){
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;
		j--;
	}
}

void reverseWords(char *arr, int size){
	reverse(arr,0,size-1);
	int start = 0, end;
	for(int i=0; i<size; i++){
		if(arr[i]== ' '){
			end = i-1;
			reverse(arr,start,end);
			start = i+1;
		}
	}
}

int main(){
	char arr[] = "i am rahul";
	int size = strlen(arr);
	reverseWords(arr,size);
	printf("sentence after reversing words %s\n", arr);
	return 0;
}
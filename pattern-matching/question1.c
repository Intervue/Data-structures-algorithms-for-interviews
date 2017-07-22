/*
Given a text and a pattern, find all occurences of a pattern in a given text.

METHOD1:
Naive approach:
Find all substrings of length equal to the other strings that need to be found. See whatever is 
equal to this string.

Time complexity:
length of one substring is it starts from i will be m, so it will end at i+m-1
Since it cannot exceed beyond n-1 (n is the length of the main string)
i+m-1 <= n-1 => i <= n-m
Therefore it can be anywhere from o to n-m, that is n-m+1 values.
Therefore total time complexity will be (n-m+1)*m //substrings*comparsions for each
which is nm.
If length is equal to n/2 or higher
worst case time complexity will be O(n^2)

Space complexity: O(1)


METHOD2:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search(char *text, char *pattern){
	int len1 = strlen(text);
	int len2 = strlen(pattern);

	int i,j;

	for(i=0;i<=len1-len2;i++){
		for(j=0;j<len2;j++){
			if(text[i+j] != pattern[j]){
				break;
			}
		}
		if(j == len2){
			printf("pattern found at %d\n", i);
		}
	}


}

int main(){
	char text[100], pattern[100];
	printf("enter the first string\n");
	gets(text);

	printf("Enter pattern string\n");
	gets(pattern);

	search(text, pattern);

	return 0;
}




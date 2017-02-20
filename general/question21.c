/*
4. Write a C Program to sort five words in "Lexicographical Order" (i.e., dictionary order). Use any sorting
   algorithm of your choice. You should collect the words from the user in a loop, and store it in
   an array of strings, with each row containing exactly one string. You are not allowed to allocate
   any extra memory than required; thus, for each row of the array, you must perform dynamic memory allocation.
   Do not forget to free all dynamically allocated memory after the program finishes. The sorting should
   modify the original array of strings.
       Input: five words from the user 			     
       Output: the sorted array contents, printed in order                                                    [4]
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
     
	char *s[5], *t;
	printf("enter any five strings: \n");
	for(int i=0; i<5;i++){
		int len;
		printf("Enter the number of char's in %dth string\n",i);
		scanf("%d",&len);	
		s[i] = (char *)malloc(len*sizeof(char));
		scanf("%s",s[i]);
	}	

	for(int i=1;i<5;i++){
		for(int j=1;j<5;j++){
			if(strcmp(s[j-1],s[j]) > 0){
				t = (char *)malloc(strlen(s[j-1])*sizeof(char));
				strcpy(t,s[j-1]);
				strcpy(s[j-1],s[j]);
				strcpy(s[j],t);
				free(t);
			}
		}
	}

	printf("Strings in order are : \n");

	for(int i=0;i<5;i++){
		printf("%s\n", s[i]);
	}
	for(int j=0;j<5;j++){
		free(s[j]);
	}
	return 0;

}





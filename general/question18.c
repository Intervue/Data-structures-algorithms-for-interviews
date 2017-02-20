/*
1. Write a C program which will accept two strings and check whether all characters from the first string are present 
   in the second string. Order in which the characters are present is not important. Example run:      
   if String-1 is "abcd" and String-2 is "bcxyzad", the program outputs "Yes", whereas if String-1 is "abcdr",
   the program outputs "No". Assume each string can have maximum 10 characters.
       Input: the two strings from the user
       Output: "Yes" or "No"        
*/

#include <stdio.h>
#include <string.h>

int main(){

	char str1[10], str2[10], counter = 0;

	printf("enter two strings\n");
	scanf("%s %s",str1, str2);

	int a[26]={0};

	int str2_len = strlen(str2);
	int str1_len = strlen(str1);
	for(int i=0;i<str2_len;i++){
		a[str2[i]-'a']=1;
	}
	
	for(int k=0; k<26;k++){
		printf("%d\n", a[k]);
	}

	for(int j=0;j<str1_len;j++){
		if(a[str1[j]-'a'] != 1){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;

}






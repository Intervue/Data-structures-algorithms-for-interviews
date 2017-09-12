/*
Given two strings a and b print whether they contain any common subsequence (non empty) or not.

Hash table and check if any alphabet of other string is already greater than 0;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int hash[26];

int commonSub(char *str1, char *str2){
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int i;
	for(i=0;i<26;i++){
		hash[i] = 0;
	}

	for(i=0;i<len1;i++) {
		hash[str1[i]-'A']++;
	}

	for(i=0;i<len2;i++) {
		if(hash[str2[i]-'A'] > 0){
			return 1;
		}
	}
	return 0;
}


int main() {
	int cases;
	scanf("%d",&cases);
	int i;
	for(i=0;i<cases;i++) {
		char *str1 = (char *)malloc(sizeof(char)*100);
		char *str2 = (char *)malloc(sizeof(char)*100);

		scanf("%s %s",str1, str2);
		printf("%d\n", commonSub(str1, str2));

	}
	return 0;
}
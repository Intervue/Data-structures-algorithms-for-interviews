/*
Generate all permutations of a given string

Backtracking is a concept wherein at each point we backtrack to see what was done and was is left

METHOD:
Idea is to keep swapping at each level to achieve this

*/
// C program to print all permutations with duplicates allowed
#include <stdio.h>
#include <string.h>
#include <string.h>

int hash[256];

void initHash(){
	int i;
	for(i=0;i<256;i++){
		hash[i] = 0;
	}
}

void outputResult(char *result){
	int i, length = strlen(result);

	for(i=0;i<length;i++){
		printf("%c ", result[i]);
	}
	printf("\n");
}


void permute(char *str, int size, char *result, int level){

	if(level == size){
		outputResult(result);
		return;
	}

	int i;
	for(i=0; i<size; i++){
		if(hash[str[i]] == 0){
			continue;
		}
		result[level] = str[i];
		hash[str[i]]--;
		permute(str, size, result, level + 1);
		hash[str[i]]++;
	}
}

int main(){
	char str[] = "ABC";
	int length = strlen(str);

	char result[length];

	int i;

	initHash();
	for(i=0;i<length;i++){
		hash[str[i]]++;
	}

	permute(str,length,result,0);

	return 0;
}
/*
http://practice.geeksforgeeks.org/problems/-regex-matching/0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculatePrefixSuffixArray(int *psa, char *pattern, int size){
	
	int i=1,len=0;
	psa[0] = 0;

	while(i<size){
		if(pattern[i] == pattern[len]){
			len++;
			psa[i] = len;
			i++;
		}else{
			if(len != 0){
				len = psa[len-1];
			}else{
				psa[i] = 0;
				i++;
			}
		}
	}
}

int textExists(char *text, char *pattern){
	int plen = strlen(pattern);
	int tlen = strlen(text);
	int psa[plen];

	calculatePrefixSuffixArray(psa,pattern, plen);
	
	int i=0, j=0;
	
	while(i<tlen){
		if(pattern[j] == text[i]){
			j++;
			i++;
		}

		if(j == plen){
			return 1;
			j = psa[j-1];
		}

		else if(i< tlen && pattern[j] != text[i]){
			if(j != 0){
				j = psa[j-1];
			}else{
				i++;
			}
		}
	}
	return 0;
}


int checkFromStart(char *text, char *pattern){
	// printf("here.........\n");
	int plen = strlen(pattern);
	int tlen = strlen(text);

	// printf("text is %s\n", text);
	// printf("pattern is %s\n", pattern);

	int i=1;
	while(i<plen){
		// printf("comparing %c and %c\n", pattern[i], text[i-1]);
		if(pattern[i] != text[i-1]){
			// printf("they are not equal...\n");
			return 0;
		}
		// printf("they are equal\n");
		i++;
		// printf("-----------------\n");
	}
	return 1;
}

int checkFromEnd(char *text, char *pattern){
	int plen = strlen(pattern);
	int tlen = strlen(text);

	int i = plen-2, j=tlen-1;	
	
	while(i >= 0){
		if(pattern[i] != text[j]){
			return 0;
		}
		j--;
		i--;
	}

	return 1;
}

int main(){
	int cases;
	scanf("%d",&cases);
	int i;
	for(i=0;i<cases;i++){
		char pattern[2000];
		char text[2000];

		scanf("%s",pattern);
		scanf("%s",text);
		int len = strlen(pattern);
		if(pattern[0] == '^'){
			printf("%d\n", checkFromStart(text,pattern));
		}else if(pattern[len-1] == '$'){
			printf("%d\n", checkFromEnd(text,pattern));	
		}else{
			printf("%d\n", textExists(text,pattern));	
		}
	}
	return 0;
}
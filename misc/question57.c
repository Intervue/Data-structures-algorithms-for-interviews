
/*
http://practice.geeksforgeeks.org/problems/search-pattern/0
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void makeRef(int *ref, char *pattern, int length){
	int i=1,len=0;
	ref[0] = 0;

	while(i < length) {
		if(pattern[i] == pattern[len]){
			len++;
			ref[i] = len;
			i++;
		}else{
			if(len == 0){
				i++;
			}else{
				len = ref[len-1];
			}
		}
	}

}

void searchString(char *text, char *pattern){
	int tlen = strlen(text);
	int plen = strlen(pattern);

	int ref[plen];

	int i;
	for(i=0;i<plen;i++){
		ref[i] = 0;
	}

	makeRef(ref,pattern, plen);

	int j=0; i=0;
	int noPattern = 1;
	while(i < tlen) {
		if(text[i] == pattern[j]) {
			i++;
			j++;
		}
		if(j==plen) {
			noPattern = 0;
			printf("%d ", i-j + 1);
			j = ref[j-1];
		}
		else if(i < tlen && text[i] != pattern[j]) {
			if(j!=0) {
				j = ref[j-1];
			}else{
				i++;
			}
		}
	}
	printf("\n");
	if(j < plen && noPattern != 0) {
		printf("%d\n", -1);
	}	

}

int main(){
	int cases;
	scanf("%d",&cases);
	int i;
	for(i=0;i<cases;i++) {
		char text[11000], pattern[11000];

		scanf("%s",text);
		scanf("%s",pattern);

		searchString(text, pattern);

	}
	return 0;
}
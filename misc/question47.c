
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int matchNow(char *pattern, char *text){

	int plen = strlen(pattern);
	int tlen = strlen(text);

	int i=0,j=0;

	while(i<tlen && j<plen){

		if(pattern[j] != '*' && pattern[j] != '?'){
			if(text[i] == pattern[j]){
				i++;
				j++;	
			}else{
				return 0;
			}
		}else if(pattern[j] == '*'){
			
		}

	}

	return 1;
}	

int main(){
	int cases;
	scanf("%d",&cases);
	int i;
	for(i=0;i<cases;i++){
		char pattern[100], text[100];

		scanf("%s", pattern);
		scanf("%s", text);

		printf("%d\n", matchNow(pattern, text));

	}
	return 0;
}
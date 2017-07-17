#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

int hash1[256], hash2[256];


int cal(char *str1, char *str2){

	int j;

	for(j=0;j<256;j++){
		hash1[j] = 0;
		hash2[j] = 0;
	}

	int len1 =strlen(str1);
	int len2 = strlen(str2);

	if(len1 != len2){
		return 0;
	}
	int i;
	for(i=0;i<len1;i++){

		if(hash1[str1[i]] == 0){
			
			hash1[str1[i]] = str2[i];	

		}else{
			if(hash1[str1[i]] != str2[i]){
				
				return 0;
			}

		}
		
		if(hash2[str2[i]] == 0){
			hash2[str2[i]] = str1[i];
		}else{
			if(hash2[str2[i]] != str1[i]){
				return 0;
			}
		}

	}

	return 1;
	
}

int main(){

	int cases;
	scanf("%d",&cases);

	int i;

	char str1[MAX], str2[MAX];

	for(i=0;i<cases;i++){
		scanf("%s",str1);
		scanf("%s",str2);

		int isIsomorphic = cal(str1, str2);

		printf("%d\n",isIsomorphic);

	}

	return 0;
}
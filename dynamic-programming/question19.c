/*
Given a sentence without spaces between words. Break the words in such a 
way that they are meaningful

How to test if words are meaningful or not:
Assume that there is already a hash data structure with all the meaningful words present in it.

NAIVE approach: In worst case if we try to break the word after each character, total characters
being n, n-1 spaces can be inserted. Therefore after each character either a space can be inserted
or either it cannot be inserted.
Hence 2^n-1 ways are there and total n words can be formed and to check each word O(1) time is required.
Total time complexity is exponential

METHOD:
Dynamic programming:

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkPresent(int i, int j, char *given, int n, char dict[n][16]){
	int k;
	char str[j-i+2];
	int m = 0;
	for(k=i;k<=j;k++){
		str[m] = given[k];
		m++; 
	}
	str[m] = 0;
	for(k=0;k<n;k++){
		if(strcmp(str,dict[k]) == 0){
			return 1;
		}
	}
	return 0;
}

int checkSplit(int n, char dict[n][16], char *given){

	int len = strlen(given);
	int dp[len][len];

	int i,j;

	for(i=0;i<len;i++){
		for(j=0;j<len;j++){
			dp[i][j] = -1;
		}
	}

	int k = 0;
	for(i=0;i<len;i++){
		for(j=i+k;j<=i+k;j++){
			if(checkPresent(i,j,given,n,dict)){
				dp[i][j] = 1; 
			}else{
				dp[i][j] = 0;
				int m = i;
				while(m <= j){
					if(dp[i][m] && dp[m+1][j]){
						dp[i][j] = 1;
						break;
					}
					m++;
				}
			}
		}
		j = j-1;
		if(j == len-1){
			k++;
			i = -1;	
		}
		if (k == len){
			break;
		}
	}
	return dp[0][len-1];
}

int main(){
	int cases;
	scanf("%d", &cases);

	int i;
	for(i=0; i<cases;i++){
		int n;
		scanf("%d", &n);
		char dict[n][16];
		int j = 0;
		char str[n*16];
		getchar();
		fgets(str,n*16,stdin);
		char *token = strtok(str, " ");
		while(token != NULL){
			strcpy(dict[j],token);
			token = strtok(NULL, " ");
			j++;
		}
		char given[101];
		scanf("%s",given);
		printf("%d\n", checkSplit(n,dict,given));

	}

	return 0;
}
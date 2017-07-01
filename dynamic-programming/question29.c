/*
Given a string, find out if it becomes a palindrome or not after doing atmost k deletions

Naive approach:
lets say the string is abxca
and value of k=2;
then answer is YES, because we can do a min of 1 deletions and max of 2 deletions

Therefore, number of ways to solve this will be
nc1+ nc2....nck = n^k
which is exponential

METHOD1:
DP Longest common subsequence:
If we reverse the given string and try to find the longest common subsequence of the given string with its
reversal, definately the LCS is going to be palindrome.
If the length of the main string and the LCS is subtracted we will get the min number of deletions
required.
If that min number is less than the max value of k given in the question answer will be YES else NO.

Time complexity: O(n^2) //for LCS
Space complexity: O(n^2) //for LCS

Also, space complexity can be reduced to O(n) time if just one row is maintained at any point of time for LCS
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void revString(char *str, char *reverse, int len){
	int i,j;
	int temp;
	i = len-1;
	j = 0;
	while(i>-0){
		reverse[j] = str[i];
		j++;
		i--;
	}
	printf("inside reverse function\n");
	printf("%s\n", reverse);
}

int max(int a, int b){
	return a>b?a:b;
}

int checkPal(char *str, int k){
	int len = strlen(str);
	char reverse[len];
	revString(str, reverse, len);

	int lcs[len+1][len+1];
	int i,j;
	for(i=0;i<=len;i++){
		lcs[i][0] = 0;
		lcs[0][i] = 0;
	}

	for(i=1;i<=len;i++){
		for(j=1;j<=len;j++){
			if(str[i-1] == reverse[i-1]){
				lcs[i][j] = lcs[i-1][j-1] + 1;	
			}else{
				lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
			}
		}
	}

	if(lcs[len][len] > k){
		return 0;
	}
	return 1;
}

int main(){
	int k;
	printf("enter the value of k\n");
	scanf("%d",&k);
	char str[] = "acbxcda";
	
	int isPalindrome = checkPal(str,k);
	if(isPalindrome){
		printf("YES\n");
	}else{
		printf("NO\n");
	}

	return 0;
}
/*
Given two strings X and Y, find the minimum cost to make two strings equal using only delete operations. 
Cost to delete character in X is S and in Y is P

METHOD1:
DP using LCS
Here we need to minimize the number of delete operations, so that the cost can be minimized.
Hence we need to find as many matching characters in both the strings as possible.
One way is to find the longest common subsequence in both the strings and the remaining characters
apart from those should be deleted.
If the length of one strings is n and other is m

Time complexity: O(mn) //to find LCS
Space complexity: O(mn)

If length of LCS is l
Cost of deletion: (m-l)S + (n-l)P

METHOD2:
Here we use DP:
C(i,j) = {
	
	C(i-1,j-1) if s[i] == s[j],
	min{ C(i-1,j),(j-1,i) } , if not equal
	
	0  ; i =0
	1 ; i = 0 || j = 0

}

Therefore we need to minimize cost. Assume that the length of one string is n and other i m. In worst case
C(i,j) can have m*n unique subproblems. A binary tree can be made to see the repeating sub problems as per the
given recurive equation. Hence using bottom-up dynamic programming algo, we can solve this by making a 2d array
with length 1 greater than the total length of the string.
Here 0,1 means that we are comparing string with no letter with string with 1st letter and trying to find 
the answer (0,2): string with no letter with string with two letters and so on

Time complexity: O(mn)
Space complexity: O(mn)
*/

//METHOD2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findMin(int a,int b){
	return (a<b)?a:b;
}

int findCost(char *str1, char *str2, int cost1, int cost2){
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int sol[len1+1][len2+1];

	int i,j;

	sol[0][0] = 0;
	
	for(i=1;i<len1+1;i++){
		sol[i][0] = cost1*i;
	}

	for(j=1;j<len2+1;j++){
		sol[0][j] = cost2*j;		
	}

	for(i=1;i<len1+1;i++){
		for(j=1;j<len2+1;j++){
			if(str1[i-1] == str2[j-1]){
				sol[i][j] = sol[i-1][j-1];
			}else{
				sol[i][j] = findMin(sol[i-1][j]+1,sol[i][j-1] + 2);
			}
			// printf("adding value for (%d,%d) as %d\n", i,j,sol[i][j]);
		}
	}

	printf("priting the sol array\n");

	for(i=0;i<len1+1;i++){
		for(j=0;j<len2+1;j++){
			printf("%d  ", sol[i][j]);
		}
		printf("\n");
	}

	return sol[len1][len2];
}

int main(){

	char str1[] = "RAVI";
	int cost1 = 1;
	int cost2 = 2;
	char str2[] = "AIBD";

	int cost = findCost(str1,str2, cost1, cost2);

	printf("min cost for making two strings equal is: %d\n", cost);

	return 0;
}



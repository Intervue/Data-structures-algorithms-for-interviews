/*
Compute Longest common subsequence between two strings

METHOD1:
We can find out all subsequences for string1 and then compare it each sub sequence with string two and find
out which ever matched by keeping two pointers one on the subsequence and one on the string and logically
incrementing each as we compare. In this process we can keep a track of LCS.

Time complexity: n*O(2^m); //number of comparisons * number of subsequences. Length of string1 is m and 2 is n.
Space complexity: O(1)

METHOD2: 
In this case we compare the last character of both the strings, if they are same, then we decrement both
the pointers by 1 and compare again, if they are not same then we keep the max value of one of the two cases.
Case 1 involves decrementing first and keep second at the same place and case 2 is other way round.
Max here means max common b/w two strings.

Time complexity: O(mn) //m and n are sizes of two strings
Space complexity: O(mn) //space occupied by the table
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b){
	return (a>b)?a:b;
}

int compareStrings(char *str1, char *str2, int len1, int len2){
	int m[len1 +1][len2+1];
	int i,j;
	for(i=0; i<=len1;i++){
		for(j=0;j<=len2;j++){
			if(i==0 || j==0){
				m[i][j] = 0;
			}else if(str1[i-1] == str2[j-1]){
				m[i][j] = 1 + m[i-1][j-1];
			}else{
				m[i][j] = max(m[i-1][j],m[i][j-1]);
			}
		}
	}
	return m[len1][len2];
}

int main(){
	char str1[] = "AAB";
  	char str2[] = "ACA";

  	int len1 = strlen(str1);
  	int len2 = strlen(str2);

  	int len = compareStrings(str1,str2,len1, len2);

  	printf("length is %d\n", len);
	return 0;
}


//METHOD2 using recursion
#include <stdio.h>
#include <stdlib.h>
#define MAX 200

int table[MAX][MAX];

int max(int a, int b){
	// printf("finding max between %d, %d \n",a,b);
	return a>b?a:b;
}

int lcs(int start1, int start2, char *str1, char *str2, int len1, int len2){
	if(start1 == len1 || start2 == len2){
		return 0;
	}
	if(table[start1][start2] == -1){
		if(str1[start1] == str2[start2]){
			table[start1][start2] =  1 + lcs(start1+1,start2+1,str1, str2, len1, len2);
		}else{
			int a = lcs(start1+1,start2,str1,str2,len1,len2);
			int b = lcs(start1,start2+1,str1,str2,len1,len2);
			table[start1][start2] =  max(a,b);		
		}
	}
	return table[start1][start2];
}

void init(){
	int i,j;
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			table[i][j] = -1;
		}
	}

}

int main(){
	int cases;
	scanf("%d", &cases);
	int i;
	for(i=0;i<cases;i++){
		int len1, len2;
		scanf("%d %d", &len1, &len2);
		char str1[len1+1],str2[len2+1];
		scanf("%s",str1);
		scanf("%s",str2);
		init();
		int me = lcs(0,0,str1,str2, len1, len2);
		printf("%d\n", me);
	}
	return 0;
}
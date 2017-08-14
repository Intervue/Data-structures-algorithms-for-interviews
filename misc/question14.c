/*edit distance*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findMin(int a, int b, int c){
	return (a < b)? ((a<c)?a:c): ((b<c)?b:c);
}

int editDistance(char *str1, char *str2){

	int len1 = strlen(str1);
	int len2 = strlen(str2);
	
	int dp[len1+1][len2+1];

	int i,j;

	dp[0][0] = 0;
	for(i=1;i<=len2;i++){
		dp[0][i] = i;
	}
	for(i=1;i<=len1;i++){
		dp[i][0] = i;
	}

	for(i=1;i<=len1;i++){
		for(j=1;j<=len2;j++){
			if(str1[i-1] == str2[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}else{
				dp[i][j] = 1 + findMin(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	return dp[len1][len2];
}

int main(){
	int cases;
	scanf("%d",&cases);

	int i;

	char str[2];

	for(i=0;i<2;i++){
		scanf("%c",&str[i]);
	}

	for(i=0;i<cases;i++){
		int p,q;
		scanf("%d %d",&p,&q);
		
		char str1[200], str2[200];

		scanf("%s %s",str1,str2);
		
		printf("%d\n", editDistance(str1, str2));
	}

}
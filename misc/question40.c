#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findMax(int a, int b){
	return a>b?a:b;
}

void strrev(char *str){
	int len = strlen(str);

	int i=0,j=len-1;
	while(i<j){
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}

}

int findPal(char *str1, char *str2){
	int len = strlen(str1);
	int i,j;
	int dp[len+1][len+1];

	for(i=0;i<=len;i++){
		dp[0][i] = 0;
		dp[i][0] = 0;
	}

	for(i=1;i<=len;i++){
		for(j=1;j<=len;j++){
			if(str1[i-1] == str2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}else{
				dp[i][j] = findMax(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
		

	return len - dp[len][len];

	

}

int main(){
	int cases;
	int i;
	scanf("%d",&cases);
	for(i=0;i<cases;i++){
		char str[41];
		scanf("%s",str);
		char rev[41];
		strcpy(rev,str);
		strrev(rev);
		printf("%d\n", findPal(rev,str));

	}
	return 0;
}
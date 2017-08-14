#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash[256];

int checkChain(int n, char arr[n][31]){

	int i,j;

	if(n == 1 && strlen(arr[0]) == 1){
		return 1;
	}

	if(n <= 1){
		return 0;
	}

	char str[n*2 + 1];
	int i = 0;
	for(j=0; j<n; j++){
		str[i] = arr[j][0];
		i++;
		str[i] = arr[j][strlen(arr[j])-1];
		i++;
	}	

	for(i=0;i<256;i++){
		hash[i] = 0;
	}

	int count = 0;
	for(i=0;i<strlen(str);i++){
		hash[str[i]]++;
		count++;
	}

	for(i=1; i<strlen(str);i=i+2){
		for(j=0;j<strlen(str);j++){
			if(arr[i] == arr[j] && j%2 != 0 && j-i >= 3){
				
			}
		}
	}
	return 1;
}

int main(){
	int cases;
	scanf("%d", &cases);
	int i;
	for(i=0;i<cases;i++){
		int n;
		scanf("%d", &n);
		
		char arr[n+1][31];		
		
		int j;

		for(j=0; j<n;j++){
			scanf("%s",arr[j]);
		}

		printf("%d\n", checkChain(n,arr));

	}
	return 0;
}
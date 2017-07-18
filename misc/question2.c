#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int hash[256];

int cal(char *str){

	int k;
	for(k=0;k<256;k++){
		hash[k] = 0;
	}

	int length = strlen(str);

	int allEqual = true;

	int mid = length/2;

	int max = 0;

	int i = 0;
	int j = mid;

	int count = 0;

	while(i<mid && j<length){

		if(str[i] == str[j]){
			i++;
			j++;
			count++;
			if(max < count){
				max = count;
			}
		}else{
			if(i == 0){
				j++;
			}
			i = 0;
			count = 0;
			max = 0;
		}
	}

	int z;

	for(z=0;z<length;z++){
		hash[str[z]]++;
	}

	if(hash[str[0]] == length){
		return length-1;
	}

	return max;
}

int main(){
	int cases;
	scanf("%d", &cases);

	int i;

	char str[100000];

	for(i=0;i<cases;i++){
		scanf("%s",str);
		int ans = cal(str);	
		printf("%d\n", ans);
	}

	return 0;
}
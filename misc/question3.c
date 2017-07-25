/*
Additive sequence
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isAdditive(char *str){
	int length = strlen(str);

	int isAdditive = 1;

	int i;



	printf("%d\n", str[length-1]-'0');
	// for(i=2;i<length;i++){
	// 	printf("comparing %d with %d and %d ", str[i]-'0',str[i-1]-'0',str[i-2]-'0');
	// 	if((str[i]-'0') != ((str[i-1]-'0') + (str[i-2] - '0'))){
	// 		return 0;
	// 	}
	// }

	return isAdditive;
}

int main(){

	int cases;
	scanf("%d", &cases);

	char str[200];

	int i;
	for(i=0;i<cases;i++){
		scanf("%s",str);
		if(isAdditive(str)){
			printf("%d\n", 1);
		}else{
			printf("%d\n", 0);
		}
	}

	return 0;
}
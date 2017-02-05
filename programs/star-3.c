/* Program to print star 3 pattern */

//pre-process fetching contents of library stdio.h which contains predefined functions in C
#include <stdio.h>

//default function that is run by C everytime
int main(){
	
	for(int i = 0; i < 5; i++){
		
		for(int j = 5; j >=i; j--){
			printf(" ");
		}

		for(int k = 0; k <= 2*i; k++){ 
			printf("*");
		}	
		
		printf("\n");

	}	
	
	return 0;
}
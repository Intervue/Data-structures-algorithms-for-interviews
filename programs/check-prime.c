/* Program to check if a number if prime or not C */

//pre-process fetching contents of library stdio.h which contains predefined functions in C
#include <stdio.h>

//default function that is run by C everytime
int main(){
	
	int num;

	int isPrime = 0;

	printf("enter a number\n");
	scanf("%d", &num);

	for(int i = 2; i <=num/2; i++){

		if(num%i == 0){
			isPrime = 1;
			break;//breaking out of the loop once out check is satisfied
		}

	}

	if(isPrime == 0){
		printf("number is not prime\n");
	}else{
		printf("number is prime\n");
	}


}
/* Program to find factorial of a number in C */

//pre-process fetching contents of library stdio.h which contains predefined functions in C
#include <stdio.h>

//default function that is run by C everytime
int main(){
		
	int num;

	printf("enter a number\n");
	scanf("%d", &num);

	if(num < 0){
		printf("factorial for negative numbers does not exist\n");
	}

	//since factorial of a number if always positive it is better to use unsigned for a bigger range (0 - range)
	// and not (-range to range)
	unsigned long long fact = 1; //integer having bigger size compared to normal integer

	for(int i = 2; i <= num; i++){

		fact = fact*i;

	}

	printf("factorial is %d = %llu\n", num, fact); //llu is format specifier for long long int

	return 0;

}
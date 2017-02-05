/* Program to print fibonacci series in C */

//pre-process fetching contents of library stdio.h which contains predefined functions in C
#include <stdio.h>

//default function that is run by C everytime
int main(){
	//predefined function from the library which prints the output given to it
	int num, prev, last, sum;

	printf("enter a number\n");
	scanf("%d", &num);

	for(int i=0; i <=num; i++){

		if(i < 2){
			prev = 0;
			last = 1;	
		}
		
		sum = prev + last;

		printf("%d ", sum);

		prev = last;
		last = sum;



	}
	
	return 0;
}
/* Program to check if a given number is a palindrome or not in C */

//pre-process fetching contents of library stdio.h which contains predefined functions in C
#include <stdio.h>

//default function that is run by C everytime
int main(){
	//predefined function from the library which prints the output given to it
	int num, lastdigit, result = 0;
	printf("enter a number: \n");
	scanf("%d", &num);

	int originalnum = num;

	while(originalnum !=0){ //making that number in reverse
		lastdigit = originalnum%10;

		//concatenate
		result = result*10 + lastdigit; //to make that number in reverse

		originalnum /= 10;
	}

	if(num == result){
		printf("number is palindrome\n");
	}else{
		printf("number is not palindrome\n");
	}

}
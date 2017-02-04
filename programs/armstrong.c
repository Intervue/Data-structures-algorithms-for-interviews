/* Program to check if a number is armstrong or not in C */

//pre-process fetching contents of library stdio.h which contains predefined functions in C
#include <stdio.h>
#include <math.h>

//default function that is run by C everytime
int main(){
	
	int num, result=0, originalnumber, n=0, remainder;

	printf("enter a number\n");
	scanf("%d", &num);
	originalnumber = num;

	while(originalnumber != 0){
		originalnumber = originalnumber/10;
		n++;
	}
	originalnumber = num;
	while(originalnumber != 0){
		remainder = originalnumber%10;
		result += pow(remainder, n);
		originalnumber /= 10;
	}

	if(result == num){
		printf("this is armstrong number");
	}else{
		printf("this is not an armstrong number");
	}

}
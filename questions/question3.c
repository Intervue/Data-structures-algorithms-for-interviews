/* 
Program to swap two variables without using any other variable
*/

#include <stdio.h>

int main(){

	int num1,num2;

	printf("enter the two variables needed to be swapped: \n");
	scanf("%d %d", &num1, &num2);

	printf("num1 %d\t num2 %d\n", num1, num2);

	num1 = num1 + num2;

	num2 = num1 - num2;

	num1 = num1 - num2;

	printf("After swapping\n num1 %d\t num2 %d\n", num1, num2);

}
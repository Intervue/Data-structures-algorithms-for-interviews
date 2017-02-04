/* Program to show enumeration datatype */

#include <stdio.h>

int main(){
	
	char operator;
	double a,b;	
	printf("enter an operator (+, -, *, /)\n");
	scanf("%c",&operator);

	printf("enter two operators \n");
	//lf is the format specifier for double
	scanf("%lf %lf",&a, &b);

	switch(operator){
		//representing operators in single quotes will convert them to integers (ascii values)
		case '+': printf("additon of a and b: %lf\n", a+b); break;
		case '-': printf("subtraction of a and b: %lf\n", a-b); break;
		case '/': printf("division of a and b: %lf\n", a/b); break;
		case '*': printf("multiplication of a and b: %lf\n", a*b); break;
		default: printf("please enter a valid operator\n"); break;
	}

	
}
/* 
2. Write a C program to find the sum of digits of a positive integer.
Note that the positive integer can have any value within the allowed range 
of positive integers on your computer.                         
Example- If number is 12345 then sum is 1+2+3+4+5=10 
  
  input: the number
  output: the sum of digits of the number                       [2]

*/
#include <stdio.h>
int main(){

	int num, remainder, sum=0;

	printf("enter a number: \n"); 
	scanf("%d", &num);
	
	while(num > 0){  

		remainder = num%10;
 
		sum += remainder; 

		num /= 10; 

	}

	printf("the sum is %d\n", sum);

}




  
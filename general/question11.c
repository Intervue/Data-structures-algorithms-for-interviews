/*
1. Write a C function to find whether a positive integer is a power of two, using
   a function "void is_power_of_two (int number)".
   Hint: use the shift operator, and iterate over each bit. DO NOT COMPARE WITH SUCCESIVE
   POWERS OF TWO.
   Input: A positive integer.
   Output : "yes" if the number is power of two, else "no".    [2]
*/
#include <stdio.h>

void is_power_of_two (unsigned int x){
 	while (((x & 1) == 0) && x > 1) /* While x is even and > 1 */
   		x >>= 1;
 	if (x == 1){
 		printf("the number is a power of two\n");
 	}else{
 		printf("the number is not a power of two\n");
 	}
}

int main(){
	int num, remainder, binary = 0, i = 1;

	printf("Enter a number\n");
	scanf("%d", &num);

	is_power_of_two(num);
}
 
   
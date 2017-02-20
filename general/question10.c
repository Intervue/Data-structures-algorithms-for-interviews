/* 
 The Fibonacci Sequence is the series of numbers:
   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...n terms
   The next number is found by adding up the two numbers before it. 0 and 1 are the starting numbers.
   Write a C program to print the numbers that do not appear in the Fibonacci series.
   
   input: Number of terms 👎 in Fibonacci sequence to be considered.  
   output: The numbers that are not in Fibonacci sequence. For
   example, if the user enters n=7, the values to be printed are: 4 6 7     [3]
*/
#include <stdio.h>
#include <math.h>

int main(){

	int num, count = 0, prev, current, sum;

	printf("enter the number of terms:\n");
	scanf("%d", &num);

	prev = 0; 
	current = 1;

	while(1){
		
		sum = current + prev;
		prev = current;
		current = sum;

		if(current - prev > 1){

			for(int i= (prev + 1); i < current && i<= num; i++){
				printf("%d\n", i);
			}	

		}

		if(sum > num){
			break;
		}	

	}
}

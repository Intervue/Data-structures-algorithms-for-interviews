/* 
Use ternary condition operator to find min and max among three integers
output: min and max of three
*/

#include <stdio.h>

int main(){

	int a,b,c, max, min;

	printf("enter 3 integers:\n");
	scanf("%d %d %d", &a,&b,&c); 

	max = (a>b)?((a>c)?a:c):((b>c)?b:c); //oneway
	min = (a < b && a < c)? a: (b < c)? b: c; //another way	 	
		
	printf("max number is: %d\n", max);
	printf("min number is: %d\n", min);

}
/*
Count the number of set bits in an integer

If number is given, simply divide it by 2 in a loop and incremenet count if rem is 1
TC: logn
*/


#include <stdio.h>
#include <stdlib.h>

int setBits(int num){
	int rem;
	
	int count = 0;
	while(num){


		rem = num%2;
		if(rem){
			count++;
		}
	
		num = num/2;
		


	}
	
	return count;
}


int main(){

	int n;
	printf("enter the number\n");
	scanf("%d",&n);

	printf("num set bits are: %d\n", setBits(n));

}
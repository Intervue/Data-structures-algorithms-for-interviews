/*
Check whether parenthesis are balanced or not

In this we push each parenthesis on to stack and whenever there is a parenthesis we compare it with the top
of the stack, if it is same, we pop it off. Keep doing that for every parenthesis. 
In the end if stack is empty, then parenthesis is balanced

Time complexity: O(n)
Space complexity: O(n)
*/

#include <stdio.h>
#include <string.h>

int main(){
	char input[100];
	int step;
	while(1){
		printf("1. Enter set of characteristics\n");
		printf("1. Exit\n");
		
		switch(step){
			case 1: gets(input);

				break;
			case 2: exit(1); 
				break;
		}

	}		

	return 0;
}
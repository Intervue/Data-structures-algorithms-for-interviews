/* Program to count the number of characters in a string constant */

#include <stdio.h>

//strlen is the name of the function which is taking character as argument
int strlen(char s[]){
	
	int i = 0;
	//this loop increments i until end of string is reached
	while(s[i] != '\0'){
		i = i + 1;
	}

	return i;

}

//need something to convert string to array in main()
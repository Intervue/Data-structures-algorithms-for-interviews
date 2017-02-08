/* Program to remove char c from the string */

//pre-process fetching contents of library stdio.h which contains predefined functions in C
#include <stdio.h>

void squeeze(char s[], int c){

	int i, j;

	for(i=j=0; s[i] != '\0'; i++){

		if(s[i] != c){ //it will replace that letter with the next letter and the increment j
			s[j++] = s[i];
		}

	}

	s[j] = '\0';

	printf("%s\n", s);
}
//default function that is run by C everytime
int main(){

	char s[] = "rachulc";

	squeeze(s, 'c');
	
}
	
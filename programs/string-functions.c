/* Various string functions in C */

//pre-process fetching contents of library stdio.h which contains predefined functions in C
#include <stdio.h>

//str copy function self made
char *strcpynew(char *d, const char *s)
{
   char *saved = d;
   while (*s)
   {
       *d++ = *s++;
   }
   *d = 0;
   return saved; //returning starting address of s1
}

//default function that is run by C everytime
int main(){
	
	char s1[] = "rahul"; //initializing strings
  char s2[] = "arora"; //initializing strings

	strcpynew(s1, s2);

	printf("%s\n", s1);	//updated string after strcpy
  printf("%s\n", s2); 

}
/* Various string functions in C */

//pre-process fetching contents of library stdio.h which contains predefined functions in C
#include <stdio.h>

//str copy function self made
char *strcpynew(char *d, char *s){
  char *saved = d;
  while ((*d++ = *s++) != '\0');
   
  return saved; //returning starting address of s1
}

char *strcatnew(char *d, char *s){

  char *saved = d;

  while(*d != '\0'){
    *d++; //finding end of d string;
  }

  while((*d++ = *s++) != '\0');
  // *d = 0; 
  return saved;

}

int *strcmpnew(char *d, char *s){

  while((*d == *s)){
    if(*s == '\0'){
      return 0;  
    }
    *d++;
    *s++;
  }

  return *d - *s;

}

//default function that is run by C everytime
int main(){

	// //FOR STRCPY 
	char s1[] = "rahul"; //initializing strings
  char s2[] = "arora"; //initializing strings
	strcpynew(s1, s2);
	printf("strcpy: %s\n", s1);	//updated string after strcpy

  //for STRCAT
  char s3[] = "rahul"; //initializing strings
  char s4[] = "arora"; //initializing strings
  strcatnew(s3, s4);
  printf("strcat: %s\n", s3); //updated string after strcpy

  //for strCMP
  char s5[] = "a"; //initializing strings
  char s6[] = "a"; //initializing strings
  printf("strcmp: %d\n", strcmpnew(s5, s6)); //updated string after strcpy
}
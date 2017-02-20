/*
Write a C function to check whether a positive integer is a palindrome or not,
   using the C function "void is_palindrome (int number)". 
   A "palindromic number" is a number that remains the same when its digits are reversed. Eg: 16461           
   Input: A positive integer.
   Output : "yes" if the number is a palindrome, else "no".       [3
*/
#include <stdio.h>

void is_palindrome(int a){

   int reverse = 0;
   int originalnum = a;

   while(a){
      reverse = reverse*10 + a%10;  
      a /= 10;
   }

   if(originalnum == reverse){
      printf("number is a palindrome\n");
   }else{
      printf("number is not a palindrome\n");
   }

}

int main(){

  int num;
  printf("enter a number\n");
  scanf("%d",&num);
  is_palindrome(num);
	
}






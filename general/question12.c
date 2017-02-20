/*
2. Write a C Program to find the Greatest Common Divisor (GCD) of two positive integers,
   using a function "int GCD (int a, int b)" which returns the GCD of two
   positive integers "a" and "b" passed as arguments. Note that the values of "a" and "b" might be
   arbitrary, and proper arrangements should be made to ensure that the
   function works for both the cases: "a >= b" and "a < b". 
   Input : two positive integers in the "main()" portion of the program.
   Output: the GCD, as returned by the "GCD()" function.    [2]
*/
#include <stdio.h>

int GCD(int a, int b){

   int min, value;
   min = (a < b)?a:b;

   if(a%min == 0 && b%min == 0){
      value = min;
   }else{
      for(int i= (min-1); i>1;i--){
         if(a%i ==0 && b%i ==0){
            value = i;
            break;
         }
      }
   }
   return value;
}

int main(){

   int num1, num2, ans;

   printf("Enter two positive integers:\n");
   scanf("%i %i", &num1, &num2);
   
   ans = GCD(num1, num2);

   printf("GCD for %d and %d is %d\n",num1, num2, ans);
	
}
 
//Alternate way
// #include <stdio.h>
// int main(){
//     int n1, n2;
//     printf("Enter two positive integers: ");
//     scanf("%d %d",&n1,&n2);
//     while(n1!=n2){
//         if(n1 > n2)
//             n1 -= n2;
//         else
//             n2 -= n1;
//     }
//     printf("GCD = %d",n1);
//     return 0;
// } 







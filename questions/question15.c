/*
Given an array of integers, find the maximum and minimum element from this array using a function 
   "void MaxMin (int arr[], int size, int *max_ptr, int *min_ptr)", where "size" denotes the number of  
   elements in the array. Print the maximum and minimum values from the main() function.
   The array might be hard-coded in your "main()" function.
   
   input: none
   output : value of max and min from "main()". 
*/

//@TODO
#include <stdio.h>

void MaxMin(int arr[], int size, int *max_ptr, int*min_ptr){

   printf("working\n");

   int j = 1;;
   max_ptr = arr;
   min_ptr = arr;

   printf("max %d\n", *max_ptr);
   printf("min %d\n", *min_ptr);

   for(int i=1; i<size; i++){
      j = i;
      if(*max_ptr < arr[i]){

         max_ptr = arr+i;

      }

      if(*min_ptr > arr[j]){
         min_ptr = arr+j;
      }

   }

   printf("max number is %d\n", *max_ptr);
   printf("min number is %d\n", *min_ptr);

}

int main(){

   int a[]={1,124,21,4,5,8,3,56,52,0};
   int size=sizeof(a)/sizeof(a[0]);

   MaxMin(a, size, 0, 0);

}






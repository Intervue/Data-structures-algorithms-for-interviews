/*
3. The median of a finite list of numbers can be found by arranging all the numbers from the lowest value to 
   the highest value, and then picking the middle one (e.g., the median of {3, 3, 5, 9, 11} is 5). Your task is to take 
  "N" real values, probably containing repitions, through command-line, and find the median of those numbers.
   Remember that all commnad line arguments are of "char *" type, hence you need to use the "atof()" function.       
   INPUT: Example: ./a.out 2.355 4.5 3.6 2.12 3.6 6.4 2.355
   OUTPUT: 3.6 (median of the given numbers)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSort(int arr[], int n){
   int i, key, j;
   for (i = 1; i < n; i++){
      key = arr[i];
      j = i-1;
      while (j >= 0 && arr[j] > key){
         arr[j+1] = arr[j];
         j = j-1;
      }
      arr[j+1] = key;
   }
}

void print_array(int array[],int n){
   for (int i = 0; i < n; ++i){
      printf("%d\t",array[i] );
   }
   printf("\n");
}

int main(int argc, char const *argv[]){

   int n = argc-1;
   int array[argc];
   for(int i=1;i<argc; i++){
      array[i-1] = atof(argv[i]);
   }

   insertionSort(array, n);
   print_array(array,n);

   if(n%2==0){
      printf("The median of given numbers is:%f\n",(float)(array[n/2]+array[n/2-1])/2);
   }else{
      printf("The median of given numbers is:%f\n",(float)(array[n/2]));
   }

}

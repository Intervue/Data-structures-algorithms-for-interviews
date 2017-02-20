/*
2. Given an array of integers, reverse the original array using a function "void reverse(int arr[])". 
   For swapping two elements use another function "void swap (int *aptr, int *bptr)". Finally, 
   print the reverse of the array from the "main()" function.
   The array might be hard-coded in your "main()" function.
   
   input: none 
   output: the reversed array. 
*/

#include <stdio.h>

void swap(int *aptr, int *bptr){
	
	*aptr = *aptr + *bptr;
	*bptr = *aptr - *bptr;
	*aptr = *aptr - *bptr;

}

void reverse(int arr[], int b){

	int i,j,size = b;
	j = size - 1;
	i = 0;
	while(1){
		
		swap(&arr[i], &arr[j]);
		i++;
		j--;
		if(j==i || j<i){
			break;
		}
	}
}

int main(){

	int a[] = {1,2,3,4,5,6,7,8};
	int size = sizeof(a)/sizeof(a[0]);
	reverse(a, size);
	
	for(int i = 0; i < size; i++){
		printf("%d\n", a[i]);
	}
}






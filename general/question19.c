/*
2. Write a C program to find the average of "n" integers entered by user. 
   To perform this task, allocate memory dynamically, and do not use
   any statically declared large array.			
       Input: value of "n", and the "n" integers
       Output: The average of the "n" integers entered                                                        [2]      
*/

#include <stdio.h>
#include <stdlib.h>


int main(){

	int n; float avg = 0;
	printf("enter value of n\n");
	scanf("%d",&n);

	int *a = (int *)malloc(n*sizeof(int));

	for(int i=0; i<n;i++){
		printf("enter %d value of array\n", i);
		scanf("%d", a+i);
	}

	for(int j=0; j<n;j++){
		avg += a[j];
	}

	avg = avg/n;

	printf("average is %f\n", avg);
	free(a);
	return 0;

}






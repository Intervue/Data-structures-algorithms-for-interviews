/* 
1. Write a C program to print "Pascal's Triangle". 
The numbers in the r-th row of Pascal's triangle represent
the coefficients in the Binomial expansion of (a+b)^{r-1}.
The first four rows of Pascal triangle are shown below :-
       1
      1 1
     1 2 1
    1 3 3 1
  
 

  input: Number of rows of Pascal triangle to print
  output: Resultant Pascal's Triangle                          [3]

*/
#include <stdio.h>
int main(){

	int i,j,k,q,rows;

	printf("enter the number of rows:\n");
	scanf("%d", &rows);

	int prev[rows];

	for(i=0; i< rows; i++){

		int temp[rows];

		temp[0] = 1;

		for(j=rows-i; j > 0; j--){
			printf("%s"," ");
		}

		for(k = 1; k < i+1; k++){

			temp[k] = prev[k] + prev[k-1];

		}

		temp[i] = 1;

		for(q = 0; q< i+1; q++){
			printf("%d %s", temp[q], " ");
			prev[q] = temp[q];
		}

		printf("\n");

	}
	
}




  
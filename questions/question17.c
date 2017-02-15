/*
3. A square N X N matrix "A" is said to be "orthonormal" if A*AT = I where "AT" is the 
transpose of the matrix "A" and "I" is the NXN identity matrix. Implement the following 
functions to check whether the matrix "A" stored in a two dimensional array 
A[N][N] is orthonormal:
(a) "void matTranspose (float A[][N], float AT[][N])" to calculate the 
transpose of "A" and store it in "AT".                                           [3]
(b) "void OrthoNormal(float A[][N], float AT[][N])" - makes use of the function
"matTranspose()" to print whether "A" is orthonormal or not.              [2]

The matrix "A" might be hardcoded in "main()". Write the entire program in a single file.
   
   input: none
   output: whether matrix "A" is orthonormal or not.
*/

#include <stdio.h>

void print_matrix(int n, float A[][n]){
	for(int i =0; i<n; i++){
		for(int j=0; j<n;j++){
			printf("%f\t", A[i][j]);
		}
		printf("\n");
	}
}

int OrthoNormal(int n,float product[][n]){
	int value;
	for(int i=0; i<n;i++){
		for(int j=0;j<n;j++){
			if((i!=j && product[i][j]==0) || (i==j && product[i][j] == 1)){
				value = 1;
			}else{
				value = 0;
			}
		}
	}
	return value;
}

void matTranspose(int n, float A[][n], float AT[n][n]){

	for(int i =0; i<n; i++){
		for(int j=0; j<n;j++){
			AT[i][j] = A[j][i];
		}
	}

}

void product_of(int n,float A[][n], float AT[][n],float product[][n]){
	int sum = 0;
	for(int i =0; i<n; i++){
		for(int j=0; j<n;j++){
			for(int k=0;k<n;k++){
				sum += A[i][k] + AT[k][j];
			}
			product[i][j] = sum;
			sum = 0;
		}
	}
}

int main(){

	int n = 3;

	float A[][3]={
                {1,2,3},
                {3,4,5},
                {5,6,7}
                };
	float AT[n][n], product[n][n];

	printf("Matrix A is:\n");	
	print_matrix(n,A);

	matTranspose(n,A,AT);
	printf("Matrix AT is:\n");	
	print_matrix(n,AT);

	product_of(n,A,AT,product);
	printf("Product of A and AT is:\n");
    print_matrix(n,product);

    if(OrthoNormal(n,product)){
    	printf("matrix is orthonormal\n");
    }else{
    	printf("matrix is not orthonormal\n");
    }


}






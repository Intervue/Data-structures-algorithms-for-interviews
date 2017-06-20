/*
Find the number of n-bit integers which do not have any two consequent zeroes

Here it means that if there a number n which is represented by bits
10101.. it should not contain any two consecutive zeroes.

Since a number is represented as 0 or 1, there are in total 2^n ways to rearrange them for n bit 
integer. To validate if any 0s are occuring together will take another O(n) time.
Therefore time complexity in this case is exponential.

METHOD:
DP:
Here if we have an n bit integer, it can either start from 1 or 0,
it it starts from 1 next number can be 1 also and 0 also, hence problem is broken into n-1
parts
but if it starts from 0 the next number has to be 1, it cannot be zero. Hence here problem
now is n-2 size.
Therefore
f(n) = f(n-1) + f(n-2)

This is nothing but the program to fibonacci series where memoization can be used

Time complexity: O(n)
Space complexity: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

int fib(int n){
	int f[n+1];
	int i;
	f[0] = 0;
	f[1] = 1;
	for(i=2;i<=n;i++){
		f[i] = f[i-1] + f[i-2];
	}
	return f[n];
}

int main(){
	int n = 9;
	printf("total here is: %d\n", fib(n));
	return 0;
}


//RECURSIVE
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int f[MAX];

int fibRecursive(int n){
	if(f[n] == -1){ //if does not exist then only compute
		if(n < 2){
			f[n] = n;
		}
		else{
			f[n] = fibRecursive(n-1) + fibRecursive(n-2);
		}
	}
	return f[n];
}

void initialize(int n){
	int i;
	for(i=0; i<=n;i++){
		f[i] = -1;
	}
}

int main(){
	int n = 9;
	initialize(n);
	printf("total here is: %d\n", fibRecursive(n));
	return 0;
}
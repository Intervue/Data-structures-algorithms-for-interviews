/*
Given n-stairs, how many number of ways a person can climb to top 
from bottom using 1 step or 2 steps

Naive approach:
Lets say the stairs are given as 1 2 3 4 5 6... n
Generate all the sub sequences of the numbers from 1 to n. Now examine if each subsequence is posible
or not.
Eg: 1 4 5 is not possible as user can only take a max of 2 steps.
but 1 2 3 4 5 is valid.
Therefore it will take another O(n) time to examine such subsequences

Time complexity: O(2^n)n //which is exponential

METHOD:
DP:
Here if we start from number of ways it will take to reach nth step, it will be equal to number of ways to reach
n-1 + number of way to reach n-2.
which is f(n)=f(n-1) + f(n-2)
Therefore is is nothing but fibonacci series

Time complexity: O(n)
Space complexity: O(n)

*/ 

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int f[MAX];

int fib(int n){
	if(f[n] == -1){
		if(n < 2){
			f[n] = 1;
		}else{
			f[n] = fib(n-1) + fib(n-2);	
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
	//lets say value of n is 20
	int n = 9;
	initialize(n);
	printf("number of ways to reach the %dth step is %d\n", n,fib(n));
	
	return 0;
}


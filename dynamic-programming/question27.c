/*
Given a 2xn board and tiles of size 2x1, count the number of ways to fill the board using 2x1 tiles

Therefore the tile is the size of two squares, and it can either be placed horizontally or vertically.

Solution:
It placed vertically the size of the remaining problem will be n-1
It horizontally, then you cannot place another till vertically till 2 columsn, therefore size of
the problem now is n-2

f(n) = f(n-1) + f(n-2)

Hence this is nothing but fibnacci series

Time complexity: O(n^2)
Space complexity: O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int f[MAX];

int fib(int n){
	if(f[n] == -1){
		if(n<2){
			f[n]=n;
		}else{
			f[n] = fib(n-1) + fib(n-2);	
		}
	}
	return f[n];
}

void initialize(int *arr, int n){
	int i;
	for(i=0;i<=n;i++){
		f[i] = -1;
	}
}

int main(){
	int n;
	printf("enter the value of n\n");
	scanf("%d",&n);

	initialize(f,n);

	int ans = fib(n);
	printf("%dth fibonacci number is or number of ways to fill the tile is %d\n", n,ans);
}
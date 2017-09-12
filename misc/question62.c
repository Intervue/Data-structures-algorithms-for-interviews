/*
http://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair/0
*/
#include <stdio.h>
#include <stdlib.h>

unsigned long long int f[101];

void calFib(int n) {
	unsigned long long int a = 1;
	unsigned long long int b = 1;
	f[0] = a;
	f[1] = b;
	int i;
	for(i=2;i<=n;i++){
		unsigned long long int d = a + b;
		f[i] = d;
		a = b%1000000007;
		b = d%1000000007;
	}
}

unsigned long long int fib(int n) {
	if(f[n] == -1) {
		if(n < 2) {
			f[n] = 1;
		}else{
			f[n] = fib(n-1) + fib(n-2);
		}
	}
	return f[n]%1000000007;
}

int main() {
	calFib(100);
	int cases;
	int i;
	// for(i=0;i<1000;i++){
		// printf("%llu\n", f[i]);
	// }
	scanf("%d",&cases);
	for(i=0;i<cases;i++){
		int n;
		scanf("%d",&n);
		printf("%llu\n",fib(n));
	}
	return 0;
}
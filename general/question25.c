/*
GCD and LCM of two numbers.

The logic is that GCD of two numbers does not change even if smaller number is subtracter from
larger, so we can keep doing it until one of them reaches 0 or becomes equal to the other.

LCM can be found out by multiplying two numbers and dividing by HCF.

*/

#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b){
	if(a == 0 || b== 0){
		return 0;
	}
	if(a == b){
		return a;
	}
	if(a > b){
		return gcd(a-b,b);
	}
	return gcd(a,b-a);
}

int findlcm(int hcf, int a, int b){
	return (a*b)/hcf;
}

int main(){
	int a = 20;
	int b = 10;

	int hcf = gcd(a,b);
	int lcm = findlcm(hcf,a,b);

	printf("lcm is: %d hcf is: %d\n",lcm, hcf);
	
	return 0;
}
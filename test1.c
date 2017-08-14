#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int ipow(int base, int exp){

	if(!exp){
		return 1;
	}
	int result = 1;
	if(exp & 1){
		result *= base;
	}
	exp >>= 1;
	base *= base;
	result *= pow(base, exp);

	return result;

}



int main(){

	int n;
	scanf("%d", &n);

	

	printf("power is %d\n", ipow(2,n));
	
	return 0;
}
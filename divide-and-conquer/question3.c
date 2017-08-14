/*
Custom C function to implement a pow function
*/

/*
The function is buggy because it can overflow, cannot work for negative value of power. Also it cannot work
for decimals. It is also slow because it is doing a particular multiplications so many times.
It also does not handle fractional power
*/

// #include <stdio.h>
// #include <stdlib.h>

// int customPow(int base, int power){
// 	int i;
// 	int temp = 1;
// 	for(i=0;i<power;i++){
// 		temp *= base;
// 	}
// 	return temp;
// }	

// int main(){
// 	printf("value is %d\n", customPow(10,4));
// 	return 0;
// }

/*
Here is a better function that runs faster and handle all the cases
In this case each time exp value is converted to half and base value is squared
*/
#include <stdio.h>
#include <stdlib.h>

//iterative
int ipow(int base, int exp){
	int result = 1;
	while(exp){
		if(exp & 1){ //will return 0 if number is even and will return 1 if number if odd
			//therefore odd value is taken out of the bracket and remaning operations are done on
			//even value
			result *= base;
		}
		exp >>= 1; //used to convert exp value to half
		base *= base;
	}
	return result;
}

//recursive
int ipowRecursive(int base, int exp){
	if(exp == 0){
		return 1;
	}
	int result = ipowRecursive(base,exp/2);
	if(exp & 1){
		return result*result*base;
	}
	return result*result;
}

int main(){
	// int a = 50;
	printf("value is %d\n", ipowRecursive(10,4));
	return 0;
}
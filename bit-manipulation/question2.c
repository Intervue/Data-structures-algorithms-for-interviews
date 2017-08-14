/*
find if a number if power of 2

If we subtract a power of 2 numbers by 1 then all unset bits after the only set bit become set; 
and the set bit become unset.

So, if a number n is a power of 2 then bitwise & of n and n-1 will be zero. 
We can say n is a power of 2 or not based on value of n&(n-1). 
The expression n&(n-1) will not work when n is 0. 
To handle this case also, our expression will become n && (!n&(n-1))
*/

#include <stdio.h>
#include <stdlib.h>

int isPowerOfTwo(int n){
	return n && !(n & (n-1));
}

int main(){
	int n;
	printf("enter the number\n");
	scanf("%d",&n);

	if(isPowerOfTwo(n)){
		printf("number is pwr\n");
	}else{
		printf("no.\n");
	}
	return 0;
}


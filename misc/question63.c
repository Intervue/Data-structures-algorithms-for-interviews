/*

*/

#include <stdio.h>
#include <stdlib.h>

int dig[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};

int lastNon0Digit(int n) {
	if(n < 10) {
		return dig[n];
	}else{
		int a = 6;
		int b = 4;
		if (((n/10)%10)%2 == 0)
	        return (6*lastNon0Digit(n/5)*dig[n%10]) % 10;
	    else
	        return (4*lastNon0Digit(n/5)*dig[n%10]) % 10;
		}
}

int main() {

	int cases;
	scanf("%d",&cases);
	int i;
	for(i=0;i<cases;i++) {
		int n;
		scanf("%d",&n);
		printf("%d\n", lastNon0Digit(n));
	}
}
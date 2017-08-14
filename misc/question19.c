/*
http://practice.geeksforgeeks.org/problems/count-possible-ways-to-construct-buildings/0

Construct buildings

*/
/*
http://practice.geeksforgeeks.org/problems/count-possible-ways-to-construct-buildings/0

Construct buildings

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned long long int f[100001];

void findAns(int plots){

	unsigned long long int a = 2;
	unsigned long long int b = 3;
	unsigned long long int d;

	f[1] = 2;
	f[2] = 3;

	int i;
	for(i=3; i<=100001 ;i++){
		d = a + b;
		f[i] = d;
		a = b%1000000007;
		b = d%1000000007;
	}
}

int main(){
	int cases;
	scanf("%d", &cases);
	int i;

	findAns(10001);

	for(i=0;i<cases;i++){
		int plots;
		scanf("%d", &plots);
		
		int d  = ((f[plots]%1000000007)*(f[plots]%1000000007))%1000000007;
		printf("%d\n", d);
		
	}
	return 0;
}	
#include <stdio.h>
#include <stdlib.h>

void display(int f[2][2]){
	int i,j;
	printf("-------------------\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%d ", f[i][j]);
		}
		printf("\n");
	}
	printf("----------------\n");
}

void mul(int a[2][2], int b[2][2]){
	int p = a[0][0]*b[0][0] + a[0][1]*b[1][0];
	int q = a[0][0]*b[0][1] + a[0][1]*b[1][1];
	int r = a[1][0]*b[0][0] + a[1][1]*b[1][0];
	int s = a[1][0]*b[0][1] + a[1][1]*b[1][1];

	a[0][0] = p;
	a[0][1] = q;
	a[1][0] = r;
	a[1][1] = s;
}


void ipow(int f[2][2], int power){
	
	if(power <= 1){
		return;
	}

	int base[2][2] = {
		{1,1},
		{1,0}
	};

	mul(f,f);

	ipow(f,power/2);			

	if(power%2 != 0){
		mul(f,base);
	}

}

void ipowIterative(int f[2][2],int power){

	int base[2][2] = {
		{1,1},
		{1,0}
	};
	
	while(power > 1){
		mul(f,f);
		if(power%2 !=0){
			mul(f,base);
		}
		power = power/2;
	}
	
}

int fib(int n){
	int f[2][2] = {
		{1,1},
		{1,0}
	};
	printf("calling pow with power %d\n", n-1);
	ipowIterative(f,n-1);

	return f[0][0];
}

int main(){

	int n = 11;

	printf("answer is %d\n", fib(n));

	return 0;
}



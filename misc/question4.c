/**/
#include <stdio.h>
#include <stdlib.h>

int findMin(int a, int b, int c){
	return (a < b)? ((a < c)?a:c): ((b < c)?b:c);
}

int calculate(int start,int target, int a, int b){
	if(start >= target){
		return 0;
	}
	int x,y,z;
	if(start == 0){
		x = b;
	}else{
		x = b + calculate(2*start, target, a, b);
		y = a + calculate(start + 1, target, a, b);
		z = a + calculate(start -1 ,target, a, b);
	}
	return findMin(x,y,z);	
}
	
int main(){
	int cases;
	scanf("%d",&cases);
	int i;
	int a,b,n;
	for(i=0;i<cases;i++){
		scanf("%d %d %d",&n,&a,&b);
		printf("calculate for dest %d and a and b are %d and %d\n", n, a, b);
		printf("%d",calculate(0,n,a,b));
	}
	
	return 0;
}

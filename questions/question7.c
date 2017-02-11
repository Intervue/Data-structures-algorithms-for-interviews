/* 
Generate random numbers b/w 5 and 10, using probability of 
a = 2/10
b = 3/10
c = 3/10
d = 2/10
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 11

int main(){
	int a;
	
	srand(time(NULL));
	
	a = 1+rand()%size;

	if(a < 3){
		printf("%s\n", "a");	
	}else if(a < 6){
		printf("%s\n", "b");
	}else if(a > 9){
		printf("%s\n", "c");
	}else{
		printf("%s\n", "d");
	}
	
}



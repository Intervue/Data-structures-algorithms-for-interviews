/* 
Program to check if a circle can be drawn through three points in a catesian plane
output: yes or no
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

	int x1,y1,x2,y2,x3,y3, slope1, slope2, slope3;

	printf("enter values of x and y for 3 points in a cartesian plane:\n");

	scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

	if(abs(y2-y1) == 0){
		slope1 = 0;
	}else{
		slope1 = abs(x2-x1)/abs(y2-y1);	
	}
	
	if(abs(y3-y1) == 0){
		slope2 = 0;
	}else{
		slope2 = abs(x3-x1)/abs(y3-y1);	
	}

	if(abs(y2-y3) == 0){
		slope3 = 0;
	}else{
		slope3 = abs(x2-x3)/abs(y2-y3);
	}
	
	if(slope1 == slope2 && slope1==slope3){

		printf("%s\n", "no, cirlce cannot be drawn");
	}else{
		printf("%s\n", "yes, circle can be drawn");
	}
	
}
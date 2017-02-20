/* 
Coordinates of 3 vertices of an equilateral triangle are given on a cartesian plane.
Calculate the coordinates of the center and the area of the circle inscribed in the triangle.
input: coordinates of vertices of triangle.
output: coordinates of incenter
area of incirlce
*/

#include <stdio.h>

int main(){

	int t1[2], t2[2], t3[2], i, t1_length, t2_length, t3_length;	

	for(i = 0; i < 3; i++){

		printf("enter the x and y coordinates for triangle %d\n", i+1);
		if(i==0){
			scanf("%d %d", &t1[0], &t1[1]);	
		}
		if(i==1){
			scanf("%d %d", &t2[0], &t2[1]);	
		}
		if(i==2){
			scanf("%d %d", &t3[0], &t3[1]);	
		}		
		

	}

	//@TODO
	

	

}
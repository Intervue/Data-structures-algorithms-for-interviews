/* 
Question description:
A square is made by bending a single piece of wire. If we make a circle of this wire, 
what will be the radius and area of the circle?
input = lenght of side of square
*/

#include <stdio.h>

int main(){

	int length_side_square;
	double radius, area;

	printf("enter the length of side of the square: \n");
	scanf("%d", &length_side_square);

	radius = (4*length_side_square)/(2*3.14); //now total length will be the circumference

	area = 3.14*radius*radius;

	printf("radius of the square is %f\n", radius);
	printf("area of the square is %f\n", area);

}
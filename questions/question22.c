/*
1. Suppose, you have been given "N" rectangular wooden blocks, where "N" is a user-defined integer. 
   Collect the dimensions of each box from a file (format described below), and then store the numbers 
   in an array of structure, where each entry of the array is a structure called "box" containing 
   three floats, containing the three dimensions of the boxes. Note that since "N" is not initially
   known, the array must be allocated space dynamically. 
   Then, call a function "float find_maximum_height (box *box_array, int num_boxes)" to 
   calculate and return the maximum height that can be obtained by arranging these cube one above another. 
   Note that a box can be placed on any of its six faces. While accessing each element from the "box_array" array,
   do not directly use the individual elements of the array but, use pointer to a structure.
   e.g. to access the "i"-th element of the array, declare and use a structure pointer as follows:
   box *box_ptr;
   ...........
   box_ptr = box_array + i; // note the use of pointer arithmetic   

   INPUT: Input will be given in a file "dimensions.txt", which you should create yourself. The first line
   of the file contains the numerical value "N", and each of the next "N" lines contains 3 floating point 
   values separated by spaces. You can consider using the "fgets()" function to read the lines 
   from the file, and "sscanf()" or "strtok()" to collect the individual numbers from a line.
   Example "dimension.txt":
   4
   1.2 2.5 3.1
   2.7 4.0 2.4
   5.3 6.4 2.2
   3.0 4.1 6.8

   OUTPUT: the maximum height of the arrangement
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
		
	

}





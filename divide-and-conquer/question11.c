/*
Search an element in row wise and column wise sorted 2d array

METHOD1:
Naive approach, searching for an element using for loops
Time complexity: O(n^2)
Space complexity: O(1)

METHOD2:
In this case it can be done in linear time. Since arrays is in sorted order top to bottom and left
to right. We can start from top right. We can maintain two variable. i will traverse rows and j will
traverse columns. Initial value of i will be zero and j will be n-1. Now if value to be found is
lesser than top right decrease j to move towards lesser elements. If its greater increase i.
Follow this and it will end up at the element required.
Time complexity: O(m+n) or O(2n) if both n and m are equal
Space complexity: O(1)

METHOD3:
Binary search. Now since array is sorted row and column wise, we find the middle of the whole
2d array. If the element to be found is less than this middle element then it is definately not
present in the fourth quadrant (if the 2d array is divided into 4 parts).
If element to be found is greater than x, then it definately cannot be a part of first quadrant.
Therefore we can narrow our search down to only 3 quadrants each time
Time complexity: T(k) = 3T(k/4) + O(1) //we search thirce in 3 quadrants. each quadrant has 1/4 
elements of total elements k. O(1) is the comparison which is done with the middle element.
By masters theorem and substituting k as n^2 we get n^1.5 as time complexity
Space complexity: O(1) //iterative
*/ 
//METHOD2
#include <stdio.h>
#include <stdlib.h>

int main(){
	int arr[4][4] = {
		{0,1,2,3},
		{4,5,6,7},
		{8,9,10,11},
		{12,13,14,15}
	};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	return 0;
}
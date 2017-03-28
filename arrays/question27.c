/*
Given an unsorted array of +ve integers, 
find the number of triangles that can be formed with three different elements as three sides of the triangle

A triangle can only be formed with the sum of any two sides is greater than the third side.

METHOD1: Brute force
Pick all combinations from the given number and check the condition specified
Picking combinations can be done in nc3.
Time Complexity: O(n^3)
Space Complexity: O(1)

METHOD2: 
Sort the array
Take three points i, j and k
i will be first, j will be second and k will b i+2 to start with. j will go till n-2 always
k will go until sum of i and j is less than k.
The numbers between j and k will be the total triangles for that combination.
Repeat for all i and js
Time complexity: O(n^2)
Space complexity: O(1)
*/


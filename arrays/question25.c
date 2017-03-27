/*
Rotate an array of n elements by d elements

METHOD1:
make a new array of d elements, store the first d elements in that
The shift the remaining elements 
Now add the d elements in the end
Time complexity: O(n)
Space complexity: O(d)

METHOD2:
take a variable and keep inserting elements to be moved to the right one by one and keep shifting elements
to the left one by one.
Here the space complexity will be comparatively less.
Time complexity: O(d X n) because we will have to shift n elements d times
Space complexity: O(1) //as we are only using 1 variable

METHOD3:
Take the GCD of size of array and number of elements to be rotated. Assume it comes out to be 2.
Now make groups of 2. Take an external variable. Put the first element into that variable. now shift
first element of each group to the new first element of the group towards its left. Eg. Grp 2 first 
element now becomes grp1 first element and so on.
There will be a place in the end that will be emptied. (last grp first element). Insert this variable
to that place.
Similarly do it for the 2nd element as well.
Time complexity: O(n) //number of movements were less
Space complexity: O(1)

*/
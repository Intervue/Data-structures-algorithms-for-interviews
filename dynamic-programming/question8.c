/*
Find the maximum sum sub array

METHOD1:
We can simply find all the sub arrays. Since they are contiguous there will be O(n^2) such sub arrays.
Now, for all sub arrays we can maintain a variable and find max sum possible. Time complexity to find
max sum can be reduced by finding cumulative sum array for the main array and then just
by computing that in constant time sum can be found

Time complexity: O(n^2)
Space complexity: O(n) //in case cumulative array is used

METHOD2:

*/

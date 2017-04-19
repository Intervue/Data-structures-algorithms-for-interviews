/*
Consider a set of intervals, merge all overlapping intervals

Eg: (6,8)(2,5)(1,3)(13,20)(9,14)(100,120)

METHOD1: 
naive approach
For each set compare it with other sets and if there is an overlap  merge them. Once merged compare the
merged set with remaining and merge if possible.
Time complexity: O(n^2)
Space complexity: O(1)

METHOD2:
Sort the sets given on the basis of the starting element of each set. Once they are sorted, in a single
iteration compare each element with its consequent element. If there is overlapping, merge them else move
to the next one.
Time complexity: O(n)
Space complexity: O(1)
*/


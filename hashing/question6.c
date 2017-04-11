/*
Given an array, print all subarrays in the array which has sum 0

METHOD1:
Find all the sub arrays of the array. For each element there are n subarrays. Total elements are n.
Total subarrays = n*n = n^2. For all these subarrays find sum which will take O(n) time in worst case.
Time complexity: O(n^3)
Space complexity: O(1)

METHOD2:
Find the array containing cumulative sum for all the values.
Now find all the sub arrays and find the value for the sum of each sub array from cumulative sum array in constant
time.
Time complexity: O(n^2)
Space complexity: O(n)

METHOD3:
Store the cumulative sum array in a hashtable. Eg. if the sum is 11 is should be stored at 11th index of hashTable
with count 1. If 11 repeats again increment count to two.
Now scan the hashtable and see all values having count greater than 1. That will be the total number of sub arrays.
Time complexity: O(n)
Space complexity: O(n)
*/
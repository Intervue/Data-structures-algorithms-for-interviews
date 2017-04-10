/*
Given an array and a range, find the elements that are in the range but not in the array

METHOD1:
Naive approach, check for each element in the range whether is present in the array or not
Time complexity: O(mn) //assuming m elements are there in the range
Space complexity: O(1)

METHOD2:
Sort the array. Now from the range use binary search to search the first element from the range 
If first element is not present in the array consider the next one. Now the bigger element from
the array till the end and the range are two sorted lists. We need to compare them to find the
missing numbers from the array that are in the range.

Time complexity: O(nlogn) + O(logn) + O(m+n)
If m is small then O(nlogn) otherwise if m is very big O(m) is answer
Space complexity: O(1)

METHOD3:
Create hash table of size n for the given array. Now search all elements from the range in the hash
If not found, print them.
Time complexity: O(m+n) //which ever is greater will dominate
Space complexity: O(n) //hash table

*/
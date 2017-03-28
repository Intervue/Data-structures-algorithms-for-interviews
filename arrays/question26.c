/*
Given n non negative integers representing an elevation map where width of each bar is 1. 
Find the amt. of water that is trapped in between these bars after raining

METHOD1:
Find the highest bar to the left and right of each bar including that bar.
Then take the minimum of those two and subtract it from the height of the bar. That is the amount
of water it will store for itself. Repeat for each bar.
Time Complexity: O(n^2)
Space Complexity: O(1)

METHOD2:
Find the highest bar to the left of each bar including that bar and store it in an array (left).
Repeat the above exercise for right and store in array right.
Now water it can hold will be min(left[i],right[i])-height of ith index. Find the sum of all.
Time complexity: O(n)
Space complexity: O(n)
*/
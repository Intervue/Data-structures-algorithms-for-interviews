/*
Find a subset in an array whose sum is w

METHOD:
Since number of subsets possible are 2^n, by brute force we can solve it

Better method:
we cannot use greedy here, as it will always pick the smallest or largest number which wont give the
right answer always, hence we use DP. 
DP in this case is similar to 0/1 knapsack problem. Therefore we need a sum of S and at any point if
we include the ith element, it will be
S(i,n) = s(i,n-ai) || s(i-1,n) ;n>ai //by taking first i elements is the sum of n possible
//either include it || dont include it
= s(i-1,n) ; n<ai
it will give false if i is 0 (no elements are left) //base condition
it will always give true if sum is zero //base condition

Here also time complexity will be O(nw)
Algo will be same as that of prev.
*/


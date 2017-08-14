=========================== Dynamic Programming ============================

Questions involving finding subsequences have same kind of variations like (print all, print some satisfying a particular criteria, count etc.)

/*
Should know how to print the solutions by backtracking as well. @@@@@@@@
*/

1) skipped (matrix chain multiplication) @@@@@@@@@

2) Longest common subsequence: O(nm) 

   L(i,j) = { //where L is the length

   		1 + L(i-1, j-1) ; if str1[i] == str2[j]
   		
   		MAX(L(i-1,j), L(i,j-1)); if not equal

   		0 ;				if i = 0 or j = 0

   }


3) skipped (multi-stage graph) @@@@@@@@

4) 0/1 Knapsack: O(nw)

	P(i,w) = { //where P is the profit (w will be taken as j obviously)

		MAX(Profit(i) + P(i, w - arr[i]), P(i-1,w)) ; if weight(i) < w

		P(i-1, w) ; if weight(i) > w

		0; i = 0 OR w = 0

	}


5 ***) Subset sum problem. O(ns) (lot of variations: find all subsets, count of number of subsets, print the subset, print subset with given sum, print subset with max length and given sum, min length and given sum)

	Whether a subset exists or not

	DP(i, j) = { //where j is the sum

		DP(i-1, j - arr[i]) || DP(i-1,j) ; if arr[i] is less than j

		DP(i-1,j) ;if arr[i] is greater than j

		0; if i = 0 (no array to be considered)
		1; if j = 0 (sum to be considered is 0)

	} 

	//In case where count is to be found just replace || with +

6) skipped (travelling salesman problem): 2^n with DP, naive: n! @@@@@@@@

7) skipped (All pair shortest path algorithm - Floyd warshall) @@@@@@@@

8) Max sum subarray - Kadane algorithm :O(n)

	Here we keep a current variable and keep adding the array values to it. Whenever current becomes -ve
	make it zero and continue. Max variable is kept which is always updated. At every point when its
	updated track of index is kept.
	Also if you want to solve it for -ve sum, then make curr = 0 after assigning max variable the -ve
	value of curr.
	When max is found, start from index backwards and stop where sum == max. That will be the subarray

9 ***) Longest Increasing Subsequence (variations can be print LIS, print max sum with LIS, print max sum with LIS and length k)	O(n^2) @@@@@@@@

	METHOD1:
	
	Here we initialize an array with equal size with all 1s.

	Then we start from i=1,and compare it with all the previous elements and check if prev elements,
	corresponding value in this array if added to the current value at position i can make it bigger.
	If yes, we do it. In this process we keep a track of max

	Recursive equation:

	LIS(i) = { //longest increasing subsequence
		1 + max(all 0 to i-1 values) ; if value is less than i

		1 ; if value (0 to i-1) is greater than i
	}

	METHOD2: Sort and find LCS

10) max sum increasing subsequence: O(n^2) @@@@@@@@ 

	Here we consider the max sum instead of considering the max length each time we compare

	MSIS(i) = {

		max(MSIS[j] + arr[i]); if(arr[j] < arr[i])	
		j=0 to i-1

		arr[i]; if arr[j] for all J > arr[i]
	}	


11) longest subsequence in an array which has consecutive elements

	Sort and find longest sequence of consecutive elements (nlogn)

	Store all values in hash table, then traverse the main array again, for each value
	check prev least and next largest number consecutively in hash table. If it exists
	mark it using a flag. Keep the check of the count. Repeat process for all elements.
	O(n) as hash table wont be traversed for all elements as we use a flag. Also if 
	subsequence is a part of one number, and if it is a part of other number also, it will
	not be of longer length.


12 ***) Given a binary matrix, find the largest square sub matrix with all 1's @@@@@@@@ (variation: longest
rectangle in a matrix with all 1s)

	
	Consider all cells to be rightmost bottom of the square sub matrix. 

	DP(i,j) = {

		min(arr(i-1,j-1), arr(i-1,j), arr(i,j-1)) + arr(i,j) ; if arr(i,j) is 1

		0 ;             if arr(i,j) is 0
		arr[i,j)			i = 0 OR j = 0 //copy first row and columnn as it is
	}


13) skipped (Find kth ugly number)

14) Find the longest decreasing subsequence (reverse of longest increasing, start from opposite end of array)

15 ***) Perfect hill longest subsequence @@@@@@@@ (variation: longest bitonic subsequence)

	Compute LDS and LIS for the given array
	Now traverse from 0 to size, and take min of LIS and LDS and multiply by two. Subtract 1 from result.
	That will be perfect hill sequence length at that point. Keep track of when this value is maximum
	O(n^2)
	
16) Edit distance - Given two words, word1 and word2, find min operations to convert word1 to word2 with some given set of rules (three operations are insert, delete and replace)

	Op(i,j) = { //Op is operations required, i is word1, j is word2

		//if two dont match
		1 + min(
				Op(i-1,j-1) //replace
				Op(i-1, j) //delete
				Op(i, j-1) //insert
			)	

		//if match
		Op(i-1, j-1)

		length of j; if i=0	
		length of i; if j=0
	}


17) skipped (Largest sum independent set in a binary tree)

18) Find the number of n-bit integers which do not have any two consequent zeroes O(n)

	In this case our problem size is n.

	_ _ _ _ _ _ _ _ ....... upto n

	First place can be taken by a 0 or 1. In case of 0, the next number can only be 1 which we are sure of
	therefore prob size reduces to n-2
	In other case starting from 1, next place can be 0 or 1. Therefore problem size has only reduced by 1

	Total count = f(n-1) + f(n-2) which is nothing but fibnacci


19 ***) skipped (Given a sentence without spaces between words. Break the words in such a way that they are meaningful)
	@@@@@@@@ (variation: word break part 2)

20) Partition problem: we need to divide the array into two parts where the difference in the sum of the two parts is minimum.
	
	

	















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

20) skipped (Partition problem: we need to divide the array into two parts where the difference in the sum of the two parts is minimum.) @@@@@@@@

21 ***) Find the longest palindromic subsequence @@@@@@@@ (variations: longest palindromic substring, find all distinct continuous palindromic sub-strings, count all palindromic subsequences, given a string find min characters to be inserted to form a palindrome, Given a string, find out if it becomes a palindrome or not after doing atmost k deletions)

	METHOD1:
	Reverse the sequence and find LCS

	METHOD2: (here i has to be less than j and we traverse diagnally)

	LPS(i,j) = { //longest palindromic subsequence

		2 + LPS(i+1,j-1) ;//if i<j and arr[i] == arr[j]

		max(
			LPS(i+1,j), 
			LPS(i,j+1)  //if i<j and arr[i] != arr[j]
		)

		0;   if i > j

 	}

 	String questions can also be addressed by finding LCS and subtracting from length (check variations)

22) Given n-stairs, how many number of ways a person can climb to top from bottom using 1 step or 2 steps

	Either person can take 1 step from anywhere or two steps. Total can be all such combinations
	Therefore
	f(n)  = f(n-1) + f(n-2)

23) skipped (Longest non-overlapping repeating sub string)	@@@@@@@@

	Worst case method:
	Find all substrings and find using KMP where it exists and maintain a counter

24) Given two strings X and Y, find the minimum cost to make two strings equal using only delete operations. 
Cost to delete character in X is S and in Y is P

	METHOD1:
	We find the LCS of the two strings and simply subtract LCS length from both the lengths and multiply
	with their respective costs.

	METHOD2:

	C(i,j) = { //cost
		C(i-1, j-1) //if str1[i] == str2[j]

		min(
			S + c(i-1,j),
			P + c(i, j-1)
		)

		P *length j ; i = 0
		S *length i ; j = 0
	}

25) Count the number of times string occured as the subsequence of the other string

	METHOD1:
	Find lcs and it will definitely have multiple solutions if we back track, we can count those.
	In this case length of LCS will be equal to length of pattern

	METHOD2:

	N(i,j) = { //number of times

		N(i-1,j-1) + N(i-1, j); //if str1[i] == str2[j]

		N(i-1, j) ;//if str1[i] != str2[j]

		0;  i = 0
		1;  j = 0

	}

26 ***) Given an amount and some coins, find out in how many ways can this amount be formed (variation:
finite and infinite supply of coins, find min coins to make up that amount)

	When finite:

	N(i,j) = { //number of coins (i is the coins, j is sum)

		N(i-1,j-arr[i]) + N(i-1,j) ; if arr[i] <= S

		N(i-1,j) ; if arr[i] > S

		0	i = 0;
		1	j = 0;
	}

	When infinite
	N(i,j) = { //number of coins (i is the coins, j is sum)

		N(i,j-arr[i]) + N(i-1,j) ; if arr[i] <= S

		N(i-1,j) ; if arr[i] > S

		0	i = 0;
		1	j = 0;
	}

	In the variation where min coins have to be found, we simply take min instead of adding.

27) Given a 2xn board and tiles of size 2x1, count the number of ways to fill the board using 2x1 tiles
	(variation: size nxm, tile size 1xm)

	f(n) = f(n-1) + f(n-2)

	Either we can put 2x1 board horizontally or vertically. If vertical problem size reduces to n-1
	If horizontal, problem size reduces n-2 as the other tile also can be place horizontally only


	f(n) = f(n-1) + f(n-m)

	Here 2 has been replaced by m simply. There m can be anything and applying the above logic, it will
	give this equation

	NOTE: 2xn will be same as nx2

28) Given a cost matrix mxn having a cost at each cell. Find the min cost that it will take to reach cell (m-1,n-1) from top left corner cell (0,0) if the only allowed directions to move are right, down and diagnal down
	
	There can be two ways to solve this condition: rightmost bottom as start or leftmost top as start

	C(i,j) =  { //cost which is initialized taking values from matrix only

		C(i,j) + min(                      if i>0 and j > 0
				C(i-1, j-1),
				C(i-1, j),
				C(i, j-1)  
			) 

		C(i, j-1) + C(i,j) ; if i = 0
		C(i-1, j) + C(i,j) ; if j = 0

	}

29) skipped (Find the sum of digits for all numbers from 1 to N for a given N)

30) skipped (Given a string of digits, find the length of the longest substring of a string, such that the length of the substring is '2k' digits and sum of left k digits is equal to the sum of right k digits)

31) skipped (cutting the road)

	



	








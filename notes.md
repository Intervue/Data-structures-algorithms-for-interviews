=========================== Dynamic Programming ============================


DIFFERENT QUESTIONS:

31, 29, 23, 20, 19, 17



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

   http://www.geeksforgeeks.org/space-optimized-solution-lcs/
   For space optimized solution use binary indexes and if odd use first row, if even use 0th as we only need
   2 rows at a time. Fill the table accordingly.


3) Multi-stage graph @@@@@@@@

	Here a source is given and a destination is given and we need to find the shortest path from src to 
	destination.

	We maintain a 1d array since is a multistage graph where edges are there from one stage to the next one
	only and not between vertices in a stage. We can maintain a 1d array and apply bottom up evaluation

	At any point
	C(i) = { //cost of reaching from i to destination

		min (
			C(i,j) + C(j)    ; this will be for all j > i and j < vertices and edges should exist between i and j
		)

	}

	0th index will give ans.


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

6) Travelling salesman problem: 2^n with DP, naive: n! @@@@@@@@

	Salesman wants to start from src come back to src visiting each vertex only once (hamiltonian path)
	in the least cost possible

	T(i,S) = {
		min(C(i,j) + T(j,S-{j})); when S is not null
		C(i,1); when S is null, assuming he has to come back to 1
	}

	Total problems after DP = (n-1)2^n-2 , exponential time complexity even after DP
	Even a table of exponential size is required
	TC: n^2 2^n //takes O(n) time to solve each prob (NP COMPLETE)


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

10) max sum increasing subsequence: O(n^2) @@@@@@@@ (can return length or sum, take whatever is to be found
as array cell value)

	Here we consider the max sum instead of considering the max length each time we compare

	MSIS(i) = { //max sum increasing subsequence

		max(MSIS[j] + arr[i]); if(arr[j] < arr[i])	
		j=0 to i-1

		arr[i]; if arr[j] for all J > arr[i]
	}	


11) longest subsequence in an array which has consecutive elements
	
	METHOD1:
	Sort and find longest sequence of consecutive elements (nlogn)

	METHOD2: O(n)
	Store all values in hash table, then traverse the main array again, for each value
	check prev least and next largest number consecutively in hash table. If it exists
	mark it using a flag. Keep the check of the count. Repeat process for all elements.
	O(n) as hash table wont be traversed for all elements as we use a flag. Also if 
	subsequence is a part of one number, and if it is a part of other number also, it will
	not be of longer length.


12 ***) Given a binary matrix, find the largest square sub matrix with all 1's @@@@@@@@ (variation: longest
rectangle in a matrix with all 1s)

	
	Consider all cells with 1 to be rightmost bottom of the square sub matrix. 

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


17 ****) Largest sum independent set in a binary tree - no two nodes are adjacent to each other: @@@@@@@@
	(variation: largest independent set in a binary tree )

	Largest independent set in a binary tree:

	LIS(root) = { //largest independent set
		1 + LIS (root->left->left) + LIS(root->left->right) 
		+ LIS(root->right->left) + LIS(root->right->right); if included
	
		LIS(root->left) + LIS(root->right); if not included
	}

	Here the approach for dynamic programming will be we will be storing calculated data in the structure.

	If Largest sum is to be given in the independent set: root->data instead of 1 if it is included part
	In the end find Max of the two
	/*
		if(!root){
			return 0;
		}
		int size_excl = LISS(root->left) + LISS(root->right);
		
		int size_incl = 1;
	    if (root->left)
	       size_incl += LISS(root->left->left) + LISS(root->left->right);
	    if (root->right)
	       size_incl += LISS(root->right->left) + LISS(root->right->right); 
	   	
	   	return findMax(size_excl, size_incl);
   	*/


18) Find the number of n-bit integers which do not have any two consequent zeroes O(n)

	In this case our problem size is n.

	_ _ _ _ _ _ _ _ ....... upto n

	First place can be taken by a 0 or 1. In case of 0, the next number can only be 1 which we are sure of
	therefore prob size reduces to n-2
	In other case starting from 1, next place can be 0 or 1. Therefore problem size has only reduced by 1

	Total count = f(n-1) + f(n-2) which is nothing but fibnacci


19 ***) Given a sentence without spaces between words. Break the words in such a way that they are meaningful
	@@@@@@@@ (variation: word break part 2, alien dictionary)

	Word break:
	Here we can split the given sentence anywhere and check it that word is valid or not.
	Therefore if from 0 to 6, 0 being start and 6 being end, we need to check

	WBP(i,j) = {

		1 or TRUE;  if(i,k)  is valid and k+1,j is valid (check for all k 1 to j); || if i to j is directly valid

		0 if not valid

	}

	Here we fill the table diagnolly as i is always less than j. TC: O(n^3)


	Word break part 2: Here we also need to print the valid words: To be done (skipped)


20) Partition problem: we need to divide the array into two parts where the difference in the sum of the two parts is minimum.) @@@@@@@@
	
	In this problem if we find the total sum of the array and then half it. Then find that half sum in the array
	using subset sum problem, then that subarray and the remaining part of the array will be the two sub arrays

	O(nk)// where k is half of the sum.
	

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

 	----------------------------------------------------------------------------

 	Longest palindromic substring
 	


22) Given n-stairs, how many number of ways a person can climb to top from bottom using 1 step or 2 steps

	Either person can take 1 step from anywhere or two steps. Total can be all such combinations
	Therefore
	f(n)  = f(n-1) + f(n-2)

23) Longest non-overlapping repeating sub string @@@@@@@@

	Worst case method:
	Find all substrings and find using KMP where it exists and maintain a counter

	DP:
	Here we take i and j two pointers. Since they cannot overlap, 
	i and j represent the end points of two substrings that match each other.
	if
	i = 0, j = 1 to n - 1
	i = 1, j = 2 to n - 1

	and so on. Therefore,

	L(i,j) = { //length of substring ending with i and j respectively

		1 + L(i-1, j-1); if str[i] == str[j]
		0 if not equal

		for i == j
		1 ; if match
		0 ; if not match

		0; if i >=j 
	}

	We also maintain a max variable and update it whenever we find a higher value.

	NOTE: In questions involving substrings, mostly we traverse diagnolly or we only calculate top right
	portion  of the matrix as i <=j or i < j for such cases.


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
	This is nothing but a variation of LCS where we find total...

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
	In case of min: first row is to be taken as INFINITY. When number of coins are zero its impossible to make 
	a sum

	Int case of max (where max coins are to be found): take first row (except 0,0) as -INFINITY because 
	if a particular sum is left after subtracting a particular number, and the left sum is not valid it has
	to be -INFINITY only as it is not valid.

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

	If starting from left corner top, write first row and col in a cumulative manner as per recursive eqn also, then from i=1,j=1 onwards:

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

30 ***) Given a string of digits, find the length of the longest substring of a string, such that the length of the substring is '2k' digits and sum of left k digits is equal to the sum of right k digits @@@@@@@@

	The objective of the question is to find substrings whose sum of first k digits is equal to last k
	Variations can also be there where any first k digits sum should be equal to l digits

	Therefore, we create a 2D matrix which stores sum of all possible substrings. Since its a substring i<=j
	Therefore it needs to be filled diagnally.

	While filling, we check how are we actually computing the sum for remaining diagnols after filling the first diagnol. If the two values responsible for sum computation are equal we update that length of substring
	in the max variable if variable if less than that length. We do this check as per the requirements given in the question.
	If it says substring is of even length, then we do the above check for even length substrings only.


31 ***) Given a rod of length 'n' inches and an array of prices that contains prices of all pieces of size smaller than n, find the max value obtainable by cutting the rod and selling the pieces (variation: find max pieces in which a rod can be cut if it can be cut into x y and z pieces only given length as N)@@@@@@@@
	
	This can be approached as 0/1 knapsack with duplicate items

	P(i,j) = { //max price

		max(price[i] + P(i, j - arr[i]), //if length of rod given is lesser than j
			P(i-1, j)
		 )

	 	P(i-1,j)              //if length of rod given is higher than j

	 	0    ;j = 0 (length of rod is zero)
	 	0    ; i= 0 (no segmentation prices given)
	}


32 ***) skipped (Playing a game)

33) skipped (Collect max coins from the grid in two traversals)
	








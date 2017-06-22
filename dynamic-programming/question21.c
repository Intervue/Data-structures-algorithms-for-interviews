/*
Find the longest palindromic subsequence

Naive approach:
Find all the subsequences of a given string. 2^n.
Then O(n) time to see if its a palindrome or not and then keep a variable to find the max
length. This time complexity is exponential

METHOD1:
DP: We can reverse the string and store it in an another string.
Now we can apply the algo to find the LCS. Whatever the LCS will be is going to be a palindrome 
itself.

Time complexity: O(n^2)

METHOD:
DP: Explanation:
Here we can consider a string and try to match the first and the last element, like we do in order
to identify whether a string is a palindrome or not.
We will have two possibilities

if it matches    (then we move the pointer ahead to compare the inner elements from both sides)
if it does not match (then we take max of two cases. In one we move pointer from right and keep left fixed
and other is opposite of it)

Recursive equation for the same can be formed as below:

PL(0,n-1) = {
		
		PL(1,n-2) //if equal
		max{ PL(0,n-2) , PL(1,n-1)  } //if not equal
}

Now it is proved that it can be solved recursively. Now taking an example for 0,5 and making a tree
using these recursive equations will show us repeating sub problems.

Therefore, we need to find unique sub problems, for that we generalize the definition of recursive eqns
as:
PL   (i,   j)
if    1    n-1  //if value of i is 1 j can be between 1 and n-1, therefore it can have n-1 values
      2    n-2
      3	   n-3 and so on 

      That means there are n^2 unique sub problems

Therefore, we make a matrix of size n^2 and ...

*/
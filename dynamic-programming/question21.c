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

Therefore, we make a matrix of size n^2 and taking example as "naudna"
There is a default row 0 for the matrix and apart from that matrix will look like this

   0 n a u d n a
0
n
a
u
d
n
a

The cells below the diagnal element will not be considered as i always needs to be less than j. Now we traverse
The matrix diagnally each time and as per recursive equations keep filling the matrix.
Note that the diagnal element will initially be all 1 as n a u d n a are all palindromes if taken one at a time

By repeating this process we can actually find a palindrome with the longest length.

Time complexity: O(n^2)
Space complexity: O(n^2)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findMax(int a, int b){
	return (a>b)?a:b;
}

int findLongestPal(char *str){

	int length = strlen(str);
	int dp[length][length];
	int i,j;

	for(i=0;i<length;i++){
		dp[i][i] = 1;
	}
	int k;
	for(j=1;j<length;j++){
		i=0,k=j;
		while(k<=5){
			if(str[i] == str[k]){
				dp[i][k] = 2 + dp[i+1][k-1];
			}else{
				dp[i][k] = findMax(dp[i+1][k],dp[i][k-1]);
			}
			k++;
			i++;	
		}	
	}
	return dp[0][length-1];
}

int main(){
	char str[] = "raudra";

	int len = findLongestPal(str);
	printf("longest palindrome is with length %d\n", len);
	return 0;
}



















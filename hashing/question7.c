/*
Find four elements i,j,k and l in an array such that i+j=k+l

METHOD1:
Brute force. We pick 4 elements from n elements. 4 for loops will be involved. Check the formula for each combination.
Time complexity: O(n^4)
Space complexity: O(1)

METHOD2:
Find out all possible pairs. Now for all pairs store the sum and the number of times it has occured in a Binary search
tree. Also it should point to the pair that is responsible for that sum. If there are more than 1 pair, then add the
pair to the linked list. 
Eg: (8,2) -> 5,3 -> 6,2
Binary node having sum 8 repeating two times pointing to a linked list with pairs
Now traverse it and node having more than 1 pair is the answer.
Time complexity: O(n^2)//to make pairs + O(n^2logn^2) //to store them in binary search tree
= O(n^2logn)
Space complexity: size of binary search tree having n^2 elements: O(n^2)

METHOD3:
Store the above in a hashtable instead of BST. The hashtable will have sum as indices and frequency. Also it will
contain pointer to a list.
Time complexity: O(n^2) //as insertion and search will now be in O(1)
Space complexity: O(n^2) //size of hash table

*/
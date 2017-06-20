/*
Given a sentence without spaces between words. Break the words in such a 
way that they are meaningful

How to test if words are meaningful or not:
Assume that there is already a hash data structure with all the meaningful words present in it.

NAIVE approach: In worst case if we try to break the word after each character, total characters
being n, n-1 spaces can be inserted. Therefore after each character either a space can be inserted
or either it cannot be inserted.
Hence 2^n-1 ways are there and total n words can be formed and to check each word O(1) time is required.
Total time complexity is exponential

METHOD:
Dynamic programming:

*/

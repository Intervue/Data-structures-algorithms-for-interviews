/*
Rabin Karp string matching algorithm

In this algorithm we compute the hash value (using some hash function) of the pattern string

Now in the text string we keep taking  substrings of length equal to pattern string and compute there
hash value. To efficiently compute the hash value (assume length of pattern string is 3)

text: abbecd
pattern: abb

initially abb's hash value will be found then for bba, we can simly subtract a and add e's hash
value to make this happen in constant time,

One hash value is a match with pattern string hash value, then we can compare the substring and the pattern
string just to be sure.

Time complexity: O(mn) //comparing hash and substring
Space complexity: O(1)

Disadvantage: Making the hash function is not that easy
*/
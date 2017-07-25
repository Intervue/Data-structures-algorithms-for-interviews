/*
Boyer-Moore algorithm for string comparison

In this algorithm rather than comparing from front, we compare from the last digit.
The only thing is that the pattern string and the text string should be placed in line always.
It means that the pointers should be aligned such that the first digit of the pattern string INITIALLY
should be aligned with the first digit of text string and so on.

Now we compare the last characters and keep doing that till they are not equal. If they are not equal.
We search the character from the text string that is not equal in the pattern string. Whereever that character
is found first starting from the back, we will align the string now in such a way that
those two characters are aligned with each other and start comparing from the back again.

If they are still not equal, we move the entire pattern string to the just next place where the mismatch
occured.
If equal we repeat the above para.

In the above scenario we literally will not move the string but the pointers will be moves on the text
and pattern strings.

To make the pointer movement and searching the mismatched character easier, we maintain a table for the
pattern string which will contain the last occurence of each and every character For eg:

0 1 2 3 4 5 6 7
A B C A B D E F

Table will be a hash table something like this

F - 7
E - 6
D - 5
C - 2
B - 4
A - 3

This will make the movement of the pointers easier, whenever we have to align, the pattern string with
the text one, we will just see where the mismatch was - where that character's last occurence in the string
is and shift by that much amount.

if this subtraction result is negative, then no need to move to the left, just shift 1 step to the right
as we are coming from the left only and it has been proved that at left there is no match.

Time complexity: O(n/m)
Space complexity: O(1) //for the table as hash table size is not dependent on the input

Boyer-Moore algorithm is much more efficient than KMP at places where pattern to be searched has characters
as different as possible. If the characters are same, then in worst case it will give a time complexity of
O(mn) where it will end up comparing most of the characters, therefore, in case characters are mostly same
use KMP

*/
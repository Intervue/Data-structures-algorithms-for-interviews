/*
Check whether given two strings are rotations of each other or not

Two strings are rotation of each other, if on rotation of one string, we get the other.
If a string is of length n, then n rotations are possible. If one such rotation matches the other string,
then one string is rotation of the other

METHOD1:
Rotate the given string on character at a time, and each time compare with the other string. If one of 
the rotation matches, then two strings are rotation of each other.

Time complexity: O(n^2) //because for each rotation we have to compare n characters, which will take O(n)
time, and there will be n such rotations
Space complexity: O(1)

METHOD2:
Concatenate one string with itself. On concatenation the string obtained, the other string will be 
a substring in that string if they are rotation of each other.
Time complexity : O(n) //concatenation is constant time operation, and find if one string is a substring
of the other or not can be done in linear time using KMP algo
Space complexity: O(1)
*/
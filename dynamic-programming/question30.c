/*
Find the sum of digits for all numbers from 1 to N for a given N

NOTE: This is sum of digits and not sum of numbers. Therefore two digit numbers will be summed like
10 = 1 + 0
11 = 1 + 1
and so on for 3 4 or greater digited numbers

METHOD1:
When number becomes greater than 9, just do a while loop in which you pick the least significant digit
and keep adding it to the sum until the number becomes 0.

Time complexity: O(nlogn) //logn base10 is the worst case number of digits present in nth number.
Space complexity: O(1)

METHOD2:




*/
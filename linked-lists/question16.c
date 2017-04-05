/*
Apply merge sort on linked list

T(N) - total time taken to solve algo (sort)

Time complexity:
1) Find middle of linked list O(N)
2) Sort first half //T(N)/2
3) Sort second half //T(N)/2
4) Merge them O(N) //we have already seen this

Total = 2T(N)/2 + KN = O(NlogN)

*/
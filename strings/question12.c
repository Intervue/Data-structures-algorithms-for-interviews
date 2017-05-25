/*
Find first non-repeating characters from a stream of characters

METHOD1:
In this case since there is a stream of characters which are coming at a regular interval, if we use out prev
approach, for each input we will have to use that approach resulting in O(n) time complexity for each
input. If n such inputs are there O(n^2)
Time complexity: O(n^2)
Space complexity: O(1)

METHOD2:
Here we store values in hash table as they come. Apart from increasing the counter we also store a pointer
to a linked list, which will be nodes having the values that come in. Each time if the value in hash Table
increases more than 1 we remove that node from the head and other node takes it place. Hence we always print
the top of the linked list after removing the repeatitions.

Note: we can also maintain a queue instead of linked list and pop everytime when size in hash table increases
to more than 1, and do not push that repeating element in the queue and print the top everytime

Time complexity: O(n) //total
Space complexity: O(n)
*/
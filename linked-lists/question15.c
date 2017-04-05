/*
Merge K sorted linked lists of size N into one sorted linked list

METHOD1:
Naive approach where each linked list is merged into the other one by one
Time complexity: O(K^2 N^2)
Space complexity: O(1)

METHOD2:
USING MIN HEAP. min heap is made using the first k elements (first element of each list) and then delete min
and add the next node of that list to the heap it it exists.
Apeend the deleted node from the heap to the merged list
Keep repeating until heap becomes empty
Time complexity:
O(logk) to delete and add element. Therefore O(2logK)
total elements KN-K
heap is made out of K elements initially O(K)
Total: O(KN-K)logK
Space complexity: O(k)//size of the heap

METHOD3:
By divide and conquer. We join two lists at a time and leave the result there until all linked lists taken
two at a time are merged. We move to the second level where each linked list now has 2N elements.
Now we again take two at a time to make 4N elements and keep doing that until we reach KN elements.
By analysis it is found that the number of steps required to merge them to KN is logK
total number of work done at each step is equal to moving KN elements to the next step.
Time complexity: O(KNlogK)
Space complexity: O(1)

METHOD4:
If we use a binary search tree instead of min heap, chances are that the tree might get skewed and to add each
node further may take O(k) time. Delete may also take O(k) time
Therefore total time complexity will come out to be O(k^2 N). There using min-heap was a better option.
If time complexity in binary search tree is to be reduced, you will have to keep it balanced (so rotation is 
required). But that is costly.
*/


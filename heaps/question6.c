/*
Find k largest elements from an array

METHOD1:
Find max element from the array. Now output that element and replace it with the last element and decrease the
size of the array. Again find the max element and repeat the steps above. Keep doing it k times.
Time complexity: O(kn) //assuming k is less than n
Space complexity: O(1)

METHOD2:
Sort the array and display the last k elements.
Time complexity: O(nlogn)
Space complexity: O(1)

METHOD3:
Build a max heap from the given array. Delete max k times and print
Time complexity: O(n) + O(klogn) //n for building the heap klogn as for deleting max k times. If k is almost 
equal to n here, time complexity will become O(nlogn), if small then O(n)
Space complexity: O(1)

METHOD4:
Create a binary search tree from the given elements. Find the maximum each time from the BST and remove it 
fromt the tree and repeat it k times.
Time complexity: O(n^2) + O(kn) //n^2 to make the binary search tree as in worst case the tree can be skewed.
n to search for each element. Since it is done k times O(kn)
Space complexity: O(2^n) OR O(n) //BST using array or linked list

METHOD5:
Make a min heap using the first k elements in the array and assume that they are the largest k elements in the
array. Now from k+1th element start comparing each n-k remaining elements with the root of the heap and replace
if the root of the heap is smaller than that element and apply heapify again.
Repeat these steps for all n-k remaining elements and in the end the min-heap will have k largest elements 
from the array
Time complexity: O(k) + O((n-k)logk) //k for building the heap having k elements and (n-k)logk elements because
that many time minheapify will be called
Space complexity: O(1) //min heap and max heap do not require additional data structure. Same array can
be manipulated unless mentioned in the question
*/
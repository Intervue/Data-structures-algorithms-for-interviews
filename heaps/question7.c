/*
Find median in a stream of numbers

Stream of numbers mean the numbers are coming one after the other and for each input change you have to 
find what is stated in the question.

METHOD1:
You can apply merge sort to sort the elements each time, anf find median, in case of even numbers median
is middle two elements and odd numbers median is the middle element. But since for each input we will have 
to apply merge sort on the previous inputted numbers as well. So here insertion sort will work better, as
once applied we will just have to apply it for the 1 input that is coming. 
Time complexity: O(n^2) //for first sort for rest of the inputs it can be done in O(n) for each input
Space complexity: O(1)

METHOD2:
Creating a BST. In this case since elements are streaming we will make sure that at any point the 
number of elements in the left sub tree and right sub tree are equal or atmost have a difference of 1.
If they are equal, root element in the median, if they are not equal, then if the LST has more elements
then max element (traverse to left and then to right most) in this tree is the second median, in case
RST has more then least element in this tree is the second median. Each time when the difference in the
number of elements increases to more than 1, then whichever side is dominant (if right, pick the least from
right, if left pick highest from left) and substitute in place of the root and make the root to be inserted
again as another element. This was the tree will be kind of equal at both the ends.
Time complexity: O(n) //Worst case if LST and RST are both skewed, average case can be logn also
Space complexity: O(n) //linked list representation of BST but it can take a lot of space because of pointers
but using array is not efficient because in worst case if the three is skewed array will take up 2^n time.

METHOD3:
Maintain two heaps, one min heap and one max heap. Insert min half elements from the array in the max heap and 
max half in the min heap. Now root of the min heap and root of the max heap will be the medians.
They represent positions of two elements while in the sorted array. (dry run it). The positions of other
elements does not really matter. When element is inserted in max heap, if the element is lesser than root,
only then it will be inserted otherwise it will be inserted in the min heap to enusre that max heap contains
only the lower half of the elements. Now if at this stage the min heap has more than 1 element greater than 
the max heap, min heap root will be deleted and min heapify will be run on it and this root will now be
inserted into max heap and maxheapify will run to make sure that both the heaps are balanced at any stage.
Time complexity: O(logn) + O(logn) + O(logn) //inserting in max heap + removing from max heap + Inserting in min
At any point in worst case O (logn) will be the complexity. For n elements it will be nlogn
Space complexity: O(n) //since elements are coming in stream we cannot do both min and max heap in the same
data structure, so we will have to make separate data structures.


*/
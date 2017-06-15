# Quick Notes:

### For Arrays: (methods that can be applied)

- sorting and then doing something, hashtable, two pointers in a loop are some of the operations that are popular to solve algos.
Hash table can also be made for storing sum etc.
- to find all combinations use nested for loops (worst algos)
- another way is to stop at an element and traverse all its previous elements
- fixing one number and having two pointers one at start and one at end to make some operation
- Consider making new arrays if anything does not work or satisfies requirements. These arrays may contain cumulative sum from left to right or right to left or soul of the algo which can make computation easy.
- Compare those arrays sometimes to find algos
- Cumulative sum or prod can work out to solve algos
- XOR operation can be applied to see the number repeating odd number of times as XOR will return that num
only if there is one number that repeats odd number of times
- If element in an array is to be found, and length is known apply binary search. Will complete the search in O(logn) times. If binary search cant be applied look in sizes of k at a time to limit the search set.
- We cannot find time complexity of something whose input size is unknown.
- If some number is repeating like in 0s and 1s example, 0 can be changed to -1 for certain operations.
- To find duplicates for array containing elements between 1 to n, iterate, lets say value is 3, go to third index and change value to negative. If value is already negative that means 3 has repeated and so on check for all.
- You can also use an external variable OR divide array elements into relevant groups by some computation to solve the algo
- For questions with repeating sub problems, try thinking out using recursion
- returning a function in recursion which is called will ultimately end of returning the base value 
which has to be returned
- Sometimes if the algo seems to be complicated move to a generalized format where the result is assumed to be N and you are solving it for some x by going from solution to problem, and then try to figure out the algo. (refer question 28.c for more clarification)
- Circular array can be used to implement a queue. Here the increment is not done just by incrementing by 1, but is done by incrementing by 1 and taking mod with array size. Like this you keep rotating the array. Refer question 2 stacks and queue for more info
- For questions involving subarrays:
    - Naive approach
    - Can maintain another data structure (may be a queue) sometimes to solve the algo
    - Can maintain a hash Table to solve the algo
    - Can maintain multiple variables to solve the algo
    - Can maintain two pointers to solve the algo
    - Kabane's algo

### For Linked Lists: (methods that can be applied)
- Use multiple variables to not loose track of the linked list and keep moving them ahead in a manner such that various operations can be done on a linked list
- If you dont want a function to return a value of something, just send that value to the address of the variable by passing the address of variable as argument and accessing it has **
- maintain hash table of addresses of the different nodes (first node has this address and so on) to access the value later without traversing
- maintain multiple pointers. The pointers can be moved at different speeds as per requirements.
- sometimes linked list while designed can have flags to make an algo possible
- If linked list has a loop, and two pointers are taken one moving at double the speed of other, they will meet at some point inside the loop. The distance from the start of the list to the first node where the loop starts is equal to the distance from where they meet to the first node.
- Linked list is generally is used to store large numbers which cannot be stored in an int or is used to store polynomials. If numbers are stored in linked list, you will have to apply your own operations (add, subt and so on for that)
- Use general Data structures like stacks and queues or arrays to sometimes solve the algo.
- Try connecting the end of the linked list to the front or make a loop to solve an algo.
- To make games like snakes & ladders, we can use a linked list with a random pointer, next pointer and data.
Whenever there is a ladder or snake, the random pointer will point there else it will be NULL.
- Consider making additional connections (links to the new list or old list) for traversing or reference point of view when there are multiple things involved (random node eg:). New node sometimes can be added in the middle of the two nodes to maintain a connection and so on.
- In program involving partition or merging always take mid as start+end/2 and not subtraction because this will always give the correct value. Subtraction may not give the correct value as you keep breaking the array into smaller parts

### For Hashing: (methods that can be applied)
-  When solving questions divide value with the size of the hashTable. Keep the size of the hash table one
greater than size of elements to be stored.
- Solve using chaining or linear probing
- Heap, BBST-AVL are some popular data structures that can be also used for questions involving hash table.
- Binary search is very widely used. Can only be applied if the length of array is known and if array is sorted.
- Sometimes, scanning once and searching and keeping additional variables for check can do the job.
- In hashing the structure can vary as per requirements. It can store anything from sum to frequency to pointers. So decide the structure as per always.
- For hash table take mod with the number of elements present.
- In case of question involving single array using recursion where tree is made, make sure that proper
start and end of array is chosen(specifically where array is split again and again)

### For Stacks & Queues: (methods that can be applied)
- For a stack and queue for each implementation or algo its core functionalities should hold true everytime.
Eg popping and pushing on a stack takes O(1) time.
- For making a stack using two queues or vice-versa either burden can be on push operation or pop operation. The one having burden will hold the task of enqueuing and dequeuing to move it to the other stack or queue.
Refer to stacks and queues question4 for more info
- For questions in stacks and queues use additional stacks/queues as datastructures to implement some algorithms
- You can store the minimum or max in other stack/queue or data structure for every push and pop and so on.
For eg storing the minimum so far in another stack so that each time when a number if popped off, if we pop off the minimum from the other stack, we will have min from the remaining elements sitting on top of the other stack. Like this many operations can be applied.
- You can also modify the numbers being pushed onto a stack and maintain an external reference by doing some computations to make an algorithm work. (Eg question5).
- Stack is useful where something is to be computed for every element but it is going to come late after iterating over various other elements. Since it has to follow a sequence, the no. for which computation cannot be done as of now can be pushed in the stack. The number for which computation is done can be popped off from the stack (eg. question6)
- Some algos may require implementing a stack using a different data structure. For eg using Double linked list over single linked list or using single linked list over arrays and so on. (question 7)

### Heaps (methods that can be applied):
- A large heap can be delcared and only a small portion of it can always be included in the heap operations.
- Whenever a heap is built, swapping etc. will be there if elements do not follow the heap property (max or min)
- Sometimes to find largest element in an array, min heap can be made, for few first elements, and each
time comparisons can be done with remaining element to eliminate the minimum elements.
- Methods where min and max heap can be applied BST can also be used (depends on question) 
- Sometimes a combination of min heap and max heap can be used to solve questions. Min heap can contain
maximum elements from array and max heap can contain minimum elements from array (this can be known at runtime without sorting the array). (refer question 7)
- Since each data structure has its own significance, sometimes it is good to use multiple data structures
like min heap + max heap + linked list as BST and so on for some algos to perform series of operations
- Given max heap to be converted to min heap, if you delete max each time and insert it in min heap it will
take logn time for each element therefore, total n elements. It will take nlogn time. Therefore, if you
just take the array as a random array rather than taking it as a max heap you can build the min heap in O(n)
time which is a better method.

### Trees (methods that can be applied)

- Recursion is used more often than not in case of trees to implement anything.
- Preorder traversal can give the path from top to any node.
- Sometimes it is good to store the path in an array to solve some algos
- For level order traversal queue is used. Each time parent is pushed, then when popping the parent its children are pushed on the queue
- Most questions in trees involve doing the core algo on the LST and then on the RST and in the end using recursion getting the desired result.
- In  a tree sometimes, if two pointers are to be returned for a DLL, we return only one and make the other point to the one that is also required so that we can get it using the one that is returned. Refer to question7 method2
- while applying recursion whatever is returned is returned for that particular function stack and will be assigned to the variable or thing that called that execution stack. In case local variables in recursion are to be used pass them as address and argument should be of type pointer while assignment.
- There are two ways of incrementing levels while traversal, one is to increment once when visiting LST and RST and decrement once when returning from LST or RST OR pass level as argument as level+1, when visiting LST and so on.
- Preorder traversal is best when you have to print nodes using some logic or visit any node given distance from another node or root. (even true for vertical tree order traversal)
- Somtimes hashtable can be used to store elements while traversal. Hashing comes in handy while searching for elements using a particular logic. So can be implemented along with trees.
- Sometimes if there is a problem determining the size of the hash table, linked list can be used instead which will further have linked lists attach to each nodes. So each node of the main linked list will behave as a cell of the hash Table.
- Deleting paths in recursion means, just free the root.
- Sometimes other functions can also be used inside recursion.
- The nodes of a subtree will always occur together in case of any traversal. The order may be different but there will be no interleaving.
- Sometimes to compare two subtrees, we can apply inorder and preorder OR inorder or postorder traversal and compare the o/p strings in the end. As studies earlier, preorder and inorder or postorder and inorder will 
always generate a unique tree.
- In case of question involving single array using recursion where tree is made, make sure that proper
start and end of array is chosen(specifically where array is split again and again)

### For Strings (methods that can be applied)
- All concepts of arrays are applicable to strings, since they are characters arrays (the ones that are general and not just applicable to numbers)
- For searching both BST and hash table can be applied.
- Hash table can be made for a character array (string). Length of hashtable should be 256, because ASCII values maximum is upto 255 starting from zero, therefore only that much space will be taken at max.
- Two pointers in a loop both on same side one tracking duplicates one tracking unique can be used to remove duplicates from a string.
- In case of string arr size should be measured using strlen and not using sizeof as sizeof also includes \0
- Sometimes a string can be merged with itself or the other to solve some algos. For eg: if one string is rotation of the other, concatenating one with itself can give a string where second string will be a substring in this string.
- Store as many things as required to solve the algo in hash table as it is a structure 
- It is always good to free memory assigned to hashTable after the end of the program
- Sometimes hashtable value can be decremented and not incremented to solve an algo for eg. finding anagram
- Excel column number and name relation has to do with the number system. In case of excel the number system
base is 26. Therefore numbers are from 1-26. Just that numbers in this case start from 1 and not from zero
as compared to other bases for eg 2 which has 0 and 1 and so on.
Therefore given a number we can keep dividing it by 26 until we receive a number which is less than 26 as
remainder.
Then we take the remainder and quotient from bottom to top and assign them alphabets corresponding to their
values.

### For Greedy
- Used in case of optimization problems (maximize of minimize something)
- When to use heaps vs when to use sorting: When the problem requires just finding the min or max, we can use sorting, but if after finding something is to be inserted again for which in case of sorting it will take O(n) time as it requires finding the place, heaps are better as they take only O(logn) time to do the same thing.
- In order to represent nodes using bits etc, (eg: huffman coding), we use trees.
- Huffman codes or optimal merge patterns where something is to be minimized, always choose the maximum
value to be at the top of the tree with min edge length (or path to be traversed) and min at bottom with
max edge or path to be traversed to minimize work.
- Min cost spanning tree and shortest path problems are two different things. In shortest path a source will be given and we will have to reach the target in the shortest path possible given weight of each edge. In case of min cost spanning tree we have to construct a graph with min weight possible connecting ALL the nodes. Therefore priority of the algo varies
- In greedy method, to min or max something (different methods), we can be greedy about something to solve the algo, and bring in cases which can defy out method. One of them will work.
- Hash tables and mix and match of data structures like min and max heaps can also be used in solving greedy algos

### For divide and conquer

- In repeating elements with fixed size and ordered array we can use binary search. Also linear search can be
used where if an element should be repeating a given number of times, you can check its value at i and then
i+given number of times to see if thats true or not.
- In divide and conquer even number of multiplications can be reduced from n to logn to get the same result. Example is the pow function where the base value is square everytime and power is halved everytime to get the same answer in logn multiplications. In case the power value is odd, the result is given the base value such that power value is converted to even and then same operations are applied.
- In binary search whatever the algo be, always start from the middle and compare values to the left or right. You may even compare the extreme left and the right values to see lower and upper bound or some pattern to solve the algo. But in binary search always start from the middle. Also to break the recursion to return result successful condition will be a unique property trait at that index as per algo. Find that trait.
- Sometimes rather than searching in left array or right array, it is better to divide into two components/groups and apply various operations like comparison, merges etc. Note: since its divide and conquer number of division should be done till the end where we will be left with one element in each group.
- Sometimes, we apply binary search and on finding the middle element we apply the logic that is the crux of the algo to the middle element to find out whether to search in right array or left array. Eg: crux of algo if is swapping we do swapping, if comparing we do comparing, if it is applying some formula, we do that.
- To write the iterative version of a recursive version follow the steps below
      - Replace the recursion break condition with the while loop which will run
      - Apply the same conditions and update the value of the variables in that condition. These variables will be a part of the while loop also. Rather than calling the function with updated values, just update the values of the variables and while loop will handle the rest
      - Make sure to assign both the variable values that are passed into the function in recursion while doing it in while loop as iteration
      - The false condition (if any false value is to be returned for validation) will come after the end of while loop
- To write recursive from iterative, replace while loop condition and its opposite should be break condition of recursion and reverse the sub steps

### Dynamic Programming

- Programming in this means to use a table and we dynamically decide whether to call a function to do the computation or use this table
- Dynamic programming is just like divide and conquer and can be applied to any problem with optimal substructure (given problems should be breakable into smaller problems and solution to sub problem is a part of the solution to the main problem) and overlapping sub problems and recusive eqns
- In problems involving dynamic programming, we start from the basic case first (for eg in 0/1 knapsack), we see if the weight of knapsack is 1 and object weight is 1, then if weight is 2 and object weight is 1 and so on, we keep finding solution to every basic problem to derive the solution for the main problem.
- Questions involving subsequence, kadane's algo can be applied or hash table or pointers can be used
- In questions involving matrices somehow, to calculate the next number as per the algo it will involve the diagnal, upper or left element as we did in most of the algos.
- Sometimes we divide bigger problem into smaller problems by approaching it from the other side.
For eg: if a number that is needed should satisfy division by 2/3/5, we will rather multiply the base
number with 2/3/5 to generate the next one. Therefore a bigger problem to generate series was broken
down to a smaller problem to generate the next number each time. To keep track of multiple generations
sometimes, multiple variables can be used.
- Sometimes a given problem can be solved by reducing it to another known problem whose solution
is known.
- For problems involving subsequences, we can break them down to smaller problems. Specifically for 
linear array, array of length 1 less than total can be taken and a pattern can be found for dynamic programming to make recursive equations. 
- Sometimes results of two DP solutions can be merged using some algo to find the final result.

# Topic0: Programming Questions

## Note:
**Questions statements are included in the file itself**

### General Questions

- [question1.c](/general/question1.c)
- [question2.c](/general/question2.c)
- [question3.c](/general/question3.c)
- [question4.c](/general/question4.c)
- [question5.c](/general/question5.c)
- [question6.c](/general/question6.c)
- [question7.c](/general/question7.c)
- [question8.c](/general/question8.c)
- [question9.c](/general/question9.c)
- [question10.c](/general/question10.c)
- [question11.c](/general/question11.c)
- [question12.c](/general/question12.c)
- [question13.c](/general/question13.c)
- [question14.c](/general/question14.c) (still to be done)
- [question15.c](/general/question15.c)
- [question16.c](/general/question16.c)
- [question17.c](/general/question17.c)
- [question18.c](/general/question18.c)
- [question19.c](/general/question19.c)
- [question20.c](/general/question20.c)
- [question21.c](/general/question21.c)
- [question22.c](/general/question22.c)
- [question23.c](/general/question23.c)
- [question24.c](/general/question24.c)

### Arrays

- [Insertion Sort](/arrays/question1.c)
- [Merge Procedure](/arrays/question2.c)
- [Merge Sort](/arrays/question3.c)
- [Partition Procedure](/arrays/question4.c)
- [Quick Sort](/arrays/question5.c)
- [Bubble Sort](/arrays/question6.c)
- [Counting Sort](/arrays/question7.c)
- [find a pair in an array whose sum is X](/arrays/question8.c)
- [Moore Voting algorithm to find majority element in an array](/arrays/question9.c)
- [Find the max difference between any two elements in the array](/arrays/question10.c)
- [Find the number occuring odd number of times in a given array](/arrays/question11.c)
- [Separate 0's and 1's from a given array](/arrays/question12.c)
- [Seperate even and odd numbers using partition method for separating 0's and 1's](/arrays/question13.c)
- [Given an array A, find two elements whose sum is closest to zero](/arrays/question14.c) 
- [Find the triplet in given array that sum to given value 'x'](/arrays/question15.c)
- [Find the equilibrium index of an array](/arrays/question16.c)
- [In an array of unknown size having all 0s at one side and all 1s at other, find the index where 1st 1 exists.](/arrays/question17.c)
- [Given an array and an integer K, find max element for each and every contiguous subarray of size k](/arrays/question18.c)
- [Count number of smaller elements on the right of each element in an array](/arrays/question19.c)
- [Find the subarray with the given sum](/arrays/question20.c) 
- [Consider and array which contains only 0's and 1's. Find largest sub array which contains only 0's and 1's](/arrays/question21.c) 
- [Given an array of n-integers, construct product array such that prod[i] is equal to product of all elements except arr[i] without using division operator](/arrays/question22.c)
- [Find the duplicate in O(n) time and O(1) extra space](/arrays/question23.c)
- [Find the two repeating numbers in an array in which all elements are in range 1 to n occuring atleast once](/arrays/question24.c)
- [Rotate an array of n elements by d elements](/arrays/question25.c)
- [Given n non negative integers representing an elevation map where width of each bar is 1. Find the amt. of water that is trapped in between these bars after raining](/arrays/question26.c)
- [Given an unsorted array of +ve integers, find the number of triangles that can be formed with three different elements as three sides of the triangle](/arrays/question27.c)
- [Given an array, find the smallest number that is not possible with the sum of numbers from the array](/arrays/question28.c)
- [Write a program to do binary search in an array](/arrays/question29.c)

### Linked List

- [Program to create a singly linked list, insert and delete nodes and print all of them](/linked-lists/question1.c)
- [Move the last node to the begining of a linked list](/linked-lists/question2.c)
- [Traverse a Single linked list using recursion](/linked-lists/question3.c)
- [Iterative program to reverse a linked list](/linked-lists/question4.c)
- [Recursive program to reverse a linked list](/linked-lists/question5.c)
- [Find the middle node of a linked list](/linked-lists/question6.c)
- [Find the kth node from the end of the linked list](/linked-lists/question7.c)
- [Given a single linked list. Check if it has a loop](/linked-lists/question8.c)
- [Find the starting node of cycle if cycle exists in a given linked list](/linked-lists/question9.c)
- [Suppose there are two single linked lists both of which merge at the same point and become a single linked list. Find the node at which they merge](/linked-lists/question10.c)
- [Alternating split of a given linked list](/linked-lists/question11.c)
- [A linked list has three elements- data, link to next node and one random pointer pointing to a random node. Clone the linked list.](/linked-lists/question12.c)
- [Check whether a given list is a palindrome or not](/linked-lists/question13.c)
- [Merge two sorted linked-lists into one sorted linked-list](/linked-lists/question14.c)
- [Merge K sorted linked lists of size N into one sorted linked list](/linked-lists/question15.c)
- [Apply merge sort on linked list](/linked-lists/question16.c)
- [Consider a single linked list with each node having an arbitrary pointer with initial value NULL.Give an algorithm to make the arbitrary pointer point to the greatest value node on its right side.](/linked-lists/question17.c)
-[Insertion and deletion in memory efficient double linked lists](/linked-lists/question18.c)

### Hashing

- [General question to understand linear probing](/hashing/general-question1.c)
- [General question to understand chaining](/hashing/general-question2.c)
- [Check whether given array contains duplicates in k-distance or not](/hashing/question1.c)
- [Check whether two sets given are disjoint or not](/hashing/question2.c)
- [Group all the occurences of the elements order by their first occurence](/hashing/question3.c)
- [Given an array A, Count the distinct elements in all windows of size K](/hashing/question4.c)
- [Given an array and a range, find the elements that are in the range but not in the array](/hashing/question5.c)
- [Given an array, print all subarrays in the array which has sum 0](/hashing/question6.c)
- [Find four elements i,j,k and l in an array such that i+j=k+l](/hashing/question7.c)


### Stacks & Queues

- [Implement a stack using arrays & linked-list](/stacks-and-queues/question1.c)
- [Implement a queue using circular array](/stacks-and-queues/question2.c)
- [Implement a queue using two stacks](/stacks-and-queues/question3.c)
- [Implement a stack using queues](/stacks-and-queues/question4.c)
- [Design a stack such that get Minimum should be O(1)](/stacks-and-queues/question5.c)
- [Given an array, find the closest greater element which is present on the right side of the element](/stacks-and-queues/question6.c)
- [Implement stack with push ,pop, find middle element, delete middle element in 0(1)](/stacks-and-queues/question7.c)
- [Consider a set of intervals, merge all overlapping intervals](/stacks-and-queues/question8.c)
- [Check whether parenthesis are balanced or not](/stacks-and-queues/question9.c)
- [The stock span problem](/stacks-and-queues/question10.c)
- [Implement a queue using linked list](/stacks-and-queues/question11.c)


### Heaps

- [Given an array, create a max heap](/heaps/question1.c)
- [Given a max heap, apply different heap operations (find max, delete max,increase key, insert key, decrease key.)](/heaps/question2.c)
- [Write a program for heap sort](/heaps/question3.c)
- [Find a max element in a min-heap](/heaps/question4.c)
- [Build a min-heap and write algo to delete an arbitrary element](/heaps/question5.c)
- [Find k largest elements from an array](/heaps/question6.c)
- [Find median in a stream of numbers](/heaps/question7.c)
- [Given k-sorted lists, Find the minimum range to which at last one number belongs from every list](/heaps/question8.c)
- [Print out all integers in the form of a^3+b^3 where a and b are integers between 0 and N in sorted order](/heaps/question9.c)
- [Convert BST to max heap](/heaps/question10.c)

### Trees

- [Build a binary search tree and apply various operations on it](/trees/question1.c)
- [Check whether two trees are identical or not](/trees/question2.c)
- [Mirror tree](/trees/question3.c)
- [Implementation of Level order traversal in case of trees](/trees/question4.c)
- [Find lowest common ancestor of given two nodes in a binary search tree](/trees/question5.c)
- [Solve the problem above for the binary tree](/trees/question6.c)
- [Convert a binary tree into a double linked list in such a way that the order of nodes represents the inorder traversal of binary tree. Note this has to be done in place](/trees/question7.c)
- [Find the diameter of the given binary tree](/trees/question8.c)
- [Get the level of a given key in a binary tree](/trees/question9.c)
- [Print nodes k-distance from the root](/trees/question10.c)
- [Print nodes which are at a k distance from the given key in a binary tree](/trees/question11.c)
- [Program to implement vertical tree order traversal](/trees/question12.c)
- [Vertical sum of the given binary tree](/trees/question13.c)
- [Check whether the given binary tree is sum tree or not](/trees/question14.c)
- [Print top view of a binary tree](/trees/question15.c)
- [Print bottom view of a binary tree](/trees/question16.c)
- [Print left view of a binary tree](/trees/question17.c)
- [Remove all paths of length k from root in a binary tree](/trees/question18.c)
- [Check whether a given binary tree if a subtree of another binary tree](/trees/question19.c)
- [Check whether given two nodes are cousins in a binary tree](/trees/question20.c)
- [Form a balanced binary search tree from a given sorted array](/trees/question21.c)
- [Convert a given binary search tree into balanced binary tree](/trees/question22.c)

### Strings
- [Find a maximum occuring character in a given string](/strings/question1.c)
- [Remove duplicates from a given string](/strings/question2.c)
- [Check whether given two strings are rotations of each other or not](/strings/question3.c)
- [Reverse the words in a given sentence](/strings/question4.c)
- [Reverse a given string](/strings/question5.c)
- [Check whether given string is palindrome or not](/strings/question6.c)
- [Find the first non-repeating character in a given string](/strings/question7.c)
- [Run length encoding](/strings/question8.c)
- [Check whether given two strings are anagrams of each other](/strings/question9.c)
- [Find excel column name for given excel column number](/strings/question10.c)
- [Find the smallest window in the string containing all characters of another string](/strings/question11.c)
- [Find first non-repeating characters from a stream of characters](/strings/question12.c)

### Greedy

- [Make a program for greedy knapsack problem](/greedy/question1.c)
- [Make a program to implement huffman encoding](/greedy/question2.c)
- [Make a program to sequence given jobs with deadlines to maximize profits](/greedy/question3.c)
- [Optimal merge patterns](/greedy/question4.c)
- [Program for PRIMS algorithm](/greedy/question5.c)
- [Program for KRUSKALS algorithm](/greedy/question6.c)
- [Program for DIJKSTRA algorithm](/greedy/question7.c)
- [Program to implement a simple graph](/greedy/question8.c)
- [Consider n-ropes with different length. Find algo to tie up all the rope into a single rope with min cost](/greedy/question9.c)
- [Find max intervals from given intervals such that none of them are overlapping](/greedy/question10.c)
- [Number of railway platforms](/greedy/question11.c)
- [Rearrange the string such that same characters are d distance away](/greedy/question12.c)

### Divide and conquer

- [Find a majority element using linear search that occurs more than n/2 times](/divide-and-conquer/question1.c)
- [Nuts and bolts problem](/divide-and-conquer/question2.c)
- [Write a custom C function to implement a pow function](/divide-and-conquer/question3.c)
- [Select an element in sorted rotated array](/divide-and-conquer/question4.c)
- [Count inversions in an array](/divide-and-conquer/question5.c)
- [Find the missing number in arithmetic progression](/divide-and-conquer/question6.c)
- [Given an array containing 1's and 0's in which all 0's appear before all 1's, count the number of 1's in the array](/divide-and-conquer/question7.c)
- [Given an array with 2n integer in the formal a1,a2,a3...b1,b2,b3.. Shuffle the array to a1b1 a2b2 a3b3 ...](/divide-and-conquer/question8.c)
- [Given a sorted array of non repeated integers a[1--n]. Check whether there is an index i for which a[i]=i](/divide-and-conquer/question9.c)
- [Find the maximum element index in an array which is first increasing and then decreasing](/divide-and-conquer/question10.c)
- [Search an element in row wise and column wise sorted 2d array](/divide-and-conquer/question11.c)

### Dynamic Programming
- [Algorithm to find optimized soln for matrix chain multiplication](/dynamic-programming/question1.c)
- [Compute Longest common subsequence between two strings](/dynamic-programming/question2.c)
- [Multistage graph dynamic programming algorithm](/dynamic-programming/question3.c)
- [0/1 Knapsack dynamic programming algorithm](/dynamic-programming/question4.c)
- [Find a subset in an array whose sum is w](/dynamic-programming/question5.c)
- [Travelling salesman problem](/dynamic-programming/question6.c)
- [All pair shortest path algorithm](/dynamic-programming/question7.c)
- [Find the maximum sum sub array](/dynamic-programming/question8.c)
- [Find the max sum increasing sub sequence](/dynamic-programming/question9.c)
- [Find the longest subsequence in an array such that elements are consecutive](/dynamic-programming/question10.c)
- [Given a binary matrix, find the largest square sub matrix with all 1's](/dynamic-programming/question11.c)
- [Find kth ugly number](/dynamic-programming/question12.c)
- [Find the longest increasing subsequence](/dynamic-programming/question13.c)
- [Find the longest decreasing subsequence](/dynamic-programming/question14.c)
- [Perfect hill longest subsequence](/dynamic-programming/question15.c)


## Some important concepts to solve algos better

- For extreme values refer to limits.h constants given by C
- `XOR` means taking sum of the bits and dividing by two, remainder will be the answer
= 'XOR' is commutative
- 'XOR' of a number with itself is 0
- 'XOR' of zero with a number is the number itself
- '1s compliment is number obtained by reversing all the bits in the binary representation of a number. o to 1 and 1 to 0'
- Linear hashing is (h(k) + i)modm (where m is the size of the hash table, h(k) is the hash function that takes the key k and returns a value i is the parameter that is incremented to get different values)
- Subarrays of an array are always contiguous whereas subsequence may not be contiguous
- There are only two ways to make any data structure one is to use an array (where size is fixed and memory is contiguous) OR you can use the heap memory (structures and linked list). So Array and linked list or combo of these two are used to implement any data structure. In most cases linked list takes more time to do operations if data structure is implemented using it. But advantage is dynamic memory allocation
- For INFIX to POSTFIX conversion, data structure used is stack. In stack all the operators are stored. For evaluation of POSTFIX stack is used to store operands
- Evaluating and expression = convert from INFIX to postfix --> Evaluate POSTFIX. Time complexity: O(n)
- Heap can be implemented as a binary tree or ternary tree or n-ary tree. Heap is an almost complete binary tree. Leaves should always be filled from left to right in a heap
- Heap should be used when along with insertion, find min and delete min or max it to be done in less time
- In a min/max heap the root contains the min/max element compared to its children. Applicable for all levels.
- To make a heap rather than making a linked list (as it involves a lot of storage), we make an array.
- Every tree which is having one node or leaf (node with zero children) is already a min or max heap.
- From an array if a heap is to be constructed, follow:

  ```C
	LEFT(i) = 2i + 1;
	RIGHT(i) = 2i + 2;
	PARENT(i) = (i-1) / 2; (valid for array with index 0)
  //Go level by level from left to right and write elements from the array or to the array basically.
  //Note dividing by two means right shift in binary and multiplying means left shift in binary
  //There can be more than 1 max or min heap of a given array
  //In a complete or almost complete binary tree, leaves start from floor(n/2+1) to n
  ```

- An array in descending order is MAX HEAP and array in ascending order is MIN HEAP.
- There is an O(n) time algo to convert an element into a heap. So no need to sort as sorting take O(nlogn)
- Recursion adds to the space complexity as well as time complexity.
- In a max heap, finding min, deleting random element or searching an element will take O(n) time because here max heap is as good as an array.
- For Binary Search tree implementation using an array, space complexity is O(2^n), but using linked list, it
is O(n)
- Stream of numbers mean the numbers are coming one after the other and for each input change you have to 
find what is stated in the question.
- There are three ways to traverse any binary tree (can be applied to 3-ary or n-ary trees as well with some modifications)

```C
//all nodes should have children, even leafs
INORDER //left root right - second visit
PREORDER//root left right - first visit
POSTORDER //left right root - third visit
```
- Binary tree is a normal thing placing the element in order as given in the array in parent child relationship from left to right BUT Binary search tree follows a particular order.
- Binary search tree is usually used to store keys. Keys generally point to a particular record. Therefore keys have to be unique.
- INORDER traversal of BST gives us all elements in ascending order. (least element left most, max right most)
- *To understand recursion better or to do a dry run or make a recursive program follow the method of 123. i.e executing all lines turn by turn at a single place as explained in trees double order traversal or indirect recursion*
- Indirect recursion is when some function A calls B and B again calls A and so on.
- Number of structures possible with N non-labelled nodes is 2ncn/n+1
- Number of trees possible per structure if labelled n nodes is n! (total trees will be 2ncn/n+1 * n!)
- Given PRE ORDER POST AND IN ORDER only 1 tree will satisfy all conditions (number of trees with n nodes given pre post and in only 1 tree is possible. Even combination of any with INRODER will generate a binary tree uniquely)
- Expression tree is a tree in which operator occupied the root along with the nodes on the left or right side. (correct side can be checked by inorder traversal). Also operators have to be arranged on the tree as per their precendence.
- preorder, postorder and inorder traversal of an expression tree gives the respective forms.
- LCRS (left child right sibling), in this left pointer points to the left child and right pointer points
to the siblings which are children of the parent node along with this node. Representation is used to present
trees having random number of children not necessary equal
- Array representation of trees is used in case of heaps where going up and down is required. The disadvantage of using array is that if a tree is skewed, arrays have to be as large as 2^n for storing n values given indexes of parent and child which is not the case in case of heaps.
- *Recursion will keep populating the stack until dealing with statements to be executed, once a definite value truthy or falsy is returned, it will then pop off the execution context that returned that value. It is important to even return a function because then stack will know that this function is going to return something which may be a another function being returned or a value. This is how it keeps going.Note if return statement is not written then if else statement should be used so to avoid control of the program going downwards in the non satisfying condition. So return statement is just a replacement of if else in recursion*
- Level order traversal uses a queue in which parent is pushed onto the queue and then its popped (dequeued) and its children are pushed in order from left to right and same process is repeated. Therefore we keep scanning the nodes level by level.
- Level order traversal is similar to BFS (breadth first search in graphs) and other traversals like inorder, preorder and postorder are similar to DFS (depth first search in graphs)
- Vertical tree order traversal: Root is at a distance 0 from itself. When we move to the left child it is at a distance -1 from the root, the right child is at a distance 1 from the root. If we keep doing -1 for every left child and +1 for every right child, we will have multiple nodes at the same distance value. The nodes having same distance value fall on a vertical line. If we traverse that line, it is called vertical tree order traversal
- Sum tree is the one where sum of values in the LST and sum of values in the RST is equal to the root. This is valid for all the nodes except the tree
- Recursion execution stack only remembers the next line if there is no return statement, else it will return the execution stack
- Two nodes in a tree are siblings if they are at the same level and have same parent, are cousins if they
are at same level but do not have same parent
- O(1) means time complexity or space complexity is not dependent on the input size
- One string is rotation of the other, if one of the rotations of one string matches the other one.
- Run length encoding means, traversing through the given character array and displaying which character
is repeating how many times along with the character as output. 
Eg: SSMMMAAARRT => S2M3A3R2T1
- Two strings are anagrams if they have same no of characters and they are composed of the same letters.
Even if there are repetitions, they are going to be same. 
- Ideal approach of writing a program is return from a functiona and keep strings at a single place and not scattered
- Greedy method and DP are two programing paradigms which can be used to solve optimization problems
- Greedy method fractions are allowed
- For huffman coding to work letters must not be uniformly distributed
- Spanning tree is min number of edges present in the graph such that all nodes are connected. Span tree is always subgraph of the main graph and cannot contain edges which are not present in the main graph
- Number of edges incident on the node is degree of node in undirected graphs. In case of directed, there is no degree but in degree and out degree
- Kirchoff theorem is used to find spanning tree of non-weighted undirected simple graph
- Given a weighted graph, finding the minimum cost spanning tree can be done using two algos PRIMS and KRUSKALS. Both are greedy methods
- In PRIMS, whenever weights of edges are duplicates, there is a chance that we might get more than 1 spanning tree. But final cost will remaing the same for all in that case
- Dijsktra algo cannot be applied to graphs having -ve weight edges because the algo does not have capability to find if that edge is -ve or its getting converted to a -ve weight cycle. If there is a -ve weight cycle in the graph shortest path will not exist as with each cycle path will keep on decreasing.
- Tree is an acyclic graph
- Greedy method and dynamic programming are the only two methods that can be applied to find the solution to optimization problems. Greedy may not give the right solution everytime for each problem but will work for some of them and it takes less time. Dynamic on the other hand takes a little more time but always gives the correct answer to such problems.
- n factorial is nothing but n power n
- In a graph represented by cost matrix, if two vertices have an edge, weight will be given otherwise
if they dont have edge it is infinity.
- Travelling salesman problem time complexity O(n^2 ^ 2^n)
- Ugly number is a one which can be written as a product of 2,3 or 5 or a combination of these numbers. 1 is also considered as ugly number as it is an exception.


# C Programming - Topic1: Introduction

## Simple program to print '```hello world```' in C

[File here!](/programs/hello-world.c)

```C
#include <stdio.h>

int main(){
	printf("Hello world \n");
}

```

## Running this program

In the command line do the following (while in the file directory):

```
gcc hello-world.c

./a.out
```

## Code explanation

1. ```stdio.h``` is a standard C library to be included
2. ```main()``` is the function which is executed by C compiler each time the program in C is run. In case another function is to be called, it can be called via main. 
3. ```printf``` prints the output on the screen
4. ```gcc hello-world.c``` creates output file a.out. This command converts the high level language written in C to binary for out computer to understand it
5. ```./a.out``` is run to see the output
6. ```#include``` is the pre-processor directive which will fetch the file ```stdio.h``` for predefined functionalities of C

### Note:

`#define` is another preprocessor used in C discussed ahead.
`gcc -Wall -save-temps hello-world.c` is used to see all the temporary files that are created while a C program in executed and converted from high level language to assembly language to machine code and finally to the output


## Format specifiers to print different things

- `%d` prints as decimal number
- `%6d` prints as decimal number but atleast 6 characters wide 
- `%f` prints as floating point number
- `%6f` prints as floating point number in atleast 6 characters
- `%.2f` prints as floating point number but should have two characters after decimal
- `%6.2d` prints as floating point number with 6 places before decimal and 2 after decimal
- `%c` prints as ascii character

These specifiers can be used as example shown below:

```C
printf("%d",2);
```

## Character input and output in C

- 'getchar()' reads the next input character from a text stream and returns that as its value
- 'putchar()' prints a character each time it is called

### Example explained with comments:

[File here!](/programs/put-get-char.c)

```C
#include <stdio.h>

//default function that is run by C everytime
int main(void){
	//declaring a variable c that will take the input given
	int c;
	//assigning input using this function to variable c
	c = getchar();
	//this will keep printing until end of file is there
	while(c != EOF){
		//this function will print output on the screen
		putchar(c);
		//after printing the output it takes input until while loop ends
		c = getchar();
	}
}
```

# Topic2: Data Types in C

All variable start with a name which is a character and can include underscore (_). It should not start with a number or _.

- `char' - A single byte used to represent a character (numbers from 0-255 can be stored). Each decimal number is encoded as a character
- `int' - an integer (size is machine and compiler dependent) 
- `float' - A single byte (single-precision floating point number). Machine must have atleast 32 bits.
- `double' - A single byte (double-precision flaoting point number). Machine must have atleast 64 bits.

## Qualifiers that can be added to data types
- `short' - eg short int (will have a size smaller than int and long int)
- `long' - eg long int (size greater than short int and int)
- `signed' - generally used for int and char types (range -128 to 127 for int)
- `unsigned' - used for int and char (range 0 - 255 for int)

## Note:
`sizeof(int)` returns number of bytes `int` is taking in the system. Similarly char and float can be found. 
For floating point numbers larger than double `long double` can be used

## Program to find sizeof()

```C
#include <stdio.h>

int main(){
	//sizeof() can be passed any data type along with a qualifier
	//it returns the number of bytes that data type is occupying as per your system and compiler
	printf("%lu\n",sizeof(long int));

}
```

## Enumeration datatype

Type of constant which is helpful in improving the readability of the program

```C
//it will enumerate 0 as NO and 1 as YES. This can be used throughout the program
//default value of first will be zero and second will be 1 and it keeps on increasing unless some specific numbers are mentioned there
enum boolean {NO, YES};

//in this case value is specified for jan which is 1, so other values will have 2, 3 and so on values
enum months {JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC}

```

## Example using enumeration

[File here!](/programs/enumeration.c)

```C
#include <stdio.h>

int main(){
	//this will interpret no as 0 and yes as 1. So these can now be used conditionally
	enum boolean {no, yes};

	if(yes){
		printf( "hello world\n");
	}else{
		printf( "nothing\n");
	}

}
```

## Type conversion

Sometimes we need to convert variable from one type to another.

For eg: when adding double to long double, we need to convert both of them to long double so that we dont loose any information. The result will be given automatically in the bigger one of all.

### Priority order for conversion is as follows:

1. long double
2. double
3. float
4. short or int
5. char

Such conversions are also done in assignments. The right hand side is always converted to the type of left hand side in that case. There will be loss in information while doing so if the right hand side is lies upper in the priority order as compared to left hand side.

## Casting

When type conversion is done explicitly, it is called casting

Eg: converting int to float to store in float variable f

`f = (float) 10`


## Constants

If the following is specified in programs, they will automatically be characterized as the corresponding datatypes 

- 1234 - int
- 1234l - long int
- 12.34 - float
- 037 - octal (3X8+7)
- 0X12 - hexadecimal 
- 0x12l - long octal
- 'x' - character constant (ascii value of character is taken if used along with int)

## Note:

`const float pi = 3.14` makes the variable pi a constant which cannot be changed. If it is changed compilter throws an error.

## Example

```C
#include <stdio.h>

int main(){
	
	int i = 17; 
	char c = 'c'; //ascii value 99
	// "c" cannot be used. only 'c' can be used as single inverted commas will convert it to ascii value

	float sum;
   	//type conversion happens here	
	sum = i + c;

	printf("%f\n",sum); //prints 116.000000

}
```

## String constants

Generally they are represented using double quotes. 

`"string"`

The above example is having 6 bytes but we need 7 character space to store it because every string constant ends with null (\0).

## Example

[File here!](/programs/count-string-constant.c)

```C
//strlen is the name of the function which is taking character as argument
int strlen(char s[]){
	
	int i = 0;
	//this loop increments i until end of string \0 is reached
	while(s[i] != '\0'){
		i = i + 1;
	}

	return i;

}
```

## Assignment Operators

`i = i + 2;` 

increment the value of i by 2 and store it in i

shorthand for this

`i += 2;`

### In general:

```
expr1 = expr1 op expr2

can be written as:

expr1 op = expr2

```

## Bit Operators 

Some bit wise operators are discussed as below:

A (60) = 00111100
B (13) = 00001101

then:

- A & B (AND operations) = 00001100
- A | B (OR operation) = 00111101 
- A ^ B (XOR operation = add both of them and divide by 2 and write the remainder) = 00110001
- ~A (NOT operation) = 11000011 
- A << 2 (left shift by two) = 11110000 which is equal to 240 (it is nothing but multiplying by 2 power 2)
- A >> 2 (right shift by 2) = 00001111 which is 15 (it is nothing but dividing by 2 power 2) 


## Ternary Operator

### Example:

```C
#include <stdio.h>

int main(){
	
	int num;

	printf("enter a number:\n");
	//this will take input from user and assign it to vairable num
	scanf("%d",&num);
	//ternary operator to get the output
	(num%2 == 0 )? printf("number is even\n"): printf("number is odd\n");

}
```

## Increment and decrement operator

- `++n` increments n before its value is used
-  `n++` increments n after its value is used

```C
n = 2;
X = n++; //it will assign 2 to X and then increment n to 3;
```

```C
n = 2;
X = ++n; //it will increment n to 3 and assign it to X
```

## Precedence and order of evaluation of operators

`precedence`: which ever operator has higher priority is evaluated first

`associativity`: if precedence of two operators is same, which one is evaluated first is found out using associativity

[Click here!](http://www.difranco.net/compsci/C_Operator_Precedence_Table.htm) to see the full chart


## Note:

These can be remembered from top to bottom from the chart as `u asc blac` (unary, arithmetic, shift, comparison, bitwise, logical, ternary, assignment, comma)


## Program to print Fahrenheit - Celsius Table

[File here!](/programs/fahrenheit-celsius.c)

```C
#include <stdio.h>

int main(){
	
	int fahr, celsius;

	int lower, upper, step;

	lower = 0; // this is the lower limit of temperature table
	upper = 300; // this is the upper limit of temperature table
	step = 20; //step size

	fahr = lower; //initialized with lower value

	while(fahr <= upper){

		celsius = 5*(fahr - 32)/9; //here the precedence and associativity can be seen

		//will print the result in table format
		printf("%d\t %d\n", fahr, celsius);

		fahr += step; //incrementing by step size
 
	}

}
```

## Note:

Before using any function or variable in C we need to declare it always.
If function is from library then no need to declare it


# Topic3: Flow Control

Flow control means controlling the flow of program as per need.

There are various ways to do that:

- conditional statements (`if, elseif, else`)
- switch statement
- while loop
- do while loop
- for loop
- continue and break statements


## Example

Program to check whether a given number is even or odd using if else

[File here!](/programs/even-odd.c)

```C
#include <stdio.h>

//default function that is run by C everytime
int main(){
	int num;

	printf("enter some number: \n");
	scanf("%d", &num); //address of num will be returned when we write &num

	if(num%2 == 0){
		printf("number is even\n");
	}else{
		printf("number is odd\n");
	}

	return 0;
}
````

## Example of switch statement

```C
int main(){
	
	int weekday;	
	printf("enter weekday numbers between 1 and 6\n");
	scanf("%d",&weekday);

	switch(weekday){
		//break statement is important because if one case turns true no other case should execute
		//cases can contain expressions but only constants. No variables are allowed in cases
		// default case can be present anywhere
		case 0: printf("monday"); break; 
		case 1: printf("tuesday"); break;
		case 2: printf("wednesday"); break;
		case 3: printf("thur"); break;
		case 4: printf("fri"); break;
		case 5: printf("sat"); break;
		case 6: printf("sun"); break;
		default: printf("enter a valid weekday\n"); break;

	}

	
}
```

## Example

Simple calculator

[File here!](/programs/simple-calculator.c)

```C
#include <stdio.h>

int main(){
	
	char operator;
	double a,b;	
	printf("enter an operator (+, -, *, /)\n");
	scanf("%c",&operator);

	printf("enter two operators \n");
	//lf is the format specifier for double
	scanf("%lf %lf",&a, &b);

	switch(operator){
		//representing operators in single quotes will convert them to integers (ascii values)
		case '+': printf("additon of a and b: %lf\n", a+b); break;
		case '-': printf("subtraction of a and b: %lf\n", a-b); break;
		case '/': printf("division of a and b: %lf\n", a/b); break;
		case '*': printf("multiplication of a and b: %lf\n", a*b); break;
		default: printf("please enter a valid operator\n"); break;
	}

	
}
```

### Note:

`Difference between while and do while loop is that while loop will check the condition first and execute the body, do while will check the condition after executing the body once, the decide whether to exit the loop or not`

```C
int main(){
	
	int a = 20;
	//do has its own body following by while statement
	do{
		printf("%d\n", a);
		a++;
	} while(a<20); //output: 20. as it executes the body once

	//this is the while loop
	while(a<20){
		printf("%d\n", a);
		a++;
	} //output nothing

	//for loop
	for(int i = 1; i<a; i++){
		printf("value of i %d", i);
	}
	
	return 0;

}
```

```C
//program to probe the user until he enters a positive value
int main(){
	//do while loop is beneficial in this case	
	int num;
	do{
		printf("enter a positive integer\n");
		scanf("%d", &num);
	}while(num <= 0);
	
	printf("number now is %d\n", num);
	
}
```

### Note:

`Difference continue and break statement is that continue will move the loop to the next iteration and skip all the statements present between continue and the end of the loop whereas break will exit the loop. Continue statement should be used wisely in for loop, eg continue statement if before the increment of the variable which is under check in while loop can make the loop infinite. Break and continue will exit the loop that contains it. If the loops are nested, it will exit or continue for the respective loop only.`

## Example

```C
int main(){
	//infinite loop as continue statement is placed at wrong place
	int sum = 0;

	while(sum < 20){

		if(sum == 0){
			continue;
		}

		sum++;
	}

	return 0;
}
```

## Example program:

Check whether a number is prime

*Logic*: 

`One way is to start from 2 and go till n-1 to check if a number is prime`
`Better way is if no factors are found till root of a number or half of number there wont be any factors after that. The idea is to reduce the loop iterations`

[File here!](/programs/check-prime.c)

```C
int main(){
	
	int num;

	int isPrime = 0; //assuming number is not prime

	printf("enter a number\n");
	scanf("%d", &num);

	for(int i = 2; i <=num/2; i++){ //dividing the number by two and running the loop till then

		if(num%i == 0){
			isPrime = 1;
			break;//breaking out of the loop once out check is satisfied
		}

	}

	if(isPrime == 0){
		printf("number is not prime\n");
	}else{
		printf("number is prime\n");
	}


}
```

# Example program:

Find the factorial of a number.

[File here!](/programs/factorial.c)

```C
//default function that is run by C everytime
int main(){
		
	int num;

	printf("enter a number\n");
	scanf("%d", &num);

	if(num < 0){
		printf("factorial for negative numbers does not exist\n");
	}

	//since factorial of a number if always positive it is better to use unsigned for a bigger range (0 - range)
	// and not (-range to range)
	unsigned long long fact = 1; //integer having bigger size compared to normal integer

	for(int i = 2; i <= num; i++){

		fact = fact*i;

	}

	printf("factorial is %d = %llu\n", num, fact); //llu is format specifier for long long int

	return 0;

}
```

## Note:

'To find the number of digits in an integer keep dividing it by 10'

## Example program

Check is the number is armstrong or not

Eg: 341 == 3 cube + 4 cube + 1 cube, then its armstrong

[File here!](/programs/armstrong.c)

```C
//pre-process fetching contents of library stdio.h which contains predefined functions in C
#include <stdio.h>
#include <math.h>

//default function that is run by C everytime
int main(){
	
	int num, result=0, originalnumber, n=0, remainder;

	printf("enter a number\n");
	scanf("%d", &num);
	originalnumber = num;

	while(originalnumber != 0){
		originalnumber = originalnumber/10;
		n++;
	}
	originalnumber = num;
	while(originalnumber != 0){
		remainder = originalnumber%10;
		result += pow(remainder, n);
		originalnumber /= 10;
	}

	if(result == num){
		printf("this is armstrong number");
	}else{
		printf("this is not an armstrong number");
	}

}
```

## Example program

Program to print star 3 pattern

[File here!](/programs/star-3.c)

```C
//pre-process fetching contents of library stdio.h which contains predefined functions in C
#include <stdio.h>

//default function that is run by C everytime
int main(){
	
	for(int i = 0; i < 5; i++){
		
		for(int j = 5; j >=i; j--){
			printf(" ");
		}

		for(int k = 0; k <= 2*i; k++){ 
			printf("*");
		}	
		
		printf("\n");

	}	
	
	return 0;
}
```

## Example program

Program to check if the number is a palindrome or not

`Palindrome: When reverse of something is equal to that something`

[File here!](/programs/check-palindrome.c)


```C
//default function that is run by C everytime
int main(){
	//predefined function from the library which prints the output given to it
	int num, lastdigit, result = 0;
	printf("enter a number: \n");
	scanf("%d", &num);

	int originalnum = num;

	while(originalnum !=0){ //making that number in reverse
		lastdigit = originalnum%10;

		//concatenate
		result = result*10 + lastdigit; 
		//to make that number in reverse we multiply result with 10 and add remainder to it

		originalnum /= 10;
	}

	if(num == result){
		printf("number is palindrome\n");
	}else{
		printf("number is not palindrome\n");
	}

}
```

## Example program

Program to print fibonacci series

[File here!](/programs/fibonacci.c)

`Fibonacci: When sum of prev two numbers is equal to next number`


```C
#include <stdio.h>

//default function that is run by C everytime
int main(){
	//predefined function from the library which prints the output given to it
	int num, prev, last, sum;

	printf("enter a number\n");
	scanf("%d", &num);

	for(int i=0; i <=num; i++){

		if(i < 2){
			prev = 0;
			last = 1;	
		}
		
		sum = prev + last;

		printf("%d ", sum);

		prev = last;
		last = sum;



	}
	
	return 0;
}
```

# Topic4: Functions

## Introduction

If we want to reuse a functionality again and again anywhere randomly, wrap them into functions
When we want to reuse it we call that function. Eg: printf

## Example

```C
#include <stdio.h>

/* 
function to return the maximum of two numbers supplied to it as arguments
function needs to be defined before its call so that compiler knows
in case the function needs to be defined somewhere else you atleast need to include its declaration 
above the call somewhere 

Declaration in this case
int max(int, int); ->name of the function and the type of arguments it will take

*/
int max(int x, int y){
	
	//function can return a value of expression. Expression can be evaluated and converted to return type
	return (x>y)? x: y;

}

//default function that is run by C everytime
int main(){
	
	int a = 10, b = 20, maximum;
	
	//calling the function with equal number of parameters and also the same type is important
	//in case the type of parameters supplied does not match, there will be type coercion
	maximum = max(a,b); 

	printf("%d\n",maximum);

	return 0;	
}
```

### Note

`A function can return anything but an array or another function. A function is meant to return only one thing and array is a collection of things

The arguments to the function are passed by call by value

C programming language only provides call by value (which means creating a copy)
`

## Swap two variables

```C
void swap(int *, int *); //declaration or prototype

void main(){
	int x = 10,y = 20;

	swap(&x,*y); //address of x and y are sent to function

	printf("after swapping %d %d ", a, b);
}

void swap(int *a, int *b){ //pointer to fetch the value from address 
	*a = *a + *b;
	*b = *a - *b;
	*a = *b - *a;
}
//this is how we can change actual parameters from the function call. Passing the address and accessing it from pointers
This will be call by value only. In this value of address is being passed and pointers point to it.
Still call by value only
```

##Note:

`For javascript developers: The function execution context is created for C as well and local variables are popped of from the stack as they are used.
The division of the memory in OS is as follows

- Stack (execution context) -> grows downwards
- Heap (dynamic memory allocation) -> grows upwards
- SV and GV (local variables and global variables)
- Code
`

## Example

Custom C program to implement a pow function

Logic: number raised to some power is, multiplying that number power number of times. So we can implement a loop

```C
//function to return the maximum of two numbers supplied to it as arguments
int pow(int base,int n){

	int result = 1;

    for(int i = 1; i <= n; i ++){

    	result *= base; //multiplying the base for each iteration with the base itself

    }

    //Note this can be optimized further by decreasing the number of iterations in the loop

    return result;
}

//default function that is run by C everytime
int main(){
	
	int base = 5;
	int n = 3;
	
	int result = pow(base,3); //calling the function

	printf("%d \n", result);

	return 0;	
}
```
### Practice Question

`Implement the above using optimized algo`

# Topic5: Pointers

## Introduction

In C programming language memory is accessed or visualized as one dimensional array, no matter what data structure is there. (visualize memory as one dimensional array)

The size of char, int, long depends on the implementation (platform or OS eg 32 or 64 bit). There it is not true that char is always 1 byte or int is always 2 etc. (most of them has char size 1 but it is not standard)

## Note:

- 32-bit operating system:
It can process 32 bits in parallel

- 64-bit operating system:
It can process 64 bits in parallel


The entity in memory can be accessed either by address or name. By address it can be faster by using addresses.
It is because if you access it by name, name is converted to logical address and logical address is converted to physical address.

Names are generally better readable. That is where pointers come into pictures.

They are used to access value if address is given. And dynamically assigned values that do not have a name use pointers to access them.

*Pointer*: Variable containing address of another variable. The size of pointer depends on platform.
Platforms having 16 bits addresses have pointer size of 16 bits and so on.

## Declaring a pointer

```C
int *p // p is pointer or *p is a variable of type integer`

p = &b //&b contains address of b which is assigned to p. *p will fetch value from that address
//therefore in the above case b and *p both will have the same value

//Note: you cannot get addresses of constants or expressions as they cannot be declared in memory. Only variables or other structures can have address

Address will always be of same size, no matter what is the size of value of it holds.
Address has some arithmetic that is done, so it is always declared as int
```

`Address is like standing at door of a house. When * is there, we enter the house. * is called as dereferencing or indirection operation`

## Example

//For address format specifier is %p. %u is format specifier for unsigned int

```C
//default function that is run by C everytime
int main(){
	
	int x = 5;
	int *y = &x;

	printf("%d\n", x); //will print 5
	printf("%p\n", &x); //will give address of x
	printf("%p\n", y); //will give address of x
	printf("%d\n", *y); //will give value of x
	printf("%p\n", &y); //will give address of y

	return 0;	
}
```

## Pointers and functions

Good example of this is the swap function we did earlier where value of addresses was passed to the function and pointers were used to access the value and modify them

## Pointers and arrays

Whatever you could do with array and suffix, can be done with pointers.

- Byte addressable: every byte will get a new address
- Word addressable: every word will get a new address. If a world is of 2 bits, every two bit has a new address and so on.

`Even though an int may occupy two addresses, whenever address of that int is talked about, always starting address is taken`

## Note:

`In case of array int a[]. Array name A is not a variable but other way of representing the address. No where in the memory name is allocated any space. Therefore array name A is just a mnemonic. So if array A starts from address 100, A is as good as writing 100`

### Address arithmatic

- Since A is nothing but starting address of A. Therefore *A is A[0]

Whenever an integer is added to an array name A or a pointer, the addition will be scaled addition.

Eg: if A represents 100, then A+1 represents next element in the array (irrespective of the size of that value stored in the address)

*Therefore if A is at 100, and each int is occupying 2 bytes, then A+1 is 102*

A+i == A+ (i* size of int in this case). It represents Ith element

A + 3 is the 3rd element starting from A[0] i.e A[3].

*(A+3) will give you value at A[3]. Therefor compilter uses pointer in the background

Therefor A+3 is nothing but address of A[3] i.e &A[3]

```C
int *p
p = &a[0] //p now contains address of array 0th element

p = p + 1 //address of a[1] is now stored in p

p = p + i //address of a[i] is now stored in p

/* 

Compiler knows how many bytes to add when you increment value of p is by the declaration
Therefore int *p, char *p is used in respective scenarios depending on the type on which pointer is used 

*/

//Therefore
*(p + 3) ==  a[3] == p[3] // true

//Above line shows that pointer can be used as array

p + 3 == p[3] == a + 3 == &a[3] //true

//There a[3] holds value and a+3 holds address
```

## Note
`Pointer name is variable and array name is just mneumonic. Whenever we pass an array to a function, we really pass the starting address of the array which is taken by a pointer in the function call. Therefore is array name A is passed to a function, function can use a pointer to get values from the array and do same functions that could be done on an array. Therefore array name and pointers both are same`

Therefore when a is array

- a = a + 1 //not valid
- a++ //not valid
- a = p //not valid

BUT the one below is valid

- p = p + 1
- p++
- p = a


## Pointer Arithmetic OR address Arithmetic

Various operations allowed on pointers

- Assignment of pointers of same type. If two pointers are of same type we can assign them to same type.

```C
int *p, *q; //pointers of same type
p=q; //valid
q=p; //valid

int *p, a[];

p = a; //valid
a = p; //not valid

//if type is not same, typecasting needs to be done

char *c;
int *p;

p = (int *)c; //typecasting can be done if c is not of type void
```

- Adding or subtracting a pointer and an int (as we did in arrays). Addition of float or double or long is not allowed. Also pointer cannot be multiplied to an integer

- Subtracting or comparing two pointers to members of same array. If p and q are two pointers pointing to the same array, then we can compare or subtract them. (if q is ahead of p then q-p will give number of elements between p and q including q). Subtraction is also scaled down. Pointer subtraction is used to see space b/w two pointers. Two pointers cannot be added or divided or left or right shift

- Assigning or comparing to zero. Assigning a value to a pointer is meaningless. Assigning a zero or comparing with a zero only is allowed. Zero is used for error case 


## Character arrays and pointers

Most of the time we deal with character arrays in C programming. Eg printf we pass string constants which is nothing but array of characters.

Eg:

```C
char a[] = "rahul"; //valid way to declare string constant or array of characters
//we can go inside the array in this and modify characters

char *p = "rahul"; //valid way to declare string constant or array of characters
//in this case we cannnot modify anything, just access the value

//Both the array above have not 5 but 6 characters as additional \0 character is there
//Basically in a string constant and array is created in the background always with a \0 character at the end
//Simple array options apply to it
//In case of pointer p will point to starting of the array i.e at 'r' and all rules apply as we discussed about pointers and array above
```

```C
//program to copy one string to another (t to s)
//before this both of these arrays need to be passed to this function. The second empty array should be declared with equal memory
void strcpy(char *s, char *t){
	while(*s++ = *t++) //copy first then increment till \0
}

```

## Array of pointers and multidimensional arrays

Since pointer is a variable, we can declare an array of pointers

```C
//name is an array of pointers to character
char *name[] = {"ritu","rahul"}
//these pointers will have memory somewhere and they will be pointing to other memory locations to these string constants

name //will give address of starting of pointer array
name + 1 // will give address of second pointer in pointer array
*(name + 1)// will give value of that address which is nothing but address of "rahul"
*(name + 1) + 2 //will give address of 'a' in "rahul"
//total space is space taken by each row plus space taken by pointers

//the above can also be implemented as multidimensional array
char array[3][13]; //this will declare an array of 3 rows having 13 characters each
//Note in this case since maximum length is 13, if other rows do not have 13 characters, the space will go wasted. IN the pointer notation there was not waste in memory as each array has right memory

name[1][2] ////will give address of 'a' in "rahul"
//total space taken is space taken by array
```

Therefore in C array of pointers is more popular than multidimensional array

## Multidimensional arrays, pointers and function calls

In C we cannot pass full array at once to any function. It is always element by element. So we just have to pass the starting address of the array

```C
fun(int a[]) 
//a in this case will be considered as pointer to the argument which is the first element or the element to be considered in the array.You may are may not use * in this case
```

Passing a two dimensional array

```C
fun(int a[][6]) //the calling function can send an array with max array size as 6 and the called function 'a' is array of pointers pointing to the actual array passed.By default pointer will point to first row first element address

//above can also be written as
fun(int (*a)[6]) //a is a pointer which points to an integer array of 6 elements
fun(int *a[6]) //a is an array of pointers having 6 elements. The difference is cause of operator precedence
```

## Example:

```C
*p++ //by precendence incrementing the value of p, and then applying * to it
a = *p++ //assigning *p to a and then incrementing p

//llarly other way round for ++p
```

## Note

- *Left associativity*: Whenever two operators of same precedence are present then first take into consideration the one that is present left to the operand
- *Right associativity*: Whenever two operators of same precedence are present then first take into consideration the one that is present right to the operand 


## Example

```C
main(){
	int a[] = {10,20,30,40,50,60}; //a contains 6 elements
	int *p[] = {a,a+1,a+2, a+3, a+4, a+5}; //p is an array of pointers to integers and initialized with the values given
	
	int **pp = p; //pp is a pointer to a pointer to an integer. 
	//If p contains the address 200, then pp will have 200 as its value
	//*pp will be value in p
	//**pp will be value in a
	pp++; //will increment the value of pp and make it point to second address of p
	//subrac
	printf("%d %d %d",pp-p,*pp-a,**pp); //1, 1, 20
	*pp++; //increment pp first and then apply *
	
	printf("%d %d %d",pp-p,*pp-a,**pp); //2, 2, 30
	++*pp; //increment value pointed by pp
	
	printf("%d %d %d",pp-p,*pp-a,**pp); //2, 3, 40
	++**pp; //incrementing the value of a[3]
	
	printf("%d %d %d",pp-p,*pp-a,**pp); 2, 3, 41
}
```

## 'IMPORTANT NOTE or Golden rules for pointers and arrays':

In the above example if value of 3 element in array a was to be found, various ways of doing that

```C
a[3] = *(a+3) = *(p[3]) = **(p+3) = **(pp+3)//all will give the same value

//Therefore golden rule

a[something] //gives value
a + something //gives address

//If 'a' is assigned to a pointer p, then p++ can be done but a++ cannot be done. Remember this rule
//Subtraction b/w pointers is possible only if they are pointing to the same array

//Replace anything with 'a' and rule remains same
```

## Pointers to Functions

Even though function is not a variable C still allows you pointers to point to functions and make a call to function.
This is not widely used.

```C
int sum(int, int);

//generic pointer pointing to such functions
int (*fp)(int, int);
fp = sum //storing address of function in fp

s = sum(5,6)

//is equivalent to

s = (*fp)(5,6); //calling function via pointer

void* (*gp)(void*, void*)
//gp is a pointer to a function that contains two args which are void pointers which returns a void pointer

//typecasting to make it point to sum

gp = (void* (void*,void*))sum; //therefore generic pointer can be pointed to any by typecasting
```

## Some complex declarations

```C

//all have been evaluated using precedence table and associativity. So keep that in mind

char **argv
/*
it is useful in case of command line arguments. argv is a pointer to a pointer to a character
 */

int (* daytab)[13]
/*
daytab is a pointer to an array of 13 integers
*/

int * daytab[13]
/*
daytab is an array of 13 integers which are pointers to integers
*/ 

void *comp()
/*
comp is a function which is return a pointer to void
*/

char(* comp)()
/*
comp is a pointer to a function which returns a character
*/

char(*(*f())[])()
/*
a is a function which returns a pointer to an array of pointers to function which returns a character
*/

char(*(*f[3])())[5]
/*
f is an array of pointers (3 elements) pointing a function returning pointer pointing to array containing characters (5 elements)
*/
```

Topic6: Arrays

Simplest data structure which are random accessed. We can access it randomly because while storing it is stored contiguously. Since size of each element is known we can access any element.

## Note
`Storing is not contiguous and only way to access it is to go through a chain or list`


## One dimensional arrays

Explained above.

`
To access A[2] if array is starting from index 0, you will have to cover 2 elements. If starting is from 100, then you have to conver 100 + 2 elements. In general to access Ith element you have to do 100 + i.
`

`
To access A[2] if array is starting from index 1, you will have to cover 1 elements. If starting is from 100, then you have to conver 100 + 2-1 elements. In general to access Ith element you have to do 100 + i-1 and so on other things can be derived
`

## Two dimensional arrays

A is a two dimensional array with size 3 X 4. It means (horizontal X vertical)

- A has 3 rows
- A has 4 columns

Now to enable random access, even this has to be stored contiguously. Therefore, to save it two-dimensional array is converted to one-dimensional array.

There are two ways

*Row major order*
1) Take each row and put it in memory (elements continous to each other, rows contiguous to rows)

### Example

```C
//starting with index 0
00 01 02 03, 10 11 12 13, 20 21 22 23

//Now whenever element 21 is to be accessed
A[2][1] //cross two rows and 2 elements i.e 2*4 (two rows having 4 elements each) + 1(element in the last row)

//therefore if array was starting with 100
// ((2*4) + 1) + 100
// ((2*4) + 1)*size of each element + 100 //number of words or exact address

//Size of A is M X N then, starting index 0, address of array for 
A[i][j] = ((i*n) + (j))*size of each element + BASE

// llarly for index 1 can be done as explained aboved
((i-1)*n + j-1)*size + BASE
```

*Column major order*

```C
00 10 20, 01 11 21, 02 12 22, 03 13 23

//Now for A[2][1]

A[2][1] = ((1*3) (1 column each having 3 elements) + 2 (total elements to be crossed in that column))*2 + 100(base address assume)

//Therefore in general A of size MXN, index 0

A[i][j] = ((j*m)+i)*size + BASE

//If index starts from 1 subtract 1 as done above
```C

## Binary addressing of two dimensional arrays

- Row major (row column size) in binary written as is
- Column major (column row size) in binary written as is

## Example program

Determine if two arrays have an element in common

```C
int isCommon(int a[], int b[], int n, int m){ //sizes are sent as we need the end of the array
		
	int i, j;
	
	for(i = 0; i<n; i++){
		for(j=0; j<m; j++){
			if(a[i]==b[j]){
				return 1; //will return from the function
			}
		}
	}

	return 0; // return 0 if full for loop executes

}
```


#Topic7: Strings

There are a lot of built in functions for C in string.h

```C
strcat(s,t) // concatenate string t to the end of string s. It returns char * (pointer to starting address of s)
strncat(s,t) //concatenate n characters of string t to the end to string s. It returns char * (pointer to starting address of s)
strcmp(s,t) // return negative, zero or positive for s<t, s==t or s>t
//this will basically do subtraction of characters (ascii values are taken and subtracted) and string is compared
//negative or positive is the difference that comes out
strncmp(s,t,n) //same as strcmp but only in first n characters
strcpy(s,t) //copy t to s. t will be copied to s starting from beginning so chars in s may be replaced till the length of t. It will return s (that is starting address of array)
strncpy(s,t,n) //copy at most n characters of t to s
strlen(s) //return length of s
strchr(s,c) //return Pointer to first c in S or NULL if not present
strrchr(s,c) //return the Pointer to the last occurence of C and return NULL if not present
```
 
## Programs

[File here!](/programs/string-functions.c)


### strcpy()

```C
//str copy function self made
char *strcpynew(char *d, char *s){
  char *saved = d;
  while ((*d++ = *s++) != '\0'); //s will be stored in d and this expression will return d which will be compared always with RHS
   
  return saved; //returning starting address of s1
}
```

### strcat()

```C
char *strcatnew(char *d, char *s){

  char *saved = d;

  while(*d != '\0'){
    *d++; //finding end of d string;
  }

  while((*d++ = *s++) != '\0');
  // *d = 0; 
  return saved;

}
```

### strcmp()

```C
//returns ascii value after subtracting or return 0. ASCII value of \0 is 0
int *strcmpnew(char *d, char *s){

  while((*d == *s)){
    if(*s == '\0'){
      return 0;  
    }
    *d++;
    *s++;
  }

  return *d - *s;

}
```

### strlen

```C
int strlennew(char *s){

  int total; //to increase range we can take unsigned long long int

  while(*s != 0){
    total++;
  }
  
  return total;
}
```

## NOTE:

`empty string needs to be declared as per size of the input passed to do the operations`

`#define anyvalue = somevalue will assign somevalue to anyvalue before the compilation phase. So at compilation phase anyvalue wont be present at all at it will be replaced with somevalue`

### C program to remove all the occurences of character C in the string

[File here!](/programs/remove-char.c)

```C
/* Program to remove char c from the string */

//pre-process fetching contents of library stdio.h which contains predefined functions in C
#include <stdio.h>

void squeeze(char s[], int c){

	int i, j;

	for(i=j=0; s[i] != '\0'; i++){

		if(s[i] != c){ //it will replace that letter with the next letter and the increment j
			s[j++] = s[i];
		}

	}

	s[j] = '\0';

	printf("%s\n", s);
}
//default function that is run by C everytime
int main(){

	char s[] = "rachulc";

	squeeze(s, 'c');
	
}
```

#Topic8: Storage Classes

- *register*: we are telling the compiler to store variable in a register eg: register int i. Registers do not have addresses
- *external variable*: variable declared outside main() will be stored in the data section only 
- *static*: will store the variable in the data section and will be accessed from this data section everytime and not from the activation record in the stack

## Note

`Data section contains global(external variables declared outside main()) variables and static variables`


## Example:

```C
int main(){
	register int i = 10; //this is a storage class

	int *a = &i;

	printf("%d", *a); //will give error or warning as register do not have addresses

	return 0
}

```

```C
int main(){
	int i = 10;
	register int *a = &i; //store the variable a in register
	printf("%d", *a); //this will print address of other variable because address in this case is a value from another variable
}
```

```C
int i = 10;
register static int i = 10; //we cannot ask compiler to store a variable at two places. so it will give compiler error
printf("%d",i);
return 0;

```

### Example:

Counting the number of times the function was called

```C

int countFunctionCall(void){
		
		static int count = 0;
		return ++count; 

} //the activation record is popped off each time the function is called, so in the print statement only 1 will be printed as only for that activation record it will return the value of count. 
// To fix this we will declare count as static variable
// this static variable will be stored in the data section
int main(){
	countFunctionCall();
	countFunctionCall();
	countFunctionCall();

	printf("%d time function is called", countFunctionCall());

	return 0;
}

```

## Note:

`If a function does not find the variable in its own activation record(execution context) it will go to the outer environment to search for that variable (same as javascript). Therefore local and variable is same as javascript`

`Variable declared inside a function has a lifetime equal to the lifetime of activation record of the function`


## Storage Management

We need to declare variables dynamically and free memory when it has been used. To do that we need to manage out storage.

For Local variables and global variables we need not do anything.

We can allocate space by using the following:

- *malloc*: it will allocate size passed to it in heap and return pointer to the starting address of the space allocated. if the heap is out of space it will return NULL

```C
int *i;
i = (int *) malloc(sizeof(int)) //sizeof int lets say is 2 so it will allocate 2 bytes and pointer is typecasted to int
i++ // will increment address by 2 as we have used integer pointer. character pointer would have incremented it by 1 as pointer arithmetic is scaled
```

- *calloc*: Simillar to malloc but also initializes all elements to zero. You can pass number of elements to be initialized and allocated space along with the size of each element. In malloc garbage values are present by default if not initialized explicitly. Both malloc and calloc gives space in a contiguous manner only

- *realloc*: If already some space is allocated (lets say 10 bytes) and that has been used (data is filled) and we want to extend it to 20 bytes, then realloc is used. Pointer to the starting address of the space is sent along with the size with which we want it to be extended. If initally its 10 and we want to grow it to 20, pass 20. If the space of additional 10 bytes is not present contiguously, it will find somewhere else space of 20 bytes and copy all the information from previous space without any loss of data

- *free*: used to free up the space once used. 

These functions are defined in *stdlib.h*

```C
//size_t is any datatype which is unsigned and whose size is atleast 16 bits. 
//malloc(10): we are sending a number (lets say 10) to malloc, it will allocate a size of 10 bytes in the heap and will return the pointer of the starting address of the space. Any datatype pointer can be returned.
void *malloc (size_t n)

//similar to malloc but the size is given in a different way. first parameter is the number of elements to be stored, second is the size of each element
//eg: calloc(2,2): store 2 elements each of size 2 (4 bytes total)
//It will also return pointer to the starting address of space allocated. It will additionally initialize all the elements to zero
void *calloc (size_t n, size_t size)

//If already some space is allocated (lets say 10 bytes) and that has been used (data is filled) and we want to extend it to 20 bytes, then realloc is used
//pointer to the starting address of the space is sent along with the size with which we want it to be extended. If initally its 10 and we want to grow it to 20, pass 20. If the space of additional 10 bytes is not present contiguously, it will find somewhere else space of 20 bytes and copy all the information from previous space without any loss of data
void *realloc (void *ptr, size_t size). It will return NULL if no space found

//used to free up the space once done using it.
//Pass the pointer to the starting address of space allocated.
void free (void *ptr)
```

## Note

`Both malloc and calloc give space in contiguous manner only in the heap. If the space present is not contiguous, it wont allocate anything`

`Free knows how much space to free because while using malloc and calloc, if you allocate 10 bytes, system allocates 11 bytes, the extra byte is used to save number of bytes allocated for this function call. Free will read that info and free those bytes`

`If space is not freed up, it wont be reusable as it wont be allocated, that is called memory leak`


#Topic9: Structures and Unions

## Introduction to structures

Sometimes we want group elements. Eg: grouping integer, for that we use arrays. But there may be scenarios when elements are not of the same type, then we use structures.

Eg: storing employee record (age, salary, address etc.)

## Example

```C
struct{ //declaration for a structure
	int i; //declarations inside the structure
	char c;
} x, y, z; //three structures will be created x y and z with the same structure having an integer i and char c

//Therefore, we can create it in continuous manner separated by commas 

//Members can be accessed using dot

x.i = 10;
x.c = 'a'

//dot is known as the member operator. This is simillar to javascript object dot

//defining a structure containing a structure
struct{
	struct{
		int i;
		char c;
	}
}

//Another way is to name the structure made eg:

struct ex{ //ex here is called tag. Later if we want to declare multiple structures we can use ex
	int i;
	char c;
}; //this is the structure blueprint and no memory is allocated to any variable as of now

//later this can be done

struct ex x,y,z; //this will declare three structure with same body and now memory will be allocated

//Declaring nested structures with tag
struct ex1{
	struct ex a; //members of a structure can be other structures as well. Structure a having body of ex and member of new struct ex1
}

//Initializing the structure

struct ex x = {5,'a'}; //similar to javascript objects but here w/o keys

struct ex1{
	struct ex a; 
	struct ex b;
}; //blue print only

//now we can use it as

struct ex1 t; //then a structure will be created with name t containing two structures a and b which will contain both i and c.

//Accessing members can be something like this
t.a.i = 10 //similar to javascript objects

//Any levels of nesting can be defined
```

## Examples on structures, arrays and pointers

```C
struct node{
	int i;
	int j;
};
struct node a, *p; //a is a structure and p is a pointer of type struct 
p = &a;

/* 
In the above code, p holds the address of a. To access elements of a we can either do
a.i OR
(*p).i this is equivalent to p->i
Just to make the job of accessing members using pointer easier, the above symbol of right arrow was introduced
*/
```

## Note:

`Using a pointer to access the members of a structure is very important in C. Most of the times strcutures will be created dynamically using malloc etc. which returns a pointer to the starting address of space allocated. So understanding how pointers can be used to access members of a structure is important`

`Structures can be passed to a function as well as returned from a function`

```C
struct node fun(struct node n1, struct node n2)// just like javascript we can pass objects to functions
// the above funtion fun take two arguments as structures of type node and returns a struct of type node
// When this function is called with arguments, the entire structure is passed from actual arguments to formal arguments. If structure is heavy, this function call can be costly. Even when returning structure and assigning it to another structure, it will be copied, so take care of the size and the kind of operation done. Therefore dont send entire structure, send pointers to it (generally recommended)
```

## Main example explained

```C
struct node{
	int i;
	int *c;
}; //blue print for the structure node having one member as integer and other as pointer to an integer

struct node a[2], *p; //a is an array of two elements and both of them are of type struct node
//p is a pointer to a structure of type node

int b[2] = {30, 40}; //array of two integers

p = &a[0]; //p now has address of a[0] assume it to be 100
a[0].i = 10; a[1].i = 20; //initializing values of both the elements. Two operators are there. Both have same precendence but they are left to right associative so [] executes before .

a[0].c = b; //The pointer c has address of b as b is an array

//Explanation of operations if taken one by one (only if that was executed and other lines were not there)

++p -> i;
// the arrow has higher precedence in the table ++ is unary which comes second.
// therefore ++ (p->i) //it will get i from structure and increment value of i

x = (++p) -> i;
//Now () and -> have same precedence but they are left to right associative. Moreover this is preincrement. So even if brackets were not there value needs to be incremented.
//now p was earlier pointing to 100, now it points to 104 (scaled arithmetic)
//now p will get value of i from 104 and x will be assigned that value

x = (p++) -> i;
//This is post increment so brackets cannot do anything.
//so first p->i will be performed. X will get i's value and the value of p will be incremented from 100 to 104

x = *p -> c; //can be written as x = (*(p->c))
//there p->c will give address c is holding, then * will give value of what is in the address that c is holding, that is value of array b[0]
//this value will be assigned to x

x = *p->c++; //this is post increment case
//there are 4 operators in this
// highest precedence is given to ->, then *, then ++ as it is post increment
//p -> c will get address that c is holding *p will get value which is b[0]
// x will get get value 30 and then, c will be incremented that is now it points to b[1]

x = (*p->c)++;
// post increment case again
//p->c will be evaluated, and * of it will get b[0]
//this value will be assigned to x and then b[0] will be incremented as it is (*p->c)


x = *p++->c;
//this is also a post increment case
//p-> c will be executed. applying * on it will get b[0] which will be assigned to x
// after assignment p will be incremented, that is from 100 to 104

```

## Note

`Always see where ++ or -- is applied to. The entity that it is placed next to should be incremented or decremented. The entity can be a single variable or whole group (whole group needs to be in bracket to be considered as a single entity). I is always good to break the code into parts in such cases`


## Self referencial structures

reference means pointers. If a structure is pointing to structure of same type it is called self referencial.

Eg:

```C
struct ex{
	int i;
	char *c;
}

struct ex abc; //structure will be created with name abc with two elements integer i and a pointer c to character
// Initial value of pointer will be garbage value. If this pointer is used without assigning it to any value, it may lead to segmentation fault (trying to access memory element which is not present in your own address space)/

//Now if we make this char *c a pointer which points to structure of type ex as:

struct ex{
	int i;
	struct ex *link;
}
//this means that *link is a pointer to a structure of type ex which is nothing but same structure. This is called self referencial structure
```

### Why is it useful

- creating linked list of objects: two structures can be there in linkedlist of same type and pointer in one can point to the other

- In trees: In case we have a tree with left and right pointer, the pointers should point to another structure of same type of make it a tree

There are many more examples like Graphs

## Note

`Segmentation error: When trying to access a memory element that is not present in our own address space`


## Malloc

Practical examples of creation of data structures in C dynamically

```C
//declaration

void *malloc(int);
//create size of 10 bytes and return the pointer to that space allocated

//It is not advisable to call malloc with a number like this because int size may vary with platforms so better to use size of everytime.

int *p = (int *)malloc(sizeof(int)); //correct way
//to free this memory
free(p);

```

## Note

'Whenever malloc is called, it makes a system call to allocate some memory to you. If you as for x byes it will take more than x from the system call and cut out x from the memory it has received, so next time you ask for more memory it does not make an additional system call and try allocate memory that only it has available as system calls can be costly'


`Therefore malloc might not always get contiguous blocks of memory from OS as sometimes user may call system call directly and sometimes malloc may be called. So memory management by malloc is a bit complex as it has to manage holes (additional spaces created cos of memory allocation and freeing up space) as well as non-contiguous memories that are received from the system.`

`Therefore it will create a linked list. Each linkedlist will mention size it has and pointer to the next when. When you request space malloc will scan this linked list everytime and allocate space. This process is called first fit`

`Most frequest usage of malloc is with structures`


```C
struct node{
	int i;
	struct node *l;
}

struct node *p = (struct node *)malloc(sizeof(struct node));
//whatever is returned by malloc will by typecasted and allocated to a pointer of same type as structure

p->i//to access members and so on
```

# Topic10: Input and Output

## Formatted output - printf

- we can pass any number of arguments to printf. It depends on the format string (contains format and conversion specifiers)

```C
int printf(char *format, arg1, arg2, ....); 
this printf will return an int. Generally it returns number of characters it printed
Therefore this value can be captured also.

prinf("%d", printf(char *format, arg1, arg2, ....));
//there the outside printf will print whatever inner printf will return
````

## Inside format string

There can be any number of format or conversion specifiers in a format string

```C
"This is %d", a //In this case a can be converted to a number
//This format specifier will specify how the input should be printed
```

## Formatted input - scanf

```C
int scanf(char *format, any number of arguments);
//the above function will return an integer
//whenever the user will enter the input how to interpret it and where to save it will be decided by the format string

int day, month, year;

scanf("%d %d %d", &day, &month, &year);
//whenever user has entered the input take first part and interpret it as decimal and store it in the address specified by that variable. Therefore argument list should always be addresses or pointers

//We pass addresses to scanf because, variables might be present only in a functions activation record. scanf //may be outside that. Therefore it has no access to variables but has got access to the addresses of those variables.


//scanf returns the number of elements into which it has successfully stored the data

int sscanf(char *string, char *format, arg1, arg2,....);
            //10 20 30.    %d %d %d, 
            //this will save 10 in decimal format in arg1 and so on. will return the number of arguments successfully stored

```

## Example

Count number of set bits in X

Logic: keep right shifting and check each bit by using AND with 1. The one that gives 1 as output increment count

```C
int bitCount(usigned X){
	int b;

	for(b-0; X!=0; X>>=1){ //right shifting each time by 1. This loop will stop when X is zero (that is last bit even has fallen off the boundary)
		if(X & 1){ //AND with 1 and check if this is not equal to zero
			b++; //increment if its 1
		}
	}

	return b; //returning total number of set bits present
}
```

# Topic11: File Input/Output

Real world input and output should always come and go from a file

## File handling in C

```C

FILE *fp;
//structure provide by C (FILE). This is present in <stdio.h>
//declare the pointer to that structure (called fp here). fp is a pointer to FILE structure

//open the file to use it now for any purpose(CRUD)
FILE *fopen(char *name, char *mode);
//fopen is a function. Takes the name(path) of the file to open and mode in which it is to be open
//mode can be: reading, writing, appending
//you cannot read from a file which does not exist. Therefore it will return NULL
//If you open a file for writing, all info from file will be deleted and will have to start from scatch
//use appending if you want to just append
//if file is opened for writing which does not exist, new file will be created and pointer will point to it

int fclose(FILE *fp);
//close a file once done with operations.
//closing a file is important to free the resources allocated to it to process it
//eg buffers will be allocated in the heap section of the process to operate on file
//fclose will give resources and they will be freed
//this function will return positive if successfully file is closed, negative if not closed

/*
Reasons to close a file:

1. If we dont close the file we will not be able to reuse the pointer as the relationship developed b/w file opened and the pointer will not go away

2. you dont loose any data while using fclose

3. When the program is terminated fclose is automatically called
*/
```

```C
//various functions provided by c to operate on files

fopen()
//open the file

fclose()
//

getc()
//reads a character from the file

putc()
//puts a character in the file

fscanf()
//reads a set of data from the file

fprintf()
//writes a set of data to a file

getw()
//reads an integer from a file

putw()
//writes an integer to a file

fseek()
//set the position to desired point. Moving the cursor across a file

ftell()
//gives current position in the file

rewind()
//sets the position to the beginning point

gets() and puts()
//to read unformatted data. The above functions are used to read formatted data
//scanf does not read the spaces, it will read only until it finds a space.
//if you want scanf to read it then use gets()

//gets() takes character pointer to a string. It will keep reading until it finds EOF or terminating new line

getchar() and putchar()
//used to get and print data respectively from the user onto the string. It will read only one character and output one character

int main(){

	int c;
	printf("enter a string\n");
		
	c =getchar();
	
	putchar(c);	//outputs the first character even if you enter a string

}

```

## Example

getc and putc

```C
#include <stdio.h> //file functions are in this

int main(){

	FILE *fp1, *fp2;
	char c;
	fp1 = fopen("file.txt","w");

	if(fp1 == NULL){
		printf("file content does not exist\n");
	}

	int a[5] = {'n','a','h','u','i'};	
	
	for(int i = 0; i<5;i++){
		putc(a[i], fp1);
	}

	fclose(fp1);	

	fp2 = fopen("file.txt","r");

	if(fp2 == NULL){
		printf("file content does not exist\n");
	}

	while((c = getc(fp2)) != EOF){
		printf("%c", c);
	}

	printf("\n");
	
}
```

## Example

fscanf

```C
#include <stdio.h> //file functions are in this

int main(){

	FILE *fp;
	char str1[5]; int num;
	
	fp = fopen("file.txt","r");

	if(fp == NULL){
		printf("file could not be opened\n");
	}	

	fscanf(fp, "%s %d", str1, str2, &num);

	printf("this is the num value %d\n", num);
	printf("%s\n", str1);
	printf("%s\n", str2);
	
}
//Similarly fprintf works, it prints data onto a file (useful in case of making debug files)
```


## Example

```C

#include <stdio.h>

void main(){
	FILE *fp;
	int len;

	fp = fopen("file.txt", "r");

	if(fp == NULL){ //this validation should always be done whenever dealing with files
		printf("error opening file")
	} //otherwise there may be errors

	fseek(fp, 0, SEEK_END); //SEEK_END is an integer constant (assume its defined by #define as 3)
	//now this means go to end of it and dont move. Explained in next code set

	len = ftell(fp); //ftell will return current position, thereby giving length of the file in this case

	fclose(fp);
	//closing the file

	printf("Total size of file text = %d bytes\n", len); //will print 4

}

```

## IMPORTANT CONSTANTS

```C
/*
purpose of constants

1) SEEK_SET // Start from beginning of file (is set as 0)
2) SEEK_CUR // we want to start from current position in the file (is set as 1)
3) SEEK_END //start from end of the file (is set as 2)

//to increase the readability of the program we use these constants

//Example
fseek(fp,2,SEEK_SET) //this will start from starting of the file and move two characters to the right

fseek(fp,1,SEEK_CUR) //this will move one position to right from current position

//this is useful as we may skip some characters everytime in our program

fseek(fp,-1,2) //will move one character to the left from end of file (EOF character)

//positive value: move to right
//negative value: move to left

//Syntax of fseek
int fseek(FILE *Stream, long int offset, int whence);
//pointer to file structure, bytes to which read write head is to be moved, where to start from
// it will return a zero or non-zero. IF zero successful, if nonzero something wrong has occured and function failed
*/

long int ftell(FILE *stream) //takes pointer to FILE as input and returns long int
//it will return current position in the file you are standing at. In case error is there it returns -1
```

## gets() and puts()

```C

char* gets(char *s) 
//function reads a line from stdin (standard input) into the buffer(string in this case) pointer to by S (string) until either a terminating new line or EOF
//it will return s itself. In case there is some error it returns NULL

int puts(char *s) //it will wrtite the string S and a trailing newline to stdout (standard output)
//it will write whatever is present in s as output and append \n to it. Will return positive number if successful else will return -1

```

```C
#include <stdio.h>

void main(){
	char str[100];
	printf("enter a string \n"); //entered rahul arora
	// \n will make sure it stops reading when there is a newline

	gets(str); //read whatever user entered
	puts(str); //whatever was read will be printed
}


```

## Relationship b/w putc(), getc(), putchar() and getchar()

putc() and getc() takes arguments as file pointers whereas getchar() will read from keyboard by default


```C
int getc(FILE *fp);
int putc(int c, FILE (fp)); //c is the string that holds the data
//even though c will be a char it will be converted to integer and placed as argument
```

In an operating system we have three strings available to us

```C
stdin //related to keyboard
stdout //related to output
stderr

//hence we can also use 
getc(stdin)
putc(ch, stdout) //this will put character into the file

```

## File reading and writing using putc() and getc()

```C
#include <stdio.h>

void main{
	FILE *fp;
	char ch;
	fp = fopen("text.txt",'w');//opening file in write mode

	printf("enter the data");

	while((ch = getchar()) != EOF){ //enter ctrl c to denote EOF
		putc(ch, fp); //put character entered into the file
	}

	fclose(fp);

	fp = fopen("one.txt", 'r');

	while((ch = getc(fp)) ! = EOF){
		printf("%s", ch); //print whatever you can read from the file
	}

	fclose(fp);
}

```

## Note

- `getc` and `getchar` both are same just that getc takes a file pointer and to get characters one by one from the file. getchar on the other hand takes characters from the keyboard. getc can be used to take characters from the keyboard by doing `getc(stdin)`

- 'putc' and `putchar` both are same just that putc prints to the file and putchar prints to the screen. putc can be used to print to the screen by using `putc(stdout)

- `putc` takes first argument as character to be printed to the file and second argument as the file pointer

- Always ASCII values are stored and get from the file and appropriate conversions are done to display it properly to the user



## Example

C program to read a stream of characters

Generally in a stream we dont know how many chars we are going to read. If the requirement was known we could have used an array of defined size to save the data and then print it, but here it is unknown so we will dynamically allocate space. 

```C
#include <stdio.h> //file functions are in this
#include <stdlib.h>
#define DEFAULT_SIZE 100; // constant whose value is 100

int resize(char *p, int count);

char *resize(char *p, int capacity){
	return realloc(p, (capacity + DEFAULT_SIZE*sizeof(char)));
}

int main(){

	int count = 0; //variable to count the number of characters read

	int capacity = DEFAULT_SIZE;

	char *input; //variable input as a pointer to a character

	char ch;

	input = (char*)malloc(DEFAULT_SIZE*sizeof(char)); //will create 100 bytes of memory

	//validation required

	//EOF is denoted by ctrl+d in linux
	while((ch = getchar()) ! = EOF ){
		if(count == capacity){ //in case our capacity is over we take additon 100 bytes from relloc

			input = resize(input, capacity); //we resize if we run out of memory everytime by 100 bytes
			//validation required
			capacity = capacity + DEFAULT_SIZE; //updating capacity to new memory allocated

		}

		input[count++] = ch; //we store value of ch in space allocated to us
	}
	//check before putting if memory is availble to put NULL otherwise resize
	input[count] = NULL;

	puts(input); //print whatever is there is pointed by input
	
}
```

## Example

C program to count input lines

```C
void main(){
	int linecount,c ;

	while((c=getchar())!=EOF){
		if(c== '\n'){ //increment whenever newline character is there
			++linecount;
		}
	}

	printf("%d", linecount); //print answer
}
```	

## Example

C program using fscanf(), fprintf()

```C
#include <stdio.h> //file functions are in this

struct emp{
	char name[10];
	int age;
};

void main(){

	struct emp e;
	FILE *p, *q;

	p = fpen("test.txt", "a"); //append will make the cursor to be at the end of file
	q = fpen("test.txt","r"); //when we open it in reading, it will assume that we will read from beginning

	//this will work as these are two different pointers

	printf("enter the name and age");

	scanf("%s %d", &e.name, &e.age);

	fprintf(p, "%s %d", e.name, e.age); //printed in the file whatever we read

	fclose(p); //closing all the buffers related to p to finish relationship b/w p and file

	do{ //we started with do while as we were sure that there is atleast one value in the file
		fscanf(q, "%s %d", e.name, &e.age) //read from beginning and store it in respective variable mentioned
		prinf("%s %d", e.name, e.age);
	}while(!feof(q)); //do it till we reach EOF
}
```

## feof(p)

`this function will return non-zero value if there is end of file pointed by p. will return a zero value if end of file is not there`

## size_t

- is a standard in C which is used to denote unsigned lengths. Because length min is anyway zero which can never be signed. Therefore mostly when dealing with sizes or length, they are typecasted or referred as size_t datatype. Eg: size_t i instead of int i etc.
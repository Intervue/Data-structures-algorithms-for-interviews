/*
Program to implement Huffman encoding

METHOD:
In case of huffman encoding the condition is that elements should not be uniformly distributed.
There the element that is repeating most number of times, we represent it using least number of bits
and the element that is repeating least number of times, we use max bits. Therefore in this case we can
represent this thing using tree.
The algo is to make a min heap out of the given elements (as we are required to find min each time) and also
insertion is to be done (therefore sorting is not used).

Now each time min is extracted twice. A new node is made which will contain the value equal to the sum
of the two mins (freq). The left node smaller one will be the left child of the newly created node and the
bigger of the two will be the right child. Like this we keep repeating this process for n-1 elements
to build the tree.
Now we can fix one pattern that is making left edge of each tree as 0 and right as 1 or vice versa down
to the bottom and then we traverse for each node to generate the huffman codes.

Note that in this each node will have its own unique pattern which wont be present in any of the nodes.
Also note that node which is smaller has to be on the left and each time there is a possibility that not 
always there will be a tree, many a times there can be forests also and then you combine two search forests.
This may happen because least two values will be different from the current sequence

Time complexity: O(nlogn) //finding min n times (twice) and inserting the sum back to the tree O(logn) which
is done n-1 times again
Space complexity: O(n) //tree
*/
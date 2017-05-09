/*
Find lowest common ancestor of given two nodes in a binary search tree

Where the path to the parent for two nodes meet for the first time, that is the lowest common ancestor

//METHOD1
Since this is a binary search tree, we can search for two elements given say (10,20) and we can store the path of it
that is the elements in the way in an array for both the searches. Then we can compare both the arrays and see 
where they are common at the max index. That index value is the least common incestor.
Time complexity: O(h) for search which in worst case can be O(n)
Space complexoty: O(h) for storing the path which in worst case can be O(n)


//METHOD2
We can do a simultaneous search for this. There is no need to store the path in an array in this case. If we see the
search splitting at a node, that is one element is smaller and one is greater than the node value, then that node
is the lowest common ancestor. If we see one value to be found as the node value itself, and the other node is
either greater or smaller than the node, then that node in this case also is the lowest common ancestor.
Time complexity: O(h) or O(n) //worst case
Space complexity: O(1) //if we do not do it using recursion else O(n)

Variation of this prob can be that, children have backlinks to the parent, then find the lowest common ancestor.
In this case we can apply a method similar to the linked list where two linkedlist were getting merged into a single 
one and we had to find the merging point. Therefore, in this case, we can see the height of both the nodes given from
the root and we can traverse from child to parent level by level alternatively and see where they meet. Both the nodes,
need to be brought at the same level for this. Therefore finding height is important. But there wont be any difference
to the time or space complexity given.
*/


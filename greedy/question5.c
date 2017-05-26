/*
Program for PRIMS algorithm

PRIMS algo is used to find the min cost spanning tree for a weighted graph given cost matrix and set of 
edges

METHOD1:
Here we first find the min edge from the set of edges given and from the cost matrix we can see that the
edge is between which two vertices. Those vertices are then stored in an array t. We will make a tree out
of it
Then we will make another array near where we will calculate for all the vertices of the graph if they are
nearer to edge that connects to nodes (they will be nearer to only one of them), The one to which they will
be nearer will be written in the array.
Now we will see for which combination given in the near array the cost is minimum, the one for which it is
minimum will be pushed to array t and then near array will be updated for the newly added node.
This way we keep on complete until the array t is full and all values in near array are zero.
Note: we will keep making the values zero once the nodes corresponding to them are already a part of the tree

Time complexity: O(n^2) //as for each node in the near array we need to compute its cost compared to the 
remaining nodes where n is the number of vertices

METHOD2:
Using heap.

Google and code this algorithm
*/
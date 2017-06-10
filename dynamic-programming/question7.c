/*
All pair shortest path algorithm

In this algorithm every vertex is a node and a destination, so we need find the shortest path from a 
vertex to every other node.

Therefore we can apply Dijkstra algorithm (kind of greedy algo only) on each vertex.
For one vertex (single source) time complexity was O(Elogv) therefore for all it will be
O(VElogv) which for dense graphs is equal to O(v^3 logv).
Also if we apply bellman ford algorithm for -ve cycle it is O(VE) which for every vetex is
O(V^2 E) which for densse graphs is O(V^4).
Both the algos are expensive, so we will try to apply DP now.

Floyd-warshall algorithm.
Here we relax one node at a time one by one and make matrices corresponding to that node. We then use
the recently computed matrix to further optimize it by relaxing the other node. Keep repeating this
exercise until all the nodes are relaxed and n such matrices are made. The last matrix is the final
answer.

The analogy behind this is cost from 1 to 2 can be from 1 to 2 or 1 to 3 to 2 or 1 to 3 to 4 to 2.
Therefore whichever is minimum we have to take that and every node has to be a source and a destination
for which computation has to be done. Hence this method is applied

Time complexity: Since n times n^2 sub problems are solved. Total sub problems are n^3 and time to solve
one is constant. Hence time complexity is O(n^3)

Space complexity: O(n^3), can be optimized further if two matrices are used and values are overriden for
the next operation once done

Logic: At any point 1 to 2 can be achieved either by going directly or from some other edge. Similarly
2 to 3 and all other combinations. Hence min(directly, relax some other) is always taken into 
consideration

*/
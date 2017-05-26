/*
Program for DIJKSTRA algorithm

In this the source is initialized to zero and rest of the nodes are given value infinity
, then min heap is made. From the min heap min is extracted and decrease key operation is applied
for the node which is nearest to the source (that is with min edge weight). Now its value is decreased
from infinity to a particular value. This is the decrease key operation. Like this each time decrease key
is applied and each time every outgoing edge is relaxed (decrease key is applied).
The nodes that are already relaxed for that an array is maintained so that we do not relax them again.
Like this we will get the min values for each node from the source.

Note: If the graph is undirected, then then every edge incident on the node must be relaxed rather than
just the outgoing edges

Time complexity: O(Elogv) + O(VlogV)

Dijsktra algo cannot be applied to graphs having -ve weight edges
*/
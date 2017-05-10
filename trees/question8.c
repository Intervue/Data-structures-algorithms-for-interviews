/*
Find the diameter of the given binary tree

Diameter of the binary tree is the max distance between any two nodes.

METHOD:
Using recursion we can find the height of the LST and the RST at each node. We can maintain a global
variable for diameter which can be updated if the new computed values is greater than the existing value.

Time complexity: O(n)
Space complexity: O(n)
*/
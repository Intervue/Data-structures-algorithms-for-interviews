/*
Convert a given binary search tree into balanced binary tree

METHOD1:
Build the tree from scratch by doing the traversal of the BST and balance the tree when needed
Time complexity: O(nlogn) //n elements worst case at logn level comparison and balancing may be required
Space complexity: O(h) //recursion, worst case can be O(n)

METHOD2:
Build a sorted array by doing inorder traversal of BST. Then apply the method2 discussed in question21, where
middle element of the array was picked recursively and made the root everytime.
Time complexity: O(n)
Space complexity: O(n) //recursion
*/
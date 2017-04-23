/*
Convert BST to max heap

METHOD1:
Since BST is generally not stored in the array, so we cannot use the data structure to convert directly
into the max heap as we did in min to max heap or vice versa conversion. Therefore we do a INORDER traversal
of BST. It will give us numbers in ascending order. Now reversing the array will be descending order which is
nothing but a MAX HEAP
Time complexity: O(n)
Space complexity: O(1)

Note in the method above we could have simply done reverse INORDER TRAVERSAL in order to avoid reversing the 
array. In that we traverse the RST print and then traverse LST 
*/
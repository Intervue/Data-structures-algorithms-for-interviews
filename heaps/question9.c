/*
Print out all integers in the form of a^3+b^3 where a and b are integers between 0 and N in sorted order

METHOD1:
Here all integers that lie between 0 and N will, combinations of those will be made with each other and
a3+b3 will be computed for each and presented in a sorted order. Imagine it has a matrix lets say the
range is between 0 to 3, then combinations are 00,01,02,03,10,11,12,13 and so on. Therefore 0^3+0^3 and so
on is computed and each time lets say value is in a two dimensional array. Now the entire column of 
the array is picked and a min heap is made out of it. Each time min is deleted and new element from the
row in serial order is inserted and minified. This way we will get all elements in sorted order
Time complexity: O(n^2)logn //total elements are n^2 inserted and deleting from the min heap takes logn
time.
Space complexity: O(n) to store n elements in a heap. matrix wont be taken into consideration because it
will not be a matrix, its just for understanding purposes. In actual implementation everything can be done
on runtime

*/
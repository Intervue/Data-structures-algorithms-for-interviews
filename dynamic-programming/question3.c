/*
Multistage graph dynamic programming algorithm

Multi-stage graph:
In this graph there is an edge between stage 1 to stage2 but there is not edge between vertices
present at the same stage. The vertices in each stage are present in the same line, and we need
to find the shortest path from source to destination given.

METHOD:
Normal approach can be 
1) Using Dijkstra algorithm: This is used to find distance from source to every other node and its
time complexity was Elogv, with dynamic it can be done in a better way
2) Greedy: Greedy cannot be applied because greedy will always take least edge at start into
consideration, hence, it wont be a good method as it may not give the correct answer.
3) Dynamic: Here we take min of cost of all the edges from a particular node. On making the tree
we see that there is an optimal substructure and repeating sub problems. Here in recursion there will
be a stopping condition where we are at a stage which is one less than the final stage where we will
be putting in final values.
Now, we start evaluating from the last stage. Vertices are numbered in the increasing order such that
each vertex in a stage has a lesser number than every vertex in its next stage. Lets say there are 8 
vertices. 
min(n) = min(all the optional from n to greater than n) + T(value greater than n)
Eg: min of 5 will be min{(5,6) + T(6),(5,7} + T(7), (5,8) + T(8)} and so on. If there is no edge
between any two vertices numbered, it will be taken as inifinity. There we starting evaluating from
8 in this case and go till 1. T(1) will the final answer (least distance from source to destination)
This is the bottom up dynamic programming approach since we maintain an array and store values in that
array so that can be used for subsequent calculations (Dry run to understand).

Time complexity: O(n^2) //since every node ends up evaluating values from it till the end worst case n-1
Space complexity:  O(n)//array + recursion stack , array in this case will be equal to the number of
vertices.
Space complexity is O(n^2) which is O(v^2) which is O(E) better than dijkstra algo.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	
	return 0;
}
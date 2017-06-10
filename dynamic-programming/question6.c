/*
Travelling sales man problem.

Here a salesman has to start from a village and cover all the village only once and come back to
his village in the min cost possible.

Now given a graph using the cost matrix we have weights of all edges with us. Assume the graph
to be a square with 4 vertices {1,2,3,4}

Now we always need min of T(1,{2,3,4}) = min(T(1,2) + T(2,{3,4}))  and other combinations
So we evaluate them. By building the recursion tree it is found out that there are
(n-1)* 2^(n-2) unique subproblems for which DP is to be applied.

Therefore space complexity will be that huge (exponential) even after applying DP.
To solve each sub problem O(n) time is required, hence time complexity is O(n^2*2^n)

If this is done using brute force method it will take O(n!) time complexity which is way more
bigger than 2^n

Build the algo yourself as it will involve a big matrix and two for loops with bottom-up approach.   
*/
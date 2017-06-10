/*
0/1 Knapsack

In this knapsack, either the value is allowed if the the remaining weight of the knapsack is greater 
than weight of object or its not allowed. Fractional weight cannot be put.
Therefore greedy methods fails in this because if the p/w ratio is 1 for some element. even if
the overall profit by including all objects of it is greater than some other object, this 
wont be considered as its profit by weight ratio is less.

Solution:
Dynamic Programming:
Here we have two options, either we include an object in the knapsack or we do not include it.
If we include it then weight will be reduced by weight of the item includes and then we will
consider the item which is 1 lesser than that. If we do not include it, we will simply move the
the item lesser than that in weight and will not decrease the weight. Then we are going to take
the max of the two. Therefore, max of (include, not include) will be taken into consideration.

Eg: K(3,5) //knapsack with capacity 5 and object 3 whose weight is lets say 4 can be written as
max(K(2,1), K(2,5)) //as now we move to object 2 but updated capacity is 1 or we dont include and 
move to 2

If the weight of knapsack remaining is lesser than object then we simply move to the object previous
to that without doing anything.
If either weight is 0 or the items are over then it will return 0. This is also the breaking condition
for recursion.
This way we have nw unique subproblems (n is the total items and w is the weight of knapsack).
Therefore we maintain a table and at each step we keep calculating we see if the weight of knapsack is
 1 and object weight is 1, then if weight is 2 and object weight is 1 and so on, we keep finding 
 solution to every basic problem to derive the solution for the main problem.

At each step we do constant work.
Time complexity: O(nw) 
Space complexity: O(nw) //space occupied by the table

In this case if we would have applied the brute force method that is finding all possible solutions and
seeing which is max, Time complexity would have been O(2^n).

But in the above dynamic programming method if the weight of knapsack is close to 2^n, then it fails.
Therefore depending on the weight, we choose the kind of method to be applied. 
*/
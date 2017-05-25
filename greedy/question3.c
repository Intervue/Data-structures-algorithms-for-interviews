/*
Make a program to sequence given jobs with deadlines to maximize profits

Here some jobs will be given along with some profits associated to each job if the job is done in
given deadline.
METHOD:
First we find the job with the max deadline. That is the max slot that will be available to us. Therefore
array will be of that size. Now, we arrange them in decreasing order of profits. Once that is done we pick
max profit job and place it as far away as possible such that it is meeting its deadline. Like this we
keep scanning the empty slot to place a job as far as possible such that it meets its deadline. Like this
we maximize profit.
Note: if the deadline is very very high as compared to the no. of jobs, always limit the array size
with the number of jobs given. So compare both. 
Time complexity: O(n^2) //in worst case we will end up scanning all the cells in the array
Space complexity: O(n) //array size or O(max deadline)
*/
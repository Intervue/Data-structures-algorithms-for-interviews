/*
Optimal merge patterns

In this some files with sorted number of records are given. We need to make an algo such that
there is min record movement when merging them in sorted order into single file

Same algo as that of Huffman codes. File with lowest records is moved more so is kept at the bottom
away from the root. Files with higher number of records are placed closer to the root i.e. merged
later

Time complexity: O(nlogn)

*/
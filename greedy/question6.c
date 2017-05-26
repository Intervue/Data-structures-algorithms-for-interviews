/*
Program for KRUSKALS algorithm

To find the min cost spanning tree of undirected weighted graph

METHOD:
In this case rather then picking the min edge for once and then choosing neighbours which are min, we 
choose min numbers from all over the graph each time. Thus there wont be a single tree that is growing
but different forests will be there which will be connected in the end. A condition to keep in mind
is that there should be no cycle formed when picking edges like that.
*/
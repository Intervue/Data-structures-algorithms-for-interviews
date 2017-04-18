/*
Design a stack such that get Minimum should be O(1)

NOTE: When stack is to be designed in order to do something the core functionalities of the stack should
still hold in that design. Eg: Pushing and popping can be done in O(1) time in a stack. This should be
true always

METHOD1:
Maintain and another stack which will store minimum so far values.
For each push into the main stack, the min is compared and if there is a different value it is pushed onto 
this stack. For every pop from the main stack if the popped off element is equal to the min, then the min is
popped off as well. If the main stack contains duplicate values, then the min so far stack should also
contain duplicate to make sure that popping off is consistent and works correctly.
Time complexity: Both pop and push in O(1)
Space complexity: O(n) //worst case

METHOD2:
Maintain a variable that will store the min value so far for every push done. For every push done,
if there is a new minimum, instead of pushing this minimum onto the stack, subtract the min so far value from
this min and push that value on the stack. Eg if minimum so far is 9 and new min is 2 push 2-9 that is -7 
on the main stack. Like this make the stack.
While popping off, each time compare the number on the stack with the min so far, if the number is bigger
pop that number else popp of the min so far value. Also update the min so far value by subtracting the smaller
value on the stack from it. Eg if the min so far was 2 (which was popped off) and value on stack was -7,
new min so far value should be 2-(-7) which is 9. This way the whole algo will work.
Time complexity: O(1)
Space complexity: O(1)
*/

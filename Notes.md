# Notes

## Arrays

1. When processing an array that requires checking the next index to determine what to do with the current index, try doing from the end of the array.
2. Think about processing array problems from the back in general.
3. If array is sorted, try using 2 pointers approach.
4. transform(v.begin(), v.end(), v.begin(), function) applies a function to each element in a container.
5. accumulate(v.begin(), v.begin(), 0) sums up all the elements in a container.  
6. Be careful when adding to an array when looping over it as it'll cause an infinite cycle.

## Strings

1. stoi(str, idx/nullptr, base) converts str to an integer with the specified base.  
2. Use 2 pointers approach if there are 2 strings to be compared.  

## Trees

1. Pre-order/post-order Traversal with markers (#) for null node unique determines a Binary Tree after inserting a character before/after the root node.

## Bit Manipulation

1. Finding the only non-duplicate requires XORing every bit with one another since a ^ 0 = a and a ^ a = 0 and it is commutative. This can also be used to find the only missing element in an array of n elements from 0 to n.  
2. n & 1 gives the last bit of n.
3. n & (n - 1) gives the least significant 1 bit of n.

## Math

1. S_n = n * (n + 1) / 2
2. Shift int x to the left: x * 10
3. Get last digit of int x: x % 10
4. Remove last digit of int x: x / 10  


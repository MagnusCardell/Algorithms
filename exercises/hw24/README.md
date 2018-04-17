Alg Dynamic programming homework
Homework 25   Due Tuesday, 4-17-18
A. Reading

    1. Please (re)read sections 6.1 and 6.2 carefully.

B. Exercises

    1. Implement the solution given for the longest increasing subsequence problem given in section 6.2. Have your program read a list of numbers from a file, and output the length of the longest increasing subsequence. Please submit your code through git.

    2. Implement the (slow) recursive solution mentioned in the text box for the longest increasing subsequence problem, and compare the running time with your previous solution (for several input sizes).Please submit your code through git.

    3.[C] Estimate, empirically, a function that approximates the running time of the recursive approach. For example, is it close to 3n4.5?

    4.[C] Exercise 6.1, page 177.

Outer loop, goes over every number in the orignal_array(OA). Creates an array of sums the size of the OA. The algorithm then adds the sum of the current index of the outer loop. The inner loop then starts, comparing maxsum of the current index to all other previous maxsums in the OA. If the current index gives a new maxsum, update that variable. When both loops are finished, return the maxsum. 

    5.[C] Exercise 6.2.

The problem is that we want to minimize the penalty  and maximum the number of miles you can travel. The subproblem is that we want to figure out if it is more effective to rest at the current specific spot, or the next spot. Using a modified edit-distance algorithm, I can imagine setting up the algorithm to find the shortest path (minimum penalty) between route A and B where a displacement is equal the penalty of stopping. 
So, using the edit-distance algorithm, at any point we risk a penalty of p[i-1] + (200−(aj−ai))^2 where aj,ai=subproblems and j<i.

    6.[C] Exercise 6.3.



    7.[C] Exercise 6.8, page 179.

    8. Implement your solution to problem 6.8 in such a way that it reads in the two strings from a file (put each string on a line by itself), and then prints out the longest common substring. Please submit your code using git.
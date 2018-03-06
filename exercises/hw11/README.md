Homework 12   Due Tuesday, 3-6-18
A. Divide and conquer

    1.[C] Exercise 2.11, page 73.

I will prove the property described when matrices X and Y are multiplied together. 
First, consider all sub-matrices of X and Y, and how they can be summarized as the sum from k=1 --> n. These sub-matrices are bounded by (i,j) where (i,j) < n/2. So the product X . Y = Sum of X(i,k) . Y(k,j) from k=1 --> n

Because of the properties of matrix multiplication, X . Y = A(i,k) . E(k,j) + B(j,k) . G(k,j) where k = 1-->n. 
Similarly, the other three quadrants follow the same structure, which results in a property supporting the problem statement. Thus the problem is proven by definition.

    2.[C] Exercise 2.15.

To avoid allocating new memory, I would have to imagine to use index values to keep track of the locations: max_limit and min_limit. After an initial sort, the array is run through, if the current value is less than v, increment min_limit, if more than v: increment max_limit. The start of all values less than v is in the range 0 to min_limit. All values equal to v is from min_limit to ((total array length)-max_limit). 

The limitation on memory would also need to apply on the initial sort, with something like a selection or bubble sort. 

    3.[C] Exercise 2.18, page 74.

Because the fundamental question is "is A[i] <= z?" in the context of a binary search, the algorithm effectively cuts the array in half with each comparison. Cutting the array in half until the worst case scenario target is found, is therefore log(base b)n where n is the starting value of the array size and b, the number of concurrent calls. 

B. Binary search

    1. Create an array of random integers, sort them, and then use binary search to find the index of some particular value. Please write the binary search part of the code from scratch. Please submit the C++ code via git. 


    2. Create a vector of strings, such that the strings are in alphabetical order. It is ok to hard-code a set of strings that are already in alphabetical order. Then create a binary search function that works to find a particular word among the vector of strings, similar to your first binary search. Please submit the C++ code via git. 

C. Reading

    1. Please read section 3.1, pages 80-82.

D. Exercise

    1. Implement a stack data structure as a C++ class. Here is a concise definition for a stack. Please use a simple array as the basis for your data structure. Your stack should have a constructor whose argument gives the maximum number of elements to be stored in the stack (thus allowing you to allocate an appropriate fixed-size array), as well as push and pop methods. Please submit the C++ code via git. 
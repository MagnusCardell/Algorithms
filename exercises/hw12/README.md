Homework 13   Due Thursday, 3-8-18
A. Review

    1.[C] Let us assume that f(n) is O(g(n)), and also that g(n) is O(f(n)). Under these assumptions, is f(n) necessarily Theta(g(n))? Please write a proof or find a specific counter-example.

B. Reading

    1. Please read about the STL version of a stack

C. Exercises

    1. Implement a stack based on a dynamically allocated array, in such a way that the stack can handle an arbitrary number of items. Use the reallocation policy that when the current array gets full, create a new array that is 100 elements longer than the current array, and copy information from one array to the other, before deallocating. Your allocation should rely on the standard C++ new operator. Please submit the code through git.

    2. Implement a stack based on an array, but this time double the size of the array each time it gets full. Please submit the code through git.

    3. Implement a stack based on a linked list. Please submit the code through git.

    4. Make an STL stack. Please submit the code through git.

    5.[C] Time all four implementations: what is the average number of cycles required per push when pushing less than twenty elements? Less than a thousand? Less than a million?

    6.[C] With a friend, analyze and explain the results of your experiments, both in terms of constant factors and asymptotic complexity. Please put your results and analysis on two slides that you can share during class.

D. Reading 2

    1. Please read sections 3.2.1 and 3.2.2 on depth-first search.

E. Exercises 2

    1.[C] Exercise 3.6, page 96.

    2.[C] Exercise 3.26, page 100.

    3.[C] Exercise 3.27.
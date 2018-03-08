Homework 13   Due Thursday, 3-8-18
A. Review

    1.[C] Let us assume that f(n) is O(g(n)), and also that g(n) is O(f(n)). Under these assumptions, is f(n) necessarily Theta(g(n))? Please write a proof or find a specific counter-example.

Here is my thinking. If g(n) = O(f(n)), then g(n) <= f(n). Similarly, if f(n) = O(g(n)) , then f(n) <= g(n). Therefore, g(n) = f(n) which is the definition of Theta, this f(n) = Theta(g(n)).


B. Reading

    1. Please read about the STL version of a stack

Read it!

C. Exercises

    1. Implement a stack based on a dynamically allocated array, in such a way that the stack can handle an arbitrary number of items. Use the reallocation policy that when the current array gets full, create a new array that is 100 elements longer than the current array, and copy information from one array to the other, before deallocating. Your allocation should rely on the standard C++ new operator. Please submit the code through git.

see stack1.cpp

    2. Implement a stack based on an array, but this time double the size of the array each time it gets full. Please submit the code through git.
stack2.cpp

    3. Implement a stack based on a linked list. Please submit the code through git.

linkedlist_stack.cpp

    4. Make an STL stack. Please submit the code through git.

see stl_stack.cpp

    5.[C] Time all four implementations: what is the average number of cycles required per push when pushing less than twenty elements? Less than a thousand? Less than a million?

Fixed size stack - 2800/10 = 280 per push
Double size stack - 3200/10 = 320 per push
Linked list stack - 610/10 = 61 per push
STL stack  - 2900/10 = 290 per push


clearly less than a thousand per push. 

    6.[C] With a friend, analyze and explain the results of your experiments, both in terms of constant factors and asymptotic complexity. Please put your results and analysis on two slides that you can share during class.

D. Reading 2

    1. Please read sections 3.2.1 and 3.2.2 on depth-first search.

E. Exercises 2

    1.[C] Exercise 3.6, page 96.

In an undirected graph, that the sum of all verteces is equal to the cardinality of all edges multiplied by 2. This is because every edge has to symbolice both ingoing and outgoing degrees. Therefore the sum of all verteces is its edges multiplied by 2.

    2.[C] Exercise 3.26, page 100.

a) Assume there is a graph for the Koningsberg bridge problem. I then want to prove that all vertices has an even degree. All verteces must be distinct and each vertece needs to be used. A node with k number of verteces must therefore be visited k times. This concludes that there must be an even number of verteces. Because the total number of verteces is 13, not all bridges will be used. Therefore there is no Eulerian tour. 

b) An undirected graph is an Eulerian tour if and only if every every path is distinct and only visited once. 

c) An undirected graph distinguished between ingoing verteces and outgoing verteces. A Eulerian path must therefore show an equal amount of outgoing as ingoing paths in order for every path to be able to visited. This show that the total number of verteces must be even, thus it supports there being no Eulers path on the Koningsberg bridges. 

    3.[C] Exercise 3.27.

By definition of an edge-disjoin path, such a path can be found between pairs with uneven number of vertices. 
Given that every node has 2n+1 vertices, and a total of k nodes. The total number of nodes is then 2nk + k number of vertices. In an undirected graph, every vertice can be used as either ingoin or outgoing. By the definition of an edge-disjoin path every node needs to be joine by two distinct paths. This requires there to be even number of nodes. So we have left k to distribute over k nodes. Because 2n vertices already have been distribued, every node can be layered one extra bridge that will still keep the edge-disjoint property and so finish up all vertices. 

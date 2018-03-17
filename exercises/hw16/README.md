Alg Breadth first homework
Homework 17   Due Saturday, 3-17-18
A. Exercises

    1.[C] Suppose you have a directed graph with four vertices called A, B, C, and D, and the edges are as follows: the out-edges of A go to B, C, and D, the out-edges of B go to C and D, and there is just one out-edge of C, which goes to D. Draw this graph on a piece of paper, and verify that it is a directed acyclic graph. Now, how many distinct paths can be used to travel from A to D? Hint: the answer is between 3 and 7.

The requirements for a graph to be a DAG is that it must be directed and have be acyclic. This graph contain no cycle i.e. no back edge so we can go ahead an count the number of distinct paths from A to D.
A,D
A,B,D
A,C,D
A,B,C,D

So total number of paths are 4, which is within the given range of 3-7. 

    2.[C] Consider a dag with nodes A, B, C, D, E, F, and G. In this graph, there exist edges that connect from A to the rest of the nodes (B through G), from B to the nodes C through G, and so forth, so that the structure is the same as in the previous problem, except that we have more nodes. Now, how many paths exist in this graph from A to G?

Looking at this systematically, when we have 2 nodes, there is 1 unique path between them.
3 nodes has 2 unique paths
4 has 4 paths (see A.1)
5: 8 paths
    AE
    ABE
    ACE
    ADE
    ABCE
    ABDE
    ACDE
    ABCDE
6: 16

A pattern emerges where the total number of unique paths can be calculated by 2^(n-2) where n is the number of nodes. 

So the given graph with 7 nodes, has 32 possible unique paths from A-G. 

    3.[C] Exercise 3.29, pages 101,102.

I will first show that any two members of a group are related, such that x,y in Si and (x,y) in R. The set S is made up of the union of all disjoint subsets. Any two subsets can not have any intersectionalities, i.e. for w in S and w in Sm cannot at the same time be w in Sn. 

Given two members (x,y) of a subset Si where i can be any subset in S. By definition of a subset, these two members fulfill reflecivity, symmetry, and transitivity. If a third element (z in Sk) had the following relation where x is symmetric to z, then by transitivity z is also a member of Si which means that Sk is a subset of Si. Given that no two subsets can have any intersectionalities, Sk must equal Si and all of its members be related. 


    4.[C] Exercise 3.30.

On page 91, the book describes the formation of SCC graphs where cyclic portions of a directed graph can be partitioned groups. Extending this analogy to an equivalence relation, means that there exists an equivalence relation between a pair of nodes (x,y) if they fullfill the requirements of reflexivity, symmetry, and transitivity. 

Given two nodes (x,y) in one subcycle Gi of a graph G. Given that they are reflexive by definition, they are symmetric if there exists a unique path from x -> y such that there is a path y -> x. If (x,y) are symmetric, z in Gi shows transitivity if x -> z and z -> x. Which means that y->z and z->y. 

As an example from Figure 3.9, The two subcycles Gi=(D) and Gj=(B,E) each show these equvalence relations. B->D but D cannot go to B, so no symmetry. And so on. 

B. Reading

    1. Please read sections 4.1 and 4.2.

C. Exercises
For these exercises, feel free to work with another person if you would like to do so.

    1. Implement breadth-first search: write a program that works on a graph that is given in a text file in DIMACS format. Please submit the code through git.

    2. Solve the pouring water problem (3.8), and this time find the minimum number of moves necessary to reach the goal (using C++). Please submit the code through git.

    3.[C] Solve a variation on the pouring water problem: what if we have five buckets with capacity 23, 29, 31, 37, and 41, respectively, and we start with the first and last buckets filled (the rest are empty), can we get the three largest buckets to contain 4 each? If no, how many nodes must we search to learn this fact, and if yes, how many moves does it take? Please submit the code through git and post your solution here.
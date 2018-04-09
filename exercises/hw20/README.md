Alg Minimum spanning tree homework
Homework 21   Due Saturday, 4-7-18
A. Reading

    1. Please read the beginning of Chapter 5, up to the end of section 5.1.1.

Greedy Algorithms. 
Minimum Spanning trees. 
    - Property 1: removing a cycle cannot disconnect a graph 
    - Definition: Input: An undirected graph G = (V,E);edge weights w. 
                OUtput: A tree (V,E') with E' in E that minimizes weight(T) = Sum(W).

    - Kruskal's minimum spanning tree. 
        selects lightest edges from E repeatedly that does not produce a cycle. 
        -Greedy: always picks the decision with most obvious immediate advantage. 

    - Property 2: a tree on  n nodes has n-1 edges.  (129)
    - Property 3: Any connected, undirected graph G=(V,E) with |E| = |V|-1 is a tree.
    - Property 4: An undirected graph is a tree if and only if there is a unique path between any pair of nodes.  

B. Exercises

    1.[C] Exercise 5.1ab, page 148.

    a) 
E - A: 1
E - F: 1
E - B: 2
F - B: ignored
F - G: 3
G - H: 3
G - C: 4
F - C: ignored
B - C: ignored
G - D: 5
... all nodes are connected, all remaining edges will be ignored
Sum: 19

b)
If instead of E-B we chose F-B since both have the same weight, it would create an equally minimmized tree. So there are 2 minimum spanning trees.

    2.[C] Exercise 5.4, page 148.

A vertex in a graph is defined as a node that can have multiple edges connecting to other nodes. A connected component signify a collection of nodes, at least 2, that are connected by vertices but are not connected to other nodes in the graph.
Property 2 of trees tells us that a tree on n nodes has n-1 edges. A collection of k sub-graphs (connected components) must therefore have at least n-k edges by definition. 


    3.[C] Implement an inefficient version of Kruskal's algorithm: to see whether a particular edge will cause a cycle, use DFS. Submit your code through git and your output here.



    4.[C] Please solve the Loopy Transit problem, including using the suggested input and output formats. Submit your code through git and your output here.




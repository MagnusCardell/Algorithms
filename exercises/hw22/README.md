Alg Set cover homework
Homework 23   Due Thursday, 4-12-18
A. Reading

    1. Please read section 5.3, Horn formulas.

    2. Please read section 5.4, Set cover.

B. Exercises

    1.[C] Exercise 5.5, page 148.

a) My intuitive reaction is that it cannot change because its an equal change on all factors.
We know that the minimum spanning tree has n-1 edges. The weight of such a tree is the sum of all weights sum(n-1). An increase of 1 at all edges, would lead this sum to be old_sum + (n-1) where old_sum is the sum of the minimum spanning tree before the weight increase. Therefore the tree remians the optimal solution. 

b) For example

A - B 2
B - C 1
C - E 1
A - E 5

The shortest path right now is A-B-C-E with a length of 4. If all edges increase by 1, this would instead be 7, which is greater than A-E of 6. Therefore the shortest path can change. 

    2.[C] Exercise 5.9, page 149.

a) False. Property 2 stated that a tree on n nodes has n-1 edges. The minimum spanning tree therefore has at n-1 edges. If there are more than n-1 edges in the graph, then there are more that one path between two nodes. However, because the problem states its unique, its the only edge between two nodes. Therefore it must always be present in all MST.

b) True. Assuming that the heaviest weight of edge e is part of a cycle, then by Property 1 removing a cycle in the cycle cannot disconnect the graph. Therefore, e cannot be part of any MST. 

c) True. If e is one of the minimum weights in Graph g, then it must be part of a MST. 

d) True. The lightest edge in a MST is guaranteed to be added first in the greedy algorithm, therefore it is guaranteed to always be a part of any MST.

e) True. By the definition of cut, the edge e has to be the lightest of some cut of G. If we replaced e with another edge e2 in G where e<e2, then Therefore e is the lightest accross this very cut. 

f) True. By the definition of cut, the lightest edge e will always be part of a MST of G because when a cycle is encountered it will be the optimal choice to preserve for a greedy algorithm. 

g) False. Because the Dijsktra finds the shortest path in total between two nodes its not always a MST tree within the connected trees. For example: 
A-B 1
B-C 1
C-D 1
D-F 1
A-F 2

A MST tree would connect A-B-C-D-F. Dijkstra will choose the A-F path even though its the heaviest edge in the graph. 

h) False. Not necessarily. See the answer of g) and Disjkra's algorithm

i) True. By the definition of Prim's algorithm, Prim always picks the lightest edge, so this would include negative values. 

j) True. Proof by contradiction. If we had a MST tree that did not include a r-path between two nodes, then the MST would contain an edge e>r. If e>r and a r-path exists, its not the lightest edge, which contradicts the definition of a MST tree. Therefore any r-path is contained withing a MST tree. 

    3.[C] Exercise 5.32, page 154.

To prepare, each fact is connected to some number of statements, which in turn may be connected to their statements. For a fact to be true, their statments must be true. Starting with the statement we want to prove, we dissect each section on a high level, like taking its neighbours, and check recursively if they are true. If one statement is true at any point in the graph, then it is true for all other statements, therefore we only need to visit each node once. 

I imagine using a BFS search that explorer all its sub-statements/neighbours until it has hit a leaf node. Working itself upward, if its substatements are true, the parent is true etc. This way, we achieve a lienar logic contsraint programming. 

    4.[C] Exercise 5.33.

An optimal cover would be to assign all uneven to one set, and all even to another. S1={1,3,5, ... , (n^2)-1} S2={2,4,6, ... , n^2}. The greedy algorithm may not always choose the optimal solution, but still assign effective sets. To show that the greedy algorithm picks at least logn sets, I need to show that the depth of the options are logn.If we at every time assign half sets, we will end up with logn number of sets. For example if n=32 (power of 2), then S1= {1,2,3,...,16}, S2= {17,18,..,25}, S3= {26, 27, ..., 30}, S4= {31, 32}. A total of 4 examples which is greater than log(32).   

    5.[C] Optional: Exercise 5.34, page 155. Feel free to consider n to be two less than a power of two.


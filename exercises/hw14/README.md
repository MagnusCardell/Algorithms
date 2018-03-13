Alg Pouring water homework
Homework 15   Due Tuesday, 3-13-18
A. Reading

    1. Please read the rest of chapter 3 (section 3.4).

B. Exercises

    1.[C] Exercise 3.4, page 96.

a)

(i)
A 1,16
C 2,9
D 3,8
F 4,7
J 5,6
H 10,15
G 11,14
I 12,13
B 17,18
E 19,20

(ii)
A 1,18
B 2,17
C 3,14
F 4,13
I 5,12
H 6,11
G 7,10
D 8,9
E 15,16

Rank post value with highest denominator first:
(i): E, B, A, H, G, I, C, D, F, J
(ii): A, B, E, C, F, I, H, G, D

Do DFS on graph G with reversed vertice direction.
(i): 
E
B
A
H, I, G
C, J, F, D

(ii)
A, E, B
C
F, H, D, G, I

b)
(i): for each scc group, the highest post value denotes a source/sink. So C
(ii): F

c) Imagine me drawing this with arrows
(i) E -> B -> A -> H,I,G -> C,J,F,D
(ii) A,E,B -> C -> F,H,D,F,I

d)
(i) 1, to make is a loop
(ii) 1, Since this creates a loop.


    2.[C] Exercise 3.7

As I understand it, each vertice has to be either V1 or V2, and the same set cannot be next to each other. 

Using a DFS starting at the root. Set add that node to V1. Do DFS on its neighbours, each adding the node to the opposite of its parent. So V2 if its parent node is V1, V1 if its parent node is V2. At each node, we check equality between V1 and V2 at the current node. If it belongs to both, then this is not a bipartite graph. When the DFS search is done, and no equality has been rise, the graph can be confirmed bipartite. 

Note that I am imagining using a hash map, so that the set check can be achieved in constant time, making this a linear algorithm.  

    3.[C] Exercise 3.12, page 97.

In a DFS tree, given that post[u] < post[v], and that u,v are separated by one edge, then pre[u] > pre[v]. By the definition of node ancestry this shows that v is an ancestor of u.

    4.[C] Exercise 3.16

So, each course has a directed vertice between them if one is a prerequisite of the other. Assuming that a course cannot be taken until its prerequisite courses are done, then the minimum number of semesters are the length of the longest SCC cycle. This is becauase all other courses can be taken in parallel and be finished before the longest sequence is done. 

Using a SCC DFS search. The algorithm first identifies SCC cycles longer than 1. It then starts at the highest post-value, pops that node, and traverses over its neighbours. When the stack is empty, the sequence is done and the minimum amount of semesters are found. 

C. Team Project

    1.[C] Who are you working with?

    2. Implement a C++ solution to Exercise 3.8, page 97. Please submit the code through git.
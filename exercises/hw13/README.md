Homework 14   Due Saturday, 3-10-18
A. Reading

    1. Please read the rest of section 3.2, depth-first search.

    2. Please read section 3.3, extending to directed graphs.

B. Exercises

    1.[C] Exercise 3.1, page 95.

First, the question of where to start the search. Since A is alphabetically first, we start there

A (1,12)
<tree edge> A-B
<back edge> A-E
B (2,11)
<tree edge>B-C
<tree edge>B-E
C (3,8)
<tree edge>C-F
F (4,7)
<tree edge>F-I
I (5,6)
<No edge>
E (9,10)
<cross edge> E-F

D (13,18)
<tree edge> D-G
<back edge> D-H
G (14,17)
<tree edge> G-H
H (15,16)
<No edge>

    2.[C] Exercise 3.2.
a)

T: Tree edge
F: Forward edge
B: Back edge
C: Cross edge

A (1,16)
    2 edges
    T: A-B
    F: A-F

B (2,13)
    2 edges
    T: B-C
    T: B-E

C 3(,12)
    1 edge
    T: C-D

D (4,11)
    1 edge
    T: D-H

H (5,10)
    1 edge
    T: H-G

G (6,9)
    1 edge
    T: G-F

F (7,8)
    1 edge
    B: F-G 

E (14,15)
    2 edges
    C: E-D
    C: E-G

b)
A (1,15)
    2 edges
    T: A-B
    T: A-H
B (2,10)
    1 edge
    T: B-F
F (3,9)
    3 edges
    T: F-C
    T: F-D
    F: F-E
C (4,5)
    1 edge
    B: C-B
D (6,8)
    2 edges
    C: D-C
    T: D-E
E (6,7)
    0 edges
H(11,14)
    1 edge
    T: H-G
G(12,13)
    2 edges
    B: G-A
    C: G-B


    3.[C] Exercise 3.3.

A (1,15)
C (2,13)
D (3,10)
F (4,9)
G (5,6)
H (7,8)
E (11,12)
B (14,16)

Which gives the following topological sort: B-A-C-E-D-F-H-G (decresing order of post vertex values)
a) See above
b) (A,B) are sources. (G,H) are sinks.
c) See above
d)  A or B 
    C
    D or E
    F
    G or H

    8 possible combinations.


    4.[C] Exercise 3.5.

function giveRev(tree root){
    if (root == null) return;
    vector<tree> result;
    for vertex in tree[root]{
        result.push(vertex);
        if(tree[vertex] not in result) {
            result.push(giveRev(tree, tree[vertex]))
        }
    }
    return result;
}


    5.[C] Exercise 3.9, page 97.

Given an adjacency list. The hard part is doing this is linear time. But I think, doing a DFS search on all unvisited nodes, should return a linear search, visiting each node once. 

function countNeighbours(Tree, u){
    Tree[u] = visitied;
    for ( v in Tree[u]){
        if(Tree[v] != visited ){
            DFS(Tree, v)
        }
        twodegree[u] += len(Tree[v]);
    }
}


    6.[C] Exercise 3.11.

search(Tree, e){
    stack<nodes> dfs;
    dfs.push(Tree[0]);
    while (!dfs.empty()){
        node t = dfs.top();
        dfs.pop()

        for( v in t){
            if (t[v] == e) return True; //If there is an edge matchin, return true,
            dfs.push(t[v]);
        }
    }   
}

    7. Write a C++ program that can read in a graph, storing it internally as an adjacency-list. It is fine to use vectors, if you so choose. Here is an example input file (DIMACS format):

    p edge         5       4
    e         0         1
    e         0         2
    e         1         2
    e         2         3

    The first two words are just keywords, then it says that we have 5 vertices and 4 edges. The next four lines give the edges. So the resulting graph could be drawn like this:

           1     4
          / \
         /   \
        0-----2-----3

    Please check that, once you read in a file, you can also write it out in DIMACS format and submit the code through git.

    8. Implement depth-first search for undirected graphs, and give an example input (a graph and a starting vertex) and output. Again please submit your code through git. (the pre- and post- visit numbers for all vertices) for your implementation.





Note: Here is an example of one way to read in a file, one line at a time, and split each line into words. --> split.cpp

Note2: To convert a string str into an int n, you can do this:

n = atoi(str.c_str());
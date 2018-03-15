Alg All paths homework
Homework 16   Due Thursday, 3-15-18
A. Programming Exercises

    1. Create a queue data structure in C++, similar to your stack data structure, using a fixed size array (written from scratch...). A queue is like an escalator: you can add items on one end (inject), and retrieve items from the other end (eject). Please submit the code through git.

    2. Exercise 3.10 (non-recursive explore). Please write your answer in C++. Feel free to use the STL stack, or any stack you find convenient. Please submit the code through git.

B. Design Exercises

    1.[C] Exercise 3.15 (one-way streets).

a) Using the Strongly Connected Component algorithm, the result should show that all intersections are one big cycle. In this case, every intersection is a node, and every road is a directed vertice corresponding to the direction of the one way street. Since SCC is an adapted DFS search, which is linear, this will also be linear.

b) So, this is assuming that not all intersections are reachable from the town hall. However, the mayor claims that everything reachable is also a SCC, meaning its a cycle. Using the previous algorithm of a SCC DFS search, the constraint that all intersections must be reached can be lifted to instead say that all cycles including the town hall must be a SCC. 

    2.[C] Exercise 3.18 (tree).

Using a DFS search, all nodes are marked according to their pre and post visit values. This is put into a hash map that has linear lookup time. At the end of the explore function then, all that is needed is a lookup query for each node in question. The bottleneck in this case is the DFS search. Using the explore function, each node has to be set to visited upon discovery to achieve linear time. 

    3.[C] Exercise 3.23 (all paths).

DFS(Tree t, node n){
    stack<node> queue;
    n.visited = true;
    count = 0;
    queue.push(n);

    while(!queue.isEmpty()){
        node t = queue.pop();
        vector<node> neighbours = t.getNeighbours();

        if(t == n) count++;

        for n in neighbours{
            if(n.visited == true) continue;
            queue.push(n);
        }
    }
    return count;
}

To explain, using a deapth first search, and a starting node, each node that is not visited before is added to the stack. Since every node is unqiue, every time we reach a node equal to n, we can increment count. This count is then returned.
Alg All cycles homework
Homework 20   Due Thursday, 4-5-18
A. Exercises

    1.[C] Exercise 4.13, page 121.

There is a gas station in every city. 
a) Because this has to be linear, I cannot use Dijkstra's algorithm.  So instead, given two cities s and t, use BFS or DFS to see if you reach t from s if you only add edges Le < L to the stack queue. This way you can see if you can reach t. 

b) Using Dijkstra's shortest path algorithm, every city will be visited (V) multiplied by each edge (E) at (V). That is how many times you need to perform the checks and inserts using the priority queue, which in a binary heap as cost log(V). Therefore Dijkstra's shortest path algorithm using a binary heap priority queue fullfills these criteria. The shortest path is the minimum tank capacity required to travel between city t and s without refilling in other cities. 


    2.[C] Exercise 4.15, page 122.

In Dijkstra's implementation, we add a new shortest path if dist(v) > dist(u) + l(u, v). Now, given the restrictions in the book, we can add a check to correct for unique shortest paths using 
    if dist(v) == dist(u) + l(u,v):
        usp[s] = true

Meaning that if the distance from the current node to the next, already matches the existing distance, then the path lengths are not unique thus usp[s] cannot be true, so skip it. 

    3.[C] Exercise 4.21, page 125.

a) Each graph edge represents an exchange rate. I want to find the minimal cumulative exchange rate between currency s and t. Using Dijkstra's shortest path should be applicable where path represents exchange rate. 

b) First of all, there needs to be a cycle. In this cycle I will end up with more units than what I started with in a directed graph, meaning that all transactions can be performed in close succession. (Not s -> t then t -> s). So there needs to be a longest path between s and t, and a shortest path between s and t at the same time, that are unique. The difference between these two paths needs to be sufficiently large that any loss by either is covered. 

So, using Dijsktra's shortest path algorithm with a max-heap to find the longest path, and another with a min-heap. As soon as both are found, we keep checking if the values for these paths change to the extent that the exhcange loss becomes covered. We also need to update all other pahts to see if there is a new longest and shortest path. 

    4.[C] Implement heapsort ( Here is a visualization), and compare its running time to mergesort. Which is faster, in practice?

    5.[C] (All cycles) Given a directed graph, find all the cycles in the graph. To answer this question, please design an algorithm that will find these cycles brute force, and then implement it in C++. Note that the challenge is to identify each cycle, not just to count them. In your solution to this problem, please make clear how you tested your solution, so that it is easy for the TAs to use similar tests.
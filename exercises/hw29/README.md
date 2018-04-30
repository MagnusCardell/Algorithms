Alg Independent Sets in Trees homework
Homework 29   Due Thursday, 4-26-18
A. Reading

    1. Please read section 6.5 (Chain matrix multiplication).



    2. Please read section 6.7 (Independent sets in trees).

B. Exercises

    1.[C] Exercise 6.18, page 181.

Yes. By utilizing dynamic programming principles, the brid of possibilites built by the algorithm will be of n*v size. So to check every possbiility it will take O(nv). 

    2.[C] Exercise 6.20, page 182.

Using Dynamic programming, we get the following subproblems: 

    cost(i,j) = Sum(freq k + min{r=1}^{j}\begin{bmatrix} optcost(i, r-1) + optcost(r+1, j) \end{bmatrix} 

    3.[C] Exercise 6.24ab, pages 183,184.

Time and space complexity of dynamic programming. Our dynamic programming algorithm for computing the edit distance between strings of length m and n creates a table of size n x m and therefore needs O(mn) time and space. In practice, it will run out of space long before i runs out of time. How can this space requirement be reduced?

    a) Show that if we just want to computer the value of the edit distance rather than the optimal sequence of edits, then only O(n) space is needed, because only a small portion of the table needs to be maintained at any given time. 

When the edit distance algorithm finds out the solution to the current column, it only needs to know what the previous column values where. Therefore, at any point in the graph, we only need 2 columns, the current column, and the previous column. Using 2n = O(n) space. Tested and proved in hirschberg_a.cpp

    b) Now suppose that we also want the optimal sequence of edits. As we saw earlie, this problem can be recast in terms of a corresponding grid-shaped dag, in which the goal is to find the optimal path from node (0,0) to node (n,m). It will be convenient to work with this formulation, and while we're talking about convenience, we might as well also assume m is a power of 2.

    Let's start with a small addition to the edit distance algorithm that will turn out to be very useful. The optimal path in the dag must pass thorugh an intermediate node (k,m/2) for some k; show how the algorithm can be modified to also return this value k.

An optimal path to a node (i, j) in the "dag" that now is the edit distance matrix. K represents the value that the optimal edit distance will pass through (k, m/2). If we use the previous algorithm, we simple need to stop halfway through string m and return the optimal value k in that column. It is also valuable to return coordinates for later use. (in c). See hirschberg_b.cpp for code and demonstration


    c) Now consider a recursive scheme:

    procedure find-path((0,0) -> (n,m)) 
    compute the value k above
    find-path((0,0) -> (k,m/2))
    find-path((k, m/2) -> (n,m))
    concatenate these two paths, with k in the middle

    show that this scheme can be made to run in O(nm) time and O(n) space. 

Using the Masters Theorem, we have reccurrence scheme to analyze. T(n,m) = T(k, m/2)+T(m/2, n−k) + O (nm). We are only calling new stack frames acccording to the worst case edit distance: m+n so it is apparent that the Initial work will overpower the leafnodes. We can also use the Master Theorem to show this.
    a=1
    b=2
    d=1

    log2(1) < 1 so O(mn) is the running time. 

So, to compute K, it takes O(mn) time and O(m+n) space as shown in (a). At any point we only use 2 columns therefore achieving linear space complexity. 

C. Team Project
Today's team project is about a hypothetical coding competition! Imagine that you are asked to participate in a programming competition in which our whole class of 21 people functions as one team. During the competition, there are 5 algorithms (Alg1-Alg5) that need to be coded, and multiple people can work on each algorithm. The more people that work on an algorithm, the higher the chance they will figure it out and successfully complete it by the deadline. It is your job to determine the best distribution of people for each algorithm to maximize the chance you will finish it before it is due. You must assign at least one person to each algorithm or that one will not be completed! Here are the success probabilities ("P()") for each Algorithm, note that some are more difficult than others.

P(Alg1) = x/21
P(Alg2) = (x^2)/450
P(Alg3) = sqrt(x)/sqrt(21)
P(Alg4) = .5log(x)
P(Alg5) = (1.2^x)/50

For example, for Alg1, if you assign 20 people to it the change of success is 20/21.
In case you are confused, the above is a hypothetical competition, you are still working on finding the appropriate strategy in your small groups!

    1.[C] Paste your optimal solution and submit the code via git.
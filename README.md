# Algorithms
Repository for my algorithms exercises

exercises folder is for solutions to the Algorithms course i took 
csharp, cpp, python are all folders with solutions to algorithm problems in respective languages.

Big O definition:
Let f(n) and g(n) be functions from positive integers to positive reals. We can say that f = O(g) if there is a constant c > 0 such that f <= c * g(n). 

Master theorem:
If T(n) = aT([n/b]) + O(n^d) for some constants a>0, b>1, and d>=0, then

T(n) = O(n^d) if d>logb a
T(n) = O(n^d logn) if d = logb a
T(n) = O(n^(logb a)) if if d < logb a



Exhaustive search = Exponential Runtime
    - There is a quest for finding algorithms that bypass exponential runtimes
        - Greedy algorithms
        - Dynamic programming
        - Linear programming
        --> Reduce search space, run in polynomial time
    
    Problems with no polynomial runtime algorithms have no known technique for narrowing down the search area
        - Satisfiability
        - Traveling salesman problem
        - Euler and Rudraia
        - Min cut problem
        - Balanced cut problem
        - Integer linear programming
        - Three-dimensional matching
        - Independent set, vertex cover, and clique
        - Longest path
        - Knapsack and subset sum

P - all search problems solvable in polynomial time
NP - search problems not solvable in polynomial time

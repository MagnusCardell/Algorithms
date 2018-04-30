Alg Linear programming 2 homework
Homework 30   Due Sunday, 4-29-18
A. Reading

    1. Continue reading chapter 7, from section 7.1.3 to the end of section 7.2.

    2. Please skim section 7.6, the simplex algorithm.

B. Exercises

    1.[C] Exercise 7.8.

You are given the following points in the plane:
    (1,3), (2,5), (3,7), (5,11), (7,14), (8,15), (10,19)

You want to find a line ax + by = c that approximately passes through these points (no line is a perfect fit). Write a linear program (you don't need to solve it) to find the line that minimizes the maximum absolute error, 
    max(1<= i <= 7)  |ax_i + by_i - c|

I want to describe a number of constraints. However, since this question asks me to minimize something, I need to transform it into a maximize problem for Linear Programming to apply. So by shifting the signs (+/-) I can tranform a minimize into a maximize problem. Therefore, I now have the following Linear function maximize(-ax_i - by_i + c) where 0<=i<=7. Then, to convert it to Slack form, we add a variable name "Z" s.t. Z = -ax_i - by_i + c where Z is our objective value. Now, putting all on one side gets us: 0 = -ax_i - by_i + c -Z, which lets us formulate the constraints:
    -ax_i - by_i + c -Z >= 0
    -ax_i - by_i + c +Z >= 0
    a,b,c,Z >= 0
    max(Z)  0<=i<=7


    2.[C] Exercise 7.9.

A quadratic programming problem seeks to maximize a quadratic objective function (with terms like 3x1^2 or 5x1*x2) subject to a set of linear constraints. Give an example of a qudartic program in two variables x1, x2 such that the feasible region is nonempty and bounded, and yet none of the vertices of this region optimize the (quadratic) behavior. 

Linear constraints
Two variables: x1,x2
Feasible region must be bounded and nonempty

So max(x1*x2) is a quadratic problem. Now if we give the following linear constraints:
    x1, x2 >= 0 
    2(x1) * 2(x2) <= 11
    Then we see that the only values that maximize the objective within the constraints are (x,y) = (11/4, 11/4) which if we are talking about integers, does not exists as a vertice. 


    3.[C] Exercise 7.10.

Using the algorithm described on p200:
1. Start with zero flow
2. Repeat:
    a) choose an appropriate path from s to t
    b) increase flow along edges of this path as much as possible

So. First, all edges have 0 flow. Then taking each 3 possible routes from sink S, I try to maximize flow to T. 

    S, A, D, G, T = 4
    S, B, E, G, T = 1
    S, C, F, T = 4

With a total flow |f| = 4 + 1 + 4 = 9
I can then again, look for nodes I have not used to maximize flow so I find more paths:

    S, A, B, E, G, T = 2
    S, C, B, E, G, T = 2

With a new total flow |f| = 13
I think this is the maximum so I check with a minimum cut. 

Since S -> A, S -> B, C -> B, and F->T are maxed we can partition the graph into the two subgraphs:

P = {A, B, D, E, G, T}
P' = [S, C, F}

According to max-flow (7.6), the current flow is optimal if the current max flow matches the total sum of capacities from all p' in P'to p in P. 
We have the following "bridges"
    S - A = 6
    S - B = 1
    C - B = 2
    F - T = 4
    With a sum of: 13
Since the cut matches the current max flow, we know that this is the optimal solution. 

    4.[C] Exercise 7.17.

    5.[C] Exercise 7.18.
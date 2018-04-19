Alg Knapsack homework
Homework 26   Due Thursday, 4-19-18
A. Exercise

    1.[C] If F(n) = (n<=0) ? n : F(n-2) + F(n-4) + F(n-6), then what is F(100)? Please give code as well as a number as your solution.

    2.[C] Solve the edit distance problem brute force, recursively, and estimate the running time empirically. Is the number of recursive function calls close to 3n, 3n2, or something else? Submit the code via git.

B. Reading

    1. Please read section 6.4 (knapsack). The video below also has an explanation to supplement the reading.

C. Exercises

    1.[C] Create an example of a knapsack problem with four items, and solve it by hand. Provide both the problem and the solution.

    2.[C] Create an example of a knapsack problem with a different set of five items, and solve it by hand. Provide both the problem and the solution.

    3. Implement the knapsack dynamic programming solution in C++, and test it with the examples you have created above. Submit your code through git.

    4.[C] Consider the problem instance given in the knapsack section, where W=10. To 'shrink' the problem, the book suggests either considering smaller capacities or fewer items. Does it work if you consider fewer items? If it works, what are the sub-problems and what DAG do you get for this instance? If it doesn't work, why not?

    5.[C] Another idea is to instead 'shrink' the dollar value of the items in the knapsack. Does this approach also work? If it works, what are the sub-problems and what DAG do you get for this instance? If it doesn't work, why not?

    6.[C] Exercise 6.17 (change-making).
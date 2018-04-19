Alg Knapsack homework
Homework 26   Due Thursday, 4-19-18

value(0) = 0
for w from 1 to W:
    value(w) = 0
    for i from 1 to n:
        if wi <= w:
            val = value(w-wi) + vi
            if val > value(w):
                value(w) = val
return value(W)
        
A. Exercise

    1.[C] If F(n) = (n<=0) ? n : F(n-2) + F(n-4) + F(n-6), then what is F(100)? Please give code as well as a number as your solution.

The bottleneck in this recurrence is F(n-2) because it spawns the most nodes. An upper estimate can therefore be 3 * O(F(n-2)). Since F(n-2) is running n/2 times, Time complexity is linear, O(4,5n)

    2.[C] Solve the edit distance problem brute force, recursively, and estimate the running time empirically. Is the number of recursive function calls close to 3n, 3n2, or something else? Submit the code via git.

Both the recursive and brute force method are quadratic solutions. Looking at the number of output needed (filling a n*m grid) this solution is optimal. It is closer to 3n^2

B. Reading

    1. Please read section 6.4 (knapsack). The video below also has an explanation to supplement the reading.

C. Exercises

    1.[C] Create an example of a knapsack problem with four items, and solve it by hand. Provide both the problem and the solution.

This is knapsack 0 1:
Item    weight
1       5
2       3
3       10
4       1
w=17
none of the single items go above the weight limit
{1,2} = 8
{1,3} = 15
{1,4} = 6
{2,3} = 13
{2,4} = 4
{3,4} = 11
{1,2,3} = 18
{1,2,4} = 9
{1,3,4} = 16
{2,3,4} = 14
{1,2,3,4} = 19
Greatest "loot" is items {1,3,4} gets me a total value of 16 <w

    2.[C] Create an example of a knapsack problem with a different set of five items, and solve it by hand. Provide both the problem and the solution.

Stock   Price
BAC 	$ 29.895
MU      $ 52.445
GE      $ 13.965 
PM 	    $ 86.82 
TVIX 	$ 7.085 
Budget(w) = $100

BAC and MU = 82.34
BAC and GE = 43.86
BAC and PM = 116.715
BAC and TVIX = 36.98
MU and GE = 66.41
MU and PM = 139.265
MU and TVIX = 59.53
GE and PM = 100.785
GE and TVIX = 21.05
PM and TVIX = 93.905
Biggest investment with current budget is PM and TVIX at 93.905

    3. Implement the knapsack dynamic programming solution in C++, and test it with the examples you have created above. Submit your code through git.

    4.[C] Consider the problem instance given in the knapsack section, where W=10. To 'shrink' the problem, the book suggests either considering smaller capacities or fewer items. Does it work if you consider fewer items? If it works, what are the sub-problems and what DAG do you get for this instance? If it doesn't work, why not?

I'm not sure if I interpret the question correctly but I would assume that considering fewer items is only effective in a 1/0 knapsack. So that the W*n time complexity gets smaller by the nature of W being smaller. The underlying problems is to find the max value of all combinations of items. So if I am considering item i, I can either replace i-1, j-1, or i-1,j-1. Similarly to the edit distance problem. By always picking the largest, a path can be found that maximizes the "loot".

    5.[C] Another idea is to instead 'shrink' the dollar value of the items in the knapsack. Does this approach also work? If it works, what are the sub-problems and what DAG do you get for this instance? If it doesn't work, why not?

    6.[C] Exercise 6.17 (change-making).
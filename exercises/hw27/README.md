Alg Shortest paths homework
Homework 27   Due Sunday, 4-22-18
A. Reading

    1. Please read section 6.6 (shortest paths).

B. Exercises

    1.[C] Exercise 6.5 (page 178).

Pebbling a checkerboard. We are given a checkerboard which has 4 rows and n columns, and has an integer written in each square. We are also given a set of 2n pebbles, and we want to place some or all of these on the checkerboard (each pebble can be placed on exactly one square) so as to maximize the sum of the integers in the squares that are covered by pebbles. There is one constraint: for a placement of pebbles to be legal, no two of them can be on horizontally or vertically adjacent squares (diagonal adjacency is fine).

(a) Determine the number of legal patterns that can occur in any column (in isolation, ignoring the pebbles in adjacent columns) and describe these patterns.

Ignoring adjacent columns, gives us the following possible patterns:
    1 The empty checkerboard
    2 One pebble on row 1
    3 One pebble on row 2
    4 -||- row 3
    5 -||- row 4
    6 Two pebbles, row 1 and 3
    7 -||- row 1 and 4
    8 -||- row 2 and 4

A total of 8 possibilities.

Call two pattterns compatible if they can be placed on adjacent columns to form a legal placement. Let us consider subproblems consisting of the first k columns 1 <= k <= n. Each subproblem can be assigned a type, which is the pattern occurring in the last column. 

(b) Using the notions of compatibility and type, give an O(n)-time dynamic programming algorithm for computing and optimal placement. 

Drawing from the Knapsack logic, each legal pattern can be represented by an array of length n. So 8 arrays of length n. If I understand the problem correctly, an example of a legal pattern is (1)->(2-8), (2)->(4), (3)->(5) etc. The optimal solution places a maximum amount of pebbles on the board. 

So, running a loop on each index of the array (n), we place the current isolated score in each index. On the second run through, we update these values by checking all 8 array columns against each other (8n) to find the greatest legal combination in combination with the previous column. 
    Cj[x] = Cj-1[i] + Sj[x]
Where C=Combined results array. S=single legal array. j=current column, i=current legal pattern, x=the current greatest score.

This will run something like 10n but its still linear O(n). 

    2.[C] Exercise 6.7 (page 179).

A subsequence is palindormic if it is the same whether read left to right or right to left. For instance, the sequence
    A, C, G, T, G, T, C, A, A, A, A, T, C, G
has many palindromic subsequences, including A,C,G,C,A and A, A, A, A (on the other hand, the subsequence A,C,T is not palindromic). Devise an algorithm that takes a sequence x[1...n] and returns the (length of the) longest palindromic subsequence. Its running time should be O(n^2).

For a string s[1...n]. Outer loop runs n times, running through all values [1...n-1] with index value i. Inner loop runs i times, checking values [1...n-i] with index value k. For each loop we assign j=k+i and check if s[i] == s[j]. If true, store in a indexed array Arr[i,j] = Arr[i+1, j-1]+2. Else, assign 0. This is the bottleneck that I believe takes polynomial time to complete. To return the greatest palindome, the greatest value in the array Arr is found, then extracted through index backtracking. 

    3.[C] Exercise 6.16 (page 181)


    4.[C] Exercise 6.18 (page 181)
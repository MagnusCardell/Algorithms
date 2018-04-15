Alg Edit distance homework
Homework 24   Due Sunday, 4-15-18
A. Reading

    1. Please skim sections 6.1 and 6.2 (we'll come back to these after break).

    2. Please read section 6.3 carefully.

    3. Here is an Open MIT video that talks about Edit Distance, you can look at this if you want some more explanation. You might skip the part about knapsack at the end, though.

    Insert character c
    Delete character c
    Replace c with c'

B. Exercises

    1.[C] Write out the table of sub-problems shown in Figure 6.4, but make it for the words anagram and agnar instead of exponential and polynomial. Do you get an edit distance of 5?

        a   g   n   a   r

    0   1   2   3   4   5

a   1   0   1   2   3   4

n   2   1   1   1   2   3

a   3   2   2   2   1   2

g   4   3   2   3   2   2

r   5   4   3   3   3   2

a   6   5   4   4   3   3

m   7   6   5   5   4   4

No, I get edit distance of 4. 
a _ _ g n a r
a n a g r a m
With 2 insertions, and 2 substitutions

    2. Implement the edit distance algorithm given in the book, and check your result for anagram and agnar. Please submit your code through git.

    3. The edit distance between two words can be defined in many ways. Suppose that the cost of a substitution is half the cost of an insertion or deletion. Modify your algorithm to compute this revised edit distance, and test with the same word pair.

    4. Revise your program once more to find the longest common subsequence between two words. In this case, substitution is not allowed per se, but insert and delete are. Check the video above for an example and more info on it!
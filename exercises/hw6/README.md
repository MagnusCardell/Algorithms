Homework 6   Due Thursday, 2-22-18
A. Reading

    1. Take a look at this vector reference page http://en.cppreference.com/w/cpp/container/vector from about STL vectors. If you've never read this kind of documentation before, don't worry: the main thing for now is to figure out the example code at the very end. As you become more familiar with the terminology around STL containers, you may want to consult this reference multiple times in the future.

    2.[C] Working from the example at the end, write a short program that puts a random number of zeros into a vector of int (using a loop), and then prints them out (also using a loop).
    
See vector_example.cpp

B. Tree Structure

    1.[C] If you have a tree with 5 branches at each node, and height 3, how many nodes are there total on the tree?
Using the geometric series formula, there will be 156 nodes in that branch. See photo for logic

    2.[C] If you have a tree with 5 branches at each node, and height log base 3 of n, how many nodes are there on the lowest level (the leaves)?
Since n is a variable, the number of leafnodes are 5^(logn(base3)+1)

C. Sorting Algorithm
    Stogit work, not written here.
    1.[C] Who is your partner on this part of the homework?

    2.[C] Design your own sorting algorithm, and describe it in pseudo-code.

    3.[C] Analyze your algorithm: what is the time complexity, where n is the size of the input array? Please explain your reasoning.

    4. Implement your algorithm in C++, please submit the code via git. Feel free to look back at the first homework, if you want to make use of some existing code. However, don't run your code yet!

    5.[C] Refine your analysis: are there any elements of the time complexity that you would like to change, now that you see how your algorithm looks as actual code?

    6.[C] Debug, run, and time your code. How close was your analysis?

    7. Time your algorithm for a variety of input sizes, and build a graph that shows how long it takes to run for various values of n. The graph does not need to be put on the wiki (see next item.)

    8.[C] Put together three slides that 1) explain your algorithm, 2) provide the analysis, and 3) show the graph of actual running time. If you are using google docs, make a link from your homework to your slides. Otherwise, please e-mail the TAs a copy. Hopefully, everyone will present their algorithm (using their slides) on Thursday.
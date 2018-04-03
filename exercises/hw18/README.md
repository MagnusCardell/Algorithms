Alg Conserving water homework
Homework 19   Due Tuesday, 4-3-18
A. Reading

    1. Please skim sections 4.5, 4.6, and 4.7. Pay close attention to the binary heap... I'm asking you to implement one below.

    2. Here is a good visualization for a binary heap and Here is a tutorial on priority queues and binary heaps

B. Exercises

    1. Build a binary heap to use as part of your shortest path algorithm. The interface to your class should include methods for insert and deleteMin. You can test your heap by inserting a sequence of numbers like 8, 7, 15, 14, and then check that you get the right numbers back out by repeatedly calling deleteMin (to get 7, 8, etc.) Submit your code through git. 

    2.[C] Exercise 4.12, page 121.

    3.[C] Solve the pouring water problem from a prior homework (the 3-bucket version) with the following additional constraint: we want to minimize the total amount of water that is poured out of any given container. That is, we will consider the distance between two nodes to be the amount of water that is poured out during that move. As output, show the sequence of nodes for a shortest path, as well as the total distance traveled from the start to the goal. Please submit the code via git and copy your output here.
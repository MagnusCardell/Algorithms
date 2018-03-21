Alg Dijkstra homework
Homework 18   Due Thursday, 3-22-18
A. Reading
The topic of our next class is an algorithm for computing the shortest path between two points in a graph (which could be derived from a map). The Dijkstra algorithm (pronounced dike-stra) is fairly intuitive at one level: keep track of an expanding front of all nodes that are roughly the same distance from your start node.

    1. Before reading the book, check out this animation on Wikipedia. In the animation, we start at the red dot and grow the area for which we know the shortest paths until we reach the green dot. You can reload the page to restart the animation.

    2. Please carefully read sections 4.3 and 4.4.

    3. Now that you've read about Dijkstra's algorithm, please take a look at this animation to observe how various details are handled: DijkstrasAlgo.html

B. Exercises

    1.[C] Exercise 4.1, page 120.

    2. Implement a very simple priority queue, as described at the beginning of section 4.5, based on an array. Please submit the code through git.

    3. Implement Dijkstra's shortest path algorithm, as given in section 4.4.1. Use whatever graph representation you prefer, and test on some small graph that you construct by hand. Please submit the code through git.
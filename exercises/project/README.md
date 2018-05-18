Take Home Final

1. Implement a solution to the set cover example in the text on the bottom of page 145 and on page 146.  Please make your program general enough to handle other sets of cities and distances.  Your input interface should be file based for convenience and flexibility.  Create or look up a couple of additional examples of a set of cities and a distance and execute your code on them as well.

See file set_cover.txt
This implementation uses the greedy solution to pick vertices that cover the graph. Compile the file with:
    g++ -std=c++11 -Wall -o set_cover.cpp set_cover.o
Execute with:
    ./set_cover.o
By default, it runs on the graph found on page 146. To change to another graph, change the input file in main(). It accepts any file input with DIMACS format. 


2. In your text on the bottom half or page 171 and on the top half of page 172 there is an introductory section entitled Shortest reliable paths.  This section discusses a dp algorithm for the shortest path from vertex s to vertex t with no more than k edges.  Implement this algorithm.  Find or construct a reasonably sized graph and run your code on it.  In addition, construct a dp matrix solution to the graph given at the bottom of page 171.

See file shortest_path.cpp. Compile with:
    g++ -std=c++11 -Wall shortest_path.cpp -o shortest_path.o  
Run with:
    ./shortest_path.o

By default this program runs VERBOSE meaning that it prints the complete dp matrix and the graph it is reading from. To change to another graph, change the input file in main(). It accepts any file input with DIMACS format. 


3. Create a detailed pseudo code for the simplex algorithm.  The simplex algorithm is explained in your text starting on page 213 and extends to the top of page 221.  What you are to do is to understand and to distill this descriptive explanation into pseudo code.

See file simple.txt

4. Find an online simplex tool/calculator and use it to solve the simplex problem contained in section 7.1.2 in your text.

See brainstorming done in file: Linear_programming.txt and the implementation in Algo_final_LP.nb. The latter is a mathematica notebook that uses the Linear Programming engine Minimize().

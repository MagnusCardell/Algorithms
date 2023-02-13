#include <iostream>
#include <vector>
using namespace std;

#define V 4
#define INT_MAX 999
/*
Travelling Salesman Problem (TSP): 
    Given a set of cities and distance between every pair of cities, 
    the problem is to find the shortest possible route that visits 
    every city exactly once and returns back to the starting point.
*/

// Naive implementation
//Start at any node, generate (n-1)! permutations. Check length of every permutation, return the smallest. 
int tsp_naive(int graph[][V], int s)
{
    // store all vertex apart from source vertex
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);
 
    // store minimum weight Hamiltonian Cycle.
    int min_path = INT_MAX;
    do {
 
        // store current Path weight(cost)
        int current_pathweight = 0;
         
        // compute current path weight
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
 
        // update minimum
        min_path = min(min_path, current_pathweight);
        
    } while (next_permutation(vertex.begin(), vertex.end()));
 
    return min_path;
}
 
// driver program to test above function
int main()
{
    // matrix representation of graph
    int graph[][V] = { { 0, 10, 15, 20 },
                       { 10, 0, 35, 25 },
                       { 15, 35, 0, 30 },
                       { 20, 25, 30, 0 } };
    int s = 0;
    cout << tsp_naive(graph, s) << endl;
    return 0;
}
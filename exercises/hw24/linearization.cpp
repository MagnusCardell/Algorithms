#include<iostream>
#include<list>
#include<stack>
#include<limits.h>

#define Inf INT_MAX

using namespace std;

class node {
public:
  int v;
  int weight;
  node(int v1, int w) {
    v = v1;
    weight = w;
  }
  int getv() {return v;}
  int getw() {return weight;}
};

class Graph {
  int v;

  list<node> *adj;

  void topsort(int v, bool visited[], stack<int> &Stack);
public:
  Graph(int V);

  void newEdge(int u, int v, int weight);
  void sP(int s);
};

Graph::Graph(int V) {
  v = V;
  adj = new list<node>[v];
}

void Graph::newEdge(int u, int v, int weight){
  node n(v, weight);
  adj[u].push_back(n);
}



//topological sorting helper function
void Graph::topsort(int v, bool visited[], stack<int> &Stack){
  visited[v] = true; //node has now been visited

  list<node>::iterator i;//for each node in adjacency list
  for (i = adj[v].begin(); i !=adj[v].end(); ++i) {
    node n = *i;
    if (!visited[n.getv()]){//if it hasn't been visited
      topsort(n.getv(), visited, Stack);//visit it and recur
    }
  }

  Stack.push(v);//add current node to the topological order
} //runs in o(E) in adj list of V



//shortest path function
void Graph::sP(int s){
  stack<int> Stack;//create the topological ordering
  int dist[v];//array for remembering distance to nodes

  
  bool *visited = new bool[v];//set each node to not visited
  for (int i = 0; i < v; i++) {
    visited[i] = false;
  }
  //O(V)

  for (int i = 0; i < v; i++){//sort nodes topologically
    if (visited[i]==false) {
      topsort(i, visited, Stack);
    }
  }//O(V+E)
  //will only visit new nodes once, so calls it v times with e additional calls
  
  for (int i = 0; i < v; i++)//all distances are set to Infinity
    dist[i] = Inf;
  dist[s] = 0;//distance to start node is 0
  //O(V)
  
  while (Stack.empty() == false)//OUTER LOOP
    {
      // Get the next node from topological order
      int u = Stack.top();
      Stack.pop();
      
      // Update distances of all adjacent nodes
      list<node>::iterator i;
      if (dist[u] != Inf)
        {
          for (i = adj[u].begin(); i != adj[u].end(); ++i)//INNER LOOP
	    if (dist[i->getv()] > dist[u] + i->getw())
	      dist[i->getv()] = dist[u] + i->getw();
        }
    }
  //Outer loop calls V times, inner loop sums to E
  //So runtime is O(V + E)
  
  // Print the calculated shortest distances
  for (int i = 0; i < v; i++)
    (dist[i] == Inf)? cout << i << "\tINF " << endl: cout << i << "\t" << dist[i] << endl;
}
//Runtime is O(V + E)

int main() {
  Graph g(6);
  g.newEdge(0, 1, 2);
  g.newEdge(0, 2, 1);
  g.newEdge(1, 4, 3);
  g.newEdge(1, 2, 4);
  g.newEdge(2, 3, 6);
  g.newEdge(4, 5, 1);
  g.newEdge(3, 4, 1);
  g.newEdge(3, 5, 2);

  
  int s = 0;
  cout << "Following are shortest distances from source " << s <<"\n";
  g.sP(s);
  
  return 0;
}

#include <iostream>
#include <vector>
#include <fstream>
#include<stack>
#include<limits.h>
using namespace std;

#define INF INT_MAX

bool VERBOSE = true;

typedef pair<int, int> Edge;
typedef pair<int, Edge> edge;

struct Node {
  int val;
  vector<edge> nedges;
};

struct Graph {
  Node n;
  vector<Node> adjList;
  int V, E; //number of vertexes, edges
  vector<edge> edges;

  Graph();
  Graph(int Ve, int Ed);

  void newEdge(int v1, int v2, int w);
  void eraseEdge(int v1);
  void print_edges();
  void print_nodes();
  void topsort(int v, bool visited[], stack<int> &Stack);
  void shortest_path(int s, int k);
};

Graph::Graph(int Ve, int Ed) {
  V = Ve;
  E = Ed;
  adjList.resize(Ve);
}
void Graph::newEdge(int v1, int v2, int w) { //from, to, weight
  edges.push_back({w, {v1, v2}});
  adjList[v1].val = v1;
  adjList[v1].nedges.push_back({w, {v1,v2}});
}
void Graph::eraseEdge(int v1) {
  edges.pop_back();
  adjList[v1].nedges.pop_back();
}

void Graph::print_edges() {
  vector<edge>::iterator it;
  for (it = edges.begin(); it != edges.end(); it++)
  {
    int v1 = it->second.first;
    int v2 = it->second.second;
    int w = it->first;
    cout << v1 << " -> " << v2 << ": " << w << endl;
  }
}

void Graph::print_nodes() {
  for (int i = 0, i_end = adjList.size(); i < i_end; ++i) {
    cout << adjList[i].val;
    for (int j = 0, j_end = adjList[i].nedges.size(); j < j_end; ++j) {
      cout << adjList[i].nedges[j].first << " "<<adjList[i].nedges[j].second.first <<" "<<adjList[i].nedges[j].second.second;
    }
    cout << '\n';
  }
}
void Graph::topsort(int pos, bool visited[], stack<int> &Stack){
  visited[pos] = true;

  vector<Node>::iterator it;
  for (it=adjList.begin() +pos; it !=adjList.end(); ++it) {
    Node n = *it;
    if (!visited[n.val]){
      topsort(n.val, visited, Stack);
    }
  }
  Stack.push(pos);
}
//shortest reliable path, s=start node(int), k=limit on number of edges(int)
void Graph::shortest_path(int s, int k){
  stack<int> Stack;
  int dist[V];
  int limit[V];
  bool *visited = new bool[V];
  for (int i = 0; i < V; i++) {
    visited[i] = false;
  }
  for (int i = 0; i < V; i++){
    if (visited[i]==false) {
      topsort(i, visited, Stack);
    }
  }
  for (int i = 0; i < V; i++){
    dist[i] = INF;
    limit[i] = 0;
  }
  dist[s] = 0;
  limit[s] = 0;
  
  while (!Stack.empty()) {
    int u = Stack.top();
    Stack.pop();

    vector<edge>::iterator it;
    if (dist[u] != INF & limit[u] <= k) {
      for (it = adjList[u].nedges.begin(); it != adjList[u].nedges.end(); ++it){
        int v1 = it->second.first;
        int v2 = it->second.second;
        int w = it->first;
        if (dist[v2] > dist[u] + w){
          dist[v2] = dist[u] + w;
          limit[v2] = limit[v1]++;
        }
      }
    }
  }
  //limit[s] = 0;
  if(VERBOSE){
    for (int i=0; i < V; ++i){
      (dist[i] == INF)? cout<<"Dist to Node: "<<i<< " is INF with number of edges: "<<limit[i]<<endl: 
        cout<<"Dist to Node: " <<i<< " is " << dist[i] << " with number of edges: "<<limit[i]<<endl;
    }
  }
  else{
    cout<<"Shortest path to end: " <<V<< " is " << dist[V-1] << " with number of edges: "<<limit[V-1]<<endl;
  }
}

vector<string> split(const string &line, const char *delim = " \t") {
  vector<string> word;
  size_t loc0, loc1;
  loc0 = line.find_first_not_of(delim); //location of non-delim char
  if (loc0 == string::npos)
    return word;                          //if initial position=newline - return empty vector
  loc1 = line.find_first_of(delim, loc0); // else find first position of delimiter after char
  while (loc1 != string::npos) {                                                 //while position != newline
    word.push_back(line.substr(loc0, loc1 - loc0)); //get string between first char and delimiter
    loc0 = line.find_first_not_of(delim, loc1);     // next first char after current delimiter
    if (loc0 == string::npos)
      break;                                //this is newline, exit
    loc1 = line.find_first_of(delim, loc0); //find next delimiter, repeat
  }
  if (loc0 != string::npos && loc1 == string::npos)
    word.push_back(line.substr(loc0, line.size() - loc0));
  return word;
}

int main() {
  ifstream f("page171.txt");
  string line;
  //Get first line
  getline(f, line);
  vector<string> word = split(line);
  Graph g(stoi(word[1]), stoi(word[2]));

  while (getline(f, line)) {
    vector<string> word = split(line);
    g.newEdge(stoi(word[0]), stoi(word[1]), stoi(word[2]));
  }
  f.close();

  if(VERBOSE){
    cout << "Here is the graph in edges: " << endl;
    g.print_edges();
    cout << "Here is the graph in adjacency list"<<endl;
    g.print_nodes();
  }

  int k;
  cout<<"What 'k' value?"<<endl;
  cin>> k;
  
  g.shortest_path(0, k);
  return 0;
}
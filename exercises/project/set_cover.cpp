#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
/*
Pseudocode:
for v in V:
  v.covered = false
schools[V]
Makequeue Q
while(!Q.empty){
  e = Q.first
  if(!e.covered){
    for all n in e.neighbours{
      n.covered = true
    }
    e.covered = true
    schools.apped(e)
  }
}
*/
typedef pair<int, int> Edge;
typedef pair<int, Edge> edge;

struct Node {
  int val;
  vector<int> nedges;
  bool covered;
  int previsit, postvisit;

  bool operator<(const Node& right) const { return nedges.size() < right.nedges.size(); }
};

void print_queue(vector<Node> &q){
  for (int i = 0, i_end = q.size(); i < i_end; ++i) {
    cout << q[i].val << " (" << q[i].covered << ") "<<endl;
  }
}

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
  void set_cover_greedy();
};

Graph::Graph(int Ve, int Ed) {
  V = Ve;
  E = Ed;
  adjList.resize(Ve);
}
void Graph::newEdge(int v1, int v2, int w) { //from, to, weight
  edges.push_back({w, {v1, v2}});
  adjList[v1].val = v1;
  adjList[v1].nedges.push_back(v2);
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
    cout << adjList[i].val << " (" << adjList[i].covered << ") ";
    for (int j = 0, j_end = adjList[i].nedges.size(); j < j_end; ++j) {
      cout << adjList[i].nedges[j] << " ";
    }
    cout << '\n';
  }
}

void Graph::set_cover_greedy(){
  for (int i = 0, i_end = adjList.size(); i < i_end; ++i) {
    adjList[i].covered = false;
  }

  vector<int> schools;
  vector<Node> Q = adjList;
  sort(Q.begin(), Q.end()); //Using custom priority operator defined in Node struct
  //print_queue(Q);
  cout<<adjList[8].val<<endl;
  while(!Q.empty()){
    Node t = Q.back();
    Q.pop_back();
    if(!adjList[t.val].covered){
      for(int i=0, i_end=t.nedges.size(); i<i_end; ++i){
        adjList[t.nedges[i]].covered = true;
      }
      adjList[t.val].covered = true;
      schools.push_back(t.val);
    }
  }
  cout<<"We need schools at: ";
  for(int i=0, i_end=schools.size(); i<i_end; ++i){
    cout<<schools[i]<<" ";
  }
  cout<<'\n';
  return;
}

vector<string> split(const string &line, const char *delim = " \t") {
  vector<string> word;
  size_t loc0, loc1;
  loc0 = line.find_first_not_of(delim); //location of non-delim char
  if (loc0 == string::npos)
    return word;                          //if initial position=newline - return empty vector
  loc1 = line.find_first_of(delim, loc0); // else find first position of delimiter after char
  while (loc1 != string::npos)
  {                                                 //while position != newline
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
  ifstream f("page146.txt");
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

  cout << "Here is the graph in edges: " << endl;
  g.print_edges();
  cout << "Here is the graph in adjacency list"<<endl;
  g.print_nodes();

  g.set_cover_greedy();
  return 0;
}
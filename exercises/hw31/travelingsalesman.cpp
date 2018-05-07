#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Edge;
typedef pair<int, Edge> edge;

struct Node
{
  vector<int> nedges;
  bool visited = false;
  int previsit, postvisit;
};

struct Graph
{
  Node n;
  vector<Node> adjList;
  int V, E; //number of vertexes, edges
  vector<edge> edges;

  Graph();
  Graph(int Ve, int Ed);

  void newEdge(int v1, int v2, int w);
  void eraseEdge(int v1);
  void print();
  int gen_all_cycles();
  int krusk();
  bool dfs(int startNode);
  void explore(int n, int &visitNum, int &numBackEdges);
  int tsp_dyn();
};
Graph::Graph(){

}
Graph::Graph(int Ve, int Ed){
  V = Ve;
  E = Ed;
  adjList.resize(Ve);
}
void Graph::newEdge(int v1, int v2, int w){ //from, to, weight
  edges.push_back({w, {v1, v2}});
  adjList[v1].nedges.push_back(v2);
}
void Graph::eraseEdge(int v1){
  edges.pop_back();
  adjList[v1].nedges.pop_back();
}
void Graph::print(){
    vector<edge>::iterator it;
    for (it = edges.begin(); it != edges.end(); it++){
        int v1 = it->second.first;
        int v2 = it->second.second;
        int w = it->first;
        cout << v1 << " " << v2 << " " << w << endl;
    }
    return;
}

bool Graph::dfs(int startNode){
  for (auto Node : adjList) {
    Node.visited = false;
  }
  int numBackEdges = 0;
  int visitNum = 0;
  for (int i = 0; i < adjList.size(); i++){
    if (!adjList[i].visited){
      explore(i, visitNum, numBackEdges);
    }
  }
  if (numBackEdges != 0){
    return true;
  }
  else{
    return false;
  }
}
void Graph::explore(int n, int &visitNum, int &numBackEdges){
  adjList[n].visited = true;
  adjList[n].previsit = visitNum++;
  for (auto edge : adjList[n].nedges){
    if (adjList[edge].visited){
      numBackEdges++;
    }
    else if (!adjList[edge].visited){
      explore(edge, visitNum, numBackEdges);
    }
  }
  adjList[n].postvisit = visitNum++;
}

int Graph::krusk(){
  int weight = 0;
  Graph temp(this->V, this->E);
  sort(edges.begin(), edges.end());
  vector<edge>::iterator it;
  int ctr = 1;
  for (it = edges.begin(); it != edges.end(); it++){
    if (ctr < V){
      int v1 = it->second.first;
      int v2 = it->second.second;
      int w = it->first;
      temp.newEdge(v1, v2, w);
      if (temp.dfs(0) == 1){
        temp.eraseEdge(v1);
      }
      else{
        cout << v1 << " " << v2 << " " << w << endl;
        weight = weight + w;
      }
    }
    ctr += 1;
  }
  cout << "MST Weight = " << weight << endl;
  return weight;
}

int Graph::gen_all_cycles(){

  return 0;
}

int Graph::tsp_dyn(){
  
  return 0;
}

vector<string> split(const string &line, const char *delim = " \t")
{
  vector<string> word;
  size_t loc0, loc1;
  loc0 = line.find_first_not_of(delim); //location of non-delim char
  if ( loc0 == string::npos ) return word; //if initial position=newline - return empty vector
  loc1 = line.find_first_of(delim, loc0); // else find first position of delimiter after char
  while ( loc1 != string::npos ) { //while position != newline
    word.push_back( line.substr(loc0, loc1-loc0) ); //get string between first char and delimiter
    loc0 = line.find_first_not_of(delim, loc1); // next first char after current delimiter
    if ( loc0 == string::npos ) break; //this is newline, exit
    loc1 = line.find_first_of(delim, loc0); //find next delimiter, repeat
  }
  if ( loc0 != string::npos && loc1 == string::npos )
    word.push_back( line.substr(loc0, line.size()-loc0) );
  return word;
}

int main() {   
    ifstream f("graph.txt");
    string line;
    //Get first line
    getline(f, line);
    vector<string> word = split(line);
    Graph g( stoi(word[1]), stoi(word[2]));

    while ( getline(f, line) ) {
        vector<string> word = split(line);
        g.newEdge( stoi(word[0]), stoi(word[1]), stoi(word[2]) );
    }
    f.close();

    cout<<"Here is the graph: "<<endl;
    g.print();

    g.tsp_dyn();
    return 0;

}
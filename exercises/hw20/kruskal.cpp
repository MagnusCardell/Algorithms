#include <iostream>
#include <vector>
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

  Graph(int Ve, int Ed);

  void newEdge(int v1, int v2, int w);
  void eraseEdge(int v1);
  int krusk();
  bool dfs(int startNode);
  void explore(int n, int &visitNum, int &numBackEdges);
};

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

int main(){
  Graph giraffe(3, 2);
  giraffe.newEdge(0, 1, 2);
  giraffe.newEdge(0, 2, 1);
  cout << "There is a backedge in the graph: " << giraffe.dfs(0) << endl;
  //tests the dfs with a graph with no backedges
  Graph giraffe2(3, 3);
  giraffe2.newEdge(0, 1, 2);
  giraffe2.newEdge(0, 2, 1);
  giraffe2.newEdge(1, 2, 2);
  cout << "There is a backedge in the graph: " << giraffe2.dfs(0) << endl;
  //tests dfs with back edges

  /*
  Graph krusker(6, 7);
  krusker.newEdge(0, 1, 1);
  krusker.newEdge(0, 2, 3);
  krusker.newEdge(1, 3, 2);
  krusker.newEdge(1, 4, 4);
  krusker.newEdge(2, 4, 9);
  krusker.newEdge(3, 5, 3);
  krusker.newEdge(4, 5, 4);
  int mstweight = krusker.krusk();
  */
  
  Graph krusker(8,13);
  krusker.newEdge(0, 1, 6); //from book
  krusker.newEdge(0, 4, 1);
  krusker.newEdge(1, 4, 2);
  krusker.newEdge(1, 5, 2);
  krusker.newEdge(1, 2, 5);
  krusker.newEdge(2, 3, 6);
  krusker.newEdge(2, 5, 5);
  krusker.newEdge(2, 6, 4);
  krusker.newEdge(3, 6, 5);
  krusker.newEdge(3, 7, 7);
  krusker.newEdge(4, 5, 1);
  krusker.newEdge(5, 6, 3);
  krusker.newEdge(6, 7, 3);
  int mst = krusker.krusk();
  

  return 0;
}

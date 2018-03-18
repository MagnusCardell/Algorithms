#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;

struct DIMACS{
    int nodes;
    int edges;
};

struct Graph{
    vector<struct Node> tree;
    Node* root;

    Graph(){};
    Graph(Node &r);
    void addRoot(Node *r);
    Node *getRoot();
};

Graph::Graph(Node &r){
    //this->root = r;
    tree.push_back(r);
}

void Graph::addRoot(Node *r){
    this->root =r;
}
Node* Graph::getRoot(){
    return root;
}

struct Node{
    vector<Node> neighbours; //TODO: set to ID's to save memory
    int val;

    Node(){};
    Node(int val);
    void addNeighbour(Node &n);
    void addNeighbour(int n);
    void setVal(int n);
    int getVal();
    vector<Node> getNeighbours();
    bool isLeaf();
    bool operator==(Node &b);
};

Node::Node(int v){
    this->val = v;
}

void Node::addNeighbour(Node &n){
    this->neighbours.push_back(n);
    return;
}

void Node::addNeighbour(int n){
    Node temp(n);
    this->neighbours.push_back(temp);
}

void Node::setVal(int n){
    this->val = n;
}

int Node::getVal(){
    return this->val;
}

vector<Node> Node::getNeighbours(){
    return this->neighbours;
}

bool Node::isLeaf(){
    return this->neighbours.size()==0;
}

bool Node::operator==(Node &b){
    return b.val==this->val;
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

void testline(vector<string> &word){
    for ( unsigned i=0,i_end=word.size(); i<i_end; ++i )
        cout << "," << word[i];
    cout << endl;
    return;
}
void printdoc(DIMACS &d){
    cout<< "nodes: " << d.nodes
        << ". edges: " << d.edges<<endl;
}
void printCTRL(map<string, vector<string> > &m){
    for ( auto const& it : m) {
        cout << it.first
            << ": [";
        for( string s : it.second ){
            cout<< s <<" ";
        }
        cout<<"]" << endl ;
    }
}
void printGraph(Graph &g){
    for( int i=0, i_end=g.tree.size(); i<i_end; ++i){
        cout<<g.tree[i].getVal()
            <<": ";
        vector<Node> n = g.tree[i].getNeighbours();
        for(int j=0, j_end=n.size();j<j_end; ++j){
            cout<< n[j].getVal()<< ", ";
        }
        cout<<endl;
    }
}
int main()
{
    ifstream f("graph.txt");
    //vector <string> DIMAC;
    map<string, vector<string> > dimac_ctrl;

    string line;
    bool firstline =true;
    while ( getline(f, line) ) {
        vector<string> word = split(line);
        //testline(word);
        //DIMACS doc;
        
        if(firstline){
            //doc.nodes = stoi(word[2]);
            //doc.edges = stoi(word[3]);
            firstline = false;
        }
        else{
            //cout<<word[1]<<" "<<word[2]<<endl;
            dimac_ctrl[word[1]].push_back(word[2]);
        }
        //printdoc(doc);
    }
    //printCTRL(dimac_ctrl);
    f.close();

    //ASSERT that the DIMACS file is parsed into map and we are now going to do the graph
    Graph g;
    bool first_item = true;
    
    for ( auto const& it : dimac_ctrl) {
        Node temp(stoi(it.first));
        for( string s : it.second ){
            temp.addNeighbour(stoi(s));
        }
        if(first_item){
            g = Graph(temp);
            first_item=false;
        }
        else{
            g.tree.push_back(temp);
        }
    }

    printGraph(g);
}
#include<iostream>
#include<vector>
#include<map>
using namespace std;

#define INF 999

//typedef struct Edge Edge;

struct Node{
    string name;
    int val = 0;
    int dist;
    Node *parent;
    //int dist = INF;
    bool visited;
    //map<string, vector<int> > neighbours;
    Node(){};
    Node(string n){name = n;};
    //void add_neighbours(string to, int len);
};
/*
void Node::add_neighbours(string to, int len){
    if(neighbours.count(to) <= 0){
        cout<<"N: excisting key"<<endl;
        neighbours[to].push_back(len);
    }
    else{
        cout<<"N: nw key"<<endl;
        neighbours[to].push_back(len);
    }
}
*/
typedef std::map<string, Node> my_map;

struct Graph{
    Node root;
    map <string, vector<Node> > tree;
    vector<Node> vertices;

    Graph(){};
    void add_neighbour(Node from, Node to, int len);
    void print_map();
};

void Graph::add_neighbour( Node from, Node to, int len){

    for ( auto const& it : tree) {
        if(it.first)
            << ": [";
        for( Node s : it.second ){
            cout<< s.name <<": "<<s.dist<<' ';
        }
        cout<<"]" << endl ;
    }

    if(tree.count(from.name) <= 0){
        cout<<"N: new key"<<endl;
        vertices.push_back(from);
        to.dist = len;
        tree[from.name].push_back(to);
    }
    else{
        cout<<"N: existing key"<<endl;
        to.dist = len;
        tree[from.name].push_back(to);
    }
}

void Graph::print_map(){
    for ( auto const& it : tree) {
        cout << it.first
            << ": [";
        for( Node s : it.second ){
            cout<< s.name <<": "<<s.dist<<' ';
        }
        cout<<"]" << endl ;
    }
}
/*
struct Graph{
    Node root;
    vector<Node> tree;

    void add(Node n);
    void add_root(Node n);
};

void Graph::add(Node n){
    tree.push_back(n);
}

void Graph::add_root(Node n){
    root = n;
}
*/

void print_node(Node *n){
    std::cout<<"Node length: "<< n->dist <<endl;
}
/*
void print_graph(Graph *g){
    cout<<"These are the nodes and their neighbours: "<<endl;
    for( int i=0, i_end=g->tree.size(); i<i_end; ++i){
        print_node(&g->tree[i]);
        //cout<<g->tree[i].neighbours.size()<<endl;
        for(int j=0, j_end=g->tree[i].neighbours.size(); j<j_end; ++j){
            cout<<"\t";
            //print_edge(g->tree[i].neighbours[j]);
        }
        cout<<'\n';
    }

}
*/

//Construct method, to initialize a graph by hand
//I am recreating the graph from the book p.111
void construct_graph(Graph *g){
    Node A("A");
    Node B("B");
    Node C("C");
    Node D("D");
    Node E("E");

    g->add_neighbour(A, B, 4);
    g->add_neighbour(A, C, 2);
    g->add_neighbour(B, C, 3);
    g->add_neighbour(B, D, 2);
    g->add_neighbour(B, E, 3);
    g->add_neighbour(C, B, 1);
    g->add_neighbour(C, D, 4);
    g->add_neighbour(C, E, 5);
    g->add_neighbour(E, D, 1);
    return;
}


void do_dijkstra( Graph *g){
    cout<<"Starting Dijkstra's shortest path algorithm"<<endl;

    // 1. Set all values to infinite
    for( int i=0, i_end=g->vertices.size(); i<i_end; ++i){
        g->vertices[i].val = INF;
        cout<<g->vertices[i].name<<" "<<g->vertices[i].val<<endl;
    }
    /*

    // 2. Create a lookup table 
    vector <Node*> queue;

    // 3. Add root or starting point and set its distance to 0
    Node *root = &g->root;
    root->val = 0;
    queue.push_back(root);
    //cout<<queue.size();
    cout<<root->neighbours[0]->to.neighbours[0]->to.name<<endl;

    // 4. Start search until all nodes have found a shortest distance
    while(!queue.empty()){
        // a) find and delete current smallest value
        int smallest = INF;
        int index = INF;
        Node *temp;
        
        for(int i=0, i_end=queue.size(); i<i_end; ++i){
            if(queue[i]->val < smallest) {
                smallest = queue[i]->val;
                temp = queue[i];
                index = i;
                break;
            }
        }
        if(index == INF) cout<<"Something went wrong, no smallest value found"<<endl;
        queue.erase(queue.begin() +index);
        //cout<<smallest<<endl;
        //cout<<index<<endl;
        cout<<"Visiting: "<<temp->name<<endl;
        cout<<"Neighbour count: "<<temp->neighbours.size()<<endl;

        //cout<<temp.neighbours.size()<<endl;
        // b) add all edges and their distance values to their data structure
        for(int i=0, i_end=temp->neighbours.size(); i<i_end; ++i){
            //cout<<"HYE"<<endl;
            
            queue.push_back(&temp->neighbours[i]->to);
        }
        cout<<queue.size()<<endl;
        //Node *temp = dist[0];
    }
*/
    return;
}

int main(){

    Graph g;
    construct_graph(&g);
    print_node(&g.root);
    g.print_map();

    do_dijkstra(&g);

}
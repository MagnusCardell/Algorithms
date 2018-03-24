#include<iostream>
#include<vector>
#include<map>
using namespace std;

#define INF 999

typedef struct Node Node;

struct Edge{
    Node *from;
    Node *to;
    int length;
    
    Edge(Node* n1, Node* n2, int l);
};

Edge::Edge(Node* n1, Node* n2, int l){
    from = n1;
    to = n2;
    length = l;
}

struct Node{
    Node *parent;
    string name;
    int val;
    bool visited = false;
    Node(){};
    Node(string s);

};
Node::Node(string s){
    name = s;
    val = 0; //Root is always 0
}


struct Graph{
    Node *root;
    vector<Edge> vertices;
    vector<Node> tree;

    void add(Edge e);
    void add(Node n);
    void add_root(Node *n);
};

void Graph::add(Edge e){
    vertices.push_back(e);
}
void Graph::add(Node n){
    tree.push_back(n);
}

void Graph::add_root(Node *n){
    root = new Node();
    root->name = n->name;
    root->val = n->val;
}

void print_node(Node *n){
    cout<<n->name<<": "<<n->val<<endl;
}
void print_edge(Edge *e){
    cout<< e->length<<endl;
}
void print_graph(Graph *g){
    cout<<"These are the nodes: "<<endl;
    for( int i=0, i_end=g->tree.size(); i<i_end; ++i){
        print_node(&g->tree[i]);
    }
    cout<<'\n';

    cout<<"These are all the vertices: "<<endl;
    for( int i =0, i_end=g->vertices.size(); i<i_end; ++i){
        print_edge(&g->vertices[i]);
    }
}

//Construct method, to initialize a graph by hand
//I am recreating the graph from the book p.111
void construct_graph(Graph *G){
    Node A("A");
    Node B("B");
    Node C("C");
    Node D("D");
    Node E("E");
    G->add(A);
    G->add(B);
    G->add(C);
    G->add(D);
    G->add(E);
    G->add_root(&A);

    Edge t1(&A, &B, 4);
    Edge t2(&A, &C, 2);
    Edge t3(&B, &C, 1);
    Edge t4(&C, &B, 3);
    Edge t5(&B, &D, 2);
    Edge t6(&B, &E, 3);
    Edge t7(&C, &D, 4);
    Edge t8(&E, &D, 1);
    Edge t9(&C, &E, 5);

    G->add(t1);
    G->add(t2);
    G->add(t3);
    G->add(t4);
    G->add(t5);
    G->add(t6);
    G->add(t7);
    G->add(t8);
    G->add(t9);

    return;
}

Node *find_smallest_to_visit(map<string, int> *d, map<string, bool> *v ){
    
}

void do_dijkstra( Graph *g){
    Node *root = g->root;
    for( int i=0, i_end=g->tree.size(); i<i_end; ++i){
        g->tree[i].val = INF;
        g->tree[i].parent = NULL;
    }
    //print_graph(g);
    map<string, int> dist;
    dist[root->name] = 0;
    map<string, bool> visited;
    visited[root->name] = false;

    //Node nodes[g->tree.size()];
    //nodes[0] = *root;

    for(int i =0, i_end=g->tree.size(); i<i_end; ++i){
        Node *temp = find_smallest_to_visit(&dist, &visited);
    }

}
int main(){

    Graph g;
    construct_graph(&g);
    print_node(g.root);
    print_graph(&g);

    do_dijkstra(&g);

}
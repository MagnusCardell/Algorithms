#include<iostream>
#include<vector>
#include<map>
using namespace std;

#define INF 999

//typedef struct Edge Edge;

struct Node{
    Node *parent;
    int name;
    int val;
    bool visited = false;
    vector<Node> neighbours;
    Node(){};
    Node(int i);
    void add_neighbour(Node to, int len);

};
Node::Node(int i){
    name = i;
    val = 0; //Root is always 0
}
void Node::add_neighbour(Node to, int len){
    neighbours[len]= to;
}
/*
struct Edge{
    Node from;
    Node to;
    int length;
    
    Edge(Node n1, Node n2, int l);
};

Edge::Edge(Node n1, Node n2, int l){
    from = n1;
    to = n2;
    length = l;
}
*/

struct Graph{
    Node root;
    //vector<Edge> vertices;
    vector<Node> tree;

    //void add(Edge e);
    void add(Node n);
    void add_root(Node n);
};
/*
void Graph::add(Edge e){
    vertices.push_back(e);
}
*/
void Graph::add(Node n){
    tree.push_back(n);
}

void Graph::add_root(Node n){
    root = n;
}

void print_node(Node *n){
    cout<<n->name<<": "<<n->val<<endl;
}
//void print_edge(Edge *e){
//    cout<< e->from.name<<"-> "<<e->to.name<<": "<< e->length<<endl;
//}
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
/*
    cout<<"These are all the vertice distances: "<<endl;
    for( int i =0, i_end=g->vertices.size(); i<i_end; ++i){
        //cout<<g->vertices[i].from.name<<endl;
        print_edge(&g->vertices[i]);
    }
*/
}

//Construct method, to initialize a graph by hand
//I am recreating the graph from the book p.111
void construct_graph(Graph *G){
    Node A(0);
    Node B(1);
    Node C(2);
    Node D(3);
    Node E(4);

    //Edge t1(A, B, 4);
    A.add_neighbour(B, 4);
    //Edge t2(A, C, 2);
    A.add_neighbour(2, 2);
    //Edge t3(B, C, 1);
    B.add_neighbour(2, 1);
    //Edge t4(C, B, 3);
    C.add_neighbour(1, 3);
    //Edge t5(B, D, 2);
    B.add_neighbour(3, 2);
    //Edge t6(B, E, 3);
    B.add_neighbour(4, 3);
    //Edge t7(C, D, 4);
    C.add_neighbour(3, 4);
    //Edge t8(E, D, 1);
    E.add_neighbour(3, 1);
    //Edge t9(C, E, 5);
    C.add_neighbour(4, 5);

    G->add(A);
    G->add(B);
    G->add(C);
    G->add(D);
    G->add(E);
    G->add_root(A);
/*
    G->add(t1);
    G->add(t2);
    G->add(t3);
    G->add(t4);
    G->add(t5);
    G->add(t6);
    G->add(t7);
    G->add(t8);
    G->add(t9);
*/  
    return;
}

//Node *find_smallest_to_visit(map<string, int> *d, map<string, bool> *v ){
    
//}

void do_dijkstra( Graph *g){
    cout<<"Starting Dijkstra's shortest path algorithm"<<endl;

    // 1. Set all values to infinite
    for( int i=0, i_end=g->tree.size(); i<i_end; ++i){
        g->tree[i].val = INF;
        g->tree[i].parent = NULL;
    }

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
    //print_graph(g);
    //map<string, int> dist;
    //dist[root->name] = 0;
    //map<string, bool> visited;
    //visited[root->name] = false;

    //Node nodes[g->tree.size()];
    //nodes[0] = *root;

    //for(int i =0, i_end=g->tree.size(); i<i_end; ++i){
    //    Node *temp = find_smallest_to_visit(&dist, &visited);
    //}

    return;
}
int main(){

    Graph g;
    construct_graph(&g);
    print_node(&g.root);
    print_graph(&g);

    do_dijkstra(&g);

}
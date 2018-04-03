#include<iostream>
#include<vector>
#include<map>
using namespace std;

#define INF 999

//typedef struct Edge Edge;

struct Node{
    string name;
    Node *parent;
    int dist = INF;
    bool visited;
    map<string, vector<int> > neighbours;

    Node(string n){name = n;};
    void add_neighbours(string to, int len);
};

void Node::add_neighbours(string to, int len){
    if(neighbours.count(to) <= 0){
        cout<<"excisting key"<<endl;
        neighbours[to].push_back(len);
    }
    else{
        cout<<"new key"<<endl;
        neighbours[to].push_back(len);
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
void construct_graph(Node *A){
    Node B("B");
    Node C("C");
    Node D("D");
    Node E("E");

    A->add_tree("B", 4);
    A->add_tree("C", 2);
    B.add_tree("C", 3);
    B.add_tree("D", 2);
    B.add_tree("E", 3);
    C.add_tree("B", 1);
    C.add_tree("D", 4);
    C.add_tree("E", 5);
    E.add_tree("D", 1);
    return;
}

/*
void do_dijkstra( Node *r){
    cout<<"Starting Dijkstra's shortest path algorithm"<<endl;

    // 1. Set all values to infinite
    for( int i=0, i_end=g->tree.size(); i<i_end; ++i){
        r->tree[i].val = INF;
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

    return;
}
*/
int main(){

    Node root("A");
    construct_graph(&root);
    print_node(&root);
    cout<<root.tree.size()<<endl;
    //print_graph(&g);

    //do_dijkstra(&root);

}
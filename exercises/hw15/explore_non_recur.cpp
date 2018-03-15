#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

class Node{
    string value;
    bool visited;
    vector<Node> neighbours;

public:
    Node(char c){
        this->value=c;
    }

    string getValue(){
        return this->value;
    }

    bool isVisit(){
        return this->visited;
    }
    void setVisited(bool b){
        this->visited = b;
    }
    vector<Node> getNeighbours(){
        return neighbours;
    }

    bool isLeaf(){
        return neighbours.size()==0;
    }

    bool operator==(Node b){
        return b.value==value;
    }
};

void previsit(Node &n, int clock){
    cout<<n.getValue()<< "pre: "<<clock<<endl;
}
void postvisit(Node &n, int clock){
    cout<<n.getValue()<< "post: "<<clock<<endl;
}
// Non recursive explore function
vector<Node> explore(Node &root){
    stack<Node> Q;
    vector<Node> children;
    vector<Node> visit;
    int clock = 0;
    previsit(root, clock);
    clock++;

    Q.push(root);

    while(!Q.empty()){
        Node t = Q.top();
        t.setVisited(1);
        postvisit(t, clock);
        clock++;
        Q.pop();

        children = t.getNeighbours();
        reverse(children.begin(), children.end());

        for(int i=0, i_end=children.size(); i< i_end; ++i){
            if(!children[i].isVisit()){
                previsit(children[i], clock);
                clock++;
                Q.push(children[i]);
            }
        }
    }
    return visit    ;
}
int main(){
    Node graph('A');
    //needs population method if this should be tested

    vector<Node> reachable = explore(graph);
    return 0;
}
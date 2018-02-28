#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

class Node{
    char value;
    vector<Node> children;

public:
    Node(char c){
        value=c;
    }

    void addChild(Node n){
        children.push_back(n);
        return;
    }

    void addChild(char n){
        Node foo(n);
        children.push_back(foo);
    }

    char getValue(){
        return value;
    }

    vector<Node> getChildren(){
        return children;
    }

    bool isLeaf(){
        return children.size()==0;
    }

    bool operator==(Node b){
        return b.value==value;
    }
};

void construct(Node *r){
    string foo;
    cout<<"Enter children string for "<< r->getValue() << " (-1 for leafnode)"<<endl;
    cin>>foo;

    if(foo == "-1"){
        return;
    }
    else{
        for(int i=0; i<foo.length(); ++i){
            Node t(foo[i]);
            construct(&t);

            r->addChild(t);
        }
    }
}
//Queue implemented breadth first search
/* Create   - a std::queue of Nodes for FIFO(first in first out)
            - a vector children
            - a string path
    Add root to queue then start search until queue is empty
            - Get the top Node
            - add its value to path
            - pop it out from the queue
            - if queue is "goal" return path
            - else loop over all children and add them to queue
            - while loop iterates
    Upon completion of search return path (no success)
*/
string breadthFirstSearch(Node root, Node goal){
    queue<Node> Q;
    vector<Node> children;
    string path = "";

    Q.push(root);

    while(!Q.empty()){
        Node t = Q.front();
        path += t.getValue();
        Q.pop();

        if(t == goal){
            return path;
        }
        children = t.getChildren();
        for(int i =0; i< children.size(); ++i){
            Q.push(children[i]);
        }
    }
    return path;
}
//Stack implemented breadth first search
/* Create   - a std::stack of Nodes for LIFO (last in first out)
            - a vector children
            - a string path
    Add root to stack then start search until stack is empty
            - Get the top Node
            - add its value to path
            - pop it out from the stack
            - if Node is "goal" return path
            - else loop over all children and add them to queue in reverse order
            - while loop iterates
    Upon completion of search return path (no success)
*/
string depthFirstSearch(Node root, Node goal){
    stack<Node> Q;
    vector<Node> children;
    string path = "";

    Q.push(root);

    while(!Q.empty()){
        Node t = Q.top();
        path += t.getValue();
        Q.pop();

        if(t == goal){
            return path;
        }
        children = t.getChildren();
        reverse(children.begin(), children.end());

        for(int i=0; i< children.size(); ++i){
            Q.push(children[i]);
        }
    }
    return path;
}
int main(){

    char start;
    cout<<"Enter root node letter"<<endl;
    cin>> start;

    Node root(start);
    construct(&root);

    char goal;
    cout<<"Ented Node letter to search for: "<<endl;
    cin>>goal;

    string bfs = breadthFirstSearch(root, goal);
    cout<<bfs<<endl;
    string dfs = depthFirstSearch(root, goal);
    cout<<dfs<<endl;

    return 0;
}
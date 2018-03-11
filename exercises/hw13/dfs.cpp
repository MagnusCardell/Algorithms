#include <iostream>
#include <string>
#include <vector>
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
    
    string dfs = depthFirstSearch(root, goal);
    cout<<dfs<<endl;

    return 0;
}
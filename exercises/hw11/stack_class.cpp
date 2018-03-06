#include <iostream>
using namespace std;

class Stack{
    int *array;

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

int main(){

}
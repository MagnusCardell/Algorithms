#include <iostream>
#include <string>

using namespace std;

int main(){
    string test = "hi";
    for ( int i=0; i<test.length(); ++i ){
        cout<< (int)test[i] <<endl;
    }
}
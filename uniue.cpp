#include <iostream>
#include <string>
#include <map>

using namespace std;

//Brute force attempt, time should be O(n^2)
bool isUnique(string in){
    for ( int i=1; i< in.length(); ++i){
        for ( int j=i; j<in.length(); ++j){
            if( in[i-1] == in[j] ){
                return false;
            }
        }
    }
    return true;
}

// Improvement with lookup table. Time should be O(n)
bool isUnique2(string in){
    map<char, int> alph;
    for( int i=0; i<in.length(); ++i){
        if( alph.count(in[i]) > 0 ){
            return false;
        }
        else{
            alph[in[i]] = (int)in[i];
        }
    }
    return true;
}

int main(){
    cout << isUnique2("phone")<<endl;
}
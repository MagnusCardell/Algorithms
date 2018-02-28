#include <iostream>
#include <string>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//Clean version, checking that every value is equal. Also equal length
bool isPermutation(string in, string p){
    if( p.length() == 0 or in.length() ==0 or in.length()!=p.length()){
        cout<<"none"<<endl;
        return 0;
    }
    sort(in.begin(), in.end());
    sort(p.begin(), p.end());

    return in == p;
}

//Lookup table version
// 3 loops, creating time complexity O(2n+n) where n is length of string
bool isPermutation2(string in, string p){
    map<char, int> mymap;
    for( int i=0; i<in.length(); ++i ){
        if(mymap.count(in[i]) <= 0){
            mymap[in[i]] = 1;
        }
        else {
            mymap[in[i]]++;
        }
    }

    for( int i=0; i<p.length(); ++i ){
        if(mymap.count(p[i]) <= 0 ){
            cout<<"no permutation"<<endl;
            return 0;
        }
        mymap[p[i]]--;
        if(mymap[p[i]] < 0){
            cout<<"nope, no perm" <<endl;
            return 0;
        }
    }

    for( int i =0; i<in.length(); ++i){
        if(mymap[in[i]] > 0){
            return 0;
        }
    }
    return 1;
}
int main(){
    cout<<"Clean version: "<< isPermutation("cdc", "cdc")<<endl;
    cout<<"Lookup version: "<<isPermutation2("cdc", "cdc")<<endl;
}
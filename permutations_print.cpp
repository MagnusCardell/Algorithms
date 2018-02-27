#include<iostream>
#include <string>
using namespace std;

void permutations(string str, string prefix){
    if(str.length() ==0) cout<<prefix<<endl;
    else {
        for ( int i=0; i<str.length(); ++i){
            string rem = str.substr(0,i) +  str.substr(i+1);
            permutations(rem, prefix+str[i]);
        }
    }
}


void permutation(string str){
    permutations(str, "");
}

int main() {
    permutation("aba");
    return 0;
}
// There will be n! leaf nodes ex. 7 * 6 * 5 * 4 * 3 * 2 * 1 possibilities. 
// This will execute n times, so O(n)=n * n!
#include <iostream>
#include <string>
using namespace std;
//This file contains brute force and recursive edit distance solutions.


//Brute force edit distance.
// Time complexity: O(m*n) where m and n are lengths of the two strings being compared 
int edit_dist(string m, string n){
    int L[m.size()+1][n.size()+1];
    for(int i=0, i_end=m.size()+1; i<i_end; ++i){
        for(int j=0, j_end=n.size()+1; j<j_end; ++j){
            L[i][j] = 0;
        }
    }
    for(int i=0, i_end=m.size()+1; i<i_end; ++i){
        L[i][0] = i;
    }
    for(int i=0, i_end=n.size()+1; i<i_end; ++i){
        L[0][i] = i;
    }
    /*
    cout<<"This is the matrix before computing edit distances"<<endl;
    for(int i=0, i_end=m.size()+1; i<i_end; ++i){
        for(int j=0, j_end=n.size()+1; j<j_end; ++j){
            cout<<L[i][j] <<" ";
        }
        cout<<'\n';
    }*/
    cout<<endl;
    
    int mini;
    for(int i=1, i_end=m.size()+1; i<i_end; ++i){
        for(int j=1, j_end=n.size()+1; j<j_end; ++j){
            int del = L[i-1][j]+1;
            int ins = L[i][j-1]+1;
            int match = L[i-1][j-1];
            if(m[i-1] != n[j-1]) ++match;

            mini = std::min(del, std::min(ins, match));
            //cout<<mini<<" ";
            L[i][j] = mini;
        }
        //cout<<'\n';
    }
    /*
    cout<<"This is the matrix after computing edit distances"<<endl;
    for(int i=0, i_end=m.size()+1; i<i_end; ++i){
        for(int j=0, j_end=n.size()+1; j<j_end; ++j){
            cout<<L[i][j] <<" ";
        }
        cout<<'\n';
    }*/
    return L[m.size()][n.size()];
}
//Recursive edit distance
//With Master Theorem, this should be T(n) = 2T(n-1) + c so the theorem does not apply
//But we can see that it recurs the tree n-times, 2 times. so it is O(n^2)
int recur_edit_dist(string m, string n, int i, int j){
    if(0 == i) return(j);
    if(0 == j) return(i);

    int mini;
    int match = recur_edit_dist(m,n,i-1,j-1);
    if(m[i] != n[j]) ++match;
    int del = recur_edit_dist(m,n,i-1,j) +1;
    int ins = recur_edit_dist(m,n,i,j-1) +1;
    
    mini = std::min(del, std::min(ins, match));

    return mini;
}
int main(){
    string n = "agnar";
    string m = "anagram";
    int dist = edit_dist(m,n);
    cout<<"Optimal edit distance (brute force) is "<< dist <<endl;
    int dist2 = recur_edit_dist(m,n, m.length(), n.length());
    cout<<"Optimal edit distance (recursive) is "<< dist2 <<endl;
    return 0;
}
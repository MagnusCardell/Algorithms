#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print2d(vector<vector<int> > G){
    for(int i=0, i_end=G.size(); i<i_end; ++i){
        for(int j=0, j_end=G[i].size(); j<j_end; ++j){
            cout<<G[i][j] <<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
}

//This is a variant that uses time O(mn) and space O(n)
int edit_dist2(string m, string n){
    vector<vector<int> > L;
    for(int i=0, i_end=m.size()+1; i<i_end; ++i){
        vector<int> t;
        for(int j=0, j_end=2; j<j_end; ++j){
            t.push_back(0);
        }
        L.push_back(t);
    }
    for(int i=1, i_end=m.size()+1; i<i_end; ++i){
        L[i][0] = i;
        L[i][1] = 0;
    }
    
    cout<<"This is the matrix before computing edit distances"<<endl;
    print2d(L);
    
    for( int i=0, i_end=n.size(); i<i_end; ++i){

        L[0][1] = i+1;
        //find optimal solution
        for(int j=1, j_end=m.size()+1; j<j_end; ++j){
            int del = L[j-1][1]+1;
            int ins = L[j][0]+1;
            int match = L[j-1][0];
            if(n[i] != m[j-1]) ++match;
            //cout<<'\t'<<del<<" "<<ins<<" "<<match<<endl;
            int mini = std::min(del, std::min(ins, match));
            L[j][1] = mini;
        }
        print2d(L);
        //copy over front row
        for(int j=0, j_end=m.size()+1; j<j_end; ++j){
            L[j][0] = L[j][1];
        }
    }
    
    cout<<"This is the matrix after computing edit distances"<<endl;
    print2d(L);
    return L[m.size()][1];
}



int main(){
    string n = "agnar";
    string m = "anagram";
    int dist = edit_dist2(m,n);
    cout<<"Optimal edit distance is "<< dist <<endl;
    return 0;
}
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
//This is the edit distance with time O(mn) and space O(mn)
int edit_dist(string m, string n){
    vector<vector<int> > L;
    for(int i=0, i_end=m.size()+1; i<i_end; ++i){
        vector<int> t;
        for(int j=0, j_end=n.size()+1; j<j_end; ++j){
            t.push_back(0);
        }
        L.push_back(t);
    }
    for(int i=0, i_end=m.size()+1; i<i_end; ++i){
        L[i][0] = i;
    }
    for(int i=0, i_end=n.size()+1; i<i_end; ++i){
        L[0][i] = i;
    }
    
    //cout<<"This is the matrix before computing edit distances"<<endl;
    //print2d(L, m.size(), n.size());
    
    int mini;
    for(int i=1, i_end=m.size()+1; i<i_end; ++i){
        for(int j=1, j_end=n.size()+1; j<j_end; ++j){
            int up = L[i-1][j]+1;
            int down = L[i][j-1]+1;
            int diagonal = L[i-1][j-1];
            if(m[i-1] != n[j-1]) ++diagonal;

            mini = std::min(up, std::min(down, diagonal));
            //cout<<mini<<" ";
            L[i][j] = mini;
        }
        //cout<<'\n';
    }
    
    cout<<"This is the matrix after computing edit distances"<<endl;
    print2d(L);
    return L[m.size()][n.size()];
}
int main(){
    string n = "agnar";
    string m = "anagram";
    int dist = edit_dist(m,n);
    cout<<"Optimal edit distance is "<< dist <<endl;
    return 0;
}
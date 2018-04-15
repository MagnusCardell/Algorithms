#include <iostream>
#include <string>
using namespace std;


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
            int up = L[i-1][j]+2;
            int down = L[i][j-1]+2;
            int diagonal = L[i-1][j-1];
            if(m[i-1] != n[j-1]) ++diagonal;

            mini = std::min(up, std::min(down, diagonal));
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

int main(){
    string n = "agnar";
    string m = "anagram";
    int dist = edit_dist(m,n);
    cout<<"Optimal edit distance is "<< dist <<endl;
    return 0;
}
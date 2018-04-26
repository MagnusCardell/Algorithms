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
int find_k(string m, string n){
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
    
    for( unsigned int i=0, i_end=n.size(); i<i_end; ++i){
        //Find K
        if( i == m.size()/2){
            int min = 999;
            for(int i=0, i_end=L.size(); i<i_end; ++i){
                for(int j=0, j_end=L[i].size(); j<j_end; ++j){
                    if (L[i][j] < min) min = L[i][j];
                }
            }
            return min;
        }
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

    return L[m.size()+1][1];
}

int hirschberg(string n, string m){
    int n_len = n.size();
    int m_len = m.size();

    int **arr, **arr2, i, j, max, arrmax, arr2max, up, down;

   if (m_len == 1 || n_len == 0){
      if (n_len == 0)
         return 0;
      for (j = 1; j <= n_len; j++){
         if (m[1] == n[j])
            return 1;
      }
      return 0;
   }

   arr[2][2];
   arr2[2][2];

   arrmax = m_len / 2;
   arr2max = m_len - arrmax;
   up = 1;
   down = 0;


    for (i = 0; i <= arrmax; i++){
      for (j = 0; j <= n_len; j++){
         if (j == 0 || i == 0)
            arr[down][j] = 0;
         else{
            if (m[i] == n[j]){
               arr[down][j] = arr[up][j - 1] + 1;
            }
            else{
               arr[down][j] = arr[up][j];
               if (arr[down][j] < arr[down][j - 1])
                  arr[down][j] = arr[down][j - 1];
            }
         }
      }
      up ^= down;//swap up and down by using EXOR
      down ^= up;
      up ^= down;
    }

    //RECURRENCE
    string n1="";
    string n2="";
    int c1=0, c2=0;
    //Find K
    int c = find_k(n,m);

    //Do recurrence
    n1 = n.substr(0,n_len/2);
    n2 = n.substr(n_len/2, n_len);
    
    int k;
    for ( k = 0; k < m_len; k++ ) {
        c1 = find_k( n1, m.substr(0, k) );
        c2 = find_k( n2, m.substr(k, m_len) );
        
        if ( c1 + c2 == c ){
            break;
        }
    }
    
    //string m1 = m.substr( 0, k );
    //string m2 = m.substr( k, m_len );
    
    string sol1 = hirschberg( n1, m );
    string sol2 = hirschberg( n2, m );

    return ( sol1 + sol2 );

}

int main(){
    string n = "agnar";
    string m = "anagram";
    string sub = hirschberg(n,m);
    cout<<sub<<endl;

    
    return 0;
}
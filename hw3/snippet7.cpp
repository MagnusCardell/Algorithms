#include<iostream>
using namespace std;

int main(){
    int n = 100;
    int x;

    for ( int i = 0; i < n; ++i ) {
      for ( int j = 0; j < i/2; ++j ) {
        i = i + 1;
      }
    }
    
    return 0;
}
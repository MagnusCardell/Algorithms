#include<iostream>
using namespace std;

int main(){
    int n = 100;
    int x;

    for ( int i = 0; i < n; ++i ) {
      for ( int j = 0; j < i; ++j ) {
        for ( int k = 0; k < j; ++k ) {
          j += k;
        }
      }
    }
    
    return 0;
}
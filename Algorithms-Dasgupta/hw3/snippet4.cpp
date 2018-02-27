#include<iostream>
#include<math.h>
#include"../hw1/elapsed_time.h"

using namespace std;

int main(){
    int n = 100;
    int x;
    start_timer(); // this function is from elapsed_time.h

    for ( int i = 0; i < n; ++i ) {
      for ( int j = 0; j < i; ++j ) {
        x = 32*sin(.32);
      }
    }
    
    double cycles = elapsed_time();  // also from elapsed_time.h
    cout << " Total cycles: " << cycles << endl;
    return 0;
}
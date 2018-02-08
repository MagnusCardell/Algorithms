#include<iostream>
using namespace std;
 
#include"elapsed_time.h"

int main()
{
  int num_iters;
  cin >> num_iters;

  start_timer(); // this function is from elapsed_time.h
    double a = 1.0;
    for ( int i = 0; i < num_iters; ++i ) a += 2.0;
  double cycles = elapsed_time();  // also from elapsed_time.h

  cout << " Total cycles: " << cycles << endl;
}
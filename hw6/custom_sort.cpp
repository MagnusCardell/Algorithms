#include <iostream>
using namespace std;
#include <stdlib.h>
#include "../hw1/elapsed_time.h"

int *initializeArray(int n, int m)
{
  // initialize an array with random values
  int *array = new int[n];
  for (int i = 0; i < n; ++i)
    array[i] = rand() % m;
  return array;
}

int *initializeBridge(int n)
{
  // initialize an array with 0 values
  int *array = new int[n];
  for (int i = 0; i < n; ++i)
    array[i] = 0;
  return array;
}

void printArray(int *arr, int N)
{
  for (int i = 0; i < N; ++i)
    cout << " " << arr[i];
  cout << endl;
}

int main()
{
  int l_len = 0;
  int b_size = 0;
  cout<<"Enter size of input: ";
  cin >> l_len;
  cout<<"Enter Max value for input array: ";
  cin >> b_size;
  const bool verbose = false;
  int *l_list = initializeArray(l_len,b_size);
  int *bridge = initializeBridge(b_size);

  if (verbose) { cout << "Input:"; printArray(l_list, l_len); }

  //start timer
  start_timer(); // this function is from elapsed_time.h
  
  for( int i=0; i<l_len; ++i){
    bridge[l_list[i]] = 1;
  }

  for( int i=0; i< b_size; ++i){
    if(bridge[i] != 0){
      l_list[i] = i;
    }
  }
  // end timer
  double cycles = elapsed_time();  // also from elapsed_time.h

  cout << " Total cycles: " << cycles << endl;
  if (verbose){ cout << "Sorted:";printArray(l_list,l_len); }
  delete[] l_list;
  delete[] bridge;
}
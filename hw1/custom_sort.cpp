#include<iostream>
using namespace std;
#include<stdlib.h>
#include"elapsed_time.h"
 
// Note:  if you save this file as 'sort.cpp' and then create an
// executable called 'sort', you will need to run the program 
// as './sort' so that you don't get the system-wide sort program.
 
int *initializeArray( int N, int X )
{
  // initialize an array with random values
  int *array = new int[N];
  for ( int i=0; i<N; ++i ) array[i] = rand()%X;
  return array;
}
int *initializeBridge( int X )
{
  // initialize an array with NO values
  int *array = new int[X];
  return array;
}

void useBridge(int *array, int *bridge, int N)
{
  for ( int i=0; i<N; ++i ) {

      int temp = array[i];
      bridge[temp] = temp;
  }
}

int cleanBridge(int *array, int *bridge, int X){
    int n = 0;
    for( int i=0; i<X; ++i ){
        if (bridge[i] != 0){
            array[n] = bridge[i];
            ++n;
        } 
    }
    return n;
}

void printArray(int *arr, int N)
{
  for ( int i=0; i<N; ++i ) cout << " " << arr[i];
  cout << endl;
}

int main()
{
  int N;
  cin >> N;
  start_timer();
  
  const int X = 100;
  const bool verbose = true;
  int *array = initializeArray(N, X);
  int *bridge = initializeBridge(X);
  if ( verbose ) { cout << "Input:"; printArray(array, N); }
 
  useBridge(array, bridge, N);
  if ( verbose ) { cout << "Bridge:"; printArray(bridge, X); }
  N = cleanBridge(array, bridge,X); //reassign N if duplicates occurred
  if ( verbose ) { cout << "Sorted:"; printArray(array, N); }
  delete [] array;
  delete [] bridge;

  double cycles = elapsed_time(); 
  cout << " Total cycles: " << cycles << endl;

}
#include<iostream>
using namespace std;
#include<stdlib.h>
 
// Note:  if you save this file as 'sort.cpp' and then create an
// executable called 'sort', you will need to run the program 
// as './sort' so that you don't get the system-wide sort program.
 
int *initializeArray( int N )
{
  // initialize an array with random values
  int *array = new int[N];
  for ( int i=0; i<N; ++i ) array[i] = rand()%1000000000;
  return array;
}
 
void printArray(int *arr, int N)
{
  for ( int i=0; i<N; ++i ) cout << " " << arr[i];
  cout << endl;
}
 
void swap(int &a, int &b)
{
  int tmp = a;
  a = b;
  b = tmp;
}
 
int findSmallest(int i, int *array, int N)
{
  int smallestIndex=-1, smallestValue = 1000000001;
  for ( int j=i; j<N; ++j ) {
    if ( array[j] < smallestValue ) {
      smallestValue = array[j];
      smallestIndex = j;
    }
  }
  return smallestIndex;
}
 
void sortArray(int *array, int N)
{
  for ( int i=0; i<N; ++i ) {
    // find the smallest element's index
    int smallestIndex = findSmallest(i, array, N);
    // put the smallest value into place
    swap( array[i], array[smallestIndex] );
  }
}
 
int main()
{
  int array[10] = {2,4,6,456};
  const int N = 10;
  const bool verbose = true;
  int *array = initializeArray(N);
  if ( verbose ) { cout << "Input:"; printArray(array, N); }
 
  sortArray(array, N);
  if ( verbose ) { cout << "Sorted:"; printArray(array, N); }
  delete [] array;
}
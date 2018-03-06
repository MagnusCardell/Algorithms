#include <iostream>
using namespace std;
#include <stdlib.h>
#include <algorithm>

int *initializeArray(int N)
{
    // initialize an array with random values
    int *array = new int[N];
    for (int i = 0; i < N; ++i)
        array[i] = rand() % 100;
    return array;
}

void printArray(int *arr, int N)
{
    for (int i = 0; i < N; ++i)
        cout << " " << arr[i];
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
    int smallestIndex = -1, smallestValue = 1000000001;
    for (int j = i; j < N; ++j)
    {
        if (array[j] < smallestValue)
        {
            smallestValue = array[j];
            smallestIndex = j;
        }
    }
    return smallestIndex;
}

void sortArray(int *array, int N)
{
    for (int i = 0; i < N; ++i)
    {
        // find the smallest element's index
        int smallestIndex = findSmallest(i, array, N);
        // put the smallest value into place
        swap(array[i], array[smallestIndex]);
    }
}

int binary_search(int *array, int left, int right, int val)
{
    if (left > right){
        return -1;
    }
    int mid = left + ((right-left) / 2);
    //cout<<array[mid]<<endl;
    if(array[mid] == val){
        return mid;
    }
    else if(array[mid] < val){
        return binary_search(array, mid+1, right, val);
    }
    else{
        return binary_search(array, left, mid+1, val);
    }
}

int main()
{
    //int array[10] = {2,4,6,456};
    const int N = 10;
    const bool verbose = true;
    int *array = initializeArray(N);
    if (verbose)
    {
        cout << "Input:";
        printArray(array, N);
    }

    sortArray(array, N);
    if (verbose)
    {
        cout << "Sorted:";
        printArray(array, N);
    }

    int result = binary_search(array, 0, N-1, 86);
    (result == -1)? cout<<"Not found"<<endl : cout<<"Found it at index: "<<result<<endl;
    delete[] array;
}
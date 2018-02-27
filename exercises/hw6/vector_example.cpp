#include <iostream>
#include <vector>
#include<stdlib.h>

int main()
{
    // Create a vector containing integers
    std::vector<int> v;
 
    // Add random amount of 0's (in the range of 100) to vector in a for loop
    int k = rand() % 100;
    for ( int i=0; i<k; ++i ){
        v.push_back(0);
    };

    //Using a separate loop, print the values of vector v
    for(int i=0; i<k; ++i) {
        std::cout << v[i] << '\n';
    }
}
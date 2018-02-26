#include <iostream>
using namespace std;

int fib1( int n ){
    if (n <= 0) return 0;
    else if( n == 1 ) return 1;
    return fib1(n-1) + fib1(n-2);
}

//TODO: write fib2 fib3 and fib4

int main(){
    int fib = fib1(10);
    cout << "fib1: (10th) "<< fib<<endl;
}
// Each node calls 2 more nodes n times. so O(n) = 2^n
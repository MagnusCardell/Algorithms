#include <iostream>
using namespace std;

//First approach, exponential fibonacci
// each stack calls two new stacks, of max length n
// total time complexity is therefore 2^n
int fib1(int n){
    if( 0==n ) return 0;
    if( 1==n ) return 1;
    return fib1(n-1) + fib1(n-2);
}

//Polynomial fibonacci
// Linear time O(n)
int fib2(int n){
    if( 0==n ) return 0;
    int arr[n+1];
    arr[0] = 0;
    arr[1] = 1;
    for( int i=2; i<n+1; ++i) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}
int main(){
    int num =0;
    cin >> num;
    int result = fib1(num);
    cout << "Exponential time: "<< result<<endl;
    result = fib2(num);
    cout << "Polynomical time: "<< result <<endl;
}
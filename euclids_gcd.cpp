#include <iostream>
using namespace std;

int euclid_gcd(int a, int b){
    if ( 0 == b) return a;
    return euclid_gcd(b, a%b);
}

int main(){
    int result = euclid_gcd(235, 70);
    cout << result<<endl;
}
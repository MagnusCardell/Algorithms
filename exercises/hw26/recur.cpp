#include <iostream>
#include <vector>
#include"../hw1/elapsed_time.h"

using namespace std;


int F(int n){
    return n<=0 ? n : F(n-2) + F(n-4) + F(n-6);
}

int main(){
    int rec = F(1);
    cout<<"Recurrence: "<< rec<<endl;

    
}
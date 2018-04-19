#include <iostream>
#include <vector>
#include"../hw1/elapsed_time.h"

using namespace std;


void recur(int n){
    if(n <= 0) return;

    recur(n-2);
    recur(n-4);
    recur(n-6);
    return;
}

int main(){
    vector<int> timing;
    vector<int> times;
    times.push_back(10);
    times.push_back(100);
    times.push_back(1000);
    times.push_back(10000);
    for(int i=0, i_end=times.size(); i<i_end; ++i){
        start_timer(); // this function is from elapsed_time.h
        recur(i);
        double cycles = elapsed_time();  // also from elapsed_time.h
        timing.push_back(cycles);
    }
    for(int i=0, i_end=timing.size(); i<i_end; ++i){
        cout<<timing[i]<<endl;        
    }
}
#include <iostream>
using namespace std;

class Stack{
    int *array;
    int LIFO_tracker;
    int MAX;

public:
    Stack(int n){
        array = new int(n);
        LIFO_tracker = 0;
        MAX = n;
    }

    int push(int n){
        if(LIFO_tracker >= MAX){
            return -1;
        }
        array[LIFO_tracker] = n;
        LIFO_tracker++;
    }

    int pop(){
        if(LIFO_tracker < 0){
            return -1;
        }
        array[LIFO_tracker-1] = 0;//Or other null value... this is not really necessary as long as LIFO_tracker decrements. 
        LIFO_tracker--;
    }

    int doPeek(){
        return array[LIFO_tracker-1];
    }
};

int main(){
    int N = 10;
    Stack LIFO(N);
    
    for( int i=0; i< N; ++i){
        LIFO.push(i);
        //cout<<LIFO.doPeek()<<endl;
    }

    for( int i=0; i< N; ++i){
        LIFO.pop();
        //cout<<LIFO.doPeek()<<endl;
    }
}
#include <iostream>
#include "../hw1/elapsed_time.h"
using namespace std;
/*
Implement an STL stack
*/
/* 
This is a similar implementation to my stack1 and stack2 programs. Using the doubling in size when full, 
I will let the array keep track of all values. 
*/
class Stack{
    int size;
    int *array;
    int LIFO_tracker; //doubles as a size indicator
    int MAX;
    static const int first_size = 5;

private:
    void expand_stack(){    
        int *temp_arr = new int(MAX * 2);
        for(int i=0; i<MAX; ++i){
            temp_arr[i] = array[i];
        }
        *array = *temp_arr;
        MAX *= 2;
    }
public:
    Stack(){
        array = new int(first_size); 
        LIFO_tracker = 0;
        MAX = first_size;
    }

    int mypush(int n){
        if(LIFO_tracker >= MAX){
            expand_stack();
        }
        //cout<<"Expanded size... "<<MAX<<endl;

        array[LIFO_tracker] = n;
        LIFO_tracker++;
    }

    int mypop(){
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
    start_timer(); // this function is from elapsed_time.h
    int N = 10;
    Stack LIFO;
    
    for( int i=0; i< N; ++i){
        LIFO.mypush(i);
        //cout<<LIFO.doPeek()<<endl;
    }

    for( int i=0; i< N; ++i){
        LIFO.mypop();
        //cout<<LIFO.doPeek()<<endl;
    }
    double cycles = elapsed_time(); // also from elapsed_time.h

    cout << " Total cycles: " << cycles << endl;
    return 0;
}
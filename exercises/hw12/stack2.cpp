#include <iostream>
#include "../hw1/elapsed_time.h"
using namespace std;
/*
2. Implement a stack based on an array, but this time double the size of the array each time it gets full. 
    Please submit the code through git.
*/
/* To explain my code, I initiate the stack with a default size of n = 5. At reach the max size, a new array is created of size 2n. 
    Every element in the first array is then copied to that new array and the old is deleted. 
    See expand_size() and uncomment the cout statements for troubleshooting.
*/
class Stack{
    int *array;
    int LIFO_tracker;
    int MAX;
    static const int first_size = 5;

public:
    Stack(){
        array = new int(first_size); 
        LIFO_tracker = 0;
        MAX = first_size;
    }

    int mypush(int n){
        int old_max = MAX;
        if(LIFO_tracker >= MAX){
            expand_stack();
        }
        //cout<<MAX<<" "<<old_max<<endl;

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

    void expand_stack(){
        int *temp_arr = new int(MAX * 2);
        for(int i=0; i<MAX; ++i){
            temp_arr[i] = array[i];
        }
        *array = *temp_arr;
        MAX *= 2;
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

    double cycles = elapsed_time(); // also from elapsed_time.h

    cout << " Total cycles: " << cycles << endl;
    return 0;
}
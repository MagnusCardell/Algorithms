#include <iostream>
using namespace std;
/*
1. Implement a stack based on a dynamically allocated array, in such a way that the stack can handle an arbitrary number of items. 
Use the reallocation policy that when the current array gets full, create a new array that is 100 elements longer than the current array, 
and copy information from one array to the other, before deallocating. Your allocation should rely on the standard C++ new operator. 
Please submit the code through git.
*/
/* To explain my code, I initiate the stack with a default size of n = 5. At reach the max size, a new array is created of size n+100. 
    Every element in the first array is then copied to that new array and the old is deleted. 
    See expand_size() and uncomment the cout statements for troubleshooting.
*/
class Stack{
    int *array;
    int LIFO_tracker;
    int MAX;
    static const int first_size = 5;
    static const int expand_size = 100;

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
        int *temp_arr = new int(MAX + expand_size);
        for(int i=0; i<MAX; ++i){
            temp_arr[i] = array[i];
        }
        delete[] array;
        *array = *temp_arr;
        MAX += expand_size;
    }
};

int main(){
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
}
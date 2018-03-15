#include <iostream>
using namespace std;

/* A queue data structure should have FIFO: First In First Out functionality 
    With this in mind, I will add data to the back of the queue, and pop from the front. 
    
    This is done from scratch, so no stl classes or vector arrays. */

struct Q{
    int *array;
    int front;
    int back;
    int MAX;
    const static int first_size = 5;

    Q(){
        array = new int(first_size);
        front = first_size-1;
        back = first_size -1;
        MAX = first_size;
    }

    void myPush(int n);
    int myPop();
    void doubleArr();
};

void Q::myPush(int n){
    if(back <= 0){
        doubleArr();
        cout<<"need to double it to: "<< MAX <<endl;
    }
    array[back] = n;
    back--;
}
int Q::myPop(){
    if(front > MAX){
        return -1;
    }
    int res = array[front];
    array[front] = 0;
    if(front!=back) --front;
    return res;
}
void Q::doubleArr(){
    int newMax = MAX * 2;
    int *temp_arr = new int(newMax);
    int j=0;
    for(int i = front, j=1; i>=0; --i, ++j){
        temp_arr[newMax-j] = array[i];
    }
    front = newMax-1;
    back = newMax-j;
    *array = *temp_arr;
    MAX = newMax;
}

void printQueue(Q &q){
    for(int i=q.front, end_i = q.back; i>=end_i; --i){
        cout<<q.array[i]<<endl;
    }
}
int main(){
    Q queue;
    //printMaxArrSize(queue);
    //printArrSize(queue);
    for(int i=0; i<10; ++i){
        queue.myPush(i);
    }
    printQueue(queue);
    //queue.myPush(1);
    //int res = queue.myPop();
    //cout<<res<<endl;


    return 0;
}
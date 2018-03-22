#include<vector>
#include<iostream>

using namespace std;

#define INF 999

struct my_prio_queue{
    int *key;
    int size;
    int clock;

    my_prio_queue(const int &s);
    bool insertkey(const int n);
    bool decreasekey(int pos, int val);
    int deletemin();
    void makequeue();
    void shift_queue(int n);
    void print_queue();
};

my_prio_queue::my_prio_queue(const int &s){
    key = new int[s];
    for(int i=0, i_end=s; i<i_end; ++i){
        key[i] = INF; //What is the best way to set to infinity?
    }
    size = s;
    clock = 0;
}

bool my_prio_queue::insertkey(const int n){
    if(clock>=size) return false;
    key[clock] = n;
    ++clock;
    return true;
}

bool my_prio_queue::decreasekey(int pos, int val){
    if (pos >= size or pos < 0) return false;
    key[pos] = val;
    return true;
}

int my_prio_queue::deletemin(){
    int min = INF;
    int pos;
    for( int i=0, i_end=size; i<i_end; ++i){
        if(key[i] < min){
            min = key[i];
            pos = i;
        }
    }
    if (min == INF) cout<<"something wrong"<<endl;
    shift_queue(pos);
    return min;
}

void my_prio_queue::makequeue(){
    for( int i=0, i_end=size; i<i_end; ++i){
        cout<<"Enter value for pos: "<< i<<endl;
        cin>>key[i];
    }
}

void my_prio_queue::shift_queue(int n){
    for(int i=n, i_end=size-1; i<i_end; ++i){
        key[i] = key[i+1];
    }
    --size;
}

void my_prio_queue::print_queue(){
    for( int i=0, i_end=size;i<i_end; ++i){
        cout <<key[i]<<" ";
    }
    cout<<'\n';
}

int main(){
    my_prio_queue Q(5);
    //Q.print_queue();

    Q.makequeue();
    //Q.print_queue();

    Q.decreasekey(2, 4);
    //Q.print_queue();

    Q.deletemin();
    //Q.print_queue();

    return 0;
}
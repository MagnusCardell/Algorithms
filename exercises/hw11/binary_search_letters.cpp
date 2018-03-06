#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include <stdlib.h>

int binary_search(vector<string> b, int left, int right, string val)
{
    if (left > right){
        return -1;
    }
    int mid = left + ((right-left) / 2);
    //cout<<array[mid]<<endl;
    if(b[mid] == val){
        return mid;
    }
    else if(b[mid] < val){
        return binary_search(b, mid+1, right, val);
    }
    else{
        return binary_search(b, left, mid+1, val);
    }
}

int main()
{
    vector<string> bag;
    bag.push_back("A");
    bag.push_back("B");
    bag.push_back("C");
    bag.push_back("D");
    bag.push_back("E");
    bag.push_back("F");
    bag.push_back("G");
    bag.push_back("H");
    bag.push_back("I");
    bag.push_back("J");
    bag.push_back("K");

    int result = binary_search(bag, 0, bag.size(), "B");

    (result == -1)? cout<<"Not found"<<endl : cout<<"Found it at index: "<<result<<endl;
}
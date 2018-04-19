#include <iostream>
#include <vector>

using namespace std;

struct stock{
    string n;
    float v;
    float b = 100;

    stock(string s, float i);
};
stock::stock(string s, float i){
        this->n = s;
        this->v = i;
    }
int main(){
    vector<stock> stocks;
    stocks.push_back(stock("BAC", 29.895));
    stocks.push_back(stock("MU", 52.445));
    stocks.push_back(stock("GE", 13.965));
    stocks.push_back(stock("PM", 86.82));
    stocks.push_back(stock("TVIX", 7.085));
    for(int i=0, i_end=stocks.size(); i<i_end; ++i){
        for(int j = i+1, j_end = stocks.size(); j<j_end; ++j){
            cout<<stocks[i].n <<" and "<<stocks[j].n <<" = "<<stocks[i].v + stocks[j].v<<endl;
        }
    }
    return 0;
}

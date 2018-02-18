#include <iostream>
using namespace std;

#include "../hw1/elapsed_time.h"
void recursion(int n)
{
    double x = 2 * 3;
    x = x * 3;

    if (n > 0)
        recursion(n / 3);
    return;
}

int main()
{
    int n = 100;
    start_timer(); // this function is from elapsed_time.h
    recursion(n);
    double cycles = elapsed_time(); // also from elapsed_time.h

    cout << " Total cycles: " << cycles << endl;
}
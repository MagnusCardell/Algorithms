#include <iostream>
using namespace std;

#include "../hw1/elapsed_time.h"

void recursion(int n)
{
    double x = 2 * 3;
    x = x * 3;

    if (n > 0)
    {
        recursion(n / 2);
        recursion(n / 2);
        recursion(n / 2);
    }
}

int main()
{
    start_timer(); // this function is from elapsed_time.h
    recursion(100);
    double cycles = elapsed_time(); // also from elapsed_time.h

    cout << " Total cycles: " << cycles << endl;
}
#include <iostream>
#include <vector>
using namespace std;
/*
3. Implement a stack based on a linked list. 
Please submit the code through git.
*/
/* To explain my code, I create a node class that have 3 values, value, prev, next. So this will be a doubly linked linked list
    - value = value for that list
    - prev = previous node in the list
    - next = next node in the list
    Then I create a linked list with a root
*/

class Stack
{
    int val;
    class Stack *next;
    class Stack *tracker;

  public:
    Stack(int n)
    {
        val = n;
        tracker = 0;
    }

    void mypush(int n)
    {
        class Stack *tempClass;
        tempClass->val = n;
        if (tracker == NULL)
        {
            //cout << "adding at the end..." << endl;
            tempClass->next = NULL;
        }
        else
        {
            //cout << "inserting..." << endl;
            tempClass->next = tracker;
        }
        tracker = tempClass;
    }

    void mypop()
    {
        if (tracker == NULL)
        {
        }
        else
        {
            class Stack *temp = tracker;
            //cout<<"Deleted element: "<< temp->val<<endl;;
            tracker = temp->next;
        }
    }

    int doPeek()
    {
        return tracker->val;
    }
};

int main()
{
    int N = 10;
    Stack linklist(-1);

    for (int i = 0; i < N; ++i)
    {
        linklist.mypush(i);
        //cout<<linklist.doPeek()<<endl;
    }

    for (int i = 0; i < N; ++i)
    {
        linklist.mypop();
        //cout<<linklist.doPeek()<<endl;
    }
}
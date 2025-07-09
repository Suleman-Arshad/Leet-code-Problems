#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
private:
    queue<int> q1, q2;

public:
    MyStack() {}

    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop()
    {
        if (!q1.empty())
        {
            q1.pop();
        }
        else
        {
            cout << "Stack is Empty\n";
        }
    }

    int top()
    {
        if (!q1.empty())
        {
            return q1.front();
        }
        else
        {
            cout << "Stack is Empty\n";
            return -1;
        }
    }

    bool empty()
    {
        if (q1.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    return 0;
}

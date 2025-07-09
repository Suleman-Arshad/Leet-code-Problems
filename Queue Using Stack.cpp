#include <iostream>
#include <stack>
using namespace std;
class MyQueue
{
public:
    MyQueue()
    {
    }
    stack<int> s1, s2;
    void transfer()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
                /* code */
            }
        }
    }
    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        transfer();
        int n = s2.top();
        s2.pop();
        return n;
    }

    int peek()
    {
        transfer();
        return s2.top();
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

int main()
{
    MyQueue q;
    q.push(1);
    q.push(2);

    system("pause");
    return 0;
}
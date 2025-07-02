#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> st;
    stack<int> st2;
    int num;
    cout << "Enter numbers for stack and press any non_numeric number to stop\n";
    while (cin >> num)
    {
        st.push(num);
        /* code */
    }
    if (st.empty())
    {
        cout << "Stack is Empty\n";
        /* code */
    }
    else
    {
        int n = st.size() / 2;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = st.top();
            st.pop();
            /* code */
        }
        cout << "Middle Element of Stack : " << st.top() << endl;
        st.pop();
        int a;
        for (int i = n - 1; i >= 0; i--)
        {
            /* code */
            a = arr[i];
            st.push(a);
        }
        int nup;
        while (!st.empty())
        {
            nup = st.top();
            st2.push(nup);
            st.pop();
            /* code */
        }
        cout << "Stack after removing middle element\n";
        while (!st2.empty())
        {
            /* code */
            cout << st2.top() << endl;
            st2.pop();
        }
        arr = NULL;
        delete[] arr;
    }
    system("pause");
    return 0;
}
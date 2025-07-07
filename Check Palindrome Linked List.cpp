#include <iostream>
#include <stack>
using namespace std;
class node
{
public:
    int value;
    node *next;
    node(int v)
    {
        value = v;
    }
};
class SLL
{
public:
    node *head;
    SLL()
    {
        head = NULL;
    }
    void push(int v)
    {
        node *nnode = new node(v);
        if (!head)
        {
            nnode->next = NULL;
            head = nnode;
        }
        else
        {
            node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = nnode;
            nnode->next = NULL;
        }
    }
    void check()
    {
        stack<int> temp;
        stack<int> copy;
        stack<int> reverse;
        node *current = head;
        while (current != NULL)
        {
            temp.push(current->value);
            copy.push(current->value);
            current = current->next;
            /* code */
        }
        while (!temp.empty())
        {
            /* code */
            reverse.push(temp.top());
            temp.pop();
        }
        while (!copy.empty() && !reverse.empty())
        {
            if (copy.top() == reverse.top())
            {
                copy.pop();
                reverse.pop();
                /* code */
            }
            else
            {
                break;
            }
            /* code */
        }
        if (copy.empty() && reverse.empty())
        {
            cout << "Linked list is palindrome\n";
            /* code */
        }
        else
        {
            cout << "Linked list is not palindrome\n";
        }
    }
    void display()
    {
        node *current = head;
        cout << "========== Modified Linked List ==========\n";
        while (current != NULL)
        {
            cout << current->value << endl;
            current = current->next;
        }
    }
};
int main()
{
    SLL s;
    int n;
    cout << "========== Enter Elements of Linked List ==========\n";
    while (cin >> n)
    {
        s.push(n);
    }
    s.check();
    // s.display();
    system("pause");
    return 0;
}
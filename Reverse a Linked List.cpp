#include <iostream>
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
    void reverse()
    {
        node *back = NULL;
        node *current = head;
        node *forward;
        while (current != NULL)
        {
            forward = current->next;
            current->next = back;
            back = current;
            current = forward;
            /* code */
        }
        head = back;
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
    s.reverse();
    s.display();
    system("pause");
    return 0;
}
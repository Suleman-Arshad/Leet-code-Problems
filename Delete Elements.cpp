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
    void Delete_Elements()
    {
        node *current = head;

        while (current != NULL)
        {
            node *prev = current;
            node *temp = current->next;

            while (temp != NULL)
            {
                if (temp->value == current->value)
                {
                    // Duplicate found: remove the node
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                }
                else
                {
                    // Move forward
                    prev = temp;
                    temp = temp->next;
                }
            }
            current = current->next;
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
    s.display();
    s.Delete_Elements();
    s.display();
    return 0;
}
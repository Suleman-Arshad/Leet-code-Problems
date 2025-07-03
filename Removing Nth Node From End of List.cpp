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
//RNNFL means Removing Nth Node from last of List
    void RNNFL(int n)
    {
        if (!head)
        {
            /* code */
            cout << "Linked List is Empty\n";
        }
        else if (n == 1 && head->next == NULL)
        {
            head = NULL;
            delete head;
        }
        else
        {
            node *current = head;
            int size = 0;
            while (current != NULL)
            {
                current = current->next;
                size++;
                /* code */
            }
            if (size == n)
            {
                node *first = head;
                head = first->next;
                first = NULL;
                delete first;
            }
            else
            {
                int index = size - n;
                node *prev = head;
                current = prev->next;
                for (int i = 0; i < index - 1; i++)
                {
                    /* code */
                    prev = prev->next;
                    current = current->next;
                }
                prev->next = current->next;
                current = NULL;
                delete current;
            }
        }
    }
    void display()
    {
        if (!head)
        {
            cout << "Linked List is Empty\n";
        }
        else
        {
            node *current = head;
            cout << "========== Modified Linked List ==========\n";
            while (current != NULL)
            {
                cout << current->value << endl;
                current = current->next;
            }
        }
    }
};
int main()
{
    SLL s;
    int n, index;
    cout << "Enter Index : ";
    cin >> index;
    cout << "========== Enter Elements of Linked List ==========\n";
    while (cin >> n)
    {
        s.push(n);
    }
    s.RNNFL(index);
    s.display();
    system("pause");
    return 0;
}

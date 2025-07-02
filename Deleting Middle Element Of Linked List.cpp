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
    void Delete_Middle_Element()
    {
        // This is Edge case that is used to check if there is only one element or no element in Linked list this is used only on leetcode or when you need to return head not if you work in ADTs
        //  if (!head||head->next==NULL)
        //  {
        //      return nullptr;
        //      /* code */
        //  }

        int len = 0;
        node *current = head;
        while (current != NULL)
        {
            current = current->next;
            len++;
        }
        node *prev = head;
        current = prev->next;
        int halflen = (len / 2) - 1;
        for (int i = 0; i < halflen; i++)
        {
            prev = prev->next;
            current = current->next;
        }
        prev->next = current->next;
        current = NULL;
        delete current;
    }
    void display()
    {
        node *current = head;
        cout<<"========== Modified Linked List ==========\n";
        while (current != NULL)
        {
            cout << current->value<<endl;
            current = current->next;
        }
    }
};
int main()
{
    SLL s;
    int n;
    cout<<"========== Enter Elements of Linked List ==========\n";
    while (cin >> n)
    {
        s.push(n);
    }
    s.Delete_Middle_Element();
    s.display();
    system("pause");
    return 0;
}
#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
node *binary(node *root)
{
    int v;
    cout << "Enter node value : ";
    cin >> v;
    root = new node(v);
    if (v == -1)
    {
        return NULL;
        /* code */
    }

    cout << "Enter the left node of " << v << endl;
    root->left = binary(root->left);
    cout << "Enter the right node of " << v << endl;
    root->right = binary(root->right);
    return root;
}
bool Same_Tree(node *root1, node *root2)
{
    bool check = false;
    queue<node *> q1;
    queue<node *> q2;
    q1.push(root1);
    q2.push(root2);
    while (!q1.empty() && !q2.empty())
    {
        node *temp1 = q1.front();
        node *temp2 = q2.front();
        q1.pop();
        q2.pop();
        if (!temp1 && !temp2)
        {
            check = true;
            continue;
            /* code */
        }
        else if (!temp1 || !temp2)
        {
            check = false;
            break;
            /* code */
        }

        if (temp1->data == temp2->data)
        {
            check = true;
        }
        else
        {
            check = false;
            break;
        }

        q1.push(temp1->left);

        q1.push(temp1->right);

        q2.push(temp2->left);

        q2.push(temp2->right);

        /* code */
    }
    if (!q1.empty() || !q2.empty())
    {
        check = false;
        /* code */
    }

    return check;
}
int main()
{
    node *root1 = NULL;
    node *root2 = NULL;
    cout << "Enter the data of tree 1\n";
    root1 = binary(root1);
    cout << "Enter the data of tree 2\n";
    root2 = binary(root2);
    if (Same_Tree(root1, root2))
    {
        /* code */
        cout << "Both trees are same\n";
    }
    else
    {
        cout << "Both trees are not same\n";
    }

    system("pause");
    return 0;
}
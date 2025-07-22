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
void levelordertraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
                /* code */
            }

            /* code */
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
                /* code */
            }
            if (temp->right)
            {
                q.push(temp->right);
                /* code */
            }
        }

        /* code */
    }
}
node *BST(node *root, int d)
{
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }
    if (d < root->data)
    {
        root->left = BST(root->left, d);
    }
    else
    {
        root->right = BST(root->right, d);
    }
    return root;
}
node *Search_in_BST(node *&root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == key)
    {
        return root;
    }

    if (key < root->data)
    {
        return Search_in_BST(root->left, key);
    }
    else
    {
        return Search_in_BST(root->right, key);
    }
}
void input_nodes(node *&root)
{
    int d;
    cin >> d;
    while (d != -1)
    {
        root = BST(root, d);
        cin >> d;
        /* code */
    }
}

int main()
{
    node *root = NULL;
    cout << "===== Enter Nodes and -1 to stop \n";
    input_nodes(root);
    cout << "===== Level Order Traversal =====\n";
    levelordertraversal(root);
    int key;
    cout << "Enter key : ";
    cin >> key;
    cout << "Searching......\n";
    root = Search_in_BST(root, key);
    cout << "===== Level Order Traversal =====\n";
    levelordertraversal(root);
    return 0;
}
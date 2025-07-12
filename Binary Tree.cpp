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
node *BuildTree(node *root)
{
    int d;
    cout << "Enter data : ";
    cin >> d;
    root = new node(d);
    if (d == -1)
    {
        return NULL;
        /* code */
    }
    cout << "Enter left node of " << d << endl;
    root->left = BuildTree(root->left);
    cout << "Enter right node of " << d << endl;
    root->right = BuildTree(root->right);
    return root;
}
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
int main()
{
    node *root = NULL;
    root = BuildTree(root);
    levelordertraversal(root);
    return 0;
}
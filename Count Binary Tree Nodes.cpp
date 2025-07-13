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
int Count_nodes(node *root)
{
    int count = 0;
    if (!root)
    {
        count = 0;
        /* code */
    }
    else
    {

        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            count++;
            node *temp = q.front();
            q.pop();
            if (temp->left)
            {
                q.push(temp->left);
            }
            /* code */
            if (temp->right)
            {
                q.push(temp->right);
            }
            /* code */

            /* code */
        }
    }
    return count;
}
int main()
{
    node *root = NULL;
    root = BuildTree(root);
    cout << Count_nodes(root) << endl;
    return 0;
}
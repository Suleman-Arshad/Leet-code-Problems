#include <iostream>
#include <cmath>
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
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftnode = height(root->left);
    int rightnode = height(root->right);
    int res = max(leftnode, rightnode) + 1;
    return res;
}
bool is_balanced(node *root)
{
    if (root == NULL)
    {
        return true;
    }
    int leftnodes = is_balanced(root->left);
    int rightnodes = is_balanced(root->right);
    int difference = abs(height(root->left) - height(root->right) <= 1);
    if (leftnodes && rightnodes && difference)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void check_is_balanced(node *root)
{
    if (is_balanced(root))
    {
        cout << "Binary Tree is Balanced.\n";
    }
    else
    {
        cout << "Binary Tree is not Balanced\n";
    }
}
int main()
{
    node *root = NULL;
    root = BuildTree(root);
    check_is_balanced(root);
    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;
class node
{
private:
    /* data */
public:
    int data;
    node *left;
    node *right;
    node(/* args */ int d);
    ~node();
};

node::node(/* args */ int d)
{
    data = d;
    left = NULL;
    right = NULL;
}

node::~node()
{
}
node *BuildTree(node *&root)
{
    int d;
    cout << "Enter data : ";
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    root = new node(d);
    cout << "Enter left node of " << d << endl;
    root->left = BuildTree(root->left);
    cout << "Enter right node of " << d << endl;
    root->right = BuildTree(root->right);
    return root;
}
int Height_of_Binary_Tree(node *&root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftnode = Height_of_Binary_Tree(root->left);
    int rightnode = Height_of_Binary_Tree(root->right);
    int res = max(leftnode, rightnode) + 1;
    return res;
}
int main()
{
    node *root = NULL;
    root = BuildTree(root);
    cout << "Height of Binary Tree is " << Height_of_Binary_Tree(root) << " . " << endl;
    return 0;
}
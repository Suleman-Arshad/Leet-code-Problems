#include <iostream>
#include <cmath>
#include <vector>
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
vector<int> arr;
vector<int> Tree_into_array(node *root)
{
    if (root == NULL)
    {
        return arr;
    }
    Tree_into_array(root->left);
    arr.push_back(root->data);
    Tree_into_array(root->right);
    return arr;
}
bool is_Univalued(node *root)
{
    vector<int> arr;
    arr = Tree_into_array(root);
    bool check = false;
    int val = root->data;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != val)
        {
            check = false;
            break;
            /* code */
        }
        check = true;
        /* code */
    }
    return check;
}
int main()
{
    node *root = NULL;
    root = BuildTree(root);
    if (is_Univalued(root))
    {
        cout << "Binary Tree is Univalued\n";
    }
    else
    {
        cout << "Binary Tree is not Univalued\n";
    }
    return 0;
}
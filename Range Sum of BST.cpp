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
int sum = 0;
int RangeSum(node *root, int low, int high)
{
    if (root == NULL)
    {
        return sum;
    }
    RangeSum(root->left, low, high);
    if (root->data >= low && root->data <= high)
    {
        sum += root->data;
    }
    RangeSum(root->right, low, high);
    return sum;
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
    cout << "========== Enter BST nodes values ========= \n";
    input_nodes(root);
    int l, h;
    cout << "========== Enter Range =========== \n";
    cout << "Low : ";
    cin >> l;
    cout << "High : ";
    cin >> h;
    cout << "Sum of nums in this range is " << RangeSum(root, l, h) << "." << endl;
    return 0;
}
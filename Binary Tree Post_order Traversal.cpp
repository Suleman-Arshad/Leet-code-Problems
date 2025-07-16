#include <iostream>
#include <vector>
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
vector<int> arr;
vector<int> Postorder_traversal(node *root)
{

    if (root == NULL)
    {
        return arr;
    }
    
    Postorder_traversal(root->left);
    Postorder_traversal(root->right);
    arr.push_back(root->data);
    return arr;
}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
int main()
{
    node *root = NULL;
    vector<int> arr;
    root = BuildTree(root);
    cout << "Inorder Traversal of Binary Tree\n";
    arr = Postorder_traversal(root);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "  ";
        /* code */
    }
    cout << endl;

    system("pause");
    return 0;
}
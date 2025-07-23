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
int MinimumNodeInBST(node *root)
{
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
        /* code */
    }
    return temp->data;
}
node *Deleting_node(node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == key)
    {
        //0 child case
        if (root->left==NULL&&root->right==NULL)
        {
            delete root;
            return NULL;
            /* code */
        }
        //1 child case
        //if child is on left
        if (root->left!=NULL&&root->right==NULL)
        {
            node*temp=root->left;
            delete root;
            return temp;
            /* code */
        }
        //if child is on right
        if (root->left==NULL&&root->right!=NULL)
        {
            node*temp=root->right;
            delete root;
            return temp;
            /* code */
        }
        //2 child case
        if (root->left!=NULL&&root->right!=NULL)
        {
            int mini=MinimumNodeInBST(root->right);
            root->data=mini;
            root->right=Deleting_node(root->right,mini);
            return root;
            /* code */
        }
        
        
        /* code */
    }
    else if (root->data > key)
    {
        root->left = Deleting_node(root->left, key);
        return root;
    }
    else
    {
        root->right = Deleting_node(root->right, key);
        return root;
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
    int key;
    cout<<"Enter nodes values in BST and -1 to stop\n";
    input_nodes(root);
    cout<<"Level order Traversal Before deleting\n";
    levelordertraversal(root);
    cin.clear();
    cin.ignore();
    cout<<"Enter node value to delete : ";
    cin>>key;
    Deleting_node(root,key);
    cout<<"Level order traversal after deleting\n";
    levelordertraversal(root);
    return 0;
}
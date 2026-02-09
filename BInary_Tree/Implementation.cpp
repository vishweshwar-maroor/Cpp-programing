#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    // constructor
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildTree(node *root)
{
    cout << "Enter data :" << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << "Insert data for left node " << endl;
    root->left = buildTree(root->left);
    cout << "Insert data for right node " << endl;
    root->right = buildTree(root->right);
    return root;
}
int main()
{
}
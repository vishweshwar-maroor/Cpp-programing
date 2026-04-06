#include <iostream>
using namespacestd;
class Node
{
private:
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        left = right = NULL;
        data = val;
    };
};
// Deletion
Node* minVal(Node* root){
    Node* temp=root;
    while(temp->left!NULL){
        temp=temp->left;
    }
    return temp;
}
Node *deleteNode(Node *&root, int val)
{
    // basecase
    if (root == NULL)
    {
        return root;
    }
    else if (root->data == val)
    {
        // 0child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1child
        else if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL && root->left != NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // 2child bring min val from right tree
        else if (root->left != NULL && root->right != NULL)
        {
            Node* mini= minVal(root->right);
            root->data=mini->data;
            root->right=deleteNode(root->right,mini->data);
            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = deleteNode(root->left, val);
        return root;
    }
    else
    {
        root->right = deleteNode(root->right, val);
        return root;
    }
}
// searching
Node *searchNode(Node *&root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    else if (root->data == val)
    {
        return root;
    }
    else if (root->data < val)
    {
        return searchNode(root->right, val);
    }
    else if (root->data > val)
    {
        return searchNode(root->left, val);
    }
    else
    {
        return root;
    }
}

// recursive
Node *InsertIntoBST(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data > root->data)
    {
        root->right = InsertIntoBST(root->right, data);
    }
    else
    {
        root->left = InsertIntoBST(root->left, data);
    }
    return root;
}
void ImplementBST(Node *&root, int data)
{
    Node *temp = root;
    if (root == NULL)
    {
        root = new Node(data);
        return;
    }
    while (temp != NULL)
    {
        if (temp->data > data)
        {
            if (temp->right == NULL)
            {
                temp->right = new Node(data);
                return;
            }
            else
            {
                temp = temp->right;
            }
        }
        if (temp->data < data)
        {
            if (temp->left == NULL)
            {
                temp->left = new Node(data);
                return;
            }
            else
            {
                temp = temp->left;
            }
        }
    }
    return;
}
void takeInput(Node *&root)
{
    int x;
    cin >> x;
    while (x != -1)
    {
        ImplementBST(root, data);
        cin >> x;
    }
}

int main()
{
    Node *root = NULL;
    cout << "Enter data: ";
    takeInput(root);
}
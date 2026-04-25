/*Problem statement
You have been given a binary tree of integers.

Your task is to check if it is a binary heap tree or not.

Note:

A binary tree is a tree in which each parent node has at most two children.

A binary heap tree has the following properties.
1. It must be a complete binary tree. In the complete binary tree every level, except the last level, is completely filled and the last level is as far left as possible.

2. Every parent must be greater than its all children nodes.
*/
#include <bits/stdc++.h>
using namespace std;

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};
/*
wrong logic

bool check(BinaryTreeNode<int> *root)
{
    // completeness
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    if (root->right != = NULL && root->left == NULL)
        return false;

    //
    if (root->left && root->left->data >= root->data)
    {
        return false;
    }
    if (root->right && root->right->data >= root->data)
    {
        return false;
    }
    return true;
}
bool binarychecker(BinaryTreeNode<int> *root){
    bool node=check(root);
    if(root){
        return(check(root->left)&&check(root->right))
    }
    else{
        return false
    }

}
bool isBinaryHeapTree(BinaryTreeNode<int> *root)
{
    // Write your code here.
    return binarychecker(root);
}
    */

// level order apprroch

bool isBinaryHeapTree(BinaryTreeNode<int> *root)
{
    // Write your code here.
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    bool end = false;
    while (q.size() > 0)
    {
        BinaryTreeNode<int> *temp = q.front();
        q.pop();
        if (temp->left)
        {
            if(temp->data<temp->left->data) return false;
            if (end)
            {
                return false;
            }
            q.push(temp->left);
        }
        else
        {
            end = true
        }
        if (temp->right)
        {
            if(temp->data<temp->right->data) return false;
            if (end)
            {
                return false;
            }
            q.push(temp->right);
        }
        else
        {
            end = true
        }
    }
    return true;
}
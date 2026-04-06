/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys strictly less than the node's key.
The right subtree of a node contains only nodes with keys strictly greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    bool validate(vector<int> &v)
    {
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] > v[i - 1])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    void inOrder(TreeNode *root, vector<int> &v)
    {
        if (root == NULL)
        {
            return;
        }
        // L
        inOrder(root->left, v);
        // N
        v.push_back(root->val);
        // R
        inOrder(root->right, v);
    }

    bool isValidBST(TreeNode *root)
    {
        vector<int> v;
        inOrder(root, v);
        bool verify = validate(v);
        return verify;
    }
};
class Solution
{
public:
    bool isValidBST(TreeNode *root, double min = -std::numeric_limits<double>::infinity(), double max = std::numeric_limits<double>::infinity())
    {
        // Basecase
        if (root == NULL)
        {
            return true;
        }
        bool checkl = true, checkr = true;
        if (root->left != NULL)
        {
            if (root->left->val < root->val && (root->left->val < max && root->left->val > min))
            {
                checkl = isValidBST(root->left, min, root->val);
            }
            else
            {
                checkl = false;
            }
        }
        else
        {
            checkl = true;
        }
        if (root->right != NULL)
        {
            if (root->right->val > root->val && (root->right->val < max && root->right->val > min))
            {
                checkr = isValidBST(root->right, root->val, max);
            }
            else
            {
                checkr = false;
            }
        }
        else
        {
            checkr = true;
        }
        return (checkr && checkl);
    }
};
#include <iostream>
using namespace std;

int main()
{
}